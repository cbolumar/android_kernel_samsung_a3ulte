/*
 * =================================================================
 *
 *
 *	Description:  samsung display common file
 *
 *	Author: jb09.kim
 *	Company:  Samsung Electronics
 *
 * ================================================================
 */
/*
<one line to give the program's name and a brief idea of what it does.>
Copyright (C) 2012, Samsung Electronics. All rights reserved.

*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
*/
#ifndef _SS_DSI_MDNIE_S6E3HA0_AMS510CW01_H_
#define _SS_DSI_MDNIE_S6E3HA0_AMS510CW01_H_

#include "../ss_dsi_mdnie_lite_common.h"

#define MDNIE_COLOR_BLINDE_CMD_OFFSET 133

#define ADDRESS_SCR_WHITE_RED   0x97
#define ADDRESS_SCR_WHITE_GREEN 0x99
#define ADDRESS_SCR_WHITE_BLUE  0x9B

#define MDNIE_STEP1_INDEX 1
#define MDNIE_STEP2_INDEX 2

static char level_1_key_on[] = {
	0xF0,
	0x5A, 0x5A
};

static char level_1_key_off[] = {
	0xF0,
	0xA5, 0xA5
};

static char DSI0_BYPASS_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x00, //ascr algo lce 10 10 10
};

static char DSI0_BYPASS_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x00, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xd5, //ascr_skin_Rr
	0x2c, //ascr_skin_Rg
	0x2a, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf5, //ascr_skin_Yg
	0x63, //ascr_skin_Yb
	0xfe, //ascr_skin_Mr
	0x4a, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf9, //ascr_skin_Wg
	0xf8, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_NEGATIVE_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x30, //ascr algo lce 10 10 10
};

static char DSI0_NEGATIVE_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x00, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xd5, //ascr_skin_Rr
	0x2c, //ascr_skin_Rg
	0x2a, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf5, //ascr_skin_Yg
	0x63, //ascr_skin_Yb
	0xfe, //ascr_skin_Mr
	0x4a, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf9, //ascr_skin_Wg
	0xf8, //ascr_skin_Wb
	0xff, //ascr_Cr
	0x00, //ascr_Rr
	0x00, //ascr_Cg
	0xff, //ascr_Rg
	0x00, //ascr_Cb
	0xff, //ascr_Rb
	0x00, //ascr_Mr
	0xff, //ascr_Gr
	0xff, //ascr_Mg
	0x00, //ascr_Gg
	0x00, //ascr_Mb
	0xff, //ascr_Gb
	0x00, //ascr_Yr
	0xff, //ascr_Br
	0x00, //ascr_Yg
	0xff, //ascr_Bg
	0xff, //ascr_Yb
	0x00, //ascr_Bb
	0x00, //ascr_Wr
	0xff, //ascr_Kr
	0x00, //ascr_Wg
	0xff, //ascr_Kg
	0x00, //ascr_Wb
	0xff, //ascr_Kb
	/* end */
};

static char DSI0_COLOR_BLIND_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x30, //ascr algo lce 10 10 10
};

static char DSI0_COLOR_BLIND_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x00, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xd5, //ascr_skin_Rr
	0x2c, //ascr_skin_Rg
	0x2a, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf5, //ascr_skin_Yg
	0x63, //ascr_skin_Yb
	0xfe, //ascr_skin_Mr
	0x4a, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf9, //ascr_skin_Wg
	0xf8, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_HBM_CE_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3f, //ascr algo lce 10 10 10
};

static char DSI0_HBM_CE_MDNIE_2[] = {
	0xEC,
	0x86, //lce_gain 00 0000
	0x30, //lce_color_gain 00 0000
	0x00, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0x90, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0xbf,
	0x00, //lce_ref_gain 9
	0xb0,
	0x77, //lce_block_size h v 0000 0000
	0xfa, //lce_bright_th
	0x7f, //lce_bin_size_ratio
	0x00, //lce_dark_th 000
	0x40, //lce_min_ref_offset
	0x07, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x60,
	0x01, //de_maxplus 11
	0x00,
	0x01, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x40,
	0x00, //curve_1_b
	0x7b, //curve_1_a
	0x03, //curve_2_b
	0x48, //curve_2_a
	0x08, //curve_3_b
	0x32, //curve_3_a
	0x08, //curve_4_b
	0x32, //curve_4_a
	0x08, //curve_5_b
	0x32, //curve_5_a
	0x08, //curve_6_b
	0x32, //curve_6_a
	0x08, //curve_7_b
	0x32, //curve_7_a
	0x10, //curve_8_b
	0x28, //curve_8_a
	0x10, //curve_9_b
	0x28, //curve_9_a
	0x10, //curve10_b
	0x28, //curve10_a
	0x10, //curve11_b
	0x28, //curve11_a
	0x10, //curve12_b
	0x28, //curve12_a
	0x19, //curve13_b
	0x22, //curve13_a
	0x70, //curve14_b
	0xf7, //curve14_a
	0x70, //curve15_b
	0xf7, //curve15_a
	0x70, //curve16_b
	0xf7, //curve16_a
	0x70, //curve17_b
	0xf7, //curve17_a
	0x66, //curve18_b
	0x1a, //curve18_a
	0x76, //curve19_b
	0x14, //curve19_a
	0x82, //curve20_b
	0x11, //curve20_a
	0x92, //curve21_b
	0x0e, //curve21_a
	0x98, //curve22_b
	0x0d, //curve22_a
	0x9f, //curve23_b
	0x0c, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x30, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_RGB_SENSOR_MDNIE_1[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x00, //ascr_roi 1 ascr 00 1 0
	0x33, //algo_roi 1 algo lce_roi 1 lce 00 1 0 00 1 0
	0x00, //roi_ctrl 00
	0x00, //roi0_x_start 12
	0x00,
	0x00, //roi0_x_end
	0x00,
	0x00, //roi0_y_start
	0x00,
	0x00, //roi0_y_end
	0x00,
	0x00, //roi1_x_strat
	0x00,
	0x00, //roi1_x_end
	0x00,
	0x00, //roi1_y_start
	0x00,
	0x00, //roi1_y_end
	0x00,
};

static char DSI0_RGB_SENSOR_MDNIE_2[] ={
	0x00,
	0x00, //lce_gain 00 0000
	0x00, //lce_color_gain 00 0000
	0x00, //lce_scene_change_on scene_trans 0 0000
	0x00, //lce_min_diff
	0x00, //lce_illum_gain
	0x00, //lce_ref_offset 9
	0x00,
	0x00, //lce_ref_gain 9
	0x00,
	0x00, //lce_block_size h v 0000 0000
	0x00, //lce_bright_th
	0x00, //lce_bin_size_ratio
	0x00, //lce_dark_th 000
	0x00, //lce_min_ref_offset
	0x00, //nr sharp cs gamma 0000
	0x00, //nr_mask_th
	0x00, //sharpen_weight 10
	0x00,
	0x00, //sharpen_maxplus 11
	0x00,
	0x00, //sharpen_maxminus 11
	0x00,
	0x00, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x00, //curve_1_a
	0x00, //curve_2_b
	0x00, //curve_2_a
	0x00, //curve_3_b
	0x00, //curve_3_a
	0x00, //curve_4_b
	0x00, //curve_4_a
	0x00, //curve_5_b
	0x00, //curve_5_a
	0x00, //curve_6_b
	0x00, //curve_6_a
	0x00, //curve_7_b
	0x00, //curve_7_a
	0x00, //curve_8_b
	0x00, //curve_8_a
	0x00, //curve_9_b
	0x00, //curve_9_a
	0x00, //curve10_b
	0x00, //curve10_a
	0x00, //curve11_b
	0x00, //curve11_a
	0x00, //curve12_b
	0x00, //curve12_a
	0x00, //curve13_b
	0x00, //curve13_a
	0x00, //curve14_b
	0x00, //curve14_a
	0x00, //curve15_b
	0x00, //curve15_a
	0x00, //curve16_b
	0x00, //curve16_a
	0x00, //curve17_b
	0x00, //curve17_a
	0x00, //curve18_b
	0x00, //curve18_a
	0x00, //curve19_b
	0x00, //curve19_a
	0x00, //curve20_b
	0x00, //curve20_a
	0x00, //curve21_b
	0x00, //curve21_a
	0x00, //curve22_b
	0x00, //curve22_a
	0x00, //curve23_b
	0x00, //curve23_a
	0x00, //curve24_b
	0x00, //curve24_a
	0x00, //ascr_skin_on strength 0 00000
	0x00, //ascr_skin_cb
	0x00, //ascr_skin_cr
	0x00, //ascr_dist_up
	0x00, //ascr_dist_down
	0x00, //ascr_dist_right
	0x00, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x00,
	0x00,
	0x00, //ascr_div_down
	0x00,
	0x00,
	0x00, //ascr_div_right
	0x00,
	0x00,
	0x00, //ascr_div_left
	0x00,
	0x00,
	0x00, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0x00, //ascr_skin_Yr
	0x00, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0x00, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0x00, //ascr_skin_Mb
	0x00, //ascr_skin_Wr
	0x00, //ascr_skin_Wg
	0x00, //ascr_skin_Wb
	0x00, //ascr_Cr
	0x00, //ascr_Rr
	0x00, //ascr_Cg
	0x00, //ascr_Rg
	0x00, //ascr_Cb
	0x00, //ascr_Rb
	0x00, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0x00, //ascr_Gg
	0x00, //ascr_Mb
	0x00, //ascr_Gb
	0x00, //ascr_Yr
	0x00, //ascr_Br
	0x00, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0x00, //ascr_Bb
	0x00, //ascr_Wr
	0x00, //ascr_Kr
	0x00, //ascr_Wg
	0x00, //ascr_Kg
	0x00, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char DSI0_UI_DYNAMIC_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_UI_DYNAMIC_MDNIE_2[] ={
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x03, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x20,
	0x00, // curve_1_b
	0x14, // curve_1_a
	0x00, // curve_2_b
	0x14, // curve_2_a
	0x00, // curve_3_b
	0x14, // curve_3_a
	0x00, // curve_4_b
	0x14, // curve_4_a
	0x03, // curve_5_b
	0x9a, // curve_5_a
	0x03, // curve_6_b
	0x9a, // curve_6_a
	0x03, // curve_7_b
	0x9a, // curve_7_a
	0x03, // curve_8_b
	0x9a, // curve_8_a
	0x07, // curve_9_b
	0x9e, // curve_9_a
	0x07, // curve10_b
	0x9e, // curve10_a
	0x07, // curve11_b
	0x9e, // curve11_a
	0x07, // curve12_b
	0x9e, // curve12_a
	0x0a, // curve13_b
	0xa0, // curve13_a
	0x0a, // curve14_b
	0xa0, // curve14_a
	0x0a, // curve15_b
	0xa0, // curve15_a
	0x0a, // curve16_b
	0xa0, // curve16_a
	0x16, // curve17_b
	0xa6, // curve17_a
	0x16, // curve18_b
	0xa6, // curve18_a
	0x16, // curve19_b
	0xa6, // curve19_a
	0x16, // curve20_b
	0xa6, // curve20_a
	0x05, // curve21_b
	0x21, // curve21_a
	0x0b, // curve22_b
	0x20, // curve22_a
	0x87, // curve23_b
	0x0f, // curve23_a
	0x00, // curve24_b
	0xFF, // curve24_a
	0x30, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xff, //ascr_skin_Rr
	0x62, //ascr_skin_Rg
	0x6c, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_UI_STANDARD_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_UI_STANDARD_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x01, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x40, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf5, //ascr_Rr
	0xee, //ascr_Cg
	0x29, //ascr_Rg
	0xe8, //ascr_Cb
	0x2f, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x41, //ascr_Mg
	0xde, //ascr_Gg
	0xe6, //ascr_Mb
	0x00, //ascr_Gb
	0xf2, //ascr_Yr
	0x3d, //ascr_Br
	0xed, //ascr_Yg
	0x1d, //ascr_Bg
	0x46, //ascr_Yb
	0xdf, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xf0, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_UI_NATURAL_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};
static char DSI0_UI_NATURAL_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x01, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x40, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x91, //ascr_Cr
	0xd4, //ascr_Rr
	0xf2, //ascr_Cg
	0x22, //ascr_Rg
	0xe9, //ascr_Cb
	0x28, //ascr_Rb
	0xe2, //ascr_Mr
	0x83, //ascr_Gr
	0x2b, //ascr_Mg
	0xe7, //ascr_Gg
	0xe0, //ascr_Mb
	0x4e, //ascr_Gb
	0xf3, //ascr_Yr
	0x3e, //ascr_Br
	0xed, //ascr_Yg
	0x19, //ascr_Bg
	0x56, //ascr_Yb
	0xda, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xf0, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_UI_MOVIE_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};
static char DSI0_UI_MOVIE_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x03, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x20,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x20, //ascr_skin_on linear_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x7a, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x2b, //ascr_Rg
	0xf1, //ascr_Cb
	0x2d, //ascr_Rb
	0xff, //ascr_Mr
	0x68, //ascr_Gr
	0x15, //ascr_Mg
	0xff, //ascr_Gg
	0xfa, //ascr_Mb
	0x31, //ascr_Gb
	0xf8, //ascr_Yr
	0x34, //ascr_Br
	0xff, //ascr_Yg
	0x20, //ascr_Bg
	0x4b, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xef, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_UI_AUTO_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_UI_AUTO_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x01, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x60,
	0x01, //de_maxplus 11
	0x00,
	0x01, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x01,
	0x00, //fa_step_n 13
	0x01,
	0x00, //fa_max_de_gain 13
	0x60,
	0x3f, //fa_pcl_ppi 14
	0xff,
	0xa9, //fa_skin_cr
	0x67, //fa_skin_cb
	0x27, //fa_dist_left
	0x19, //fa_dist_right
	0x29, //fa_dist_down
	0x17, //fa_dist_up
	0x01, //fa_div_dist_left
	0xa4,
	0x02, //fa_div_dist_right
	0x8f,
	0x01, //fa_div_dist_down
	0x90,
	0x02, //fa_div_dist_up
	0xc8,
	0x20, //fa_px_min_weight
	0x20, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x00, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x5c, //ascr_skin_Rg
	0x68, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf8, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_VIDEO_OUTDOOR_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, /* mdnie_en */
	0x00, /* data_width mask 00 0000 */
	0x00, /* ascr algo lce 10 10 10 */
};
static char DSI0_VIDEO_OUTDOOR_MDNIE_2[] = {
	0xEC,
	0x98, /* lce_on gain 0 00 0000 */
	0x24, /* lce_color_gain 00 0000 */
	0x10, /* lce_scene_change_on scene_trans 0 0000 */
	0x14, /* lce_min_diff */
	0xb3, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x0e,
	0x01, /* lce_ref_gain 9 */
	0x00,
	0x66, /* lce_block_size h v 000 000 */
	0xfa, /* lce_bright_th */
	0x2d, /* lce_bin_size_ratio */
	0x03, /* lce_dark_th 000 */
	0x96, /* lce_min_ref_offset */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 13 */
	0x0a,
	0x00, /* fa_step_n 13 */
	0x32,
	0x01, /* fa_max_de_gain 13 */
	0xf4,
	0x0b, /* fa_pcl_ppi 14 */
	0x8a,
	0x6e, /* fa_skin_cr */
	0x99, /* fa_skin_cb */
	0x1b, /* fa_dist_left */
	0x17, /* fa_dist_right */
	0x14, /* fa_dist_down */
	0x1e, /* fa_dist_up */
	0x02, /* fa_div_dist_left */
	0x5f,
	0x02, /* fa_div_dist_right */
	0xc8,
	0x03, /* fa_div_dist_down */
	0x33,
	0x02, /* fa_div_dist_up */
	0x22,
	0x10, /* fa_px_min_weight */
	0x10, /* fa_fr_min_weight */
	0x07, /* fa_skin_zone_w */
	0x07, /* fa_skin_zone_h */
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* curve_1_b */
	0x20, /* curve_1_a */
	0x00, /* curve_2_b */
	0x20, /* curve_2_a */
	0x00, /* curve_3_b */
	0x20, /* curve_3_a */
	0x00, /* curve_4_b */
	0x20, /* curve_4_a */
	0x02, /* curve_5_b */
	0x1b, /* curve_5_a */
	0x02, /* curve_6_b */
	0x1b, /* curve_6_a */
	0x02, /* curve_7_b */
	0x1b, /* curve_7_a */
	0x02, /* curve_8_b */
	0x1b, /* curve_8_a */
	0x09, /* curve_9_b */
	0xa6, /* curve_9_a */
	0x09, /* curve10_b */
	0xa6, /* curve10_a */
	0x09, /* curve11_b */
	0xa6, /* curve11_a */
	0x09, /* curve12_b */
	0xa6, /* curve12_a */
	0x00, /* curve13_b */
	0x20, /* curve13_a */
	0x00, /* curve14_b */
	0x20, /* curve14_a */
	0x00, /* curve15_b */
	0x20, /* curve15_a */
	0x00, /* curve16_b */
	0x20, /* curve16_a */
	0x00, /* curve17_b */
	0x20, /* curve17_a */
	0x00, /* curve18_b */
	0x20, /* curve18_a */
	0x00, /* curve19_b */
	0x20, /* curve19_a */
	0x00, /* curve20_b */
	0x20, /* curve20_a */
	0x00, /* curve21_b */
	0x20, /* curve21_a */
	0x00, /* curve22_b */
	0x20, /* curve22_a */
	0x00, /* curve23_b */
	0x20, /* curve23_a */
	0x00, /* curve24_b */
	0xFF, /* curve24_a */
	0x70, /* ascr_skin_on linear_on strength 0 0 00000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xd5, /* ascr_skin_Rr */
	0x2c, /* ascr_skin_Rg */
	0x2a, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xf5, /* ascr_skin_Yg */
	0x63, /* ascr_skin_Yb */
	0xfe, /* ascr_skin_Mr */
	0x4a, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf9, /* ascr_skin_Wg */
	0xf8, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
	/* end */
};

static char DSI0_VIDEO_DYNAMIC_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_VIDEO_DYNAMIC_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x0f, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x70,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x01,
	0x00, //fa_step_n 13
	0x01,
	0x00, //fa_max_de_gain 13
	0x70,
	0x05, //fa_pcl_ppi 14
	0x86,
	0xa9, //fa_skin_cr
	0x67, //fa_skin_cb
	0x27, //fa_dist_left
	0x19, //fa_dist_right
	0x29, //fa_dist_down
	0x17, //fa_dist_up
	0x01, //fa_div_dist_left
	0xa4,
	0x02, //fa_div_dist_right
	0x8f,
	0x01, //fa_div_dist_down
	0x90,
	0x02, //fa_div_dist_up
	0xc8,
	0x20, //fa_px_min_weight
	0x20, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x20,
	0x00, //curve_1_b
	0x14, //curve_1_a
	0x00, //curve_2_b
	0x14, //curve_2_a
	0x00, //curve_3_b
	0x14, //curve_3_a
	0x00, //curve_4_b
	0x14, //curve_4_a
	0x03, //curve_5_b
	0x9a, //curve_5_a
	0x03, //curve_6_b
	0x9a, //curve_6_a
	0x03, //curve_7_b
	0x9a, //curve_7_a
	0x03, //curve_8_b
	0x9a, //curve_8_a
	0x07, //curve_9_b
	0x9e, //curve_9_a
	0x07, //curve10_b
	0x9e, //curve10_a
	0x07, //curve11_b
	0x9e, //curve11_a
	0x07, //curve12_b
	0x9e, //curve12_a
	0x0a, //curve13_b
	0xa0, //curve13_a
	0x0a, //curve14_b
	0xa0, //curve14_a
	0x0a, //curve15_b
	0xa0, //curve15_a
	0x0a, //curve16_b
	0xa0, //curve16_a
	0x16, //curve17_b
	0xa6, //curve17_a
	0x16, //curve18_b
	0xa6, //curve18_a
	0x16, //curve19_b
	0xa6, //curve19_a
	0x16, //curve20_b
	0xa6, //curve20_a
	0x05, //curve21_b
	0x21, //curve21_a
	0x0b, //curve22_b
	0x20, //curve22_a
	0x87, //curve23_b
	0x0f, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x30, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xff, //ascr_skin_Rr
	0x62, //ascr_skin_Rg
	0x6c, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_VIDEO_STANDARD_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_VIDEO_STANDARD_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x05, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x40,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x40, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf5, //ascr_Rr
	0xee, //ascr_Cg
	0x29, //ascr_Rg
	0xe8, //ascr_Cb
	0x2f, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x41, //ascr_Mg
	0xde, //ascr_Gg
	0xe6, //ascr_Mb
	0x00, //ascr_Gb
	0xf2, //ascr_Yr
	0x3d, //ascr_Br
	0xed, //ascr_Yg
	0x1d, //ascr_Bg
	0x46, //ascr_Yb
	0xdf, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xf0, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_VIDEO_NATURAL_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};
static char DSI0_VIDEO_NATURAL_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x05, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x40,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x40, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x91, //ascr_Cr
	0xd4, //ascr_Rr
	0xf2, //ascr_Cg
	0x22, //ascr_Rg
	0xe9, //ascr_Cb
	0x28, //ascr_Rb
	0xe2, //ascr_Mr
	0x83, //ascr_Gr
	0x2b, //ascr_Mg
	0xe7, //ascr_Gg
	0xe0, //ascr_Mb
	0x4e, //ascr_Gb
	0xf3, //ascr_Yr
	0x3e, //ascr_Br
	0xed, //ascr_Yg
	0x19, //ascr_Bg
	0x56, //ascr_Yb
	0xda, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xf0, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_VIDEO_MOVIE_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};
static char DSI0_VIDEO_MOVIE_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x07, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x40,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x20,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x20, //ascr_skin_on linear_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x7a, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x2b, //ascr_Rg
	0xf1, //ascr_Cb
	0x2d, //ascr_Rb
	0xff, //ascr_Mr
	0x68, //ascr_Gr
	0x15, //ascr_Mg
	0xff, //ascr_Gg
	0xfa, //ascr_Mb
	0x31, //ascr_Gb
	0xf8, //ascr_Yr
	0x34, //ascr_Br
	0xff, //ascr_Yg
	0x20, //ascr_Bg
	0x4b, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xef, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_VIDEO_AUTO_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_VIDEO_AUTO_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x0f, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x70,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x01,
	0x00, //fa_step_n 13
	0x01,
	0x00, //fa_max_de_gain 13
	0x70,
	0x05, //fa_pcl_ppi 14
	0x86,
	0xa9, //fa_skin_cr
	0x67, //fa_skin_cb
	0x27, //fa_dist_left
	0x19, //fa_dist_right
	0x29, //fa_dist_down
	0x17, //fa_dist_up
	0x01, //fa_div_dist_left
	0xa4,
	0x02, //fa_div_dist_right
	0x8f,
	0x01, //fa_div_dist_down
	0x90,
	0x02, //fa_div_dist_up
	0xc8,
	0x20, //fa_px_min_weight
	0x20, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x20,
	0x00, //curve_1_b
	0x14, //curve_1_a
	0x00, //curve_2_b
	0x14, //curve_2_a
	0x00, //curve_3_b
	0x14, //curve_3_a
	0x00, //curve_4_b
	0x14, //curve_4_a
	0x03, //curve_5_b
	0x9a, //curve_5_a
	0x03, //curve_6_b
	0x9a, //curve_6_a
	0x03, //curve_7_b
	0x9a, //curve_7_a
	0x03, //curve_8_b
	0x9a, //curve_8_a
	0x07, //curve_9_b
	0x9e, //curve_9_a
	0x07, //curve10_b
	0x9e, //curve10_a
	0x07, //curve11_b
	0x9e, //curve11_a
	0x07, //curve12_b
	0x9e, //curve12_a
	0x0a, //curve13_b
	0xa0, //curve13_a
	0x0a, //curve14_b
	0xa0, //curve14_a
	0x0a, //curve15_b
	0xa0, //curve15_a
	0x0a, //curve16_b
	0xa0, //curve16_a
	0x16, //curve17_b
	0xa6, //curve17_a
	0x16, //curve18_b
	0xa6, //curve18_a
	0x16, //curve19_b
	0xa6, //curve19_a
	0x16, //curve20_b
	0xa6, //curve20_a
	0x05, //curve21_b
	0x21, //curve21_a
	0x0b, //curve22_b
	0x20, //curve22_a
	0x87, //curve23_b
	0x0f, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x30, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xff, //ascr_skin_Rr
	0x62, //ascr_skin_Rg
	0x6c, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_VIDEO_WARM_OUTDOOR_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, /* mdnie_en */
	0x00, /* data_width mask 00 0000 */
	0x00, /* ascr algo lce 10 10 10 */
};
static char DSI0_VIDEO_WARM_OUTDOOR_MDNIE_2[] = {
	0xEC,
	0x98, /* lce_on gain 0 00 0000 */
	0x24, /* lce_color_gain 00 0000 */
	0x10, /* lce_scene_change_on scene_trans 0 0000 */
	0x14, /* lce_min_diff */
	0xb3, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x0e,
	0x01, /* lce_ref_gain 9 */
	0x00,
	0x66, /* lce_block_size h v 000 000 */
	0xfa, /* lce_bright_th */
	0x2d, /* lce_bin_size_ratio */
	0x03, /* lce_dark_th 000 */
	0x96, /* lce_min_ref_offset */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 13 */
	0x0a,
	0x00, /* fa_step_n 13 */
	0x32,
	0x01, /* fa_max_de_gain 13 */
	0xf4,
	0x0b, /* fa_pcl_ppi 14 */
	0x8a,
	0x6e, /* fa_skin_cr */
	0x99, /* fa_skin_cb */
	0x1b, /* fa_dist_left */
	0x17, /* fa_dist_right */
	0x14, /* fa_dist_down */
	0x1e, /* fa_dist_up */
	0x02, /* fa_div_dist_left */
	0x5f,
	0x02, /* fa_div_dist_right */
	0xc8,
	0x03, /* fa_div_dist_down */
	0x33,
	0x02, /* fa_div_dist_up */
	0x22,
	0x10, /* fa_px_min_weight */
	0x10, /* fa_fr_min_weight */
	0x07, /* fa_skin_zone_w */
	0x07, /* fa_skin_zone_h */
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* curve_1_b */
	0x20, /* curve_1_a */
	0x00, /* curve_2_b */
	0x20, /* curve_2_a */
	0x00, /* curve_3_b */
	0x20, /* curve_3_a */
	0x00, /* curve_4_b */
	0x20, /* curve_4_a */
	0x02, /* curve_5_b */
	0x1b, /* curve_5_a */
	0x02, /* curve_6_b */
	0x1b, /* curve_6_a */
	0x02, /* curve_7_b */
	0x1b, /* curve_7_a */
	0x02, /* curve_8_b */
	0x1b, /* curve_8_a */
	0x09, /* curve_9_b */
	0xa6, /* curve_9_a */
	0x09, /* curve10_b */
	0xa6, /* curve10_a */
	0x09, /* curve11_b */
	0xa6, /* curve11_a */
	0x09, /* curve12_b */
	0xa6, /* curve12_a */
	0x00, /* curve13_b */
	0x20, /* curve13_a */
	0x00, /* curve14_b */
	0x20, /* curve14_a */
	0x00, /* curve15_b */
	0x20, /* curve15_a */
	0x00, /* curve16_b */
	0x20, /* curve16_a */
	0x00, /* curve17_b */
	0x20, /* curve17_a */
	0x00, /* curve18_b */
	0x20, /* curve18_a */
	0x00, /* curve19_b */
	0x20, /* curve19_a */
	0x00, /* curve20_b */
	0x20, /* curve20_a */
	0x00, /* curve21_b */
	0x20, /* curve21_a */
	0x00, /* curve22_b */
	0x20, /* curve22_a */
	0x00, /* curve23_b */
	0x20, /* curve23_a */
	0x00, /* curve24_b */
	0xFF, /* curve24_a */
	0x70, /* ascr_skin_on linear_on strength 0 0 00000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xd5, /* ascr_skin_Rr */
	0x2c, /* ascr_skin_Rg */
	0x2a, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xf5, /* ascr_skin_Yg */
	0x63, /* ascr_skin_Yb */
	0xfe, /* ascr_skin_Mr */
	0x4a, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf9, /* ascr_skin_Wg */
	0xf8, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
	/* end */
};

static char DSI0_VIDEO_WARM_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, /* mdnie_en */
	0x00, /* data_width mask 00 0000 */
	0x00, /* ascr algo lce 10 10 10 */
};
static char DSI0_VIDEO_WARM_MDNIE_2[] = {
	0xEC,
	0x98, /* lce_on gain 0 00 0000 */
	0x24, /* lce_color_gain 00 0000 */
	0x10, /* lce_scene_change_on scene_trans 0 0000 */
	0x14, /* lce_min_diff */
	0xb3, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x0e,
	0x01, /* lce_ref_gain 9 */
	0x00,
	0x66, /* lce_block_size h v 000 000 */
	0xfa, /* lce_bright_th */
	0x2d, /* lce_bin_size_ratio */
	0x03, /* lce_dark_th 000 */
	0x96, /* lce_min_ref_offset */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 13 */
	0x0a,
	0x00, /* fa_step_n 13 */
	0x32,
	0x01, /* fa_max_de_gain 13 */
	0xf4,
	0x0b, /* fa_pcl_ppi 14 */
	0x8a,
	0x6e, /* fa_skin_cr */
	0x99, /* fa_skin_cb */
	0x1b, /* fa_dist_left */
	0x17, /* fa_dist_right */
	0x14, /* fa_dist_down */
	0x1e, /* fa_dist_up */
	0x02, /* fa_div_dist_left */
	0x5f,
	0x02, /* fa_div_dist_right */
	0xc8,
	0x03, /* fa_div_dist_down */
	0x33,
	0x02, /* fa_div_dist_up */
	0x22,
	0x10, /* fa_px_min_weight */
	0x10, /* fa_fr_min_weight */
	0x07, /* fa_skin_zone_w */
	0x07, /* fa_skin_zone_h */
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* curve_1_b */
	0x20, /* curve_1_a */
	0x00, /* curve_2_b */
	0x20, /* curve_2_a */
	0x00, /* curve_3_b */
	0x20, /* curve_3_a */
	0x00, /* curve_4_b */
	0x20, /* curve_4_a */
	0x02, /* curve_5_b */
	0x1b, /* curve_5_a */
	0x02, /* curve_6_b */
	0x1b, /* curve_6_a */
	0x02, /* curve_7_b */
	0x1b, /* curve_7_a */
	0x02, /* curve_8_b */
	0x1b, /* curve_8_a */
	0x09, /* curve_9_b */
	0xa6, /* curve_9_a */
	0x09, /* curve10_b */
	0xa6, /* curve10_a */
	0x09, /* curve11_b */
	0xa6, /* curve11_a */
	0x09, /* curve12_b */
	0xa6, /* curve12_a */
	0x00, /* curve13_b */
	0x20, /* curve13_a */
	0x00, /* curve14_b */
	0x20, /* curve14_a */
	0x00, /* curve15_b */
	0x20, /* curve15_a */
	0x00, /* curve16_b */
	0x20, /* curve16_a */
	0x00, /* curve17_b */
	0x20, /* curve17_a */
	0x00, /* curve18_b */
	0x20, /* curve18_a */
	0x00, /* curve19_b */
	0x20, /* curve19_a */
	0x00, /* curve20_b */
	0x20, /* curve20_a */
	0x00, /* curve21_b */
	0x20, /* curve21_a */
	0x00, /* curve22_b */
	0x20, /* curve22_a */
	0x00, /* curve23_b */
	0x20, /* curve23_a */
	0x00, /* curve24_b */
	0xFF, /* curve24_a */
	0x70, /* ascr_skin_on linear_on strength 0 0 00000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xd5, /* ascr_skin_Rr */
	0x2c, /* ascr_skin_Rg */
	0x2a, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xf5, /* ascr_skin_Yg */
	0x63, /* ascr_skin_Yb */
	0xfe, /* ascr_skin_Mr */
	0x4a, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf9, /* ascr_skin_Wg */
	0xf8, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
	/* end */
};

static char DSI0_VIDEO_COLD_OUTDOOR_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, /* mdnie_en */
	0x00, /* data_width mask 00 0000 */
	0x00, /* ascr algo lce 10 10 10 */
};
static char DSI0_VIDEO_COLD_OUTDOOR_MDNIE_2[] = {
	0xEC,
	0x98, /* lce_on gain 0 00 0000 */
	0x24, /* lce_color_gain 00 0000 */
	0x10, /* lce_scene_change_on scene_trans 0 0000 */
	0x14, /* lce_min_diff */
	0xb3, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x0e,
	0x01, /* lce_ref_gain 9 */
	0x00,
	0x66, /* lce_block_size h v 000 000 */
	0xfa, /* lce_bright_th */
	0x2d, /* lce_bin_size_ratio */
	0x03, /* lce_dark_th 000 */
	0x96, /* lce_min_ref_offset */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 13 */
	0x0a,
	0x00, /* fa_step_n 13 */
	0x32,
	0x01, /* fa_max_de_gain 13 */
	0xf4,
	0x0b, /* fa_pcl_ppi 14 */
	0x8a,
	0x6e, /* fa_skin_cr */
	0x99, /* fa_skin_cb */
	0x1b, /* fa_dist_left */
	0x17, /* fa_dist_right */
	0x14, /* fa_dist_down */
	0x1e, /* fa_dist_up */
	0x02, /* fa_div_dist_left */
	0x5f,
	0x02, /* fa_div_dist_right */
	0xc8,
	0x03, /* fa_div_dist_down */
	0x33,
	0x02, /* fa_div_dist_up */
	0x22,
	0x10, /* fa_px_min_weight */
	0x10, /* fa_fr_min_weight */
	0x07, /* fa_skin_zone_w */
	0x07, /* fa_skin_zone_h */
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* curve_1_b */
	0x20, /* curve_1_a */
	0x00, /* curve_2_b */
	0x20, /* curve_2_a */
	0x00, /* curve_3_b */
	0x20, /* curve_3_a */
	0x00, /* curve_4_b */
	0x20, /* curve_4_a */
	0x02, /* curve_5_b */
	0x1b, /* curve_5_a */
	0x02, /* curve_6_b */
	0x1b, /* curve_6_a */
	0x02, /* curve_7_b */
	0x1b, /* curve_7_a */
	0x02, /* curve_8_b */
	0x1b, /* curve_8_a */
	0x09, /* curve_9_b */
	0xa6, /* curve_9_a */
	0x09, /* curve10_b */
	0xa6, /* curve10_a */
	0x09, /* curve11_b */
	0xa6, /* curve11_a */
	0x09, /* curve12_b */
	0xa6, /* curve12_a */
	0x00, /* curve13_b */
	0x20, /* curve13_a */
	0x00, /* curve14_b */
	0x20, /* curve14_a */
	0x00, /* curve15_b */
	0x20, /* curve15_a */
	0x00, /* curve16_b */
	0x20, /* curve16_a */
	0x00, /* curve17_b */
	0x20, /* curve17_a */
	0x00, /* curve18_b */
	0x20, /* curve18_a */
	0x00, /* curve19_b */
	0x20, /* curve19_a */
	0x00, /* curve20_b */
	0x20, /* curve20_a */
	0x00, /* curve21_b */
	0x20, /* curve21_a */
	0x00, /* curve22_b */
	0x20, /* curve22_a */
	0x00, /* curve23_b */
	0x20, /* curve23_a */
	0x00, /* curve24_b */
	0xFF, /* curve24_a */
	0x70, /* ascr_skin_on linear_on strength 0 0 00000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xd5, /* ascr_skin_Rr */
	0x2c, /* ascr_skin_Rg */
	0x2a, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xf5, /* ascr_skin_Yg */
	0x63, /* ascr_skin_Yb */
	0xfe, /* ascr_skin_Mr */
	0x4a, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf9, /* ascr_skin_Wg */
	0xf8, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
	/* end */
};

static char DSI0_VIDEO_COLD_MDNIE_1[] ={
	/* start */
	0xEB,
	0x01, /* mdnie_en */
	0x00, /* data_width mask 00 0000 */
	0x00, /* ascr algo lce 10 10 10 */
};
static char DSI0_VIDEO_COLD_MDNIE_2[] ={
	0xEC,
	0x98, /* lce_on gain 0 00 0000 */
	0x24, /* lce_color_gain 00 0000 */
	0x10, /* lce_scene_change_on scene_trans 0 0000 */
	0x14, /* lce_min_diff */
	0xb3, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x0e,
	0x01, /* lce_ref_gain 9 */
	0x00,
	0x66, /* lce_block_size h v 000 000 */
	0xfa, /* lce_bright_th */
	0x2d, /* lce_bin_size_ratio */
	0x03, /* lce_dark_th 000 */
	0x96, /* lce_min_ref_offset */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 13 */
	0x0a,
	0x00, /* fa_step_n 13 */
	0x32,
	0x01, /* fa_max_de_gain 13 */
	0xf4,
	0x0b, /* fa_pcl_ppi 14 */
	0x8a,
	0x6e, /* fa_skin_cr */
	0x99, /* fa_skin_cb */
	0x1b, /* fa_dist_left */
	0x17, /* fa_dist_right */
	0x14, /* fa_dist_down */
	0x1e, /* fa_dist_up */
	0x02, /* fa_div_dist_left */
	0x5f,
	0x02, /* fa_div_dist_right */
	0xc8,
	0x03, /* fa_div_dist_down */
	0x33,
	0x02, /* fa_div_dist_up */
	0x22,
	0x10, /* fa_px_min_weight */
	0x10, /* fa_fr_min_weight */
	0x07, /* fa_skin_zone_w */
	0x07, /* fa_skin_zone_h */
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* curve_1_b */
	0x20, /* curve_1_a */
	0x00, /* curve_2_b */
	0x20, /* curve_2_a */
	0x00, /* curve_3_b */
	0x20, /* curve_3_a */
	0x00, /* curve_4_b */
	0x20, /* curve_4_a */
	0x02, /* curve_5_b */
	0x1b, /* curve_5_a */
	0x02, /* curve_6_b */
	0x1b, /* curve_6_a */
	0x02, /* curve_7_b */
	0x1b, /* curve_7_a */
	0x02, /* curve_8_b */
	0x1b, /* curve_8_a */
	0x09, /* curve_9_b */
	0xa6, /* curve_9_a */
	0x09, /* curve10_b */
	0xa6, /* curve10_a */
	0x09, /* curve11_b */
	0xa6, /* curve11_a */
	0x09, /* curve12_b */
	0xa6, /* curve12_a */
	0x00, /* curve13_b */
	0x20, /* curve13_a */
	0x00, /* curve14_b */
	0x20, /* curve14_a */
	0x00, /* curve15_b */
	0x20, /* curve15_a */
	0x00, /* curve16_b */
	0x20, /* curve16_a */
	0x00, /* curve17_b */
	0x20, /* curve17_a */
	0x00, /* curve18_b */
	0x20, /* curve18_a */
	0x00, /* curve19_b */
	0x20, /* curve19_a */
	0x00, /* curve20_b */
	0x20, /* curve20_a */
	0x00, /* curve21_b */
	0x20, /* curve21_a */
	0x00, /* curve22_b */
	0x20, /* curve22_a */
	0x00, /* curve23_b */
	0x20, /* curve23_a */
	0x00, /* curve24_b */
	0xFF, /* curve24_a */
	0x70, /* ascr_skin_on linear_on strength 0 0 00000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xd5, /* ascr_skin_Rr */
	0x2c, /* ascr_skin_Rg */
	0x2a, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xf5, /* ascr_skin_Yg */
	0x63, /* ascr_skin_Yb */
	0xfe, /* ascr_skin_Mr */
	0x4a, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf9, /* ascr_skin_Wg */
	0xf8, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
	/* end */
};

static char DSI0_CAMERA_OUTDOOR_MDNIE_1[] ={
	/* start */
	0xEB,
	0x01, /* mdnie_en */
	0x00, /* data_width mask 00 0000 */
	0x00, /* ascr algo lce 10 10 10 */
};
static char DSI0_CAMERA_OUTDOOR_MDNIE_2[] ={
	0xEC,
	0x98, /* lce_on gain 0 00 0000 */
	0x24, /* lce_color_gain 00 0000 */
	0x10, /* lce_scene_change_on scene_trans 0 0000 */
	0x14, /* lce_min_diff */
	0xb3, /* lce_illum_gain */
	0x01, /* lce_ref_offset 9 */
	0x0e,
	0x01, /* lce_ref_gain 9 */
	0x00,
	0x66, /* lce_block_size h v 000 000 */
	0xfa, /* lce_bright_th */
	0x2d, /* lce_bin_size_ratio */
	0x03, /* lce_dark_th 000 */
	0x96, /* lce_min_ref_offset */
	0x00, /* nr fa de cs gamma 0 0000 */
	0xff, /* nr_mask_th */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x14, /* fa_edge_th */
	0x00, /* fa_step_p 13 */
	0x0a,
	0x00, /* fa_step_n 13 */
	0x32,
	0x01, /* fa_max_de_gain 13 */
	0xf4,
	0x0b, /* fa_pcl_ppi 14 */
	0x8a,
	0x6e, /* fa_skin_cr */
	0x99, /* fa_skin_cb */
	0x1b, /* fa_dist_left */
	0x17, /* fa_dist_right */
	0x14, /* fa_dist_down */
	0x1e, /* fa_dist_up */
	0x02, /* fa_div_dist_left */
	0x5f,
	0x02, /* fa_div_dist_right */
	0xc8,
	0x03, /* fa_div_dist_down */
	0x33,
	0x02, /* fa_div_dist_up */
	0x22,
	0x10, /* fa_px_min_weight */
	0x10, /* fa_fr_min_weight */
	0x07, /* fa_skin_zone_w */
	0x07, /* fa_skin_zone_h */
	0x20, /* fa_os_cnt_10_co */
	0x2d, /* fa_os_cnt_20_co */
	0x01, /* cs_gain 10 */
	0x00,
	0x00, /* curve_1_b */
	0x20, /* curve_1_a */
	0x00, /* curve_2_b */
	0x20, /* curve_2_a */
	0x00, /* curve_3_b */
	0x20, /* curve_3_a */
	0x00, /* curve_4_b */
	0x20, /* curve_4_a */
	0x02, /* curve_5_b */
	0x1b, /* curve_5_a */
	0x02, /* curve_6_b */
	0x1b, /* curve_6_a */
	0x02, /* curve_7_b */
	0x1b, /* curve_7_a */
	0x02, /* curve_8_b */
	0x1b, /* curve_8_a */
	0x09, /* curve_9_b */
	0xa6, /* curve_9_a */
	0x09, /* curve10_b */
	0xa6, /* curve10_a */
	0x09, /* curve11_b */
	0xa6, /* curve11_a */
	0x09, /* curve12_b */
	0xa6, /* curve12_a */
	0x00, /* curve13_b */
	0x20, /* curve13_a */
	0x00, /* curve14_b */
	0x20, /* curve14_a */
	0x00, /* curve15_b */
	0x20, /* curve15_a */
	0x00, /* curve16_b */
	0x20, /* curve16_a */
	0x00, /* curve17_b */
	0x20, /* curve17_a */
	0x00, /* curve18_b */
	0x20, /* curve18_a */
	0x00, /* curve19_b */
	0x20, /* curve19_a */
	0x00, /* curve20_b */
	0x20, /* curve20_a */
	0x00, /* curve21_b */
	0x20, /* curve21_a */
	0x00, /* curve22_b */
	0x20, /* curve22_a */
	0x00, /* curve23_b */
	0x20, /* curve23_a */
	0x00, /* curve24_b */
	0xFF, /* curve24_a */
	0x70, /* ascr_skin_on linear_on strength 0 0 00000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up 20 */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xd5, /* ascr_skin_Rr */
	0x2c, /* ascr_skin_Rg */
	0x2a, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xf5, /* ascr_skin_Yg */
	0x63, /* ascr_skin_Yb */
	0xfe, /* ascr_skin_Mr */
	0x4a, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf9, /* ascr_skin_Wg */
	0xf8, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
	/* end */
};

static char DSI0_CAMERA_MDNIE_1[] ={
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_CAMERA_MDNIE_2[] ={
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x01, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x00, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_CAMERA_AUTO_MDNIE_1[] ={
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_CAMERA_AUTO_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x01, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0xb0,
	0x01, //de_maxplus 11
	0x00,
	0x01, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x01,
	0x00, //fa_step_n 13
	0x01,
	0x00, //fa_max_de_gain 13
	0xb0,
	0x3f, //fa_pcl_ppi 14
	0xff,
	0xa9, //fa_skin_cr
	0x67, //fa_skin_cb
	0x27, //fa_dist_left
	0x19, //fa_dist_right
	0x29, //fa_dist_down
	0x17, //fa_dist_up
	0x01, //fa_div_dist_left
	0xa4,
	0x02, //fa_div_dist_right
	0x8f,
	0x01, //fa_div_dist_down
	0x90,
	0x02, //fa_div_dist_up
	0xc8,
	0x20, //fa_px_min_weight
	0x20, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x30, //linear_on ascr_skin_on strength 0 0 00000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x48, //ascr_skin_Rg
	0x40, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf0, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xd8, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xd9, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xe0, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xf6, //ascr_Cb
	0x00, //ascr_Rb
	0xd8, //ascr_Mr
	0x3b, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xd9, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x14, //ascr_Br
	0xf9, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_GALLERY_DYNAMIC_MDNIE_1[] ={
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_GALLERY_DYNAMIC_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x07, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0xc0,
	0x01, //de_maxplus 11
	0x00,
	0x01, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x20,
	0x00, // curve_1_b
	0x14, // curve_1_a
	0x00, // curve_2_b
	0x14, // curve_2_a
	0x00, // curve_3_b
	0x14, // curve_3_a
	0x00, // curve_4_b
	0x14, // curve_4_a
	0x03, // curve_5_b
	0x9a, // curve_5_a
	0x03, // curve_6_b
	0x9a, // curve_6_a
	0x03, // curve_7_b
	0x9a, // curve_7_a
	0x03, // curve_8_b
	0x9a, // curve_8_a
	0x07, // curve_9_b
	0x9e, // curve_9_a
	0x07, // curve10_b
	0x9e, // curve10_a
	0x07, // curve11_b
	0x9e, // curve11_a
	0x07, // curve12_b
	0x9e, // curve12_a
	0x0a, // curve13_b
	0xa0, // curve13_a
	0x0a, // curve14_b
	0xa0, // curve14_a
	0x0a, // curve15_b
	0xa0, // curve15_a
	0x0a, // curve16_b
	0xa0, // curve16_a
	0x16, // curve17_b
	0xa6, // curve17_a
	0x16, // curve18_b
	0xa6, // curve18_a
	0x16, // curve19_b
	0xa6, // curve19_a
	0x16, // curve20_b
	0xa6, // curve20_a
	0x05, // curve21_b
	0x21, // curve21_a
	0x0b, // curve22_b
	0x20, // curve22_a
	0x87, // curve23_b
	0x0f, // curve23_a
	0x00, // curve24_b
	0xFF, // curve24_a
	0x30, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xff, //ascr_skin_Rr
	0x62, //ascr_skin_Rg
	0x6c, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_GALLERY_STANDARD_MDNIE_1[] ={
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_GALLERY_STANDARD_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x05, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x40,
	0x01, //de_maxplus 11
	0x00,
	0x01, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x40, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf5, //ascr_Rr
	0xee, //ascr_Cg
	0x29, //ascr_Rg
	0xe8, //ascr_Cb
	0x2f, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x41, //ascr_Mg
	0xde, //ascr_Gg
	0xe6, //ascr_Mb
	0x00, //ascr_Gb
	0xf2, //ascr_Yr
	0x3d, //ascr_Br
	0xed, //ascr_Yg
	0x1d, //ascr_Bg
	0x46, //ascr_Yb
	0xdf, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xf0, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_GALLERY_NATURAL_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};
static char DSI0_GALLERY_NATURAL_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x05, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x40,
	0x01, //de_maxplus 11
	0x00,
	0x01, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x40, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x91, //ascr_Cr
	0xd4, //ascr_Rr
	0xf2, //ascr_Cg
	0x22, //ascr_Rg
	0xe9, //ascr_Cb
	0x28, //ascr_Rb
	0xe2, //ascr_Mr
	0x83, //ascr_Gr
	0x2b, //ascr_Mg
	0xe7, //ascr_Gg
	0xe0, //ascr_Mb
	0x4e, //ascr_Gb
	0xf3, //ascr_Yr
	0x3e, //ascr_Br
	0xed, //ascr_Yg
	0x19, //ascr_Bg
	0x56, //ascr_Yb
	0xda, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xf0, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_GALLERY_MOVIE_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};
static char DSI0_GALLERY_MOVIE_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x07, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x40,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x20,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x20, //ascr_skin_on linear_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x7a, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x2b, //ascr_Rg
	0xf1, //ascr_Cb
	0x2d, //ascr_Rb
	0xff, //ascr_Mr
	0x68, //ascr_Gr
	0x15, //ascr_Mg
	0xff, //ascr_Gg
	0xfa, //ascr_Mb
	0x31, //ascr_Gb
	0xf8, //ascr_Yr
	0x34, //ascr_Br
	0xff, //ascr_Yg
	0x20, //ascr_Bg
	0x4b, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xef, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_GALLERY_AUTO_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_GALLERY_AUTO_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x0d, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x70,
	0x02, //de_maxplus 11
	0x00,
	0x02, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x01,
	0x00, //fa_step_n 13
	0x01,
	0x00, //fa_max_de_gain 13
	0x70,
	0x05, //fa_pcl_ppi 14
	0x86,
	0xa9, //fa_skin_cr
	0x67, //fa_skin_cb
	0x27, //fa_dist_left
	0x19, //fa_dist_right
	0x29, //fa_dist_down
	0x17, //fa_dist_up
	0x01, //fa_div_dist_left
	0xa4,
	0x02, //fa_div_dist_right
	0x8f,
	0x01, //fa_div_dist_down
	0x90,
	0x02, //fa_div_dist_up
	0xc8,
	0x20, //fa_px_min_weight
	0x20, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x30, //linear_on ascr_skin_on strength 0 0 00000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x48, //ascr_skin_Rg
	0x40, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf0, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xd8, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xd9, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xe0, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xf6, //ascr_Cb
	0x00, //ascr_Rb
	0xd8, //ascr_Mr
	0x3b, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xd9, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x14, //ascr_Br
	0xf9, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_VT_DYNAMIC_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_VT_DYNAMIC_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x07, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0xc0,
	0x01, //de_maxplus 11
	0x00,
	0x01, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x20,
	0x00, // curve_1_b
	0x14, // curve_1_a
	0x00, // curve_2_b
	0x14, // curve_2_a
	0x00, // curve_3_b
	0x14, // curve_3_a
	0x00, // curve_4_b
	0x14, // curve_4_a
	0x03, // curve_5_b
	0x9a, // curve_5_a
	0x03, // curve_6_b
	0x9a, // curve_6_a
	0x03, // curve_7_b
	0x9a, // curve_7_a
	0x03, // curve_8_b
	0x9a, // curve_8_a
	0x07, // curve_9_b
	0x9e, // curve_9_a
	0x07, // curve10_b
	0x9e, // curve10_a
	0x07, // curve11_b
	0x9e, // curve11_a
	0x07, // curve12_b
	0x9e, // curve12_a
	0x0a, // curve13_b
	0xa0, // curve13_a
	0x0a, // curve14_b
	0xa0, // curve14_a
	0x0a, // curve15_b
	0xa0, // curve15_a
	0x0a, // curve16_b
	0xa0, // curve16_a
	0x16, // curve17_b
	0xa6, // curve17_a
	0x16, // curve18_b
	0xa6, // curve18_a
	0x16, // curve19_b
	0xa6, // curve19_a
	0x16, // curve20_b
	0xa6, // curve20_a
	0x05, // curve21_b
	0x21, // curve21_a
	0x0b, // curve22_b
	0x20, // curve22_a
	0x87, // curve23_b
	0x0f, // curve23_a
	0x00, // curve24_b
	0xFF, // curve24_a
	0x30, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xff, //ascr_skin_Rr
	0x62, //ascr_skin_Rg
	0x6c, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_VT_STANDARD_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_VT_STANDARD_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x05, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x40,
	0x01, //de_maxplus 11
	0x00,
	0x01, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x40, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf5, //ascr_Rr
	0xee, //ascr_Cg
	0x29, //ascr_Rg
	0xe8, //ascr_Cb
	0x2f, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x41, //ascr_Mg
	0xde, //ascr_Gg
	0xe6, //ascr_Mb
	0x00, //ascr_Gb
	0xf2, //ascr_Yr
	0x3d, //ascr_Br
	0xed, //ascr_Yg
	0x1d, //ascr_Bg
	0x46, //ascr_Yb
	0xdf, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xf0, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_VT_NATURAL_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};
static char DSI0_VT_NATURAL_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x05, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x40,
	0x01, //de_maxplus 11
	0x00,
	0x01, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x40, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x91, //ascr_Cr
	0xd4, //ascr_Rr
	0xf2, //ascr_Cg
	0x22, //ascr_Rg
	0xe9, //ascr_Cb
	0x28, //ascr_Rb
	0xe2, //ascr_Mr
	0x83, //ascr_Gr
	0x2b, //ascr_Mg
	0xe7, //ascr_Gg
	0xe0, //ascr_Mb
	0x4e, //ascr_Gb
	0xf3, //ascr_Yr
	0x3e, //ascr_Br
	0xed, //ascr_Yg
	0x19, //ascr_Bg
	0x56, //ascr_Yb
	0xda, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xf0, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_VT_MOVIE_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};
static char DSI0_VT_MOVIE_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x07, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x40,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x20,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x20, //ascr_skin_on linear_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x7a, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x2b, //ascr_Rg
	0xf1, //ascr_Cb
	0x2d, //ascr_Rb
	0xff, //ascr_Mr
	0x68, //ascr_Gr
	0x15, //ascr_Mg
	0xff, //ascr_Gg
	0xfa, //ascr_Mb
	0x31, //ascr_Gb
	0xf8, //ascr_Yr
	0x34, //ascr_Br
	0xff, //ascr_Yg
	0x20, //ascr_Bg
	0x4b, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xef, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_VT_AUTO_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_VT_AUTO_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x0d, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x60,
	0x01, //de_maxplus 11
	0x00,
	0x01, //de_maxminus 11
	0x00,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x01,
	0x00, //fa_step_n 13
	0x01,
	0x00, //fa_max_de_gain 13
	0x60,
	0x3f, //fa_pcl_ppi 14
	0xff,
	0xa9, //fa_skin_cr
	0x67, //fa_skin_cb
	0x27, //fa_dist_left
	0x19, //fa_dist_right
	0x29, //fa_dist_down
	0x17, //fa_dist_up
	0x01, //fa_div_dist_left
	0xa4,
	0x02, //fa_div_dist_right
	0x8f,
	0x01, //fa_div_dist_down
	0x90,
	0x02, //fa_div_dist_up
	0xc8,
	0x20, //fa_px_min_weight
	0x20, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x28, //fa_os_cnt_10_co
	0x3c, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x00, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_BROWSER_DYNAMIC_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};
static char DSI0_BROWSER_DYNAMIC_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x03, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x20,
	0x00, // curve_1_b
	0x14, // curve_1_a
	0x00, // curve_2_b
	0x14, // curve_2_a
	0x00, // curve_3_b
	0x14, // curve_3_a
	0x00, // curve_4_b
	0x14, // curve_4_a
	0x03, // curve_5_b
	0x9a, // curve_5_a
	0x03, // curve_6_b
	0x9a, // curve_6_a
	0x03, // curve_7_b
	0x9a, // curve_7_a
	0x03, // curve_8_b
	0x9a, // curve_8_a
	0x07, // curve_9_b
	0x9e, // curve_9_a
	0x07, // curve10_b
	0x9e, // curve10_a
	0x07, // curve11_b
	0x9e, // curve11_a
	0x07, // curve12_b
	0x9e, // curve12_a
	0x0a, // curve13_b
	0xa0, // curve13_a
	0x0a, // curve14_b
	0xa0, // curve14_a
	0x0a, // curve15_b
	0xa0, // curve15_a
	0x0a, // curve16_b
	0xa0, // curve16_a
	0x16, // curve17_b
	0xa6, // curve17_a
	0x16, // curve18_b
	0xa6, // curve18_a
	0x16, // curve19_b
	0xa6, // curve19_a
	0x16, // curve20_b
	0xa6, // curve20_a
	0x05, // curve21_b
	0x21, // curve21_a
	0x0b, // curve22_b
	0x20, // curve22_a
	0x87, // curve23_b
	0x0f, // curve23_a
	0x00, // curve24_b
	0xFF, // curve24_a
	0x30, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xff, //ascr_skin_Rr
	0x62, //ascr_skin_Rg
	0x6c, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_BROWSER_STANDARD_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};
static char DSI0_BROWSER_STANDARD_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x01, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x40, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf5, //ascr_Rr
	0xee, //ascr_Cg
	0x29, //ascr_Rg
	0xe8, //ascr_Cb
	0x2f, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x41, //ascr_Mg
	0xde, //ascr_Gg
	0xe6, //ascr_Mb
	0x00, //ascr_Gb
	0xf2, //ascr_Yr
	0x3d, //ascr_Br
	0xed, //ascr_Yg
	0x1d, //ascr_Bg
	0x46, //ascr_Yb
	0xdf, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xf0, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_BROWSER_NATURAL_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};
static char DSI0_BROWSER_NATURAL_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x01, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x40, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x91, //ascr_Cr
	0xd4, //ascr_Rr
	0xf2, //ascr_Cg
	0x22, //ascr_Rg
	0xe9, //ascr_Cb
	0x28, //ascr_Rb
	0xe2, //ascr_Mr
	0x83, //ascr_Gr
	0x2b, //ascr_Mg
	0xe7, //ascr_Gg
	0xe0, //ascr_Mb
	0x4e, //ascr_Gb
	0xf3, //ascr_Yr
	0x3e, //ascr_Br
	0xed, //ascr_Yg
	0x19, //ascr_Bg
	0x56, //ascr_Yb
	0xda, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xf0, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_BROWSER_MOVIE_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};
static char DSI0_BROWSER_MOVIE_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x03, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x20,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x20, //ascr_skin_on linear_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x7a, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x2b, //ascr_Rg
	0xf1, //ascr_Cb
	0x2d, //ascr_Rb
	0xff, //ascr_Mr
	0x68, //ascr_Gr
	0x15, //ascr_Mg
	0xff, //ascr_Gg
	0xfa, //ascr_Mb
	0x31, //ascr_Gb
	0xf8, //ascr_Yr
	0x34, //ascr_Br
	0xff, //ascr_Yg
	0x20, //ascr_Bg
	0x4b, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xef, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_BROWSER_AUTO_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_BROWSER_AUTO_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x01, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x30, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x5c, //ascr_skin_Rg
	0x68, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf8, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_EBOOK_DYNAMIC_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_EBOOK_DYNAMIC_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x03, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x20,
	0x00, // curve_1_b
	0x14, // curve_1_a
	0x00, // curve_2_b
	0x14, // curve_2_a
	0x00, // curve_3_b
	0x14, // curve_3_a
	0x00, // curve_4_b
	0x14, // curve_4_a
	0x03, // curve_5_b
	0x9a, // curve_5_a
	0x03, // curve_6_b
	0x9a, // curve_6_a
	0x03, // curve_7_b
	0x9a, // curve_7_a
	0x03, // curve_8_b
	0x9a, // curve_8_a
	0x07, // curve_9_b
	0x9e, // curve_9_a
	0x07, // curve10_b
	0x9e, // curve10_a
	0x07, // curve11_b
	0x9e, // curve11_a
	0x07, // curve12_b
	0x9e, // curve12_a
	0x0a, // curve13_b
	0xa0, // curve13_a
	0x0a, // curve14_b
	0xa0, // curve14_a
	0x0a, // curve15_b
	0xa0, // curve15_a
	0x0a, // curve16_b
	0xa0, // curve16_a
	0x16, // curve17_b
	0xa6, // curve17_a
	0x16, // curve18_b
	0xa6, // curve18_a
	0x16, // curve19_b
	0xa6, // curve19_a
	0x16, // curve20_b
	0xa6, // curve20_a
	0x05, // curve21_b
	0x21, // curve21_a
	0x0b, // curve22_b
	0x20, // curve22_a
	0x87, // curve23_b
	0x0f, // curve23_a
	0x00, // curve24_b
	0xFF, // curve24_a
	0x30, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xff, //ascr_skin_Rr
	0x62, //ascr_skin_Rg
	0x6c, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_EBOOK_STANDARD_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};

static char DSI0_EBOOK_STANDARD_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x01, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x40, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xf5, //ascr_Rr
	0xee, //ascr_Cg
	0x29, //ascr_Rg
	0xe8, //ascr_Cb
	0x2f, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x41, //ascr_Mg
	0xde, //ascr_Gg
	0xe6, //ascr_Mb
	0x00, //ascr_Gb
	0xf2, //ascr_Yr
	0x3d, //ascr_Br
	0xed, //ascr_Yg
	0x1d, //ascr_Bg
	0x46, //ascr_Yb
	0xdf, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xf0, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_EBOOK_NATURAL_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};
static char DSI0_EBOOK_NATURAL_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x01, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x40, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x91, //ascr_Cr
	0xd4, //ascr_Rr
	0xf2, //ascr_Cg
	0x22, //ascr_Rg
	0xe9, //ascr_Cb
	0x28, //ascr_Rb
	0xe2, //ascr_Mr
	0x83, //ascr_Gr
	0x2b, //ascr_Mg
	0xe7, //ascr_Gg
	0xe0, //ascr_Mb
	0x4e, //ascr_Gb
	0xf3, //ascr_Yr
	0x3e, //ascr_Br
	0xed, //ascr_Yg
	0x19, //ascr_Bg
	0x56, //ascr_Yb
	0xda, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xf0, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_EBOOK_MOVIE_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x3c, //ascr algo lce 10 10 10
};
static char DSI0_EBOOK_MOVIE_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x03, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x20,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x20, //ascr_skin_on linear_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x17, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x27, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x59,
	0x0b,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x34,
	0x83,
	0xff, //ascr_skin_Rr
	0x50, //ascr_skin_Rg
	0x60, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x7a, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x2b, //ascr_Rg
	0xf1, //ascr_Cb
	0x2d, //ascr_Rb
	0xff, //ascr_Mr
	0x68, //ascr_Gr
	0x15, //ascr_Mg
	0xff, //ascr_Gg
	0xfa, //ascr_Mb
	0x31, //ascr_Gb
	0xf8, //ascr_Yr
	0x34, //ascr_Br
	0xff, //ascr_Yg
	0x20, //ascr_Bg
	0x4b, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf8, //ascr_Wg
	0x00, //ascr_Kg
	0xef, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_EBOOK_AUTO_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x30, //ascr algo lce 10 10 10
};
static char DSI0_EBOOK_AUTO_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x00, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xd5, //ascr_skin_Rr
	0x2c, //ascr_skin_Rg
	0x2a, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf5, //ascr_skin_Yg
	0x63, //ascr_skin_Yb
	0xfe, //ascr_skin_Mr
	0x4a, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf9, //ascr_skin_Wg
	0xf8, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf5, //ascr_Wg
	0x00, //ascr_Kg
	0xe8, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_EMAIL_AUTO_MDNIE_1[] = {
	/* start */
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x30, //ascr algo lce 10 10 10
};
static char DSI0_EMAIL_AUTO_MDNIE_2[] = {
	0xEC,
	0x98, //lce_on gain 0 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 000 000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x00, //nr fa de cs gamma 0 0000
	0xff, //nr_mask_th
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x14, //fa_edge_th
	0x00, //fa_step_p 13
	0x0a,
	0x00, //fa_step_n 13
	0x32,
	0x01, //fa_max_de_gain 13
	0xf4,
	0x0b, //fa_pcl_ppi 14
	0x8a,
	0x6e, //fa_skin_cr
	0x99, //fa_skin_cb
	0x1b, //fa_dist_left
	0x17, //fa_dist_right
	0x14, //fa_dist_down
	0x1e, //fa_dist_up
	0x02, //fa_div_dist_left
	0x5f,
	0x02, //fa_div_dist_right
	0xc8,
	0x03, //fa_div_dist_down
	0x33,
	0x02, //fa_div_dist_up
	0x22,
	0x10, //fa_px_min_weight
	0x10, //fa_fr_min_weight
	0x07, //fa_skin_zone_w
	0x07, //fa_skin_zone_h
	0x20, //fa_os_cnt_10_co
	0x2d, //fa_os_cnt_20_co
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x00, //linear_on ascr_skin_on strength 0 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xd5, //ascr_skin_Rr
	0x2c, //ascr_skin_Rg
	0x2a, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf5, //ascr_skin_Yg
	0x63, //ascr_skin_Yb
	0xfe, //ascr_skin_Mr
	0x4a, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf9, //ascr_skin_Wg
	0xf8, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xfa, //ascr_Wg
	0x00, //ascr_Kg
	0xef, //ascr_Wb
	0x00, //ascr_Kb
	/* end */
};

static char DSI0_CURTAIN_1[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //data_width mask 00 0000
	0x03, //ascr_roi 1 ascr 00 1 0
	0x02, //algo_roi 1 algo lce_roi 1 lce 00 1 0 00 1 0
	0x00, //roi_ctrl 00
	0x00, //roi0_x_start 12
	0x00,
	0x00, //roi0_x_end
	0x00,
	0x00, //roi0_y_start
	0x00,
	0x00, //roi0_y_end
	0x00,
	0x00, //roi1_x_strat
	0x00,
	0x00, //roi1_x_end
	0x00,
	0x00, //roi1_y_start
	0x00,
	0x00, //roi1_y_end
	0x00,
};

static char DSI0_CURTAIN_2[] = {
	0xEC,
	0x18, //lce_gain 00 0000
	0x24, //lce_color_gain 00 0000
	0x10, //lce_scene_change_on scene_trans 0 0000
	0x14, //lce_min_diff
	0xb3, //lce_illum_gain
	0x01, //lce_ref_offset 9
	0x0e,
	0x01, //lce_ref_gain 9
	0x00,
	0x66, //lce_block_size h v 0000 0000
	0xfa, //lce_bright_th
	0x2d, //lce_bin_size_ratio
	0x03, //lce_dark_th 000
	0x96, //lce_min_ref_offset
	0x00, //nr sharp cs gamma 0000
	0xff, //nr_mask_th
	0x00, //sharpen_weight 10
	0x00,
	0x07, //sharpen_maxplus 11
	0xff,
	0x07, //sharpen_maxminus 11
	0xff,
	0x01, //cs_gain 10
	0x00,
	0x00, //curve_1_b
	0x20, //curve_1_a
	0x00, //curve_2_b
	0x20, //curve_2_a
	0x00, //curve_3_b
	0x20, //curve_3_a
	0x00, //curve_4_b
	0x20, //curve_4_a
	0x02, //curve_5_b
	0x1b, //curve_5_a
	0x02, //curve_6_b
	0x1b, //curve_6_a
	0x02, //curve_7_b
	0x1b, //curve_7_a
	0x02, //curve_8_b
	0x1b, //curve_8_a
	0x09, //curve_9_b
	0xa6, //curve_9_a
	0x09, //curve10_b
	0xa6, //curve10_a
	0x09, //curve11_b
	0xa6, //curve11_a
	0x09, //curve12_b
	0xa6, //curve12_a
	0x00, //curve13_b
	0x20, //curve13_a
	0x00, //curve14_b
	0x20, //curve14_a
	0x00, //curve15_b
	0x20, //curve15_a
	0x00, //curve16_b
	0x20, //curve16_a
	0x00, //curve17_b
	0x20, //curve17_a
	0x00, //curve18_b
	0x20, //curve18_a
	0x00, //curve19_b
	0x20, //curve19_a
	0x00, //curve20_b
	0x20, //curve20_a
	0x00, //curve21_b
	0x20, //curve21_a
	0x00, //curve22_b
	0x20, //curve22_a
	0x00, //curve23_b
	0x20, //curve23_a
	0x00, //curve24_b
	0xFF, //curve24_a
	0x20, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0x00, //ascr_Rr
	0x00, //ascr_Cg
	0x00, //ascr_Rg
	0x00, //ascr_Cb
	0x00, //ascr_Rb
	0x00, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0x00, //ascr_Gg
	0x00, //ascr_Mb
	0x00, //ascr_Gb
	0x00, //ascr_Yr
	0x00, //ascr_Br
	0x00, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0x00, //ascr_Bb
	0x00, //ascr_Wr
	0x00, //ascr_Kr
	0x00, //ascr_Wg
	0x00, //ascr_Kg
	0x00, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static struct dsi_cmd_desc DSI0_BYPASS_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_1)}, DSI0_BYPASS_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_2)}, DSI0_BYPASS_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_NEGATIVE_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_NEGATIVE_MDNIE_1)}, DSI0_NEGATIVE_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_NEGATIVE_MDNIE_2)}, DSI0_NEGATIVE_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_COLOR_BLIND_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_1)}, DSI0_COLOR_BLIND_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_2)}, DSI0_COLOR_BLIND_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_HBM_CE_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_1)}, DSI0_HBM_CE_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_2)}, DSI0_HBM_CE_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_RGB_SENSOR_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_1)}, DSI0_RGB_SENSOR_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_2)}, DSI0_RGB_SENSOR_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_CURTAIN[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_CURTAIN_1)}, DSI0_CURTAIN_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_CURTAIN_2)}, DSI0_CURTAIN_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

///////////////////////////////////////////////////////////////////////////////////

static struct dsi_cmd_desc DSI0_UI_DYNAMIC_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_1)}, DSI0_UI_DYNAMIC_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_2)}, DSI0_UI_DYNAMIC_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_UI_STANDARD_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_UI_STANDARD_MDNIE_1)}, DSI0_UI_STANDARD_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_UI_STANDARD_MDNIE_2)}, DSI0_UI_STANDARD_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_UI_NATURAL_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_UI_NATURAL_MDNIE_1)}, DSI0_UI_NATURAL_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_UI_NATURAL_MDNIE_2)}, DSI0_UI_NATURAL_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_UI_MOVIE_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_UI_MOVIE_MDNIE_1)}, DSI0_UI_MOVIE_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_UI_MOVIE_MDNIE_2)}, DSI0_UI_MOVIE_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_UI_AUTO_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_1)}, DSI0_UI_AUTO_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_2)}, DSI0_UI_AUTO_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VIDEO_OUTDOOR_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_OUTDOOR_MDNIE_1)}, DSI0_VIDEO_OUTDOOR_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_OUTDOOR_MDNIE_2)}, DSI0_VIDEO_OUTDOOR_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VIDEO_DYNAMIC_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_DYNAMIC_MDNIE_1)}, DSI0_VIDEO_DYNAMIC_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_DYNAMIC_MDNIE_2)}, DSI0_VIDEO_DYNAMIC_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VIDEO_STANDARD_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_STANDARD_MDNIE_1)}, DSI0_VIDEO_STANDARD_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_STANDARD_MDNIE_2)}, DSI0_VIDEO_STANDARD_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VIDEO_NATURAL_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_NATURAL_MDNIE_1)}, DSI0_VIDEO_NATURAL_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_NATURAL_MDNIE_2)}, DSI0_VIDEO_NATURAL_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VIDEO_MOVIE_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_MOVIE_MDNIE_1)}, DSI0_VIDEO_MOVIE_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_MOVIE_MDNIE_2)}, DSI0_VIDEO_MOVIE_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VIDEO_AUTO_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_AUTO_MDNIE_1)}, DSI0_VIDEO_AUTO_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_AUTO_MDNIE_2)}, DSI0_VIDEO_AUTO_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VIDEO_WARM_OUTDOOR_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_WARM_OUTDOOR_MDNIE_1)}, DSI0_VIDEO_WARM_OUTDOOR_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_WARM_OUTDOOR_MDNIE_2)}, DSI0_VIDEO_WARM_OUTDOOR_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VIDEO_WARM_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_WARM_MDNIE_1)}, DSI0_VIDEO_WARM_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_WARM_MDNIE_2)}, DSI0_VIDEO_WARM_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VIDEO_COLD_OUTDOOR_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_COLD_OUTDOOR_MDNIE_1)}, DSI0_VIDEO_COLD_OUTDOOR_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_COLD_OUTDOOR_MDNIE_2)}, DSI0_VIDEO_COLD_OUTDOOR_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VIDEO_COLD_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_COLD_MDNIE_1)}, DSI0_VIDEO_COLD_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VIDEO_COLD_MDNIE_2)}, DSI0_VIDEO_COLD_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_CAMERA_OUTDOOR_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_CAMERA_OUTDOOR_MDNIE_1)}, DSI0_CAMERA_OUTDOOR_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_CAMERA_OUTDOOR_MDNIE_2)}, DSI0_CAMERA_OUTDOOR_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_CAMERA_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_CAMERA_MDNIE_1)}, DSI0_CAMERA_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_CAMERA_MDNIE_2)}, DSI0_CAMERA_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_CAMERA_AUTO_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_CAMERA_AUTO_MDNIE_1)}, DSI0_CAMERA_AUTO_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_CAMERA_AUTO_MDNIE_2)}, DSI0_CAMERA_AUTO_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_GALLERY_DYNAMIC_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_GALLERY_DYNAMIC_MDNIE_1)}, DSI0_GALLERY_DYNAMIC_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_GALLERY_DYNAMIC_MDNIE_2)}, DSI0_GALLERY_DYNAMIC_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_GALLERY_STANDARD_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_GALLERY_STANDARD_MDNIE_1)}, DSI0_GALLERY_STANDARD_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_GALLERY_STANDARD_MDNIE_2)}, DSI0_GALLERY_STANDARD_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_GALLERY_NATURAL_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_GALLERY_NATURAL_MDNIE_1)}, DSI0_GALLERY_NATURAL_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_GALLERY_NATURAL_MDNIE_2)}, DSI0_GALLERY_NATURAL_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_GALLERY_MOVIE_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_GALLERY_MOVIE_MDNIE_1)}, DSI0_GALLERY_MOVIE_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_GALLERY_MOVIE_MDNIE_2)}, DSI0_GALLERY_MOVIE_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_GALLERY_AUTO_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_1)}, DSI0_GALLERY_AUTO_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_2)}, DSI0_GALLERY_AUTO_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VT_DYNAMIC_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VT_DYNAMIC_MDNIE_1)}, DSI0_VT_DYNAMIC_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VT_DYNAMIC_MDNIE_2)}, DSI0_VT_DYNAMIC_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VT_STANDARD_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VT_STANDARD_MDNIE_1)}, DSI0_VT_STANDARD_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VT_STANDARD_MDNIE_2)}, DSI0_VT_STANDARD_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VT_NATURAL_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VT_NATURAL_MDNIE_1)}, DSI0_VT_NATURAL_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VT_NATURAL_MDNIE_2)}, DSI0_VT_NATURAL_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VT_MOVIE_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VT_MOVIE_MDNIE_1)}, DSI0_VT_MOVIE_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VT_MOVIE_MDNIE_2)}, DSI0_VT_MOVIE_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_VT_AUTO_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VT_AUTO_MDNIE_1)}, DSI0_VT_AUTO_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_VT_AUTO_MDNIE_2)}, DSI0_VT_AUTO_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_BROWSER_DYNAMIC_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_BROWSER_DYNAMIC_MDNIE_1)}, DSI0_BROWSER_DYNAMIC_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_BROWSER_DYNAMIC_MDNIE_2)}, DSI0_BROWSER_DYNAMIC_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_BROWSER_STANDARD_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_BROWSER_STANDARD_MDNIE_1)}, DSI0_BROWSER_STANDARD_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_BROWSER_STANDARD_MDNIE_2)}, DSI0_BROWSER_STANDARD_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_BROWSER_NATURAL_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_BROWSER_NATURAL_MDNIE_1)}, DSI0_BROWSER_NATURAL_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_BROWSER_NATURAL_MDNIE_2)}, DSI0_BROWSER_NATURAL_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_BROWSER_MOVIE_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_BROWSER_MOVIE_MDNIE_1)}, DSI0_BROWSER_MOVIE_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_BROWSER_MOVIE_MDNIE_2)}, DSI0_BROWSER_MOVIE_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_BROWSER_AUTO_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_BROWSER_AUTO_MDNIE_1)}, DSI0_BROWSER_AUTO_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_BROWSER_AUTO_MDNIE_2)}, DSI0_BROWSER_AUTO_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_EBOOK_DYNAMIC_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_EBOOK_DYNAMIC_MDNIE_1)}, DSI0_EBOOK_DYNAMIC_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_EBOOK_DYNAMIC_MDNIE_2)}, DSI0_EBOOK_DYNAMIC_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_EBOOK_STANDARD_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_EBOOK_STANDARD_MDNIE_1)}, DSI0_EBOOK_STANDARD_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_EBOOK_STANDARD_MDNIE_2)}, DSI0_EBOOK_STANDARD_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_EBOOK_NATURAL_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_EBOOK_NATURAL_MDNIE_1)}, DSI0_EBOOK_NATURAL_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_EBOOK_NATURAL_MDNIE_2)}, DSI0_EBOOK_NATURAL_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_EBOOK_MOVIE_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_EBOOK_MOVIE_MDNIE_1)}, DSI0_EBOOK_MOVIE_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_EBOOK_MOVIE_MDNIE_2)}, DSI0_EBOOK_MOVIE_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_EBOOK_AUTO_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_1)}, DSI0_EBOOK_AUTO_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_2)}, DSI0_EBOOK_AUTO_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc DSI0_EMAIL_AUTO_MDNIE[] = {
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(level_1_key_on)}, level_1_key_on},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_EMAIL_AUTO_MDNIE_1)}, DSI0_EMAIL_AUTO_MDNIE_1},
	{{DTYPE_DCS_LWRITE, 0, 0, 0, 0, sizeof(DSI0_EMAIL_AUTO_MDNIE_2)}, DSI0_EMAIL_AUTO_MDNIE_2},
	{{DTYPE_DCS_LWRITE, 1, 0, 0, 0, sizeof(level_1_key_off)}, level_1_key_off},
};

static struct dsi_cmd_desc *mdnie_tune_value_dsi0[MAX_APP_MODE][MAX_MODE][MAX_OUTDOOR_MODE] = {
		/*
			DYNAMIC_MODE
			STANDARD_MODE
			NATURAL_MODE
			MOVIE_MODE
			AUTO_MODE
		*/
		// UI_APP
		{
			{DSI0_UI_DYNAMIC_MDNIE,	NULL},
			{DSI0_UI_STANDARD_MDNIE,	NULL},
			{DSI0_UI_NATURAL_MDNIE,	NULL},
			{DSI0_UI_MOVIE_MDNIE,	NULL},
			{DSI0_UI_AUTO_MDNIE,	NULL},
		},
		// VIDEO_APP
		{
			{DSI0_VIDEO_DYNAMIC_MDNIE,	DSI0_VIDEO_OUTDOOR_MDNIE},
			{DSI0_VIDEO_STANDARD_MDNIE,	DSI0_VIDEO_OUTDOOR_MDNIE},
			{DSI0_VIDEO_NATURAL_MDNIE,	DSI0_VIDEO_OUTDOOR_MDNIE},
			{DSI0_VIDEO_MOVIE_MDNIE,	DSI0_VIDEO_OUTDOOR_MDNIE},
			{DSI0_VIDEO_AUTO_MDNIE,	DSI0_VIDEO_OUTDOOR_MDNIE},
		},
		// VIDEO_WARM_APP
		{
			{DSI0_VIDEO_WARM_MDNIE,	DSI0_VIDEO_WARM_OUTDOOR_MDNIE},
			{DSI0_VIDEO_WARM_MDNIE,	DSI0_VIDEO_WARM_OUTDOOR_MDNIE},
			{DSI0_VIDEO_WARM_MDNIE,	DSI0_VIDEO_WARM_OUTDOOR_MDNIE},
			{DSI0_VIDEO_WARM_MDNIE,	DSI0_VIDEO_WARM_OUTDOOR_MDNIE},
			{DSI0_VIDEO_WARM_MDNIE,	DSI0_VIDEO_WARM_OUTDOOR_MDNIE},
		},
		// VIDEO_COLD_APP
		{
			{DSI0_VIDEO_COLD_MDNIE,	DSI0_VIDEO_COLD_OUTDOOR_MDNIE},
			{DSI0_VIDEO_COLD_MDNIE,	DSI0_VIDEO_COLD_OUTDOOR_MDNIE},
			{DSI0_VIDEO_COLD_MDNIE,	DSI0_VIDEO_COLD_OUTDOOR_MDNIE},
			{DSI0_VIDEO_COLD_MDNIE,	DSI0_VIDEO_COLD_OUTDOOR_MDNIE},
			{DSI0_VIDEO_COLD_MDNIE,	DSI0_VIDEO_COLD_OUTDOOR_MDNIE},
		},
		// CAMERA_APP
		{
			{DSI0_CAMERA_MDNIE,	DSI0_CAMERA_OUTDOOR_MDNIE},
			{DSI0_CAMERA_MDNIE,	DSI0_CAMERA_OUTDOOR_MDNIE},
			{DSI0_CAMERA_MDNIE,	DSI0_CAMERA_OUTDOOR_MDNIE},
			{DSI0_CAMERA_MDNIE,	DSI0_CAMERA_OUTDOOR_MDNIE},
			{DSI0_CAMERA_AUTO_MDNIE,	DSI0_CAMERA_OUTDOOR_MDNIE},
		},
		// NAVI_APP
		{
			{NULL,	NULL},
			{NULL,	NULL},
			{NULL,	NULL},
			{NULL,	NULL},
			{NULL,	NULL},
		},
		// GALLERY_APP
		{
			{DSI0_GALLERY_DYNAMIC_MDNIE,	NULL},
			{DSI0_GALLERY_STANDARD_MDNIE,	NULL},
			{DSI0_GALLERY_NATURAL_MDNIE,	NULL},
			{DSI0_GALLERY_MOVIE_MDNIE,	NULL},
			{DSI0_GALLERY_AUTO_MDNIE,	NULL},
		},
		// VT_APP
		{
			{DSI0_VT_DYNAMIC_MDNIE,	NULL},
			{DSI0_VT_STANDARD_MDNIE,	NULL},
			{DSI0_VT_NATURAL_MDNIE,	NULL},
			{DSI0_VT_MOVIE_MDNIE,	NULL},
			{DSI0_VT_AUTO_MDNIE,	NULL},
		},
		// BROWSER_APP
		{
			{DSI0_BROWSER_DYNAMIC_MDNIE,	NULL},
			{DSI0_BROWSER_STANDARD_MDNIE,	NULL},
			{DSI0_BROWSER_NATURAL_MDNIE,	NULL},
			{DSI0_BROWSER_MOVIE_MDNIE,	NULL},
			{DSI0_BROWSER_AUTO_MDNIE,	NULL},
		},
		// eBOOK_APP
		{
			{DSI0_EBOOK_DYNAMIC_MDNIE,	NULL},
			{DSI0_EBOOK_STANDARD_MDNIE,NULL},
			{DSI0_EBOOK_NATURAL_MDNIE,	NULL},
			{DSI0_EBOOK_MOVIE_MDNIE,	NULL},
			{DSI0_EBOOK_AUTO_MDNIE,	NULL},
		},
		// EMAIL_APP
		{
			{DSI0_EMAIL_AUTO_MDNIE,	NULL},
			{DSI0_EMAIL_AUTO_MDNIE,	NULL},
			{DSI0_EMAIL_AUTO_MDNIE,	NULL},
			{DSI0_EMAIL_AUTO_MDNIE,	NULL},
			{DSI0_EMAIL_AUTO_MDNIE,	NULL},
		},
		// TDMB_APP
		{
			{DSI0_UI_DYNAMIC_MDNIE,	NULL},
			{DSI0_UI_STANDARD_MDNIE,	NULL},
			{DSI0_UI_NATURAL_MDNIE,	NULL},
			{DSI0_UI_MOVIE_MDNIE,	NULL},
			{DSI0_UI_AUTO_MDNIE,	NULL},
		},
};

#define DSI0_RGB_SENSOR_MDNIE_1_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_1)
#define DSI0_RGB_SENSOR_MDNIE_2_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_2)
#endif /*_DSI_TCON_MDNIE_LITE_DATA_FHD_S6E3HF2_H_*/
