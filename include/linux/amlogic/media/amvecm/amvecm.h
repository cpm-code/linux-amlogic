/*
 * include/linux/amlogic/media/amvecm/amvecm.h
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

#ifndef AMVECM_H
#define AMVECM_H

#include "linux/amlogic/media/amvecm/ve.h"
#include "linux/amlogic/media/amvecm/cm.h"
#include "linux/amlogic/media/amvecm/hdr10_tmo_alg.h"
#include <linux/amlogic/media/vfm/vframe.h>
#include <linux/amlogic/media/utils/amstream.h>
#include <linux/amlogic/media/video_sink/vpp.h>
#include <linux/amlogic/cpu_version.h>
#include <drm/drmP.h>


/* struct ve_dnlp_s          video_ve_dnlp; */
#define FLAG_RSV31              (1 << 31)
#define FLAG_VADJ1_COLOR        (1 << 30)
#define FLAG_VE_DNLP            (1 << 29)
#define FLAG_VE_NEW_DNLP        (1 << 28)
#define FLAG_VE_LC_CURV         (1 << 27)
#define FLAG_HDR_OOTF_LATCH     BIT(26)
#define FLAG_3D_BLACK_DIS       (1 << 25)
#define FLAG_3D_BLACK_EN        (1 << 24)
#define FLAG_3D_SYNC_DIS        (1 << 23)
#define FLAG_3D_SYNC_EN         (1 << 22)
#define FLAG_VLOCK_DIS          (1 << 21)
#define FLAG_VLOCK_EN          (1 << 20)
#define FLAG_VE_DNLP_EN         (1 << 19)
#define FLAG_VE_DNLP_DIS        (1 << 18)
#define FLAG_VADJ1_CON			(1 << 17)
#define FLAG_VADJ1_BRI			(1 << 16)
#define FLAG_GAMMA_TABLE_EN     (1 << 15)
#define FLAG_GAMMA_TABLE_DIS    (1 << 14)
#define FLAG_GAMMA_TABLE_R      (1 << 13)
#define FLAG_GAMMA_TABLE_G      (1 << 12)
#define FLAG_GAMMA_TABLE_B      (1 << 11)
#define FLAG_RGB_OGO            (1 << 10)
#define FLAG_VADJ_EN            BIT(9)
#define FLAG_MATRIX_UPDATE      (1 <<  8)
#define FLAG_BRI_CON            (1 <<  7)
#define FLAG_LVDS_FREQ_SW       (1 <<  6)
#define FLAG_REG_MAP5           (1 <<  5)
#define FLAG_REG_MAP4           (1 <<  4)
#define FLAG_REG_MAP3           (1 <<  3)
#define FLAG_REG_MAP2           (1 <<  2)
#define FLAG_REG_MAP1           (1 <<  1)
#define FLAG_REG_MAP0           (1 <<  0)

#define VPP_VADJ2_BLMINUS_EN        (1 << 3)
#define VPP_VADJ2_EN                (1 << 2)
#define VPP_VADJ1_BLMINUS_EN        (1 << 1)
#define VPP_VADJ1_EN                (1 << 0)

#define VPP_PRE_GAMMA_UPDATE        BIT(6)
#define VPP_MARTIX_GET              BIT(5)
#define VPP_MARTIX_UPDATE           BIT(4)
#define VPP_DEMO_DNLP_DIS           (1 << 3)
#define VPP_DEMO_DNLP_EN            (1 << 2)
#define VPP_DEMO_CM_DIS             (1 << 1)
#define VPP_DEMO_CM_EN              (1 << 0)

/*PQ USER LATCH*/
#define PQ_USER_CMS_SAT_HUE        BIT(24)
#define PQ_USER_CMS_CURVE_HUE_HS   BIT(23)
#define PQ_USER_CMS_CURVE_HUE      BIT(22)
#define PQ_USER_CMS_CURVE_LUMA     BIT(21)
#define PQ_USER_CMS_CURVE_SAT      BIT(20)
#define PQ_USER_SR1_DERECTION_DIS  (1 << 19)
#define PQ_USER_SR1_DERECTION_EN   (1 << 18)
#define PQ_USER_SR0_DERECTION_DIS  (1 << 17)
#define PQ_USER_SR0_DERECTION_EN   (1 << 16)
#define PQ_USER_SR1_DEJAGGY_DIS    (1 << 15)
#define PQ_USER_SR1_DEJAGGY_EN     (1 << 14)
#define PQ_USER_SR0_DEJAGGY_DIS    (1 << 13)
#define PQ_USER_SR0_DEJAGGY_EN     (1 << 12)
#define PQ_USER_SR1_DERING_DIS     (1 << 11)
#define PQ_USER_SR1_DERING_EN      (1 << 10)
#define PQ_USER_SR0_DERING_DIS     (1 << 9)
#define PQ_USER_SR0_DERING_EN      (1 << 8)
#define PQ_USER_SR1_PK_DIS         (1 << 7)
#define PQ_USER_SR1_PK_EN          (1 << 6)
#define PQ_USER_SR0_PK_DIS         (1 << 5)
#define PQ_USER_SR0_PK_EN          (1 << 4)
#define PQ_USER_BLK_SLOPE          (1 << 3)
#define PQ_USER_BLK_START          (1 << 2)
#define PQ_USER_BLK_DIS            (1 << 1)
#define PQ_USER_BLK_EN             (1 << 0)

/*white balance latch*/
#define MTX_BYPASS_RGB_OGO			(1 << 0)
#define MTX_RGB2YUVL_RGB_OGO		(1 << 1)

#define UNKNOWN_SOURCE		0
#define HDR10_SOURCE		1
#define HDR10PLUS_SOURCE	2
#define DOVI_SOURCE			3
#define PRIMESL_SOURCE		4
#define HLG_SOURCE			5
#define SDR_SOURCE			6
#define MVC_SOURCE           7
#define CUVA_HDR_SOURCE      8
#define CUVA_HLG_SOURCE      9
#define SDR_BT2020_SOURCE      10

#define DNLP_PARAM_RD_UPDATE 0x1
#define DNLP_CV_RD_UPDATE 0x2
#define WB_PARAM_RD_UPDATE 0x4
#define LC_CUR_RD_UPDATE 0x8
#define LC_PARAM_RD_UPDATE 0x10
#define LC_CUR2_RD_UPDATE 0x20

enum cm_hist_e {
	CM_HUE_HIST = 0,
	CM_SAT_HIST,
	CM_MAX_HIST
};

enum dv_pq_ctl_e {
	DV_PQ_BYPASS = 0,
	DV_PQ_CERT,
	DV_PQ_REC,
};

enum pq_table_name_e {
	TABLE_NAME_SHARPNESS0 = 0x1,/*in vpp*/
	TABLE_NAME_SHARPNESS1 = 0x2,/*in vpp*/
	TABLE_NAME_DNLP = 0x4,		/*in vpp*/
	TABLE_NAME_CM = 0x8,		/*in vpp*/
	TABLE_NAME_BLK_BLUE_EXT = 0x10,/*in vpp*/
	TABLE_NAME_BRIGHTNESS = 0x20,/*in vpp*/
	TABLE_NAME_CONTRAST = 0x40,	/*in vpp*/
	TABLE_NAME_SATURATION_HUE = 0x80,/*in vpp*/
	TABLE_NAME_CVD2 = 0x100,		/*in tvafe*/
	TABLE_NAME_DI = 0x200,		/*in di*/
	TABLE_NAME_NR = 0x400,		/*in di*/
	TABLE_NAME_MCDI = 0x800,	/*in di*/
	TABLE_NAME_DEBLOCK = 0x1000,	/*in di*/
	TABLE_NAME_DEMOSQUITO = 0x2000,/*in di*/
	TABLE_NAME_WB = 0X4000,		/*in vpp*/
	TABLE_NAME_GAMMA = 0X8000,	/*in vpp*/
	TABLE_NAME_XVYCC = 0x10000,	/*in vpp*/
	TABLE_NAME_HDR = 0x20000,	/*in vpp*/
	TABLE_NAME_DOLBY_VISION = 0x40000,/*in vpp*/
	TABLE_NAME_OVERSCAN = 0x80000,
	TABLE_NAME_SMOOTHPLUS = 0x100000,/*in di*/
	TABLE_NAME_RESERVED2 = 0x200000,
	TABLE_NAME_RESERVED3 = 0x400000,
	TABLE_NAME_RESERVED4 = 0x800000,
	TABLE_NAME_MAX,
};

#define _VE_CM  'C'

#define AMVECM_IOC_G_HIST_AVG   _IOW(_VE_CM, 0x22, struct ve_hist_s)
#define AMVECM_IOC_VE_DNLP_EN   _IO(_VE_CM, 0x23)
#define AMVECM_IOC_VE_DNLP_DIS  _IO(_VE_CM, 0x24)
#define AMVECM_IOC_VE_NEW_DNLP  _IOW(_VE_CM, 0x25, struct ve_dnlp_curve_param_s)
#define AMVECM_IOC_G_HIST_BIN   _IOW(_VE_CM, 0x26, struct vpp_hist_param_s)
#define AMVECM_IOC_G_HDR_METADATA _IOW(_VE_CM, 0x27, struct hdr_metadata_info_s)
/*vpp get color primary*/
#define AMVECM_IOC_G_COLOR_PRI _IOR(_VE_CM, 0x28, enum color_primary_e)

/* VPP.CM IOCTL command list */
#define AMVECM_IOC_LOAD_REG  _IOW(_VE_CM, 0x30, struct am_regs_s)

/* VPP.GAMMA IOCTL command list */
#define AMVECM_IOC_GAMMA_TABLE_EN  _IO(_VE_CM, 0x40)
#define AMVECM_IOC_GAMMA_TABLE_DIS _IO(_VE_CM, 0x41)
#define AMVECM_IOC_GAMMA_TABLE_R _IOW(_VE_CM, 0x42, struct tcon_gamma_table_s)
#define AMVECM_IOC_GAMMA_TABLE_G _IOW(_VE_CM, 0x43, struct tcon_gamma_table_s)
#define AMVECM_IOC_GAMMA_TABLE_B _IOW(_VE_CM, 0x44, struct tcon_gamma_table_s)
#define AMVECM_IOC_S_RGB_OGO   _IOW(_VE_CM, 0x45, struct tcon_rgb_ogo_s)
#define AMVECM_IOC_G_RGB_OGO  _IOR(_VE_CM, 0x46, struct tcon_rgb_ogo_s)

/*VPP.VLOCK IOCTL command list*/
#define AMVECM_IOC_VLOCK_EN  _IO(_VE_CM, 0x47)
#define AMVECM_IOC_VLOCK_DIS _IO(_VE_CM, 0x48)

/*VPP.3D-SYNC IOCTL command list*/
#define AMVECM_IOC_3D_SYNC_EN  _IO(_VE_CM, 0x49)
#define AMVECM_IOC_3D_SYNC_DIS _IO(_VE_CM, 0x50)

struct ve_pq_load_s {
	enum pq_table_name_e param_id;
	unsigned int length;
	union {
		void *param_ptr;
		long long param_ptr_len;
	};
	union {
		void *reserved;
		long long reserved_len;
	};
};

struct ve_pq_table_s {
	unsigned int src_timing;
	unsigned int value1;
	unsigned int value2;
	unsigned int reserved1;
	unsigned int reserved2;
};

#define AMVECM_IOC_SET_OVERSCAN  _IOW(_VE_CM, 0x52, struct ve_pq_load_s)
enum dnlp_state_e {
	DNLP_OFF = 0,
	DNLP_ON,
};
/*DNLP IOCTL command list*/
#define AMVECM_IOC_G_DNLP_STATE _IOR(_VE_CM, 0x53, enum dnlp_state_e)
#define AMVECM_IOC_S_DNLP_STATE _IOW(_VE_CM, 0x54, enum dnlp_state_e)
enum pc_mode_e {
	PCMODE_OFF = 0,
	PCMODE_ON,
};
/*PCMODE IOCTL command list*/
#define AMVECM_IOC_G_PQMODE _IOR(_VE_CM, 0x55, enum pc_mode_e)
#define AMVECM_IOC_S_PQMODE _IOW(_VE_CM, 0x56, enum pc_mode_e)

/*CUR_CSCTYPE IOCTL command list*/
#define AMVECM_IOC_G_CSCTYPE _IOR(_VE_CM, 0x57, enum vpp_matrix_csc_e)
#define AMVECM_IOC_S_CSCTYPE _IOW(_VE_CM, 0x58, enum vpp_matrix_csc_e)

/*PIC_MODE IOCTL command list*/
#define AMVECM_IOC_G_PIC_MODE _IOR(_VE_CM, 0x59, struct am_vdj_mode_s)
#define AMVECM_IOC_S_PIC_MODE _IOW(_VE_CM, 0x60, struct am_vdj_mode_s)

/*HDR TYPE command list*/
#define AMVECM_IOC_G_HDR_TYPE _IOR(_VE_CM, 0x61, enum hdr_type_e)

/*Local contrast command list*/
#define AMVECM_IOC_S_LC_CURVE _IOW(_VE_CM, 0x62, struct ve_lc_curve_parm_s)

enum lut_type_e {
	HLG_LUT = 1,
	HDR_LUT = 2,
	LUT_MAX
};

/*tone mapping struct*/
struct hdr_tone_mapping_s {
	enum lut_type_e lut_type;
	unsigned int lutlength;
	unsigned int *tm_lut;
};

#define AMVECM_IOC_S_HDR_TM  _IOW(_VE_CM, 0x63, struct hdr_tone_mapping_s)
#define AMVECM_IOC_G_HDR_TM  _IOR(_VE_CM, 0x64, struct hdr_tone_mapping_s)

/* CMS ioctl data structure */
struct cms_data_s {
	int color;
	int value;
};

#define AMVECM_IOC_S_CMS_LUMA   _IOW(_VE_CM, 0x65, struct cms_data_s)
#define AMVECM_IOC_S_CMS_SAT    _IOW(_VE_CM, 0x66, struct cms_data_s)
#define AMVECM_IOC_S_CMS_HUE    _IOW(_VE_CM, 0x67, struct cms_data_s)
#define AMVECM_IOC_S_CMS_HUE_HS _IOW(_VE_CM, 0x68, struct cms_data_s)

#define AMVECM_IOC_S_PQ_CTRL  _IOW(_VE_CM, 0x69, struct vpp_pq_ctrl_s)
#define AMVECM_IOC_G_PQ_CTRL  _IOR(_VE_CM, 0x6a, struct vpp_pq_ctrl_s)

enum meson_cpu_ver_e {
	VER_NULL = 0,
	VER_A,
	VER_B,
	VER_C,
	VER_MAX
};
/*cpu ver ioc*/
#define AMVECM_IOC_S_MESON_CPU_VER _IOW(_VE_CM, 0x6b, enum meson_cpu_ver_e)

/*G12A vpp matrix*/
enum vpp_matrix_e {
	MTX_NULL = 0,
	VD1_MTX = 0x1,
	POST2_MTX = 0x2,
	POST_MTX = 0x4
};

struct matrix_coef_s {
	u16 pre_offset[3];
	u16 matrix_coef[3][3];
	u16 post_offset[3];
	u16 right_shift;
	u16 en;
};

struct vpp_mtx_info_s {
	enum vpp_matrix_e mtx_sel;
	struct matrix_coef_s mtx_coef;
};

#define AMVECM_IOC_S_MTX_COEF   _IOW(_VE_CM, 0x70, struct vpp_mtx_info_s)
#define AMVECM_IOC_G_MTX_COEF   _IOR(_VE_CM, 0x71, struct vpp_mtx_info_s)

struct pre_gamma_table_s {
	unsigned int en;
	unsigned int lut_r[65];
	unsigned int lut_g[65];
	unsigned int lut_b[65];
};

#define AMVECM_IOC_S_PRE_GAMMA   _IOW(_VE_CM, 0x72, struct pre_gamma_table_s)
#define AMVECM_IOC_G_PRE_GAMMA   _IOR(_VE_CM, 0x73, struct pre_gamma_table_s)

/*hdr10_tmo ioc*/
#define AMVECM_IOC_S_HDR_TMO   _IOW(_VE_CM, 0x74, struct hdr_tmo_sw)
#define AMVECM_IOC_G_HDR_TMO   _IOR(_VE_CM, 0x75, struct hdr_tmo_sw)

struct am_vdj_mode_s {
	int flag;
	int brightness;
	int brightness2;
	int saturation_hue;
	int saturation_hue_post;
	int contrast;
	int contrast2;
	int vadj1_en;  /*vadj1 enable: 1 enable  0 disable*/
	int vadj2_en;
};

enum color_primary_e {
	VPP_COLOR_PRI_NULL = 0,
	VPP_COLOR_PRI_BT601,
	VPP_COLOR_PRI_BT709,
	VPP_COLOR_PRI_BT2020,
	VPP_COLOR_PRI_MAX,
};

enum vpp_matrix_csc_e {
	VPP_MATRIX_NULL = 0,
	VPP_MATRIX_RGB_YUV601 = 0x1,
	VPP_MATRIX_RGB_YUV601F = 0x2,
	VPP_MATRIX_RGB_YUV709 = 0x3,
	VPP_MATRIX_RGB_YUV709F = 0x4,
	VPP_MATRIX_YUV601_RGB = 0x10,
	VPP_MATRIX_YUV601_YUV601F = 0x11,
	VPP_MATRIX_YUV601_YUV709 = 0x12,
	VPP_MATRIX_YUV601_YUV709F = 0x13,
	VPP_MATRIX_YUV601F_RGB = 0x14,
	VPP_MATRIX_YUV601F_YUV601 = 0x15,
	VPP_MATRIX_YUV601F_YUV709 = 0x16,
	VPP_MATRIX_YUV601F_YUV709F = 0x17,
	VPP_MATRIX_YUV709_RGB = 0x20,
	VPP_MATRIX_YUV709_YUV601 = 0x21,
	VPP_MATRIX_YUV709_YUV601F = 0x22,
	VPP_MATRIX_YUV709_YUV709F = 0x23,
	VPP_MATRIX_YUV709F_RGB = 0x24,
	VPP_MATRIX_YUV709F_YUV601 = 0x25,
	VPP_MATRIX_YUV709F_YUV709 = 0x26,
	VPP_MATRIX_YUV601L_YUV709L = 0x27,
	VPP_MATRIX_YUV709L_YUV601L = 0x28,
	VPP_MATRIX_YUV709F_YUV601F = 0x29,
	VPP_MATRIX_BT2020YUV_BT2020RGB_SDR,
	VPP_MATRIX_BT2020YUV_BT2020RGB = 0x40,
	VPP_MATRIX_BT2020RGB_709RGB,
	VPP_MATRIX_BT2020RGB_CUSRGB,
	VPP_MATRIX_BT2020YUV_BT2020RGB_DYNAMIC = 0x50,
	VPP_MATRIX_BT2020YUV_BT2020RGB_CUVA = 0x51,
	VPP_MATRIX_DEFAULT_CSCTYPE = 0xffff,
};

enum hdr_type_e {
	HDRTYPE_NONE = UNKNOWN_SOURCE,
	HDRTYPE_SDR = SDR_SOURCE,
	HDRTYPE_HDR10 = HDR10_SOURCE,
	HDRTYPE_HLG = HLG_SOURCE,
	HDRTYPE_HDR10PLUS = HDR10PLUS_SOURCE,
	HDRTYPE_DOVI = DOVI_SOURCE,
	HDRTYPE_MVC = MVC_SOURCE,
	HDRTYPE_CUVA_HDR = CUVA_HDR_SOURCE,
	HDRTYPE_CUVA_HLG = CUVA_HLG_SOURCE,
	HDRTYPE_SDR2020 = SDR_BT2020_SOURCE
};

enum pd_comb_fix_lvl_e {
	PD_LOW_LVL = 0,
	PD_MID_LVL,
	PD_HIG_LVL,
	PD_DEF_LVL
};

enum vpp_transfer_characteristic_e {
	VPP_ST_NULL = 0,
	VPP_ST709 = 0x1,
	VPP_ST2084 = 0x2,
	VPP_ST2094_40 = 0x4,
};

enum ve_source_input_e {
	SOURCE_INVALID = -1,
	SOURCE_TV = 0,
	SOURCE_AV1,
	SOURCE_AV2,
	SOURCE_YPBPR1,
	SOURCE_YPBPR2,
	SOURCE_HDMI1,
	SOURCE_HDMI2,
	SOURCE_HDMI3,
	SOURCE_HDMI4,
	SOURCE_VGA,
	SOURCE_MPEG,
	SOURCE_DTV,
	SOURCE_SVIDEO,
	SOURCE_IPTV,
	SOURCE_DUMMY,
	SOURCE_SPDIF,
	SOURCE_ADTV,
	SOURCE_MAX,
};

/*pq_timing:
 *SD/HD/FHD/UHD for DTV/MEPG,
 *NTST_M/NTST_443/PAL_I/PAL_M/PAL_60/PAL_CN/SECAM/NTST_50 for AV/ATV
 */
enum ve_pq_timing_e {
	TIMING_SD = 0,
	TIMING_HD,
	TIMING_FHD,
	TIMING_UHD,
	TIMING_NTST_M,
	TIMING_NTST_443,
	TIMING_PAL_I,
	TIMING_PAL_M,
	TIMING_PAL_60,
	TIMING_PAL_CN,
	TIMING_SECAM,
	TIMING_NTSC_50,
	TIMING_MAX,
};

/*overscan:
 *length 0~31bit :number of crop;
 *src_timing: bit31: on: load/save all crop
			  bit31: off: load one according to timing*
			  bit30: AFD_enable: 1 -> on; 0 -> off*
			  screen mode: bit24~bit29*
			  source: bit16~bit23 -> source*
			  timing: bit0~bit15 -> sd/hd/fhd/uhd*
 *value1: 0~15bit hs   16~31bit he*
 *value2: 0~15bit vs   16~31bit ve*
 */
struct ve_pq_overscan_s {
	unsigned int load_flag;
	unsigned int afd_enable;
	unsigned int screen_mode;
	enum ve_source_input_e source;
	enum ve_pq_timing_e timing;
	unsigned int hs;
	unsigned int he;
	unsigned int vs;
	unsigned int ve;
};

extern struct ve_pq_overscan_s overscan_table[TIMING_MAX];

struct aipq_load_s {
	unsigned int height;
	unsigned int width;
	union {
		void *table_ptr;
		long long table_len;
	};
};

#define AMVECM_IOC_S_AIPQ_TABLE _IOW(_VE_CM, 0x6c, struct aipq_load_s)

#define _DI_	'D'

struct am_pq_parm_s {
	unsigned int table_name;
	unsigned int table_len;
	union {
		void *table_ptr;
		long long l_table;
	};
	union {
		void *reserved;
		long long l_reserved;
	};
};

#define AMDI_IOC_SET_PQ_PARM  _IOW(_DI_, 0x51, struct am_pq_parm_s)

/*3D LUT IOCTL command list*/
struct table_3dlut_s {
	unsigned int data[17 * 17 * 17][3];
} /*table_3dlut_s */;
#define AMVECM_IOC_SET_3D_LUT  _IO(_VE_CM, 0x6d)
#define AMVECM_IOC_LOAD_3D_LUT  _IO(_VE_CM, 0x6e)
#define AMVECM_IOC_SET_3D_LUT_ORDER  _IO(_VE_CM, 0x6f)

enum vlk_chiptype {
	vlock_chip_txl,
	vlock_chip_txlx,
	vlock_chip_txhd,
	vlock_chip_tl1,
	vlock_chip_tm2,
	vlock_chip_sm1,
	vlock_chip_t5,
	vlock_chip_t5d,
};

enum vlock_hw_ver_e {
	/*gxtvbb*/
	vlock_hw_org = 0,
	/*
	 *txl
	 *txlx
	 */
	vlock_hw_ver1,
	/* tl1 later
	 * fix bug:i problem
	 * fix bug:affect ss function
	 * add: phase lock
	 * tm2: have separate pll:tcon pll and hdmitx pll
	 */
	vlock_hw_ver2,
	/* tm2 verion B
	 * fix some bug
	 */
	vlock_hw_tm2verb,
};

struct vecm_match_data_s {
	enum vlk_chiptype vlk_chip;
	u32 vlk_support;
	u32 vlk_new_fsm;
	enum vlock_hw_ver_e vlk_hwver;
	u32 vlk_phlock_en;
	u32 vlk_pll_sel;/*independent panel pll and hdmitx pll*/
};

enum vd_path_e {
	VD1_PATH = 0,
	VD2_PATH = 1,
	VD_PATH_MAX = 2
};

extern signed int vd1_brightness, vd1_contrast;
extern bool gamma_en;
extern unsigned int atv_source_flg;
extern unsigned int sr_demo_flag;
extern unsigned int sr_offset[2];
extern enum hdr_type_e hdr_source_type;
extern unsigned int pd_detect_en;
extern bool wb_en;
extern struct pq_ctrl_s pq_cfg;

extern bool wb_en;
extern struct pq_ctrl_s pq_cfg;
extern struct pq_ctrl_s dv_cfg_bypass;
extern unsigned int lc_offset;
extern int bs_3dlut_en;

#define CSC_FLAG_TOGGLE_FRAME	1
#define CSC_FLAG_CHECK_OUTPUT	2
#define CSC_FLAG_FORCE_SIGNAL	4

extern int amvecm_on_vs(
	struct vframe_s *display_vf,
	struct vframe_s *toggle_vf,
	int flags,
	unsigned int sps_h_en,
	unsigned int sps_v_en,
	unsigned int sps_w_in,
	unsigned int sps_h_in,
	unsigned int cm_in_w,
	unsigned int cm_in_h,
	enum vd_path_e vd_path);
void refresh_on_vs(struct vframe_s *vf, struct vframe_s *rpt_vf);
extern void pc_mode_process(void);
extern void pq_user_latch_process(void);
extern void vlock_process(struct vframe_s *vf,
		struct vpp_frame_par_s *cur_video_sts);
void get_hdr_process_name(int id, char *name, char *output_fmt);
bool is_hdr_tvmode(void);

/* master_display_info for display device */
struct hdr_metadata_info_s {
	u32 primaries[3][2];		/* normalized 50000 in G,B,R order */
	u32 white_point[2];		/* normalized 50000 */
	u32 luminance[2];		/* max/min lumin, normalized 10000 */
};

extern void vpp_vd_adj1_saturation_hue(signed int sat_val,
	signed int hue_val, struct vframe_s *vf);
extern void vpp_vd_adj2_saturation_hue(signed int sat_val,
	signed int hue_val);
int amvecm_set_contrast1(int val);
int amvecm_set_contrast2(int val);
signed int amvecm_get_contrast1(void);
signed int amvecm_get_contrast2(void);
signed int amvecm_get_brightness1(void);
extern unsigned int vecm_latch_flag;
extern void amvecm_sharpness_enable(int sel);
extern int metadata_read_u32(uint32_t *value);
extern int metadata_wait(struct vframe_s *vf);
extern int metadata_sync(uint32_t frame_id, uint64_t pts);
extern void amvecm_wakeup_queue(void);
extern void lc_load_curve(struct ve_lc_curve_parm_s *p);

extern int amvecm_drm_get_gamma_size(u32 index);
extern void amvecm_drm_init(u32 index);
extern int amvecm_drm_gamma_set(u32 index,
			 struct drm_color_lut *lut, int lut_size);
extern int amvecm_drm_gamma_get(u32 index, u16 *red, u16 *green, u16 *blue);
extern int amvecm_drm_gamma_enable(u32 index);
extern int amvecm_drm_gamma_disable(u32 index);
extern int am_meson_ctm_set(u32 index, struct drm_color_ctm *ctm);
extern int am_meson_ctm_disable(void);

extern void enable_osd1_mtx(unsigned int en);
void set_cur_hdr_policy(uint policy);
bool di_api_mov_sel(unsigned int mode,
		    unsigned int *pdate);
enum hdr_type_e get_cur_source_type(enum vd_path_e vd_path);

int amvecm_set_saturation_hue(int mab);
u32 hdr_set(u32 module_sel, u32 hdr_process_select);
int vinfo_lcd_support(void);

/*ai detected scenes*/
enum detect_scene_e {
	BLUE_SCENE = 0,
	GREEN_SCENE,
	SKIN_TONE_SCENE,
	PEAKING_SCENE,
	SATURATION_SCENE,
	DYNAMIC_CONTRAST_SCENE,
	NOISE_SCENE,
	SCENE_MAX
};

/*detected single scene process*/
struct single_scene_s {
	int enable;
	int (*func)(int offset, int enable);
};

extern struct single_scene_s detected_scenes[SCENE_MAX];

int dv_pq_ctl(enum dv_pq_ctl_e ctl);
#endif /* AMVECM_H */
