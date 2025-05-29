/*
 * include/linux/amlogic/media/vout/hdmi_tx/hdmi_tx_ext.h
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

#ifndef __HDMI_TX_EXT_H__
#define __HDMI_TX_EXT_H__

#include "hdmi_common.h"

void direct_hdcptx14_start(void);
void direct_hdcptx14_stop(void);

/*
 * HDMI TX output enable, such as ACRPacket/AudInfo/AudSample
 * enable: 1, normal output;  0: disable output
 */
void hdmitx_ext_set_audio_output(int enable);

/*
 * return Audio output status
 * 1: normal output status;  0: output disabled
 */
int hdmitx_ext_get_audio_status(void);

/*
 * For I2S interface, there are four input ports
 * I2S_3 / I2S_2 / I2S_1 / I2S_0
 * i2s_mask: mask for were the channel are on i2s
 * 2ch via I2S_0         i2s_mask = [0001] 0x1 
 * 4ch via I2S_2 / I2S_1 i2s_mask = [0110] 0x6
 */
void hdmitx_ext_set_i2s_mask(char i2s_mask);

/*
 * get I2S mask
 */
char hdmitx_ext_get_i2s_mask(void);

struct aud_para {
	enum hdmi_audio_type type;
	enum hdmi_audio_fs rate;
	enum hdmi_audio_sampsize size;
	enum hdmi_audio_chnnum chs;
	enum hdmi_speak_location layout;
	bool fifo_rst;
};

#endif
