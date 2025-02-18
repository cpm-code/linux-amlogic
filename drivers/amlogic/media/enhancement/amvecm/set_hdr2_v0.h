/*
 * drivers/amlogic/media/enhancement/amvecm/set_hdr2_v0.h
 *
 * Copyright (C) 2017 Amlogic, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 */

#include <linux/types.h>
#include <linux/amlogic/media/vout/vinfo.h>
#include "hdr/am_hdr10_plus_ootf.h"
#include "amcsc.h"

#ifndef MAX
#define MAX(x1, x2) (double)(x1 > x2 ? x1 : x2)
#endif

#ifndef POW
#define POW(x1, x2) (int64_t)(pow((double)x1, (double)x2))
#endif

#ifndef LOG2
#define LOG2(x) (int)(x == 0 ? 0 : log2((long long)x))
#endif

#define FLTZERO 0xfc000/*float zero*/

#define peak_out  10000/* luma out*/
#define peak_in   1000/* luma in*/
/* 0:hdr10 peak_in input to hdr10 peak_out,*/
/*1:hdr peak_in->gamma,2:gamma->hdr peak out*/
#define fmt_io       2

#define precision  14/* freeze*/
/*input data bitwidth : 12 (VD1 OSD1 VD2)*/
/*10 (VDIN & DI)*/
#define IE_BW      12
#define OE_BW      12/*same IE_BW*/
#define O_BW       32/*freeze*/
#define maxbit     33/*freeze*/
#define OGAIN_BW   12/*freeze*/

int64_t FloatRev(int64_t iA);
int64_t FloatCon(int64_t iA, int MOD);

enum hdr_module_sel {
	VD1_HDR = 1,
	VD2_HDR = 2,
	OSD1_HDR = 3,
	VDIN0_HDR = 4,
	VDIN1_HDR = 5,
	DI_HDR = 6,
	HDR_MAX
};

enum hdr_matrix_sel {
	HDR_IN_MTX = 1,
	HDR_GAMUT_MTX = 2,
	HDR_OUT_MTX = 3,
	HDR_MTX_MAX
};

enum hdr_lut_sel {
	HDR_EOTF_LUT = 1,
	HDR_OOTF_LUT = 2,
	HDR_OETF_LUT = 3,
	HDR_CGAIN_LUT = 4,
	HDR_LUT_MAX
};

enum hdr_process_sel {
	HDR_BYPASS = BIT(0),
	HDR_SDR = BIT(1),
	SDR_HDR = BIT(2),
	HLG_BYPASS = BIT(3),
	HLG_SDR = BIT(4),
	HLG_HDR = BIT(5),
	SDR_HLG = BIT(6),
	SDR_IPT = BIT(7),
	HDR_IPT = BIT(8),
	HLG_IPT = BIT(9),
	HDR_HLG = BIT(10),
	HDR10P_SDR = BIT(11),
	SDR_GMT_CONVERT = BIT(12),
	IPT_MAP = BIT(13),
	CUVA_BYPASS = BIT(14),
	CUVA_SDR = BIT(15),
	CUVA_HDR = BIT(16),
	CUVA_HLG = BIT(17),
	CUVA_IPT = BIT(18),
	SDR_CUVA = BIT(19),
	HDR_CUVA = BIT(20),
	HLG_CUVA = BIT(21),
	PROCESS_MAX = BIT(22),
	/* reserved  several bits for additional info */
	RGB_OSD = BIT(29),
	RGB_VDIN = BIT(30),
	FULL_VDIN = BIT(31)
};

enum hdr_hist_sel {
	HIST_E_RGBMAX = 0,
	HIST_E_LUMA = 1,
	HIST_E_SAT = 2,
	HIST_O_BEFORE = 4,
	HIST_O_AFTER = 6,
	HIST_MAX
};

#define MTX_ON  1
#define MTX_OFF 0

#define MTX_ONLY  1
#define HDR_ONLY  0

#define LUT_ON  1
#define LUT_OFF 0

#define HDR2_EOTF_LUT_SIZE 143
#define HDR2_OOTF_LUT_SIZE 149
#define HDR2_OETF_LUT_SIZE 149
#define HDR2_CGAIN_LUT_SIZE 65


#define MTX_NUM_PARAM 16
struct hdr_proc_mtx_param_s {
	int mtx_only;
	int mtx_in[MTX_NUM_PARAM];
	int mtx_gamut[9];
	int mtx_gamut_mode;
	int mtx_cgain[MTX_NUM_PARAM];
	int mtx_ogain[MTX_NUM_PARAM];
	int mtx_out[MTX_NUM_PARAM];
	int mtxi_pre_offset[3];
	int mtxi_pos_offset[3];
	int mtxo_pre_offset[3];
	int mtxo_pos_offset[3];
	unsigned int mtx_on;
	enum hdr_process_sel p_sel;
	unsigned int gmt_bit_mode;
};

#define OO_BITS			12
#define OO_GAIN_SHIFT	3
#define OO_NOR			(OO_BITS - OO_GAIN_SHIFT)

struct hdr_proc_lut_param_s {
	int64_t eotf_lut[143];
	int64_t oetf_lut[149];
	int64_t ogain_lut[149];
	int64_t cgain_lut[65];
	unsigned int lut_on;
	unsigned int bitdepth;
	unsigned int cgain_en;
	unsigned int hist_en;
};

typedef int64_t(*MenuFun)(int64_t);
void eotf_float_gen(int64_t *o_out, MenuFun eotf);
void oetf_float_gen(int64_t *bin_e, MenuFun oetf);
void nolinear_lut_gen(int64_t *bin_c, MenuFun cgain);
extern enum hdr_process_sel hdr_func(enum hdr_module_sel module_sel,
	u32 hdr_process_select,
	struct vinfo_s *vinfo,
	struct matrix_s *gmt_mtx);

enum mtx_csc_e {
	MATRIX_NULL = 0,
	MATRIX_RGB_YUV601 = 0x1,
	MATRIX_RGB_YUV601F = 0x2,
	MATRIX_RGB_YUV709 = 0x3,
	MATRIX_RGB_YUV709F = 0x4,
	MATRIX_YUV601_RGB = 0x10,
	MATRIX_YUV601_YUV601F = 0x11,
	MATRIX_YUV601_YUV709 = 0x12,
	MATRIX_YUV601_YUV709F = 0x13,
	MATRIX_YUV601F_RGB = 0x14,
	MATRIX_YUV601F_YUV601 = 0x15,
	MATRIX_YUV601F_YUV709 = 0x16,
	MATRIX_YUV601F_YUV709F = 0x17,
	MATRIX_YUV709_RGB = 0x20,
	MATRIX_YUV709_YUV601 = 0x21,
	MATRIX_YUV709_YUV601F = 0x22,
	MATRIX_YUV709_YUV709F = 0x23,
	MATRIX_YUV709F_RGB = 0x24,
	MATRIX_YUV709F_YUV601 = 0x25,
	MATRIX_YUV709F_YUV709 = 0x26,
	MATRIX_BT2020YUV_BT2020RGB = 0x40,
	MATRIX_BT2020RGB_709RGB,
	MATRIX_BT2020RGB_CUSRGB,
	MATRIX_BT2020YUV_CUSYUV,
};

extern void mtx_setting(enum vpp_matrix_e mtx_sel,
	enum mtx_csc_e mtx_csc,
	int mtx_on);

unsigned int _log2(unsigned int value);
int hdr10p_ebzcurve_update(
	enum hdr_module_sel module_sel,
	enum hdr_process_sel hdr_process_select,
	struct hdr10pgen_param_s *hdr10pgen_param);
enum hdr_process_sel hdr10p_func(
	enum hdr_module_sel module_sel,
	u32 hdr_process_select,
	struct vinfo_s *vinfo,
	struct matrix_s *gmt_mtx);
extern void set_ootf_lut(
	enum hdr_module_sel module_sel,
	struct hdr_proc_lut_param_s *hdr_lut_param);
extern struct hdr_proc_lut_param_s hdr_lut_param;
extern int oo_y_lut_hdr_sdr_def[149];
extern int oo_y_lut_hdr_sdr[149];
extern int oo_y_lut_hlg_sdr[149];
void eo_clip_proc(
	struct vframe_master_display_colour_s *master_info,
	unsigned int eo_sel);
int hdr10_tm_update(
	enum hdr_module_sel module_sel,
	enum hdr_process_sel hdr_process_select);
extern int cgain_lut_bypass[65];
extern unsigned int hdr10_pr;
extern unsigned int hdr10_clip_disable;
extern unsigned int hdr10_clip_luma;
extern unsigned int hdr10_clip_margin;
void get_hist(
	enum vd_path_e vd_path,
	enum hdr_hist_sel hist_sel);
#define NUM_HDR_HIST 16
extern u32 hdr_hist[NUM_HDR_HIST][128];
extern u32 percentile[9];
extern u32 disable_flush_flag;
struct aml_gain_reg *get_cuva_gain(void);
int cuva_hdr_update(
	enum hdr_module_sel module_sel,
	enum hdr_process_sel hdr_process_select);
void mtx_init(enum vpp_matrix_e mtx_sel, enum mtx_csc_e mtx_csc, int mtx_on);
extern uint get_hdr_mode(void);