/*
 * =================================================================
 *
 *
 *	Description:  samsung display panel file
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
#include "ss_dsi_smart_dimming_S6E3HA2_AMS567DJ01.h"

//#define SMART_DIMMING_DEBUG

static char max_lux_table[GAMMA_SET_MAX];
static char min_lux_table[GAMMA_SET_MAX];

/*
*	To support different center cell gamma setting
*/
static char V255_300CD_R_MSB;
static char V255_300CD_R_LSB;

static char V255_300CD_G_MSB;
static char V255_300CD_G_LSB;

static char V255_300CD_B_MSB;
static char V255_300CD_B_LSB;

static char V203_300CD_R;
static char V203_300CD_G;
static char V203_300CD_B;

static char V151_300CD_R;
static char V151_300CD_G;
static char V151_300CD_B;

static char V87_300CD_R;
static char V87_300CD_G;
static char V87_300CD_B;

static char V51_300CD_R;
static char V51_300CD_G;
static char V51_300CD_B;

static char V35_300CD_R;
static char V35_300CD_G;
static char V35_300CD_B;

static char V23_300CD_R;
static char V23_300CD_G;
static char V23_300CD_B;

static char V11_300CD_R;
static char V11_300CD_G;
static char V11_300CD_B;

static char V3_300CD_R;
static char V3_300CD_G;
static char V3_300CD_B;

static char V0_300CD_R;
static char V0_300CD_G;
static char V0_300CD_B;

static char VT_300CD_R;
static char VT_300CD_G;
static char VT_300CD_B;

static int char_to_int(char data1)
{
	int cal_data;

	if (data1 & 0x80) {
		cal_data = data1 & 0x7F;
		cal_data *= -1;
	} else
		cal_data = data1;

	return cal_data;
}

static int char_to_int_v255(char data1, char data2)
{
	int cal_data;

	if (data1)
		cal_data = data2 * -1;
	else
		cal_data = data2;

	return cal_data;
}

static void print_RGB_offset(struct SMART_DIM *pSmart)
{
	pr_info("%s MTP Offset VT R:%d G:%d B:%d\n", __func__,
			char_to_int(pSmart->MTP.G_OFFSET.OFFSET_T & 0x0F),
			char_to_int(pSmart->MTP.G_OFFSET.OFFSET_T >> 4),
			char_to_int(pSmart->MTP.B_OFFSET.OFFSET_T));
	pr_info("%s MTP Offset V0 R:%d G:%d B:%d\n", __func__,
			char_to_int(pSmart->MTP.R_OFFSET.OFFSET_0),
			char_to_int(pSmart->MTP.G_OFFSET.OFFSET_0),
			char_to_int(pSmart->MTP.B_OFFSET.OFFSET_0));
	pr_info("%s MTP Offset V3 R:%d G:%d B:%d\n", __func__,
			char_to_int(pSmart->MTP.R_OFFSET.OFFSET_3),
			char_to_int(pSmart->MTP.G_OFFSET.OFFSET_3),
			char_to_int(pSmart->MTP.B_OFFSET.OFFSET_3));
	pr_info("%s MTP Offset V11 R:%d G:%d B:%d\n", __func__,
			char_to_int(pSmart->MTP.R_OFFSET.OFFSET_11),
			char_to_int(pSmart->MTP.G_OFFSET.OFFSET_11),
			char_to_int(pSmart->MTP.B_OFFSET.OFFSET_11));
	pr_info("%s MTP Offset V23 R:%d G:%d B:%d\n", __func__,
			char_to_int(pSmart->MTP.R_OFFSET.OFFSET_23),
			char_to_int(pSmart->MTP.G_OFFSET.OFFSET_23),
			char_to_int(pSmart->MTP.B_OFFSET.OFFSET_23));
	pr_info("%s MTP Offset V35 R:%d G:%d B:%d\n", __func__,
			char_to_int(pSmart->MTP.R_OFFSET.OFFSET_35),
			char_to_int(pSmart->MTP.G_OFFSET.OFFSET_35),
			char_to_int(pSmart->MTP.B_OFFSET.OFFSET_35));
	pr_info("%s MTP Offset V51 R:%d G:%d B:%d\n", __func__,
			char_to_int(pSmart->MTP.R_OFFSET.OFFSET_51),
			char_to_int(pSmart->MTP.G_OFFSET.OFFSET_51),
			char_to_int(pSmart->MTP.B_OFFSET.OFFSET_51));
	pr_info("%s MTP Offset V87 R:%d G:%d B:%d\n", __func__,
			char_to_int(pSmart->MTP.R_OFFSET.OFFSET_87),
			char_to_int(pSmart->MTP.G_OFFSET.OFFSET_87),
			char_to_int(pSmart->MTP.B_OFFSET.OFFSET_87));
	pr_info("%s MTP Offset V151 R:%d G:%d B:%d\n", __func__,
			char_to_int(pSmart->MTP.R_OFFSET.OFFSET_151),
			char_to_int(pSmart->MTP.G_OFFSET.OFFSET_151),
			char_to_int(pSmart->MTP.B_OFFSET.OFFSET_151));
	pr_info("%s MTP Offset V203 R:%d G:%d B:%d\n", __func__,
			char_to_int(pSmart->MTP.R_OFFSET.OFFSET_203),
			char_to_int(pSmart->MTP.G_OFFSET.OFFSET_203),
			char_to_int(pSmart->MTP.B_OFFSET.OFFSET_203));
	pr_info("%s MTP Offset V255 R:%d G:%d B:%d\n", __func__,
			char_to_int_v255(pSmart->MTP.R_OFFSET.OFFSET_255_MSB,
				pSmart->MTP.R_OFFSET.OFFSET_255_LSB),
			char_to_int_v255(pSmart->MTP.G_OFFSET.OFFSET_255_MSB,
				pSmart->MTP.G_OFFSET.OFFSET_255_LSB),
			char_to_int_v255(pSmart->MTP.B_OFFSET.OFFSET_255_MSB,
				pSmart->MTP.B_OFFSET.OFFSET_255_LSB));
}

static void print_lux_table(struct SMART_DIM *psmart)
{
	int lux_loop;
	int cnt;
	char pBuffer[256];
	memset(pBuffer, 0x00, 256);

	for (lux_loop = 0; lux_loop < psmart->lux_table_max; lux_loop++) {
		for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
			snprintf(pBuffer + strnlen(pBuffer, 256), 256, " %d",
				psmart->gen_table[lux_loop].gamma_setting[cnt]);

		pr_info("lux : %3d  %s", psmart->plux_table[lux_loop], pBuffer);
		memset(pBuffer, 0x00, 256);
	}
}

static void print_aid_log(struct smartdim_conf *conf)
{
	print_RGB_offset(conf->psmart);
	print_lux_table(conf->psmart);
}

void print_lux_table_hmt(struct SMART_DIM *psmart)
{
	int lux_loop;
	int cnt;
	char pBuffer[256];
	memset(pBuffer, 0x00, 256);

	for (lux_loop = 0; lux_loop < psmart->lux_table_max; lux_loop++) {
		for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
			snprintf(pBuffer + strnlen(pBuffer, 256), 256, " %d",
				psmart->hmt_gen_table[lux_loop].gamma_setting[cnt]);

		pr_info("lux : %3d  %s\n", psmart->plux_table[lux_loop], pBuffer);
		memset(pBuffer, 0x00, 256);
	}
}

void print_aid_log_hmt(struct smartdim_conf *conf)
{
	pr_info("== print_aid_log_hmt ==\n");
	print_RGB_offset(conf->psmart);
	print_lux_table(conf->psmart);
	pr_info("\n");
}

#define v255_coefficient 72
#define v255_denominator 860
static int v255_adjustment(struct SMART_DIM *pSmart)
{
	unsigned long long result_1, result_2, result_3, result_4;
	int add_mtp;
	int LSB;
	int v255_value;

	v255_value = (V255_300CD_R_MSB << 8) | (V255_300CD_R_LSB);
	LSB = char_to_int_v255(pSmart->MTP.R_OFFSET.OFFSET_255_MSB,
				pSmart->MTP.R_OFFSET.OFFSET_255_LSB);
	add_mtp = LSB + v255_value;
	result_1 = result_2 = (v255_coefficient+add_mtp) << BIT_SHIFT;
	do_div(result_2, v255_denominator);
	result_3 = (pSmart->vregout_voltage * result_2) >> BIT_SHIFT;
	result_4 = pSmart->vregout_voltage - result_3;
	pSmart->RGB_OUTPUT.R_VOLTAGE.level_255 = result_4;
	pSmart->RGB_OUTPUT.R_VOLTAGE.level_0 = pSmart->vregout_voltage;

	v255_value = (V255_300CD_G_MSB << 8) | (V255_300CD_G_LSB);
	LSB = char_to_int_v255(pSmart->MTP.G_OFFSET.OFFSET_255_MSB,
				pSmart->MTP.G_OFFSET.OFFSET_255_LSB);
	add_mtp = LSB + v255_value;
	result_1 = result_2 = (v255_coefficient+add_mtp) << BIT_SHIFT;
	do_div(result_2, v255_denominator);
	result_3 = (pSmart->vregout_voltage * result_2) >> BIT_SHIFT;
	result_4 = pSmart->vregout_voltage - result_3;
	pSmart->RGB_OUTPUT.G_VOLTAGE.level_255 = result_4;
	pSmart->RGB_OUTPUT.G_VOLTAGE.level_0 = pSmart->vregout_voltage;

	v255_value = (V255_300CD_B_MSB << 8) | (V255_300CD_B_LSB);
	LSB = char_to_int_v255(pSmart->MTP.B_OFFSET.OFFSET_255_MSB,
				pSmart->MTP.B_OFFSET.OFFSET_255_LSB);
	add_mtp = LSB + v255_value;
	result_1 = result_2 = (v255_coefficient+add_mtp) << BIT_SHIFT;
	do_div(result_2, v255_denominator);
	result_3 = (pSmart->vregout_voltage * result_2) >> BIT_SHIFT;
	result_4 = pSmart->vregout_voltage - result_3;
	pSmart->RGB_OUTPUT.B_VOLTAGE.level_255 = result_4;
	pSmart->RGB_OUTPUT.B_VOLTAGE.level_0 = pSmart->vregout_voltage;

#ifdef SMART_DIMMING_DEBUG
	pr_info("%s V255 RED:%d GREEN:%d BLUE:%d\n", __func__,
			pSmart->RGB_OUTPUT.R_VOLTAGE.level_255,
			pSmart->RGB_OUTPUT.G_VOLTAGE.level_255,
			pSmart->RGB_OUTPUT.B_VOLTAGE.level_255);
#endif

	return 0;
}

static void v255_hexa(int *index, struct SMART_DIM *pSmart, char *str)
{
	unsigned long long result_1, result_2, result_3;

	result_1 = pSmart->vregout_voltage -
		(pSmart->GRAY.TABLE[index[V255_INDEX]].R_Gray);
	result_2 = result_1 * v255_denominator;
	do_div(result_2, pSmart->vregout_voltage);
	result_3 = result_2  - v255_coefficient;
	str[0] = (result_3 & 0xff00) >> 8;
	str[1] = result_3 & 0xff;

	result_1 = pSmart->vregout_voltage -
		(pSmart->GRAY.TABLE[index[V255_INDEX]].G_Gray);
	result_2 = result_1 * v255_denominator;
	do_div(result_2, pSmart->vregout_voltage);
	result_3 = result_2  - v255_coefficient;
	str[2] = (result_3 & 0xff00) >> 8;
	str[3] = result_3 & 0xff;

	result_1 = pSmart->vregout_voltage -
			(pSmart->GRAY.TABLE[index[V255_INDEX]].B_Gray);
	result_2 = result_1 * v255_denominator;
	do_div(result_2, pSmart->vregout_voltage);
	result_3 = result_2  - v255_coefficient;
	str[4] = (result_3 & 0xff00) >> 8;
	str[5] = result_3 & 0xff;

}

static int vt_coefficient[] = {
	0, 12, 24, 36, 48,
	60, 72, 84, 96, 108,
	138, 148, 158, 168,
	178, 186,
};
#define vt_denominator 860
static int vt_adjustment(struct SMART_DIM *pSmart)
{
	unsigned long long result_1, result_2, result_3, result_4;
	int add_mtp;
	int LSB;

	LSB = char_to_int(pSmart->MTP.G_OFFSET.OFFSET_T & 0x0F);
	add_mtp = LSB + VT_300CD_R;
	result_1 = result_2 = vt_coefficient[LSB] << BIT_SHIFT;
	do_div(result_2, vt_denominator);
	result_3 = (pSmart->vregout_voltage * result_2) >> BIT_SHIFT;
	result_4 = pSmart->vregout_voltage - result_3;
	pSmart->GRAY.VT_TABLE.R_Gray = result_4;

	LSB = char_to_int(pSmart->MTP.G_OFFSET.OFFSET_T >> 4);
	add_mtp = LSB + VT_300CD_G;
	result_1 = result_2 = vt_coefficient[LSB] << BIT_SHIFT;
	do_div(result_2, vt_denominator);
	result_3 = (pSmart->vregout_voltage * result_2) >> BIT_SHIFT;
	result_4 = pSmart->vregout_voltage - result_3;
	pSmart->GRAY.VT_TABLE.G_Gray = result_4;

	LSB = char_to_int(pSmart->MTP.B_OFFSET.OFFSET_T);
	add_mtp = LSB + VT_300CD_B;
	result_1 = result_2 = vt_coefficient[LSB] << BIT_SHIFT;
	do_div(result_2, vt_denominator);
	result_3 = (pSmart->vregout_voltage * result_2) >> BIT_SHIFT;
	result_4 = pSmart->vregout_voltage - result_3;
	pSmart->GRAY.VT_TABLE.B_Gray = result_4;

#ifdef SMART_DIMMING_DEBUG
	pr_info("%s VT RED:%d GREEN:%d BLUE:%d\n", __func__,
			pSmart->GRAY.VT_TABLE.R_Gray,
			pSmart->GRAY.VT_TABLE.G_Gray,
			pSmart->GRAY.VT_TABLE.B_Gray);
#endif

	return 0;

}

static void vt_hexa(int *index, struct SMART_DIM *pSmart, char *str)
{
	str[33] = VT_300CD_G;
	str[34] = VT_300CD_B;
}

#define v203_coefficient 64
#define v203_denominator 320
static int v203_adjustment(struct SMART_DIM *pSmart)
{
	unsigned long long result_1, result_2, result_3, result_4;
	int add_mtp;
	int LSB;

	LSB = char_to_int(pSmart->MTP.R_OFFSET.OFFSET_203);
	add_mtp = LSB + V203_300CD_R;
	result_1 = (pSmart->GRAY.VT_TABLE.R_Gray)
				- (pSmart->RGB_OUTPUT.R_VOLTAGE.level_255);
	result_2 = (v203_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v203_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.R_Gray) - result_3;
	pSmart->RGB_OUTPUT.R_VOLTAGE.level_203 = result_4;

	LSB = char_to_int(pSmart->MTP.G_OFFSET.OFFSET_203);
	add_mtp = LSB + V203_300CD_G;
	result_1 = (pSmart->GRAY.VT_TABLE.G_Gray)
				- (pSmart->RGB_OUTPUT.G_VOLTAGE.level_255);
	result_2 = (v203_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v203_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.G_Gray) - result_3;
	pSmart->RGB_OUTPUT.G_VOLTAGE.level_203 = result_4;

	LSB = char_to_int(pSmart->MTP.B_OFFSET.OFFSET_203);
	add_mtp = LSB + V203_300CD_B;
	result_1 = (pSmart->GRAY.VT_TABLE.B_Gray)
				- (pSmart->RGB_OUTPUT.B_VOLTAGE.level_255);
	result_2 = (v203_coefficient+add_mtp) << BIT_SHIFT;
	do_div(result_2, v203_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.B_Gray) - result_3;
	pSmart->RGB_OUTPUT.B_VOLTAGE.level_203 = result_4;

#ifdef SMART_DIMMING_DEBUG
	pr_info("%s V203 RED:%d GREEN:%d BLUE:%d\n", __func__,
			pSmart->RGB_OUTPUT.R_VOLTAGE.level_203,
			pSmart->RGB_OUTPUT.G_VOLTAGE.level_203,
			pSmart->RGB_OUTPUT.B_VOLTAGE.level_203);
#endif

	return 0;

}

static void v203_hexa(int *index, struct SMART_DIM *pSmart, char *str)
{
	unsigned long long result_1, result_2, result_3;

	result_1 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->GRAY.TABLE[index[V203_INDEX]].R_Gray);
	result_2 = result_1 * v203_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->GRAY.TABLE[index[V255_INDEX]].R_Gray);
	do_div(result_2, result_3);
	str[6] = (result_2  - v203_coefficient) & 0xff;

	result_1 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->GRAY.TABLE[index[V203_INDEX]].G_Gray);
	result_2 = result_1 * v203_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->GRAY.TABLE[index[V255_INDEX]].G_Gray);
	do_div(result_2, result_3);
	str[7] = (result_2  - v203_coefficient) & 0xff;

	result_1 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->GRAY.TABLE[index[V203_INDEX]].B_Gray);
	result_2 = result_1 * v203_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->GRAY.TABLE[index[V255_INDEX]].B_Gray);
	do_div(result_2, result_3);
	str[8] = (result_2  - v203_coefficient) & 0xff;

}

#define v151_coefficient 64
#define v151_denominator 320
static int v151_adjustment(struct SMART_DIM *pSmart)
{
	unsigned long long result_1, result_2, result_3, result_4;
	int add_mtp;
	int LSB;

	LSB = char_to_int(pSmart->MTP.R_OFFSET.OFFSET_151);
	add_mtp = LSB + V151_300CD_R;
	result_1 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->RGB_OUTPUT.R_VOLTAGE.level_203);
	result_2 = (v151_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v151_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.R_Gray) - result_3;
	pSmart->RGB_OUTPUT.R_VOLTAGE.level_151 = result_4;

	LSB = char_to_int(pSmart->MTP.G_OFFSET.OFFSET_151);
	add_mtp = LSB + V151_300CD_G;
	result_1 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->RGB_OUTPUT.G_VOLTAGE.level_203);
	result_2 = (v151_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v151_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.G_Gray) - result_3;
	pSmart->RGB_OUTPUT.G_VOLTAGE.level_151 = result_4;

	LSB = char_to_int(pSmart->MTP.B_OFFSET.OFFSET_151);
	add_mtp = LSB + V151_300CD_B;
	result_1 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->RGB_OUTPUT.B_VOLTAGE.level_203);
	result_2 = (v151_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v151_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.B_Gray) - result_3;
	pSmart->RGB_OUTPUT.B_VOLTAGE.level_151 = result_4;

#ifdef SMART_DIMMING_DEBUG
	pr_info("%s V151 RED:%d GREEN:%d BLUE:%d\n", __func__,
			pSmart->RGB_OUTPUT.R_VOLTAGE.level_151,
			pSmart->RGB_OUTPUT.G_VOLTAGE.level_151,
			pSmart->RGB_OUTPUT.B_VOLTAGE.level_151);
#endif

	return 0;

}

static void v151_hexa(int *index, struct SMART_DIM *pSmart, char *str)
{
	unsigned long long result_1, result_2, result_3;

	result_1 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->GRAY.TABLE[index[V151_INDEX]].R_Gray);
	result_2 = result_1 * v151_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->GRAY.TABLE[index[V203_INDEX]].R_Gray);
	do_div(result_2, result_3);
	str[9] = (result_2  - v151_coefficient) & 0xff;

	result_1 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->GRAY.TABLE[index[V151_INDEX]].G_Gray);
	result_2 = result_1 * v151_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->GRAY.TABLE[index[V203_INDEX]].G_Gray);
	do_div(result_2, result_3);
	str[10] = (result_2  - v151_coefficient) & 0xff;

	result_1 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->GRAY.TABLE[index[V151_INDEX]].B_Gray);
	result_2 = result_1 * v151_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->GRAY.TABLE[index[V203_INDEX]].B_Gray);
	do_div(result_2, result_3);
	str[11] = (result_2  - v151_coefficient) & 0xff;
}

#define v87_coefficient 64
#define v87_denominator 320
static int v87_adjustment(struct SMART_DIM *pSmart)
{
	unsigned long long result_1, result_2, result_3, result_4;
	int add_mtp;
	int LSB;

	LSB = char_to_int(pSmart->MTP.R_OFFSET.OFFSET_87);
	add_mtp = LSB + V87_300CD_R;
	result_1 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->RGB_OUTPUT.R_VOLTAGE.level_151);
	result_2 = (v87_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v87_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.R_Gray) - result_3;
	pSmart->RGB_OUTPUT.R_VOLTAGE.level_87 = result_4;

	LSB = char_to_int(pSmart->MTP.G_OFFSET.OFFSET_87);
	add_mtp = LSB + V87_300CD_G;
	result_1 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->RGB_OUTPUT.G_VOLTAGE.level_151);
	result_2 = (v87_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v87_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.G_Gray) - result_3;
	pSmart->RGB_OUTPUT.G_VOLTAGE.level_87 = result_4;

	LSB = char_to_int(pSmart->MTP.B_OFFSET.OFFSET_87);
	add_mtp = LSB + V87_300CD_B;
	result_1 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->RGB_OUTPUT.B_VOLTAGE.level_151);
	result_2 = (v87_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v87_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.B_Gray) - result_3;
	pSmart->RGB_OUTPUT.B_VOLTAGE.level_87 = result_4;

#ifdef SMART_DIMMING_DEBUG
	pr_info("%s V87 RED:%d GREEN:%d BLUE:%d\n", __func__,
			pSmart->RGB_OUTPUT.R_VOLTAGE.level_87,
			pSmart->RGB_OUTPUT.G_VOLTAGE.level_87,
			pSmart->RGB_OUTPUT.B_VOLTAGE.level_87);
#endif

	return 0;

}

static void v87_hexa(int *index, struct SMART_DIM *pSmart, char *str)
{
	unsigned long long result_1, result_2, result_3;

	result_1 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->GRAY.TABLE[index[V87_INDEX]].R_Gray);
	result_2 = result_1 * v87_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->GRAY.TABLE[index[V151_INDEX]].R_Gray);
	do_div(result_2, result_3);
	str[12] = (result_2  - v87_coefficient) & 0xff;

	result_1 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->GRAY.TABLE[index[V87_INDEX]].G_Gray);
	result_2 = result_1 * v87_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->GRAY.TABLE[index[V151_INDEX]].G_Gray);
	do_div(result_2, result_3);
	str[13] = (result_2  - v87_coefficient) & 0xff;

	result_1 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->GRAY.TABLE[index[V87_INDEX]].B_Gray);
	result_2 = result_1 * v87_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->GRAY.TABLE[index[V151_INDEX]].B_Gray);
	do_div(result_2, result_3);
	str[14] = (result_2  - v87_coefficient) & 0xff;
}

#define v51_coefficient 64
#define v51_denominator 320
static int v51_adjustment(struct SMART_DIM *pSmart)
{
	unsigned long long result_1, result_2, result_3, result_4;
	int add_mtp;
	int LSB;

	LSB = char_to_int(pSmart->MTP.R_OFFSET.OFFSET_51);
	add_mtp = LSB + V51_300CD_R;
	result_1 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->RGB_OUTPUT.R_VOLTAGE.level_87);
	result_2 = (v51_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v51_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.R_Gray) - result_3;
	pSmart->RGB_OUTPUT.R_VOLTAGE.level_51 = result_4;

	LSB = char_to_int(pSmart->MTP.G_OFFSET.OFFSET_51);
	add_mtp = LSB + V51_300CD_G;
	result_1 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->RGB_OUTPUT.G_VOLTAGE.level_87);
	result_2 = (v51_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v51_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.G_Gray) - result_3;
	pSmart->RGB_OUTPUT.G_VOLTAGE.level_51 = result_4;

	LSB = char_to_int(pSmart->MTP.B_OFFSET.OFFSET_51);
	add_mtp = LSB + V51_300CD_B;
	result_1 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->RGB_OUTPUT.B_VOLTAGE.level_87);
	result_2 = (v51_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v51_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.B_Gray) - result_3;
	pSmart->RGB_OUTPUT.B_VOLTAGE.level_51 = result_4;

#ifdef SMART_DIMMING_DEBUG
	pr_info("%s V51 RED:%d GREEN:%d BLUE:%d\n", __func__,
			pSmart->RGB_OUTPUT.R_VOLTAGE.level_51,
			pSmart->RGB_OUTPUT.G_VOLTAGE.level_51,
			pSmart->RGB_OUTPUT.B_VOLTAGE.level_51);
#endif

	return 0;

}

static void v51_hexa(int *index, struct SMART_DIM *pSmart, char *str)
{
	unsigned long long result_1, result_2, result_3;

	result_1 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->GRAY.TABLE[index[V51_INDEX]].R_Gray);
	result_2 = result_1 * v51_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->GRAY.TABLE[index[V87_INDEX]].R_Gray);
	do_div(result_2, result_3);
	str[15] = (result_2  - v51_coefficient) & 0xff;

	result_1 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->GRAY.TABLE[index[V51_INDEX]].G_Gray);
	result_2 = result_1 * v51_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->GRAY.TABLE[index[V87_INDEX]].G_Gray);
	do_div(result_2, result_3);
	str[16] = (result_2  - v51_coefficient) & 0xff;

	result_1 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->GRAY.TABLE[index[V51_INDEX]].B_Gray);
	result_2 = result_1 * v51_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->GRAY.TABLE[index[V87_INDEX]].B_Gray);
	do_div(result_2, result_3);
	str[17] = (result_2  - v51_coefficient) & 0xff;

}

#define v35_coefficient 64
#define v35_denominator 320
static int v35_adjustment(struct SMART_DIM *pSmart)
{
	unsigned long long result_1, result_2, result_3, result_4;
	int add_mtp;
	int LSB;

	LSB = char_to_int(pSmart->MTP.R_OFFSET.OFFSET_35);
	add_mtp = LSB + V35_300CD_R;
	result_1 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->RGB_OUTPUT.R_VOLTAGE.level_51);
	result_2 = (v35_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v35_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.R_Gray) - result_3;
	pSmart->RGB_OUTPUT.R_VOLTAGE.level_35 = result_4;

	LSB = char_to_int(pSmart->MTP.G_OFFSET.OFFSET_35);
	add_mtp = LSB + V35_300CD_G;
	result_1 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->RGB_OUTPUT.G_VOLTAGE.level_51);
	result_2 = (v35_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v35_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.G_Gray) - result_3;
	pSmart->RGB_OUTPUT.G_VOLTAGE.level_35 = result_4;

	LSB = char_to_int(pSmart->MTP.B_OFFSET.OFFSET_35);
	add_mtp = LSB + V35_300CD_B;
	result_1 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->RGB_OUTPUT.B_VOLTAGE.level_51);
	result_2 = (v35_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v35_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.B_Gray) - result_3;
	pSmart->RGB_OUTPUT.B_VOLTAGE.level_35 = result_4;

#ifdef SMART_DIMMING_DEBUG
	pr_info("%s V35 RED:%d GREEN:%d BLUE:%d\n", __func__,
			pSmart->RGB_OUTPUT.R_VOLTAGE.level_35,
			pSmart->RGB_OUTPUT.G_VOLTAGE.level_35,
			pSmart->RGB_OUTPUT.B_VOLTAGE.level_35);
#endif

	return 0;

}

static void v35_hexa(int *index, struct SMART_DIM *pSmart, char *str)
{
	unsigned long long result_1, result_2, result_3;

	result_1 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->GRAY.TABLE[index[V35_INDEX]].R_Gray);
	result_2 = result_1 * v35_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->GRAY.TABLE[index[V51_INDEX]].R_Gray);
	do_div(result_2, result_3);
	str[18] = (result_2  - v35_coefficient) & 0xff;

	result_1 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->GRAY.TABLE[index[V35_INDEX]].G_Gray);
	result_2 = result_1 * v35_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->GRAY.TABLE[index[V51_INDEX]].G_Gray);
	do_div(result_2, result_3);
	str[19] = (result_2  - v35_coefficient) & 0xff;

	result_1 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->GRAY.TABLE[index[V35_INDEX]].B_Gray);
	result_2 = result_1 * v35_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->GRAY.TABLE[index[V51_INDEX]].B_Gray);
	do_div(result_2, result_3);
	str[20] = (result_2  - v35_coefficient) & 0xff;

}

#define v23_coefficient 64
#define v23_denominator 320
static int v23_adjustment(struct SMART_DIM *pSmart)
{
	unsigned long long result_1, result_2, result_3, result_4;
	int add_mtp;
	int LSB;

	LSB = char_to_int(pSmart->MTP.R_OFFSET.OFFSET_23);
	add_mtp = LSB + V23_300CD_R;
	result_1 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->RGB_OUTPUT.R_VOLTAGE.level_35);
	result_2 = (v23_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v23_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.R_Gray) - result_3;
	pSmart->RGB_OUTPUT.R_VOLTAGE.level_23 = result_4;

	LSB = char_to_int(pSmart->MTP.G_OFFSET.OFFSET_23);
	add_mtp = LSB + V23_300CD_G;
	result_1 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->RGB_OUTPUT.G_VOLTAGE.level_35);
	result_2 = (v23_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v23_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.G_Gray) - result_3;
	pSmart->RGB_OUTPUT.G_VOLTAGE.level_23 = result_4;

	LSB = char_to_int(pSmart->MTP.B_OFFSET.OFFSET_23);
	add_mtp = LSB + V23_300CD_B;
	result_1 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->RGB_OUTPUT.B_VOLTAGE.level_35);
	result_2 = (v23_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v23_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.B_Gray) - result_3;
	pSmart->RGB_OUTPUT.B_VOLTAGE.level_23 = result_4;

#ifdef SMART_DIMMING_DEBUG
	pr_info("%s V23 RED:%d GREEN:%d BLUE:%d\n", __func__,
			pSmart->RGB_OUTPUT.R_VOLTAGE.level_23,
			pSmart->RGB_OUTPUT.G_VOLTAGE.level_23,
			pSmart->RGB_OUTPUT.B_VOLTAGE.level_23);
#endif

	return 0;

}

static void v23_hexa(int *index, struct SMART_DIM *pSmart, char *str)
{
	unsigned long long result_1, result_2, result_3;

	result_1 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->GRAY.TABLE[index[V23_INDEX]].R_Gray);
	result_2 = result_1 * v23_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->GRAY.TABLE[index[V35_INDEX]].R_Gray);
	do_div(result_2, result_3);
	str[21] = (result_2  - v23_coefficient) & 0xff;

	result_1 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->GRAY.TABLE[index[V23_INDEX]].G_Gray);
	result_2 = result_1 * v23_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->GRAY.TABLE[index[V35_INDEX]].G_Gray);
	do_div(result_2, result_3);
	str[22] = (result_2  - v23_coefficient) & 0xff;

	result_1 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->GRAY.TABLE[index[V23_INDEX]].B_Gray);
	result_2 = result_1 * v23_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->GRAY.TABLE[index[V35_INDEX]].B_Gray);
	do_div(result_2, result_3);
	str[23] = (result_2  - v23_coefficient) & 0xff;

}

#define v11_coefficient 64
#define v11_denominator 320
static int v11_adjustment(struct SMART_DIM *pSmart)
{
	unsigned long long result_1, result_2, result_3, result_4;
	int add_mtp;
	int LSB;

	LSB = char_to_int(pSmart->MTP.R_OFFSET.OFFSET_11);
	add_mtp = LSB + V11_300CD_R;
	result_1 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->RGB_OUTPUT.R_VOLTAGE.level_23);
	result_2 = (v11_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v11_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.R_Gray) - result_3;
	pSmart->RGB_OUTPUT.R_VOLTAGE.level_11 = result_4;

	LSB = char_to_int(pSmart->MTP.G_OFFSET.OFFSET_11);
	add_mtp = LSB + V11_300CD_G;
	result_1 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->RGB_OUTPUT.G_VOLTAGE.level_23);
	result_2 = (v11_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v11_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.G_Gray) - result_3;
	pSmart->RGB_OUTPUT.G_VOLTAGE.level_11 = result_4;

	LSB = char_to_int(pSmart->MTP.B_OFFSET.OFFSET_11);
	add_mtp = LSB + V11_300CD_B;
	result_1 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->RGB_OUTPUT.B_VOLTAGE.level_23);
	result_2 = (v11_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v11_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->GRAY.VT_TABLE.B_Gray) - result_3;
	pSmart->RGB_OUTPUT.B_VOLTAGE.level_11 = result_4;

#ifdef SMART_DIMMING_DEBUG
	pr_info("%s V11 RED:%d GREEN:%d BLUE:%d\n", __func__,
			pSmart->RGB_OUTPUT.R_VOLTAGE.level_11,
			pSmart->RGB_OUTPUT.G_VOLTAGE.level_11,
			pSmart->RGB_OUTPUT.B_VOLTAGE.level_11);
#endif

	return 0;

}

static void v11_hexa(int *index, struct SMART_DIM *pSmart, char *str)
{
	unsigned long long result_1, result_2, result_3;

	result_1 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->GRAY.TABLE[index[V11_INDEX]].R_Gray);
	result_2 = result_1 * v11_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.R_Gray)
			- (pSmart->GRAY.TABLE[index[V23_INDEX]].R_Gray);
	do_div(result_2, result_3);
	str[24] = (result_2  - v11_coefficient) & 0xff;

	result_1 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->GRAY.TABLE[index[V11_INDEX]].G_Gray);
	result_2 = result_1 * v11_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.G_Gray)
			- (pSmart->GRAY.TABLE[index[V23_INDEX]].G_Gray);
	do_div(result_2, result_3);
	str[25] = (result_2  - v11_coefficient) & 0xff;

	result_1 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->GRAY.TABLE[index[V11_INDEX]].B_Gray);
	result_2 = result_1 * v11_denominator;
	result_3 = (pSmart->GRAY.VT_TABLE.B_Gray)
			- (pSmart->GRAY.TABLE[index[V23_INDEX]].B_Gray);
	do_div(result_2, result_3);
	str[26] = (result_2  - v11_coefficient) & 0xff;

}

#define v3_coefficient 64
#define v3_denominator 320
static int v3_adjustment(struct SMART_DIM *pSmart)
{
	unsigned long long result_1, result_2, result_3, result_4;
	int add_mtp;
	int LSB;

	LSB = char_to_int(pSmart->MTP.R_OFFSET.OFFSET_3);
	add_mtp = LSB + V3_300CD_R;
	result_1 = (pSmart->vregout_voltage)
			- (pSmart->RGB_OUTPUT.R_VOLTAGE.level_11);
	result_2 = (v3_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v3_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->vregout_voltage) - result_3;
	pSmart->RGB_OUTPUT.R_VOLTAGE.level_3 = result_4;

	LSB = char_to_int(pSmart->MTP.G_OFFSET.OFFSET_3);
	add_mtp = LSB + V3_300CD_G;
	result_1 = (pSmart->vregout_voltage)
			- (pSmart->RGB_OUTPUT.G_VOLTAGE.level_11);
	result_2 = (v3_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v3_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->vregout_voltage) - result_3;
	pSmart->RGB_OUTPUT.G_VOLTAGE.level_3 = result_4;

	LSB = char_to_int(pSmart->MTP.B_OFFSET.OFFSET_3);
	add_mtp = LSB + V3_300CD_B;
	result_1 = (pSmart->vregout_voltage)
			- (pSmart->RGB_OUTPUT.B_VOLTAGE.level_11);
	result_2 = (v3_coefficient + add_mtp) << BIT_SHIFT;
	do_div(result_2, v3_denominator);
	result_3 = (result_1 * result_2) >> BIT_SHIFT;
	result_4 = (pSmart->vregout_voltage) - result_3;
	pSmart->RGB_OUTPUT.B_VOLTAGE.level_3 = result_4;

#ifdef SMART_DIMMING_DEBUG
	pr_info("%s V3 RED:%d GREEN:%d BLUE:%d\n", __func__,
			pSmart->RGB_OUTPUT.R_VOLTAGE.level_3,
			pSmart->RGB_OUTPUT.G_VOLTAGE.level_3,
			pSmart->RGB_OUTPUT.B_VOLTAGE.level_3);
#endif

	return 0;

}

static void v3_hexa(int *index, struct SMART_DIM *pSmart, char *str)
{
	unsigned long long result_1, result_2, result_3;

	result_1 = (pSmart->vregout_voltage)
			- (pSmart->GRAY.TABLE[index[V3_INDEX]].R_Gray);
	result_2 = result_1 * v3_denominator;
	result_3 = (pSmart->vregout_voltage)
			- (pSmart->GRAY.TABLE[index[V11_INDEX]].R_Gray);
	do_div(result_2, result_3);
	str[27] = (result_2  - v3_coefficient) & 0xff;

	result_1 = (pSmart->vregout_voltage)
			- (pSmart->GRAY.TABLE[index[V3_INDEX]].G_Gray);
	result_2 = result_1 * v3_denominator;
	result_3 = (pSmart->vregout_voltage)
			- (pSmart->GRAY.TABLE[index[V11_INDEX]].G_Gray);
	do_div(result_2, result_3);
	str[28] = (result_2  - v3_coefficient) & 0xff;

	result_1 = (pSmart->vregout_voltage)
			- (pSmart->GRAY.TABLE[index[V3_INDEX]].B_Gray);
	result_2 = result_1 * v3_denominator;
	result_3 = (pSmart->vregout_voltage)
			- (pSmart->GRAY.TABLE[index[V11_INDEX]].B_Gray);
	do_div(result_2, result_3);
	str[29] = (result_2  - v3_coefficient) & 0xff;

}

static void v0_hexa(int *index, struct SMART_DIM *pSmart, char *str)
{
	str[30] = V0_300CD_R;
	str[31] = V0_300CD_G;
	str[32] = V0_300CD_B;
}

/*V0,V1,V3,V11,V23,V35,V51,V87,V151,V203,V255*/
static int INFLECTION_VOLTAGE_ARRAY[ARRAY_MAX] = {0, 1, 3, 11, 23, 35, 51, 87, 151, 203, 255};

#define V0toV3_Coefficient 2
#define V0toV3_Multiple 1
#define V0toV3_denominator 3

#define V3toV11_Coefficient 7
#define V3toV11_Multiple 1
#define V3toV11_denominator 8

#define V11toV23_Coefficient 11
#define V11toV23_Multiple 1
#define V11toV23_denominator 12

#define V23toV35_Coefficient 11
#define V23toV35_Multiple 1
#define V23toV35_denominator 12

#define V35toV51_Coefficient 15
#define V35toV51_Multiple 1
#define V35toV51_denominator 16

#define V51toV87_Coefficient 35
#define V51toV87_Multiple 1
#define V51toV87_denominator 36

#define V87toV151_Coefficient 63
#define V87toV151_Multiple 1
#define V87toV151_denominator 64

#define V151toV203_Coefficient 51
#define V151toV203_Multiple 1
#define V151toV203_denominator 52

#define V203toV255_Coefficient 51
#define V203toV255_Multiple 1
#define V203toV255_denominator 52

static int cal_gray_scale_linear(int up, int low, int coeff,
int mul, int deno, int cnt)
{
	unsigned long long result_1, result_2, result_3, result_4;

	result_1 = up - low;
	result_2 = (result_1 * (coeff - (cnt * mul))) << BIT_SHIFT;
	do_div(result_2, deno);
	result_3 = result_2 >> BIT_SHIFT;
	result_4 = low + result_3;

	return (int)result_4;
}

static int generate_gray_scale(struct SMART_DIM *pSmart)
{
	int cnt = 0, cal_cnt = 0;
	int array_index = 0;
	struct GRAY_VOLTAGE *ptable = (struct GRAY_VOLTAGE *)
						(&(pSmart->GRAY.TABLE));

	for (cnt = 0; cnt < ARRAY_MAX; cnt++) {
		pSmart->GRAY.TABLE[INFLECTION_VOLTAGE_ARRAY[cnt]].R_Gray =
			((int *)&(pSmart->RGB_OUTPUT.R_VOLTAGE))[cnt];

		pSmart->GRAY.TABLE[INFLECTION_VOLTAGE_ARRAY[cnt]].G_Gray =
			((int *)&(pSmart->RGB_OUTPUT.G_VOLTAGE))[cnt];

		pSmart->GRAY.TABLE[INFLECTION_VOLTAGE_ARRAY[cnt]].B_Gray =
			((int *)&(pSmart->RGB_OUTPUT.B_VOLTAGE))[cnt];
	}

	/*
		below codes use hard coded value.
		So it is possible to modify on each model.
		V0,V1,V3,V11,V23,V35,V51,V87,V151,V203,V255
	*/
	for (cnt = 0; cnt < GRAY_SCALE_MAX; cnt++) {

		if (cnt == INFLECTION_VOLTAGE_ARRAY[0]) {
			/* 0 */
			array_index = 0;
			cal_cnt = 0;
		} else if ((cnt > INFLECTION_VOLTAGE_ARRAY[0]) &&
			(cnt < INFLECTION_VOLTAGE_ARRAY[2])) {
			/* 1 ~ 2 */
			array_index = 2;

			pSmart->GRAY.TABLE[cnt].R_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-2]].R_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].R_Gray,
			V0toV3_Coefficient, V0toV3_Multiple,
			V0toV3_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].G_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-2]].G_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].G_Gray,
			V0toV3_Coefficient, V0toV3_Multiple,
			V0toV3_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].B_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-2]].B_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].B_Gray,
			V0toV3_Coefficient, V0toV3_Multiple,
			V0toV3_denominator , cal_cnt);

			cal_cnt++;
		} else if (cnt == INFLECTION_VOLTAGE_ARRAY[2]) {
			/* 3 */
			cal_cnt = 0;
		} else if ((cnt > INFLECTION_VOLTAGE_ARRAY[2]) &&
			(cnt < INFLECTION_VOLTAGE_ARRAY[3])) {
			/* 4 ~ 10 */
			array_index = 3;

			pSmart->GRAY.TABLE[cnt].R_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].R_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].R_Gray,
			V3toV11_Coefficient, V3toV11_Multiple,
			V3toV11_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].G_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].G_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].G_Gray,
			V3toV11_Coefficient, V3toV11_Multiple,
			V3toV11_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].B_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].B_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].B_Gray,
			V3toV11_Coefficient, V3toV11_Multiple,
			V3toV11_denominator , cal_cnt);

			cal_cnt++;
		} else if (cnt == INFLECTION_VOLTAGE_ARRAY[3]) {
			/* 11 */
			cal_cnt = 0;
		} else if ((cnt > INFLECTION_VOLTAGE_ARRAY[3]) &&
			(cnt < INFLECTION_VOLTAGE_ARRAY[4])) {
			/* 12 ~ 22 */
			array_index = 4;

			pSmart->GRAY.TABLE[cnt].R_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].R_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].R_Gray,
			V11toV23_Coefficient, V11toV23_Multiple,
			V11toV23_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].G_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].G_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].G_Gray,
			V11toV23_Coefficient, V11toV23_Multiple,
			V11toV23_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].B_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].B_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].B_Gray,
			V11toV23_Coefficient, V11toV23_Multiple,
			V11toV23_denominator , cal_cnt);

			cal_cnt++;
		}  else if (cnt == INFLECTION_VOLTAGE_ARRAY[4]) {
			/* 23 */
			cal_cnt = 0;
		} else if ((cnt > INFLECTION_VOLTAGE_ARRAY[4]) &&
			(cnt < INFLECTION_VOLTAGE_ARRAY[5])) {
			/* 24 ~ 34 */
			array_index = 5;

			pSmart->GRAY.TABLE[cnt].R_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].R_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].R_Gray,
			V23toV35_Coefficient, V23toV35_Multiple,
			V23toV35_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].G_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].G_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].G_Gray,
			V23toV35_Coefficient, V23toV35_Multiple,
			V23toV35_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].B_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].B_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].B_Gray,
			V23toV35_Coefficient, V23toV35_Multiple,
			V23toV35_denominator , cal_cnt);

			cal_cnt++;
		} else if (cnt == INFLECTION_VOLTAGE_ARRAY[5]) {
			/* 35 */
			cal_cnt = 0;
		} else if ((cnt > INFLECTION_VOLTAGE_ARRAY[5]) &&
			(cnt < INFLECTION_VOLTAGE_ARRAY[6])) {
			/* 36 ~ 50 */
			array_index = 6;

			pSmart->GRAY.TABLE[cnt].R_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].R_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].R_Gray,
			V35toV51_Coefficient, V35toV51_Multiple,
			V35toV51_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].G_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].G_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].G_Gray,
			V35toV51_Coefficient, V35toV51_Multiple,
			V35toV51_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].B_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].B_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].B_Gray,
			V35toV51_Coefficient, V35toV51_Multiple,
			V35toV51_denominator, cal_cnt);
			cal_cnt++;

		} else if (cnt == INFLECTION_VOLTAGE_ARRAY[6]) {
			/* 51 */
			cal_cnt = 0;
		} else if ((cnt > INFLECTION_VOLTAGE_ARRAY[6]) &&
			(cnt < INFLECTION_VOLTAGE_ARRAY[7])) {
			/* 52 ~ 86 */
			array_index = 7;

			pSmart->GRAY.TABLE[cnt].R_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].R_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].R_Gray,
			V51toV87_Coefficient, V51toV87_Multiple,
			V51toV87_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].G_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].G_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].G_Gray,
			V51toV87_Coefficient, V51toV87_Multiple,
			V51toV87_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].B_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].B_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].B_Gray,
			V51toV87_Coefficient, V51toV87_Multiple,
			V51toV87_denominator, cal_cnt);
			cal_cnt++;

		} else if (cnt == INFLECTION_VOLTAGE_ARRAY[7]) {
			/* 87 */
			cal_cnt = 0;
		} else if ((cnt > INFLECTION_VOLTAGE_ARRAY[7]) &&
			(cnt < INFLECTION_VOLTAGE_ARRAY[8])) {
			/* 88 ~ 150 */
			array_index = 8;

			pSmart->GRAY.TABLE[cnt].R_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].R_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].R_Gray,
			V87toV151_Coefficient, V87toV151_Multiple,
			V87toV151_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].G_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].G_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].G_Gray,
			V87toV151_Coefficient, V87toV151_Multiple,
			V87toV151_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].B_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].B_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].B_Gray,
			V87toV151_Coefficient, V87toV151_Multiple,
			V87toV151_denominator, cal_cnt);

			cal_cnt++;
		} else if (cnt == INFLECTION_VOLTAGE_ARRAY[8]) {
			/* 151 */
			cal_cnt = 0;
		} else if ((cnt > INFLECTION_VOLTAGE_ARRAY[8]) &&
			(cnt < INFLECTION_VOLTAGE_ARRAY[9])) {
			/* 152 ~ 202 */
			array_index = 9;

			pSmart->GRAY.TABLE[cnt].R_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].R_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].R_Gray,
			V151toV203_Coefficient, V151toV203_Multiple,
			V151toV203_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].G_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].G_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].G_Gray,
			V151toV203_Coefficient, V151toV203_Multiple,
			V151toV203_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].B_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].B_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].B_Gray,
			V151toV203_Coefficient, V151toV203_Multiple,
			V151toV203_denominator, cal_cnt);

			cal_cnt++;
		} else if (cnt == INFLECTION_VOLTAGE_ARRAY[9]) {
			/* 203 */
			cal_cnt = 0;
		} else if ((cnt > INFLECTION_VOLTAGE_ARRAY[9]) &&
			(cnt < INFLECTION_VOLTAGE_ARRAY[10])) {
			/* 204 ~ 254 */
			array_index = 10;

			pSmart->GRAY.TABLE[cnt].R_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].R_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].R_Gray,
			V203toV255_Coefficient, V203toV255_Multiple,
			V203toV255_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].G_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].G_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].G_Gray,
			V203toV255_Coefficient, V203toV255_Multiple,
			V203toV255_denominator, cal_cnt);

			pSmart->GRAY.TABLE[cnt].B_Gray = cal_gray_scale_linear(
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index-1]].B_Gray,
			ptable[INFLECTION_VOLTAGE_ARRAY[array_index]].B_Gray,
			V203toV255_Coefficient, V203toV255_Multiple,
			V203toV255_denominator, cal_cnt);

			cal_cnt++;
		 } else {
			if (cnt == INFLECTION_VOLTAGE_ARRAY[10]) {
				pr_debug("%s end\n", __func__);
			} else {
				pr_err("%s fail cnt:%d\n", __func__, cnt);
				return -EINVAL;
			}
		}

	}

#ifdef SMART_DIMMING_DEBUG
		for (cnt = 0; cnt < GRAY_SCALE_MAX; cnt++) {
			pr_info("%s %8d %8d %8d %d\n", __func__,
				pSmart->GRAY.TABLE[cnt].R_Gray,
				pSmart->GRAY.TABLE[cnt].G_Gray,
				pSmart->GRAY.TABLE[cnt].B_Gray, cnt);
		}
#endif
	return 0;
}

static char offset_cal(int offset,  int value)
{
	if (value - offset < 0)
		return 0;
	else if (value - offset > 255)
		return 0xFF;
	else
		return value - offset;
}

static void mtp_offset_substraction(struct SMART_DIM *pSmart, int *str)
{
	int level_255_temp = 0;
	int level_255_temp_MSB = 0;
	int MTP_V255;

	/*subtration MTP_OFFSET value from generated gamma table*/
	level_255_temp = (str[0] << 8) | str[1] ;
	MTP_V255 = char_to_int_v255(pSmart->MTP.R_OFFSET.OFFSET_255_MSB,
				pSmart->MTP.R_OFFSET.OFFSET_255_LSB);
	level_255_temp -=  MTP_V255;
	level_255_temp_MSB = level_255_temp / 256;
	str[0] = level_255_temp_MSB & 0xff;
	str[1] = level_255_temp & 0xff;

	level_255_temp = (str[2] << 8) | str[3] ;
	MTP_V255 = char_to_int_v255(pSmart->MTP.G_OFFSET.OFFSET_255_MSB,
				pSmart->MTP.G_OFFSET.OFFSET_255_LSB);
	level_255_temp -=  MTP_V255;
	level_255_temp_MSB = level_255_temp / 256;
	str[2] = level_255_temp_MSB & 0xff;
	str[3] = level_255_temp & 0xff;

	level_255_temp = (str[4] << 8) | str[5] ;
	MTP_V255 = char_to_int_v255(pSmart->MTP.B_OFFSET.OFFSET_255_MSB,
				pSmart->MTP.B_OFFSET.OFFSET_255_LSB);
	level_255_temp -=  MTP_V255;
	level_255_temp_MSB = level_255_temp / 256;
	str[4] = level_255_temp_MSB & 0xff;
	str[5] = level_255_temp & 0xff;

	str[6] = offset_cal(char_to_int(pSmart->MTP.R_OFFSET.OFFSET_203), str[6]);
	str[7] = offset_cal(char_to_int(pSmart->MTP.G_OFFSET.OFFSET_203), str[7]);
	str[8] = offset_cal(char_to_int(pSmart->MTP.B_OFFSET.OFFSET_203), str[8]);

	str[9] = offset_cal(char_to_int(pSmart->MTP.R_OFFSET.OFFSET_151), str[9]);
	str[10] = offset_cal(char_to_int(pSmart->MTP.G_OFFSET.OFFSET_151), str[10]);
	str[11] = offset_cal(char_to_int(pSmart->MTP.B_OFFSET.OFFSET_151), str[11]);

	str[12] = offset_cal(char_to_int(pSmart->MTP.R_OFFSET.OFFSET_87), str[12]);
	str[13] = offset_cal(char_to_int(pSmart->MTP.G_OFFSET.OFFSET_87), str[13]);
	str[14] = offset_cal(char_to_int(pSmart->MTP.B_OFFSET.OFFSET_87), str[14]);

	str[15] = offset_cal(char_to_int(pSmart->MTP.R_OFFSET.OFFSET_51), str[15]);
	str[16] = offset_cal(char_to_int(pSmart->MTP.G_OFFSET.OFFSET_51), str[16]);
	str[17] = offset_cal(char_to_int(pSmart->MTP.B_OFFSET.OFFSET_51), str[17]);

	str[18] = offset_cal(char_to_int(pSmart->MTP.R_OFFSET.OFFSET_35), str[18]);
	str[19] = offset_cal(char_to_int(pSmart->MTP.G_OFFSET.OFFSET_35), str[19]);
	str[20] = offset_cal(char_to_int(pSmart->MTP.B_OFFSET.OFFSET_35), str[20]);

	str[21] = offset_cal(char_to_int(pSmart->MTP.R_OFFSET.OFFSET_23), str[21]);
	str[22] = offset_cal(char_to_int(pSmart->MTP.G_OFFSET.OFFSET_23), str[22]);
	str[23] = offset_cal(char_to_int(pSmart->MTP.B_OFFSET.OFFSET_23), str[23]);

	str[24] = offset_cal(char_to_int(pSmart->MTP.R_OFFSET.OFFSET_11), str[24]);
	str[25] = offset_cal(char_to_int(pSmart->MTP.G_OFFSET.OFFSET_11), str[25]);
	str[26] = offset_cal(char_to_int(pSmart->MTP.B_OFFSET.OFFSET_11), str[26]);

	str[27] = offset_cal(char_to_int(pSmart->MTP.R_OFFSET.OFFSET_3), str[27]);
	str[28] = offset_cal(char_to_int(pSmart->MTP.G_OFFSET.OFFSET_3), str[28]);
	str[29] = offset_cal(char_to_int(pSmart->MTP.B_OFFSET.OFFSET_3), str[29]);
}

static int searching_function(long long candela, int *index, int gamma_curve)
{
	long long delta_1 = 0, delta_2 = 0;
	int cnt;

	/*
	*	This searching_functin should be changed with improved
		searcing algorithm to reduce searching time.
	*/
	*index = -1;

	for (cnt = 0; cnt < (GRAY_SCALE_MAX-1); cnt++) {
		if (gamma_curve == GAMMA_CURVE_1P9) {
			delta_1 = candela - curve_1p9_360[cnt];
			delta_2 = candela - curve_1p9_360[cnt+1];
		} else if (gamma_curve == GAMMA_CURVE_2P15) {
			delta_1 = candela - curve_2p15_360[cnt];
			delta_2 = candela - curve_2p15_360[cnt+1];
		} else if (gamma_curve == GAMMA_CURVE_2P2) {
			delta_1 = candela - curve_2p2_360[cnt];
			delta_2 = candela - curve_2p2_360[cnt+1];
		} else {
			delta_1 = candela - curve_2p2_360[cnt];
			delta_2 = candela - curve_2p2_360[cnt+1];
		}

		if (delta_2 < 0) {
			*index = (delta_1 + delta_2) <= 0 ? cnt : cnt+1;
			break;
		}

		if (delta_1 == 0) {
			*index = cnt;
			break;
		}

		if (delta_2 == 0) {
			*index = cnt+1;
			break;
		}
	}

	if (*index == -1)
		return -EINVAL;
	else
		return 0;
}


/* -1 means V1 */
#define TABLE_MAX  (ARRAY_MAX-1)
static void(*Make_hexa[TABLE_MAX+1])(int*, struct SMART_DIM*, char*) = {
	v255_hexa,
	v203_hexa,
	v151_hexa,
	v87_hexa,
	v51_hexa,
	v35_hexa,
	v23_hexa,
	v11_hexa,
	v3_hexa,
	v0_hexa,
	vt_hexa,
};

#if defined(AID_OPERATION)
static int find_cadela_table(int brightness)
{
	int loop;
	int err = -1;

	for(loop = 0; loop <= CANDELA_MAX_TABLE; loop++)
		if (candela_table[loop][0] == brightness)
			return candela_table[loop][1];

	return err;
}

static void gamma_init_revA(struct SMART_DIM *pSmart, char *str, int size)
{
	long long candela_level[TABLE_MAX] = {-1, };
	int bl_index[TABLE_MAX] = {-1, };
	int gamma_setting[GAMMA_SET_MAX];

	long long temp_cal_data = 0;
	int bl_level = 0;

	int level_255_temp_MSB = 0;
	int level_V255 = 0;

	int point_index;
	int cnt;
	int table_index;

	pr_info_once("%s : start !!\n",__func__);

	/*calculate candela level */
	if ((pSmart->brightness_level <= 350) &&
		(pSmart->brightness_level >= 249)) {
		/* 265CD ~ 350CD */
		if (pSmart->brightness_level == 350)
			bl_level = 350;
		else if (pSmart->brightness_level == 333)
			bl_level = 337;
		else if (pSmart->brightness_level == 316)
			bl_level = 320;
		else if (pSmart->brightness_level == 300)
			bl_level = 303;
		else if (pSmart->brightness_level == 282)
			bl_level = 286;
		else if (pSmart->brightness_level == 265)
			bl_level = 269;
		else if (pSmart->brightness_level == 249)
			bl_level = 252;
	} else if ((pSmart->brightness_level < 249) &&
				(pSmart->brightness_level >= 183)) {
		/* 183CD ~ 249CD */
		bl_level = 249;
	} else if ((pSmart->brightness_level < 183) &&
				(pSmart->brightness_level >= 72)) {
		/* 77CD ~ 172CD */
		if (pSmart->brightness_level == 72)
			bl_level = 108;
		else if (pSmart->brightness_level == 77)
			bl_level = 116;
		else if (pSmart->brightness_level == 82)
			bl_level = 122;
		else if (pSmart->brightness_level == 87)
			bl_level = 130;
		else if (pSmart->brightness_level == 93)
			bl_level = 138;
		else if (pSmart->brightness_level == 98)
			bl_level = 144;
		else if (pSmart->brightness_level == 105)
			bl_level = 153;
		else if (pSmart->brightness_level == 111)
			bl_level = 160;
		else if (pSmart->brightness_level == 119)
			bl_level = 173;
		else if (pSmart->brightness_level == 126)
			bl_level = 181;
		else if (pSmart->brightness_level == 134)
			bl_level = 191;
		else if (pSmart->brightness_level == 143)
			bl_level = 202;
		else if (pSmart->brightness_level == 152)
			bl_level = 214;
		else if (pSmart->brightness_level == 162)
			bl_level = 227;
		else if (pSmart->brightness_level == 172)
			bl_level = 240;
	} else {
		/* 68CD ~ 2CD */
		bl_level = AOR_DIM_BASE_CD_REVA;
	}

	if (pSmart->brightness_level < 350) {
		for (cnt = 0; cnt < TABLE_MAX; cnt++) {
			point_index = INFLECTION_VOLTAGE_ARRAY[cnt+1];
			temp_cal_data =
			((long long)(candela_coeff_2p15[point_index])) *
			((long long)(bl_level));
			candela_level[cnt] = temp_cal_data;
		}

	} else {
		for (cnt = 0; cnt < TABLE_MAX; cnt++) {
			point_index = INFLECTION_VOLTAGE_ARRAY[cnt+1];
			temp_cal_data =
			((long long)(candela_coeff_2p2[point_index])) *
			((long long)(bl_level));
			candela_level[cnt] = temp_cal_data;
		}

	}

#ifdef SMART_DIMMING_DEBUG
	printk(KERN_INFO "\n candela_1:%llu  candela_3:%llu  candela_11:%llu ",
		candela_level[0], candela_level[1], candela_level[2]);
	printk(KERN_INFO "candela_23:%llu  candela_35:%llu  candela_51:%llu ",
		candela_level[3], candela_level[4], candela_level[5]);
	printk(KERN_INFO "candela_87:%llu  candela_151:%llu  candela_203:%llu ",
		candela_level[6], candela_level[7], candela_level[8]);
	printk(KERN_INFO "candela_255:%llu brightness_level %d\n", candela_level[9], pSmart->brightness_level);
#endif

	for (cnt = 0; cnt < TABLE_MAX; cnt++) {
		if (searching_function(candela_level[cnt],
			&(bl_index[cnt]), GAMMA_CURVE_2P2)) {
			pr_info("%s searching functioin error cnt:%d\n",
			__func__, cnt);
		}
	}

	/*
	*	Candela compensation
	*/
	for (cnt = 1; cnt < TABLE_MAX; cnt++) {
		table_index = find_cadela_table(pSmart->brightness_level);

		if (table_index == -1) {
			table_index = CANDELA_MAX_TABLE;
			pr_info("%s fail candela table_index cnt : %d brightness %d",
				__func__, cnt, pSmart->brightness_level);
		}

		bl_index[TABLE_MAX - cnt] +=
			gradation_offset_revA[table_index][cnt - 1];

		/* THERE IS M-GRAY0 target */
		if (bl_index[TABLE_MAX - cnt] == 0)
			bl_index[TABLE_MAX - cnt] = 1;
	}

#ifdef SMART_DIMMING_DEBUG
	printk(KERN_INFO "\n bl_index_1:%d  bl_index_3:%d  bl_index_11:%d",
		bl_index[0], bl_index[1], bl_index[2]);
	printk(KERN_INFO "bl_index_23:%d bl_index_35:%d  bl_index_51:%d",
		bl_index[3], bl_index[4], bl_index[5]);
	printk(KERN_INFO "bl_index_87:%d  bl_index_151:%d bl_index_203:%d",
		bl_index[6], bl_index[7], bl_index[8]);
	printk(KERN_INFO "bl_index_255:%d\n", bl_index[9]);
#endif
	/*Generate Gamma table*/
	for (cnt = 0; cnt < TABLE_MAX; cnt++)
		(void)Make_hexa[cnt](bl_index , pSmart, str);

	/* To avoid overflow */
	for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
		gamma_setting[cnt] = str[cnt];

	/*
	*	RGB compensation
	*/
	for (cnt = 0; cnt < RGB_COMPENSATION; cnt++) {
		table_index = find_cadela_table(pSmart->brightness_level);

		if (table_index == -1) {
			table_index = CANDELA_MAX_TABLE;
			pr_info("%s fail RGB table_index cnt : %d brightness %d",
				__func__, cnt, pSmart->brightness_level);
		}

		if (cnt < 3) {
			level_V255 = gamma_setting[cnt * 2] << 8 | gamma_setting[(cnt * 2) + 1];
			level_V255 +=
				rgb_offset_revA[table_index][cnt];
			level_255_temp_MSB = level_V255 / 256;

			gamma_setting[cnt * 2] = level_255_temp_MSB & 0xff;
			gamma_setting[(cnt * 2) + 1] = level_V255 & 0xff;
		} else {
			gamma_setting[cnt+3] += rgb_offset_revA[table_index][cnt];
		}
	}
	/*subtration MTP_OFFSET value from generated gamma table*/
	mtp_offset_substraction(pSmart, gamma_setting);

	/* To avoid overflow */
	for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
		str[cnt] = gamma_setting[cnt];
}

static void gamma_init_revD(struct SMART_DIM *pSmart, char *str, int size)
{
	long long candela_level[TABLE_MAX] = {-1, };
	int bl_index[TABLE_MAX] = {-1, };
	int gamma_setting[GAMMA_SET_MAX];

	long long temp_cal_data = 0;
	int bl_level = 0;

	int level_255_temp_MSB = 0;
	int level_V255 = 0;

	int point_index;
	int cnt;
	int table_index;

	pr_info_once("%s : start !!\n",__func__);

	/*calculate candela level */
	if ((pSmart->brightness_level <= 350) &&
		(pSmart->brightness_level >= 265)) {
		/* 265CD ~ 350CD */
		if (pSmart->brightness_level == 350)
			bl_level = 350;
		else if (pSmart->brightness_level == 333)
			bl_level = 334;
		else if (pSmart->brightness_level == 316)
			bl_level = 315;
		else if (pSmart->brightness_level == 300)
			bl_level = 300;
		else if (pSmart->brightness_level == 282)
			bl_level = 283;
		else if (pSmart->brightness_level == 265)
			bl_level = 268;
		else if (pSmart->brightness_level == 249)
			bl_level = 252;
	} else if ((pSmart->brightness_level < 265) &&
		(pSmart->brightness_level >= 183)) {
		/* 183CD ~ 265CD */
		bl_level = 252;
	} else if ((pSmart->brightness_level < 183) &&
				(pSmart->brightness_level > 77)) {
		/* 82CD ~ 172CD */
		if (pSmart->brightness_level == 82)
			bl_level = 120;
		else if (pSmart->brightness_level == 87)
			bl_level = 129;
		else if (pSmart->brightness_level == 93)
			bl_level = 137;
		else if (pSmart->brightness_level == 98)
			bl_level = 143;
		else if (pSmart->brightness_level == 105)
			bl_level = 153;
		else if (pSmart->brightness_level == 111)
			bl_level = 162;
		else if (pSmart->brightness_level == 119)
			bl_level = 171;
		else if (pSmart->brightness_level == 126)
			bl_level = 179;
		else if (pSmart->brightness_level == 134)
			bl_level = 190;
		else if (pSmart->brightness_level == 143)
			bl_level = 202;
		else if (pSmart->brightness_level == 152)
			bl_level = 213;
		else if (pSmart->brightness_level == 162)
			bl_level = 228;
		else if (pSmart->brightness_level == 172)
			bl_level = 238;
	} else {
		/* 77CD ~ 2CD */
		bl_level = AOR_DIM_BASE_CD_REVD;
	}

	if (pSmart->brightness_level < 350) {
		for (cnt = 0; cnt < TABLE_MAX; cnt++) {
			point_index = INFLECTION_VOLTAGE_ARRAY[cnt+1];
			temp_cal_data =
			((long long)(candela_coeff_2p15[point_index])) *
			((long long)(bl_level));
			candela_level[cnt] = temp_cal_data;
		}

	} else {
		for (cnt = 0; cnt <TABLE_MAX; cnt++) {
			point_index = INFLECTION_VOLTAGE_ARRAY[cnt+1];
			temp_cal_data =
			((long long)(candela_coeff_2p2[point_index])) *
			((long long)(bl_level));
			candela_level[cnt] = temp_cal_data;
		}

	}

#ifdef SMART_DIMMING_DEBUG
	printk(KERN_INFO "\n candela_1:%llu  candela_3:%llu  candela_11:%llu ",
		candela_level[0], candela_level[1], candela_level[2]);
	printk(KERN_INFO "candela_23:%llu  candela_35:%llu  candela_51:%llu ",
		candela_level[3], candela_level[4], candela_level[5]);
	printk(KERN_INFO "candela_87:%llu  candela_151:%llu  candela_203:%llu ",
		candela_level[6], candela_level[7], candela_level[8]);
	printk(KERN_INFO "candela_255:%llu brightness_level %d\n", candela_level[9], pSmart->brightness_level);
#endif

	for (cnt = 0; cnt < TABLE_MAX; cnt++) {
		if (searching_function(candela_level[cnt],
//			if (searching_function(candela_level[cnt],
			&(bl_index[cnt]), GAMMA_CURVE_2P2)) {
			pr_info("%s searching functioin error cnt:%d\n",
			__func__, cnt);
		}
	}

	/*
	*	Candela compensation
	*/
	for (cnt = 1; cnt < TABLE_MAX; cnt++) {
		table_index = find_cadela_table(pSmart->brightness_level);

		if (table_index == -1) {
			table_index = CANDELA_MAX_TABLE;
			pr_info("%s fail candela table_index cnt : %d brightness %d",
				__func__, cnt, pSmart->brightness_level);
		}

		bl_index[TABLE_MAX - cnt] +=
			gradation_offset_revD[table_index][cnt - 1];

		/* THERE IS M-GRAY0 target */
		if (bl_index[TABLE_MAX - cnt] == 0)
			bl_index[TABLE_MAX - cnt] = 1;
	}

#ifdef SMART_DIMMING_DEBUG
	printk(KERN_INFO "\n bl_index_1:%d  bl_index_3:%d  bl_index_11:%d",
		bl_index[0], bl_index[1], bl_index[2]);
	printk(KERN_INFO "bl_index_23:%d bl_index_35:%d  bl_index_51:%d",
		bl_index[3], bl_index[4], bl_index[5]);
	printk(KERN_INFO "bl_index_87:%d  bl_index_151:%d bl_index_203:%d",
		bl_index[6], bl_index[7], bl_index[8]);
	printk(KERN_INFO "bl_index_255:%d\n", bl_index[9]);
#endif
	/*Generate Gamma table*/
	for (cnt = 0; cnt < TABLE_MAX; cnt++)
		(void)Make_hexa[cnt](bl_index , pSmart, str);

	/* To avoid overflow */
	for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
		gamma_setting[cnt] = str[cnt];

	/*
	*	RGB compensation
	*/
	for (cnt = 0; cnt < RGB_COMPENSATION; cnt++) {
		table_index = find_cadela_table(pSmart->brightness_level);

		if (table_index == -1) {
			table_index = CANDELA_MAX_TABLE;
			pr_info("%s fail RGB table_index cnt : %d brightness %d",
				__func__, cnt, pSmart->brightness_level);
		}

		if (cnt < 3) {
			level_V255 = gamma_setting[cnt * 2] << 8 | gamma_setting[(cnt * 2) + 1];
			level_V255 +=
				rgb_offset_revD[table_index][cnt];
			level_255_temp_MSB = level_V255 / 256;

			gamma_setting[cnt * 2] = level_255_temp_MSB & 0xff;
			gamma_setting[(cnt * 2) + 1] = level_V255 & 0xff;
		} else {
			gamma_setting[cnt+3] += rgb_offset_revD[table_index][cnt];
		}
	}
	/*subtration MTP_OFFSET value from generated gamma table*/
	mtp_offset_substraction(pSmart, gamma_setting);

	/* To avoid overflow */
	for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
		str[cnt] = gamma_setting[cnt];
}

static void gamma_init_revE(struct SMART_DIM *pSmart, char *str, int size)
{
	long long candela_level[TABLE_MAX] = {-1, };
	int bl_index[TABLE_MAX] = {-1, };
	int gamma_setting[GAMMA_SET_MAX];

	long long temp_cal_data = 0;
	int bl_level = 0;

	int level_255_temp_MSB = 0;
	int level_V255 = 0;

	int point_index;
	int cnt;
	int table_index;

	pr_info_once("%s : start !!\n",__func__);

	/*calculate candela level */
	if ((pSmart->brightness_level <= 350) &&
		(pSmart->brightness_level >= 265)) {
		/* 265CD ~ 350CD */
		if (pSmart->brightness_level == 350)
			bl_level = 350;
		else if (pSmart->brightness_level == 333)
			bl_level = 334;
		else if (pSmart->brightness_level == 316)
			bl_level = 315;
		else if (pSmart->brightness_level == 300)
			bl_level = 300;
		else if (pSmart->brightness_level == 282)
			bl_level = 283;
		else if (pSmart->brightness_level == 265)
			bl_level = 268;
		else if (pSmart->brightness_level == 249)
			bl_level = 252;
	} else if ((pSmart->brightness_level < 265) &&
		(pSmart->brightness_level >= 183)) {
		/* 183CD ~ 265CD */
		bl_level = 252;
	} else if ((pSmart->brightness_level < 183) &&
				(pSmart->brightness_level > 77)) {
		/* 82CD ~ 172CD */
		if (pSmart->brightness_level == 82)
			bl_level = 120;
		else if (pSmart->brightness_level == 87)
			bl_level = 129;
		else if (pSmart->brightness_level == 93)
			bl_level = 137;
		else if (pSmart->brightness_level == 98)
			bl_level = 143;
		else if (pSmart->brightness_level == 105)
			bl_level = 153;
		else if (pSmart->brightness_level == 111)
			bl_level = 162;
		else if (pSmart->brightness_level == 119)
			bl_level = 171;
		else if (pSmart->brightness_level == 126)
			bl_level = 179;
		else if (pSmart->brightness_level == 134)
			bl_level = 190;
		else if (pSmart->brightness_level == 143)
			bl_level = 202;
		else if (pSmart->brightness_level == 152)
			bl_level = 213;
		else if (pSmart->brightness_level == 162)
			bl_level = 228;
		else if (pSmart->brightness_level == 172)
			bl_level = 238;
	} else {
		/* 77CD ~ 2CD */
		bl_level = AOR_DIM_BASE_CD_REVD;
	}

	if (pSmart->brightness_level < 350) {
		for (cnt = 0; cnt < TABLE_MAX; cnt++) {
			point_index = INFLECTION_VOLTAGE_ARRAY[cnt+1];
			temp_cal_data =
			((long long)(candela_coeff_2p15[point_index])) *
			((long long)(bl_level));
			candela_level[cnt] = temp_cal_data;
		}

	} else {
		for (cnt = 0; cnt < TABLE_MAX; cnt++) {
			point_index = INFLECTION_VOLTAGE_ARRAY[cnt+1];
			temp_cal_data =
			((long long)(candela_coeff_2p2[point_index])) *
			((long long)(bl_level));
			candela_level[cnt] = temp_cal_data;
		}

	}

#ifdef SMART_DIMMING_DEBUG
	printk(KERN_INFO "\n candela_1:%llu  candela_3:%llu  candela_11:%llu ",
		candela_level[0], candela_level[1], candela_level[2]);
	printk(KERN_INFO "candela_23:%llu  candela_35:%llu  candela_51:%llu ",
		candela_level[3], candela_level[4], candela_level[5]);
	printk(KERN_INFO "candela_87:%llu  candela_151:%llu  candela_203:%llu ",
		candela_level[6], candela_level[7], candela_level[8]);
	printk(KERN_INFO "candela_255:%llu brightness_level %d\n", candela_level[9], pSmart->brightness_level);
#endif

	for (cnt = 0; cnt < TABLE_MAX; cnt++) {
		if (searching_function(candela_level[cnt],
//			if (searching_function(candela_level[cnt],
			&(bl_index[cnt]), GAMMA_CURVE_2P2)) {
			pr_info("%s searching functioin error cnt:%d\n",
			__func__, cnt);
		}
	}

	/*
	*	Candela compensation
	*/
	for (cnt = 1; cnt < TABLE_MAX; cnt++) {
		table_index = find_cadela_table(pSmart->brightness_level);

		if (table_index == -1) {
			table_index = CANDELA_MAX_TABLE;
			pr_info("%s fail candela table_index cnt : %d brightness %d",
				__func__, cnt, pSmart->brightness_level);
		}

		bl_index[TABLE_MAX - cnt] +=
			gradation_offset_revE[table_index][cnt - 1];

		/* THERE IS M-GRAY0 target */
		if (bl_index[TABLE_MAX - cnt] == 0)
			bl_index[TABLE_MAX - cnt] = 1;
	}

#ifdef SMART_DIMMING_DEBUG
	printk(KERN_INFO "\n bl_index_1:%d  bl_index_3:%d  bl_index_11:%d",
		bl_index[0], bl_index[1], bl_index[2]);
	printk(KERN_INFO "bl_index_23:%d bl_index_35:%d  bl_index_51:%d",
		bl_index[3], bl_index[4], bl_index[5]);
	printk(KERN_INFO "bl_index_87:%d  bl_index_151:%d bl_index_203:%d",
		bl_index[6], bl_index[7], bl_index[8]);
	printk(KERN_INFO "bl_index_255:%d\n", bl_index[9]);
#endif
	/*Generate Gamma table*/
	for (cnt = 0; cnt < TABLE_MAX; cnt++)
		(void)Make_hexa[cnt](bl_index , pSmart, str);

	/* To avoid overflow */
	for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
		gamma_setting[cnt] = str[cnt];

	/*
	*	RGB compensation
	*/
	for (cnt = 0; cnt < RGB_COMPENSATION; cnt++) {
		table_index = find_cadela_table(pSmart->brightness_level);

		if (table_index == -1) {
			table_index = CANDELA_MAX_TABLE;
			pr_info("%s fail RGB table_index cnt : %d brightness %d",
				__func__, cnt, pSmart->brightness_level);
		}

		if (cnt < 3) {
			level_V255 = gamma_setting[cnt * 2] << 8 | gamma_setting[(cnt * 2) + 1];
			level_V255 +=
				rgb_offset_revE[table_index][cnt];
			level_255_temp_MSB = level_V255 / 256;

			gamma_setting[cnt * 2] = level_255_temp_MSB & 0xff;
			gamma_setting[(cnt * 2) + 1] = level_V255 & 0xff;
		} else {
			gamma_setting[cnt+3] += rgb_offset_revE[table_index][cnt];
		}
	}
	/*subtration MTP_OFFSET value from generated gamma table*/
	mtp_offset_substraction(pSmart, gamma_setting);

	/* To avoid overflow */
	for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
		str[cnt] = gamma_setting[cnt];
}

static void gamma_init_YM4(struct SMART_DIM *pSmart, char *str, int size)
{
	long long candela_level[TABLE_MAX] = {-1, };
	int bl_index[TABLE_MAX] = {-1, };
	int gamma_setting[GAMMA_SET_MAX];

	long long temp_cal_data = 0;
	int bl_level = 0;

	int level_255_temp_MSB = 0;
	int level_V255 = 0;

	int point_index;
	int cnt;
	int table_index;

	pr_info_once("%s : start !!\n",__func__);

	/*calculate candela level */
	if ((pSmart->brightness_level <= 350) &&
		(pSmart->brightness_level >= 265)) {
		/* 265CD ~ 350CD */
		if (pSmart->brightness_level == 350)
			bl_level = 350;
		else if (pSmart->brightness_level == 333)
			bl_level = 336;
		else if (pSmart->brightness_level == 316)
			bl_level = 318;
		else if (pSmart->brightness_level == 300)
			bl_level = 304;
		else if (pSmart->brightness_level == 282)
			bl_level = 283;
		else if (pSmart->brightness_level == 265)
			bl_level = 269;
	} else if ((pSmart->brightness_level < 265) &&
				(pSmart->brightness_level >= 183)) {
		/* 183CD ~ 265CD */
		bl_level = 252;
	} else if ((pSmart->brightness_level < 183) &&
				(pSmart->brightness_level >= 82)) {
		/* 82CD ~ 183CD */
		if (pSmart->brightness_level == 82)
			bl_level = 120;
		else if (pSmart->brightness_level == 87)
			bl_level = 127;
		else if (pSmart->brightness_level == 93)
			bl_level = 135;
		else if (pSmart->brightness_level == 98)
			bl_level = 142;
		else if (pSmart->brightness_level == 105)
			bl_level = 151;
		else if (pSmart->brightness_level == 111)
			bl_level = 160;
		else if (pSmart->brightness_level == 119)
			bl_level = 171;
		else if (pSmart->brightness_level == 126)
			bl_level = 182;
		else if (pSmart->brightness_level == 134)
			bl_level = 189;
		else if (pSmart->brightness_level == 143)
			bl_level = 201;
		else if (pSmart->brightness_level == 152)
			bl_level = 215;
		else if (pSmart->brightness_level == 162)
			bl_level = 224;
		else if (pSmart->brightness_level == 172)
			bl_level = 239;
	} else {
		/* 77CD ~ 2CD */
		bl_level = AOR_DIM_BASE_CD_REVB;
	}

	if (pSmart->brightness_level < 350) {
		for (cnt = 0; cnt < TABLE_MAX; cnt++) {
			point_index = INFLECTION_VOLTAGE_ARRAY[cnt+1];
			temp_cal_data =
			((long long)(candela_coeff_2p15[point_index])) *
			((long long)(bl_level));
			candela_level[cnt] = temp_cal_data;
		}

	} else {
		for (cnt = 0; cnt < TABLE_MAX; cnt++) {
			point_index = INFLECTION_VOLTAGE_ARRAY[cnt+1];
			temp_cal_data =
			((long long)(candela_coeff_2p2[point_index])) *
			((long long)(bl_level));
			candela_level[cnt] = temp_cal_data;
		}

	}

#ifdef SMART_DIMMING_DEBUG
	printk(KERN_INFO "\n candela_1:%llu  candela_3:%llu  candela_11:%llu ",
		candela_level[0], candela_level[1], candela_level[2]);
	printk(KERN_INFO "candela_23:%llu  candela_35:%llu  candela_51:%llu ",
		candela_level[3], candela_level[4], candela_level[5]);
	printk(KERN_INFO "candela_87:%llu  candela_151:%llu  candela_203:%llu ",
		candela_level[6], candela_level[7], candela_level[8]);
	printk(KERN_INFO "candela_255:%llu brightness_level %d\n", candela_level[9], pSmart->brightness_level);
#endif

	for (cnt = 0; cnt < TABLE_MAX; cnt++) {
		if (searching_function(candela_level[cnt],
			&(bl_index[cnt]), GAMMA_CURVE_2P2)) {
			pr_info("%s searching functioin error cnt:%d\n",
			__func__, cnt);
		}
	}

	/*
	*	Candela compensation
	*/
	for (cnt = 1; cnt < TABLE_MAX; cnt++) {
		table_index = find_cadela_table(pSmart->brightness_level);

		if (table_index == -1) {
			table_index = CANDELA_MAX_TABLE;
			pr_info("%s fail candela table_index cnt : %d brightness %d",
				__func__, cnt, pSmart->brightness_level);
		}

		bl_index[TABLE_MAX - cnt] +=
			gradation_offset_ym4[table_index][cnt - 1];

		/* THERE IS M-GRAY0 target */
		if (bl_index[TABLE_MAX - cnt] == 0)
			bl_index[TABLE_MAX - cnt] = 1;
	}

#ifdef SMART_DIMMING_DEBUG
	printk(KERN_INFO "\n bl_index_1:%d  bl_index_3:%d  bl_index_11:%d",
		bl_index[0], bl_index[1], bl_index[2]);
	printk(KERN_INFO "bl_index_23:%d bl_index_35:%d  bl_index_51:%d",
		bl_index[3], bl_index[4], bl_index[5]);
	printk(KERN_INFO "bl_index_87:%d  bl_index_151:%d bl_index_203:%d",
		bl_index[6], bl_index[7], bl_index[8]);
	printk(KERN_INFO "bl_index_255:%d\n", bl_index[9]);
#endif
	/*Generate Gamma table*/
	for (cnt = 0; cnt < TABLE_MAX; cnt++)
		(void)Make_hexa[cnt](bl_index , pSmart, str);

	/* To avoid overflow */
	for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
		gamma_setting[cnt] = str[cnt];

	/*
	*	RGB compensation
	*/
	for (cnt = 0; cnt < RGB_COMPENSATION; cnt++) {
		table_index = find_cadela_table(pSmart->brightness_level);

		if (table_index == -1) {
			table_index = CANDELA_MAX_TABLE;
			pr_info("%s fail RGB table_index cnt : %d brightness %d",
				__func__, cnt, pSmart->brightness_level);
		}

		if (cnt < 3) {
			level_V255 = gamma_setting[cnt * 2] << 8 | gamma_setting[(cnt * 2) + 1];
			level_V255 +=
				rgb_offset_ym4[table_index][cnt];
			level_255_temp_MSB = level_V255 / 256;

			gamma_setting[cnt * 2] = level_255_temp_MSB & 0xff;
			gamma_setting[(cnt * 2) + 1] = level_V255 & 0xff;
		} else {
			gamma_setting[cnt+3] += rgb_offset_ym4[table_index][cnt];
		}
	}
	/*subtration MTP_OFFSET value from generated gamma table*/
	mtp_offset_substraction(pSmart, gamma_setting);

	/* To avoid overflow */
	for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
		str[cnt] = gamma_setting[cnt];
}


#endif

static void pure_gamma_init(struct SMART_DIM *pSmart, char *str, int size)
{
	long long candela_level[TABLE_MAX] = {-1, };
	int bl_index[TABLE_MAX] = {-1, };
	int gamma_setting[GAMMA_SET_MAX];

	long long temp_cal_data = 0;
	int bl_level, cnt;
	int point_index;

	bl_level = pSmart->brightness_level;

	for (cnt = 0; cnt < TABLE_MAX; cnt++) {
			point_index = INFLECTION_VOLTAGE_ARRAY[cnt+1];
			temp_cal_data =
			((long long)(candela_coeff_2p2[point_index])) *
			((long long)(bl_level));
			candela_level[cnt] = temp_cal_data;
	}

#ifdef SMART_DIMMING_DEBUG
	pr_info("\n candela_1:%llu  candela_3:%llu  candela_11:%llu \n"
		"candela_23:%llu  candela_35:%llu  candela_51:%llu \n"
		"candela_87:%llu  candela_151:%llu  candela_203:%llu \n"
		"candela_255:%llu brightness_level %d \n",
		candela_level[0], candela_level[1], candela_level[2],
		candela_level[3], candela_level[4], candela_level[5],
		candela_level[6], candela_level[7], candela_level[8],
		candela_level[9], pSmart->brightness_level);
#endif

	/*calculate brightness level*/
	for (cnt = 0; cnt < TABLE_MAX; cnt++) {
			if (searching_function(candela_level[cnt],
				&(bl_index[cnt]), GAMMA_CURVE_2P2)) {
				pr_info("%s searching functioin error cnt:%d\n",
					__func__, cnt);
			}
	}

	/*
	*	210CD ~ 190CD compensation
	*	V3 level + 1
	*/
	if ((bl_level >= 190) && (bl_level <= 210))
		bl_index[1] += 1;

#ifdef SMART_DIMMING_DEBUG
	pr_info("\n bl_index_1:%d  bl_index_3:%d  bl_index_11:%d \n"
		"bl_index_23:%d bl_index_35:%d  bl_index_51:%d \n"
		"bl_index_87:%d  bl_index_151:%d bl_index_203:%d \n"
		"bl_index_255:%d brightness_level %d \n",
		bl_index[0], bl_index[1], bl_index[2],
		bl_index[3], bl_index[4], bl_index[5],
		bl_index[6], bl_index[7], bl_index[8],
		bl_index[9], pSmart->brightness_level);
#endif

	/*Generate Gamma table*/
	for (cnt = 0; cnt < TABLE_MAX; cnt++)
		(void)Make_hexa[cnt](bl_index , pSmart, str);

	/* To avoid overflow */
	for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
		gamma_setting[cnt] = str[cnt];

	mtp_offset_substraction(pSmart, gamma_setting);

	/* To avoid overflow */
	for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
		str[cnt] = gamma_setting[cnt];
}

static void set_max_lux_table(void)
{
	max_lux_table[0] = V255_300CD_R_MSB;
	max_lux_table[1] = V255_300CD_R_LSB;

	max_lux_table[2] = V255_300CD_G_MSB;
	max_lux_table[3] = V255_300CD_G_LSB;

	max_lux_table[4] = V255_300CD_B_MSB;
	max_lux_table[5] = V255_300CD_B_LSB;

	max_lux_table[6] = V203_300CD_R;
	max_lux_table[7] = V203_300CD_G;
	max_lux_table[8] = V203_300CD_B;

	max_lux_table[9] = V151_300CD_R;
	max_lux_table[10] = V151_300CD_G;
	max_lux_table[11] = V151_300CD_B;

	max_lux_table[12] = V87_300CD_R;
	max_lux_table[13] = V87_300CD_G;
	max_lux_table[14] = V87_300CD_B;

	max_lux_table[15] = V51_300CD_R;
	max_lux_table[16] = V51_300CD_G;
	max_lux_table[17] = V51_300CD_B;

	max_lux_table[18] = V35_300CD_R;
	max_lux_table[19] = V35_300CD_G;
	max_lux_table[20] = V35_300CD_B;

	max_lux_table[21] = V23_300CD_R;
	max_lux_table[22] = V23_300CD_G;
	max_lux_table[23] = V23_300CD_B;

	max_lux_table[24] = V11_300CD_R;
	max_lux_table[25] = V11_300CD_G;
	max_lux_table[26] = V11_300CD_B;

	max_lux_table[27] = V3_300CD_R;
	max_lux_table[28] = V3_300CD_G;
	max_lux_table[29] = V3_300CD_B;

	max_lux_table[30] = V0_300CD_R;
	max_lux_table[31] = V0_300CD_G;
	max_lux_table[32] = V0_300CD_B;

	max_lux_table[33] = (VT_300CD_G << 4) | VT_300CD_R;
	max_lux_table[34] = VT_300CD_B;

}

static void set_min_lux_table(struct SMART_DIM *psmart)
{
	psmart->brightness_level = MIN_CANDELA;
	pure_gamma_init(psmart, min_lux_table, GAMMA_SET_MAX);
}

static void get_min_lux_table(char *str, int size)
{
	memcpy(str, min_lux_table, size);
}

static void generate_gamma(struct SMART_DIM *psmart, char *str, int size)
{
	int lux_loop;
	struct illuminance_table *ptable = (struct illuminance_table *)
						(&(psmart->gen_table));

	/* searching already generated gamma table */
	for (lux_loop = 0; lux_loop < psmart->lux_table_max; lux_loop++) {
		if (ptable[lux_loop].lux == psmart->brightness_level) {
			memcpy(str, &(ptable[lux_loop].gamma_setting), size);
			break;
		}
	}

	/* searching fail... Setting 300CD value on gamma table */
	if (lux_loop == psmart->lux_table_max) {
		pr_info("%s searching fail lux : %d\n", __func__,
				psmart->brightness_level);
		memcpy(str, max_lux_table, size);
	}

#ifdef SMART_DIMMING_DEBUG
	if (lux_loop != psmart->lux_table_max)
		pr_info("%s searching ok index : %d lux : %d", __func__,
			lux_loop, ptable[lux_loop].lux);
#endif
}
static void gamma_cell_determine(int ldi_revision)
{
	pr_info("%s ldi_revision: 0x%x", __func__, ldi_revision);

	V255_300CD_R_MSB = V255_300CD_R_MSB_20;
	V255_300CD_R_LSB = V255_300CD_R_LSB_20;

	V255_300CD_G_MSB = V255_300CD_G_MSB_20;
	V255_300CD_G_LSB = V255_300CD_G_LSB_20;

	V255_300CD_B_MSB = V255_300CD_B_MSB_20;
	V255_300CD_B_LSB = V255_300CD_B_LSB_20;

	V203_300CD_R = V203_300CD_R_20;
	V203_300CD_G = V203_300CD_G_20;
	V203_300CD_B = V203_300CD_B_20;

	V151_300CD_R = V151_300CD_R_20;
	V151_300CD_G = V151_300CD_G_20;
	V151_300CD_B = V151_300CD_B_20;

	V87_300CD_R = V87_300CD_R_20;
	V87_300CD_G = V87_300CD_G_20;
	V87_300CD_B = V87_300CD_B_20;

	V51_300CD_R = V51_300CD_R_20;
	V51_300CD_G = V51_300CD_G_20;
	V51_300CD_B = V51_300CD_B_20;

	V35_300CD_R = V35_300CD_R_20;
	V35_300CD_G = V35_300CD_G_20;
	V35_300CD_B = V35_300CD_B_20;

	V23_300CD_R = V23_300CD_R_20;
	V23_300CD_G = V23_300CD_G_20;
	V23_300CD_B = V23_300CD_B_20;

	V11_300CD_R = V11_300CD_R_20;
	V11_300CD_G = V11_300CD_G_20;
	V11_300CD_B = V11_300CD_B_20;

	V3_300CD_R = V3_300CD_R_20;
	V3_300CD_G = V3_300CD_G_20;
	V3_300CD_B = V3_300CD_B_20;

	V0_300CD_R = V0_300CD_R_20;
	V0_300CD_G = V0_300CD_G_20;
	V0_300CD_B = V0_300CD_B_20;

	VT_300CD_R = VT_300CD_R_20;
	VT_300CD_G = VT_300CD_G_20;
	VT_300CD_B = VT_300CD_B_20;
}

static void mtp_sorting(struct SMART_DIM *psmart)
{
	int sorting[GAMMA_SET_MAX] = {
		0, 1, 6, 9, 12, 15, 18, 21, 24, 27, 30,       /* R */
		2, 3, 7, 10, 13, 16, 19, 22, 25, 28, 31, 33,  /* G */
		4, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 34,  /* B */
	};
	int loop;
	char *pfrom, *pdest;

	pfrom = (char *)&(psmart->MTP_ORIGN);
	pdest = (char *)&(psmart->MTP);

	for (loop = 0; loop < GAMMA_SET_MAX; loop++)
		pdest[loop] = pfrom[sorting[loop]];

}

static int smart_dimming_init(struct SMART_DIM *psmart)
{
	int lux_loop;
	int id1, id2, id3;
#ifdef SMART_DIMMING_DEBUG
	int cnt;
	char pBuffer[256];
	memset(pBuffer, 0x00, 256);
#endif
	id1 = (psmart->ldi_revision & 0x00FF0000) >> 16;
	id2 = (psmart->ldi_revision & 0x0000FF00) >> 8;
	id3 = psmart->ldi_revision & 0xFF;

	pr_info("%s : ++ %d\n",__func__, id3);

	mtp_sorting(psmart);
	gamma_cell_determine(psmart->ldi_revision);
	set_max_lux_table();

#ifdef SMART_DIMMING_DEBUG
	print_RGB_offset(psmart);
#endif

	psmart->vregout_voltage = VREG0_REF_6P4;

	v255_adjustment(psmart);
	vt_adjustment(psmart);
	v203_adjustment(psmart);
	v151_adjustment(psmart);
	v87_adjustment(psmart);
	v51_adjustment(psmart);
	v35_adjustment(psmart);
	v23_adjustment(psmart);
	v11_adjustment(psmart);
	v3_adjustment(psmart);


	if (generate_gray_scale(psmart)) {
		pr_info(KERN_ERR "lcd smart dimming fail generate_gray_scale\n");
		return -EINVAL;
	}

	/*Generating lux_table*/
	for (lux_loop = 0; lux_loop < psmart->lux_table_max; lux_loop++) {
		/* To set brightness value */
		psmart->brightness_level = psmart->plux_table[lux_loop];
		/* To make lux table index*/
		psmart->gen_table[lux_loop].lux = psmart->plux_table[lux_loop];

#if defined(AID_OPERATION)
		if(id2 == PANEL_YM4) {
			gamma_init_YM4(psmart,
				(char *)(&(psmart->gen_table[lux_loop].gamma_setting)),
				GAMMA_SET_MAX);
		} else if (id3 == PANEL_REVB || id3 == PANEL_REVD) {
			gamma_init_revD(psmart,
			(char *)(&(psmart->gen_table[lux_loop].gamma_setting)),
			GAMMA_SET_MAX);
		} else if (id3 == PANEL_REVE) {
			gamma_init_revE(psmart,
			(char *)(&(psmart->gen_table[lux_loop].gamma_setting)),
			GAMMA_SET_MAX);
		} else {
			gamma_init_revA(psmart,
				(char *)(&(psmart->gen_table[lux_loop].gamma_setting)),
				GAMMA_SET_MAX);
		}
#else
		pure_gamma_init(psmart,
			(char *)(&(psmart->gen_table[lux_loop].gamma_setting)),
			GAMMA_SET_MAX);
#endif
	}

	/* set 300CD max gamma table */
	memcpy(&(psmart->gen_table[lux_loop-1].gamma_setting),
			max_lux_table, GAMMA_SET_MAX);

	set_min_lux_table(psmart);

#ifdef SMART_DIMMING_DEBUG
	for (lux_loop = 0; lux_loop < psmart->lux_table_max; lux_loop++) {
		for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
			snprintf(pBuffer + strnlen(pBuffer, 256), 256, " %3d",
				psmart->gen_table[lux_loop].gamma_setting[cnt]);

		pr_info("lux : %3d  %s\n", psmart->plux_table[lux_loop], pBuffer);
		memset(pBuffer, 0x00, 256);
	}

	for (lux_loop = 0; lux_loop < psmart->lux_table_max; lux_loop++) {
		for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
			snprintf(pBuffer + strnlen(pBuffer, 256), 256,
				" %02X",
				psmart->gen_table[lux_loop].gamma_setting[cnt]);

		pr_info("lux : %3d  %s\n", psmart->plux_table[lux_loop], pBuffer);
		memset(pBuffer, 0x00, 256);
	}
#endif

	pr_info("%s done\n",__func__);

	return 0;
}

/* ----------------------------------------------------------------------------
 * Wrapper functions for smart dimming
 * ----------------------------------------------------------------------------
 */
static void wrap_generate_gamma(struct smartdim_conf * conf, int cd, char *cmd_str) {

	struct SMART_DIM *smart = conf->psmart;

	if (!smart) {
		pr_info("%s fail", __func__);
		return ;
	}

	smart->brightness_level = cd;
	generate_gamma(conf->psmart, cmd_str, GAMMA_SET_MAX);
}

static void wrap_smart_dimming_init(struct smartdim_conf * conf) {

	struct SMART_DIM *smart = conf->psmart;

	if (!smart) {
		pr_info("%s fail", __func__);
		return ;
	}

	smart->plux_table = conf->lux_tab;
	smart->lux_table_max = conf->lux_tabsize;
	smart->ldi_revision = conf->man_id;
	smart_dimming_init(smart);
}

struct smartdim_conf *smart_get_conf_S6E3HA2_AMS567DJ01(void) {

	struct smartdim_conf * smartdim_conf;
	struct SMART_DIM *smart;

	smartdim_conf = kzalloc(sizeof(struct smartdim_conf), GFP_KERNEL);
	if (!smartdim_conf) {
		pr_info("%s allocation fail", __func__);
		goto out2;
	}

	smart = kzalloc(sizeof(struct SMART_DIM), GFP_KERNEL);
	if (!smart) {
		pr_info("%s allocation fail", __func__);
		goto out1;
	}

	smartdim_conf->psmart = smart;
	smartdim_conf->generate_gamma = wrap_generate_gamma;
	smartdim_conf->init = wrap_smart_dimming_init;
	smartdim_conf->get_min_lux_table = get_min_lux_table;
	smartdim_conf->mtp_buffer = (char *)(&smart->MTP_ORIGN);
	smartdim_conf->print_aid_log = print_aid_log;

	return smartdim_conf;

out1:
	kfree(smartdim_conf);
out2:
	return NULL;
}

/* ----------------------------------------------------------------------------
 * END - Wrapper
 * ----------------------------------------------------------------------------
 */


/* ============================================================================
 *  HMT
 * ============================================================================
 */

static int ccg6_candela_table_reverse_hmt[][2] = {
	{20,	0},
	{21,	1},
	{22,	2},
	{23,	3},
	{25,	4},
	{27,	5},
	{29,	6},
	{31,	7},
	{33,	8},
	{35,	9},
	{37,	10},
	{39,	11},
	{41,	12},
	{44,	13},
	{47,	14},
	{50,	15},
	{53,	16},
	{56,	17},
	{60,	18},
	{64,	19},
	{68,	20},
	{72,	21},
	{77,	22},
	{82,	23},
	{87,	24},
	{93,	25},
	{99,	26},
	{105,	27},
	{150,	28},
};

static int get_ccg6_max_table_hmt(void) {
	return MAX_TABLE_HMT;
}

static int get_ccg6_candela_table_hmt(int table_index, int index) {
	return ccg6_candela_table_reverse_hmt[table_index][index];
}

static int find_candela_table_hmt(int brightness) {
	int loop;
	int err = -1;
	int size = get_ccg6_max_table_hmt();

	for(loop = 0; loop < size; loop++)
		if (get_ccg6_candela_table_hmt(loop, 0) == brightness)
			return get_ccg6_candela_table_hmt(loop, 1);

	return err;
}

static int gradation_offset_reverse_hmt_single[][9] = {
/*	V255 V203 V151 V87 V51 V35 V23 V11 V3 */
	{0,	3,	3,	6,	6,	7,	8,	8,	9},
	{0,	3,	4,	6,	5,	6,	7,	8,	9},
	{0,	4,	5,	6,	6,	7,	7,	8,	13},
	{0,	4,	6,	6,	6,	7,	7,	8,	11},
	{0,	5,	6,	8,	6,	7,	7,	8,	14},
	{0,	3,	6,	8,	6,	7,	7,	9,	10},
	{0,	4,	6,	8,	6,	7,	8,	8,	12},
	{0,	4,	7,	8,	6,	7,	7,	8,	19},
	{0,	3,	7,	8,	6,	7,	8,	9,	8},
	{0,	3,	7,	8,	7,	7,	7,	8,	19},
	{0,	2,	8,	8,	7,	7,	7,	9,	9},
	{0,	3,	7,	9,	7,	7,	8,	9,	10},
	{0,	3,	8,	9,	7,	7,	7,	8,	12},
	{0,	3,	7,	9,	7,	6,	7,	8,	12},
	{0,	4,	8,	9,	8,	8,	8,	9,	7},
	{0,	5,	10,	9,	8,	8,	8,	9,	9},
	{0,	4,	9,	10,	8,	8,	8,	8,	12},
	{0,	6,	10,	10,	9,	8,	8,	8,	13},
	{0,	3,	8,	9,	8,	8,	7,	8,	13},
	{0,	6,	9,	10,	10,	8,	8,	9,	8},
	{0,	5,	9,	10,	10,	8,	8,	8,	11},
	{0,	6,	9,	11,	11,	8,	8,	8,	11},
	{0,	4,	8,	8,	6,	5,	5,	5,	8},
	{0,	3,	8,	8,	6,	6,	5,	5,	8},
	{0,	5,	8,	9,	7,	6,	5,	5,	9},
	{0,	4,	9,	9,	8,	6,	6,	6,	6},
	{0,	5,	8,	9,	8,	6,	6,	5,	7},
	{0,	5,	7,	10,	8,	6,	6,	5,	7},

	/* for 150 cd */
	{0, 0,	0,	0,	0,	0,	0,	0,	0},
};

static int rgb_offset_reverse_hmt_single[][RGB_COMPENSATION] = {
/*	R255 G255 B255 R203 G203 B203 R151 G151 B151
	R87 G87 B87 R51 G51 B51 R35 G35 B35
	R23 G23 B23 R11 G11 B11
*/
	{13, -3,	16, 0,	0,	0,	0,	0,	1,	1,	0,	0,	-1, -1, 3,	-2, 0,	0,	-7, 0,	-3, -13,	5,	-10},
	{13, -3,	16, 1,	0,	1,	0,	0,	0,	1,	0,	2,	-1, 0,	2,	-2, 0,	0,	-6, 0,	-3, -12,	4,	-9},
	{12, -3,	16, 0,	0,	0,	1,	0,	2,	0,	0,	0,	0,	-1, 2,	-2, 0,	0,	-9, 0,	-4, -19,	5,	-11},
	{13, -3,	16, 1,	0,	1,	0,	0,	1,	1,	0,	2,	0,	0,	2,	-2, 0,	0,	-7, 0,	-3, -15,	5,	-10},
	{12, -3,	15, 0,	0,	1,	0,	0,	0,	1,	0,	1,	0,	-1, 2,	-3, 0,	0,	-6, 0,	-2, -18,	5,	-12},
	{13, -3,	16, 0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	-1, 2,	-2, 0,	0,	-8, 0,	-2, -12,	4,	-9},
	{13, -3,	16, 0,	0,	0,	1,	0,	1,	1,	0,	2,	0,	0,	1,	0,	0,	1,	-7, 0,	-1, -15,	4,	-10},
	{14, -3,	16, 0,	0,	0,	0,	0,	0,	1,	0,	1,	0,	-1, 2,	-2, 0,	0,	-7, 0,	-1, -15,	4,	-10},
	{14, -3,	16, 0,	0,	1,	0,	0,	0,	1,	0,	1,	0,	-1, 2,	-2, 0,	0,	-6, 0,	-1, -12,	3,	-8},
	{14, -3,	16, 0,	0,	0,	0,	0,	1,	2,	0,	2,	0,	-1, 2,	0,	0,	2,	-7, 0,	-2, -14,	4,	-10},
	{13, -3,	16, 0,	0,	1,	0,	0,	0,	2,	0,	2,	0,	-1, 2,	-2, 0,	1,	-6, 0,	-1, -11,	4,	-8},
	{13, -3,	16, 1,	0,	1,	0,	0,	0,	0,	0,	1,	1,	0,	2,	0,	0,	2,	-5, 0,	0,	-12,	3,	-8},
	{14, -3,	16, 0,	0,	1,	1,	0,	0,	1,	0,	2,	1,	-1, 2,	-1, 0,	2,	-4, 0,	-1, -12,	3,	-8},
	{14, -3,	16, 1,	0,	1,	0,	0,	0,	2,	0,	2,	1,	0,	2,	-1, -1, 2,	-4, -1, -1, -12,	3,	-8},
	{14, -3,	16, 1,	0,	1,	0,	0,	0,	0,	0,	2,	0,	0,	1,	-1, 0,	2,	-2, 0,	0,	-10,	3,	-6},
	{13, -4,	16, 0,	0,	0,	1,	0,	1,	1,	0,	1,	0,	-1, 2,	0,	-1, 2,	-3, -1, 0,	-10,	3,	-6},
	{13, -4,	16, 0,	0,	0,	0,	0,	1,	1,	0,	1,	1,	0,	1,	-1, -1, 2,	-3, -1, 0,	-12,	3,	-6},
	{12, -4,	16, 0,	0,	0,	1,	0,	1,	2,	0,	2,	1,	0,	2,	-1, 0,	2,	-2, 0,	0,	-12,	2,	-6},
	{13, -3,	16, 1,	0,	1,	1,	0,	0,	1,	0,	2,	1,	-1, 2,	0,	0,	2,	-4, 0,	-1, -12,	3,	-6},
	{13, -4,	16, 0,	0,	0,	0,	0,	1,	2,	0,	1,	1,	0,	2,	0,	-1, 3,	-2, -1, 0,	-10,	2,	-5},
	{13, -3,	16, 0,	0,	0,	1,	0,	1,	1,	0,	2,	1,	0,	1,	0,	-1, 3,	-1, -1, 0,	-10,	2,	-5},
	{13, -4,	16, 1,	0,	0,	0,	0,	1,	2,	0,	1,	2,	0,	2,	0,	0,	2,	-2, 0,	0,	-9, 2,	-5},
	{14, -3,	16, 1,	0,	1,	0,	0,	1,	1,	-1, 2,	1,	-1, 2,	0,	-1, 2,	0,	-1, 0,	-7, 2,	-6},
	{13, -3,	16, 1,	0,	1,	1,	0,	1,	1,	-1, 2,	1,	0,	1,	1,	-1, 4,	-1, -1, 0,	-6, 2,	-6},
	{13, -4,	16, 1,	0,	1,	0,	0,	1,	2,	0,	2,	2,	0,	2,	0,	-1, 2,	0,	-1, 1,	-6, 2,	-6},
	{13, -4,	16, 0,	0,	0,	0,	0,	1,	1,	0,	2,	2,	0,	2,	1,	-1, 3,	0,	-1, 1,	-5, 2,	-5},
	{13, -4,	16, 1,	0,	1,	1,	0,	1,	0,	0,	2,	2,	0,	2,	1,	-1, 3,	0,	-1, 1,	-5, 2,	-4},
	{13, -4,	16, 1,	0,	1,	0,	0,	1,	2,	0,	2,	2,	0,	2,	0,	-1, 3,	0,	-1, 1,	-4, 2,	-4},

	/* for 150 cd */
	{-12,	-22,	-8,	-2,	-2,	-3,	6,	5,	6,	10,	8,	9,	6,	5,	7,	0,	0,	3,	5,	3,	6,	13,	17,	10},
};

static int base_luminance_reverse_hmt_single[][2] = {
	{20, 98},
	{21, 101},
	{22, 105},
	{23, 108},
	{25, 117},
	{27, 126},
	{29, 134},
	{31, 141},
	{33, 151},
	{35, 157},
	{37, 166},
	{39, 173},
	{41, 181},
	{44, 192},
	{47, 206},
	{50, 215},
	{53, 228},
	{56, 239},
	{60, 252},
	{64, 268},
	{68, 284},
	{72, 297},
	{77, 224},
	{82, 237},
	{87, 252},
	{93, 265},
	{99, 281},
	{105, 295},
	{150, 500},
};

static int get_candela_level_hmt(int brightness_level) {

	int cnt;
	int base_luminance[MAX_TABLE_HMT][2];

	memcpy(base_luminance, base_luminance_reverse_hmt_single, sizeof(base_luminance_reverse_hmt_single));

	for (cnt = 0; cnt < MAX_TABLE_HMT; cnt++)
		if (base_luminance[cnt][0] == brightness_level)
			return base_luminance[cnt][1];

	return -1;
}

static int get_gradation_offset_hmt(int table_index, int index) {
	int gradation_offset = 0;

	gradation_offset = gradation_offset_reverse_hmt_single[table_index][index];

	return gradation_offset;
}

static int get_rgb_offset_hmt(int table_index, int index) {
	int rgb_offset = 0;

	rgb_offset = rgb_offset_reverse_hmt_single[table_index][index];

	return rgb_offset;
}

static int get_gamma_curve(void)
{
	return GAMMA_CURVE_2P15;
}

static void gamma_init_hmt_150cd(struct SMART_DIM *pSmart, char *str, int size)
{
	int cnt;
	int table_index;
	int level_255_temp_MSB = 0;
	int level_V255 = 0;
	int gamma_setting[GAMMA_SET_MAX];

	pr_debug("%s : setting for %d cd\n", __func__, pSmart->brightness_level);

	for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
			gamma_setting[cnt] = str[cnt];

	for (cnt = 0; cnt < RGB_COMPENSATION - 3; cnt++) {
		table_index = find_candela_table_hmt(pSmart->brightness_level);

		if (table_index == -1) {
			table_index = get_ccg6_max_table_hmt() - 1;
			pr_info("%s fail RGB table_index cnt : %d brightness %d",
				__func__, cnt, pSmart->brightness_level);
		}

		if (cnt < 3) {
			level_V255 = gamma_setting[cnt * 2] << 8 | gamma_setting[(cnt * 2) + 1];
			level_V255 +=
				get_rgb_offset_hmt(table_index, cnt);
			level_255_temp_MSB = level_V255 / 256;

			gamma_setting[cnt * 2] = level_255_temp_MSB & 0xff;
			gamma_setting[(cnt * 2) + 1] = level_V255 & 0xff;
			pr_debug(" 0x%x 0x%x\n", gamma_setting[cnt * 2], gamma_setting[(cnt * 2) + 1]);
		} else {
			gamma_setting[cnt+3] += get_rgb_offset_hmt(table_index, cnt);
			pr_debug(" 0x%x\n", gamma_setting[cnt+3]);
		}
	}

	/* To avoid overflow */
	for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
		str[cnt] = gamma_setting[cnt];

	pr_debug("%s -- \n", __func__);
}

static void gamma_init_hmt(struct SMART_DIM *pSmart, char *str, int size) {
	long long candela_level[TABLE_MAX] = {-1, };
	int bl_index[TABLE_MAX] = {-1, };
	int gamma_setting[GAMMA_SET_MAX];

	long long temp_cal_data = 0;
	int bl_level;

	int level_255_temp_MSB = 0;
	int level_V255 = 0;

	int point_index;
	int cnt;
	int table_index;

	pr_info_once("%s : start !!\n",__func__);

	/*calculate candela level */
	bl_level = get_candela_level_hmt(pSmart->brightness_level);

	for (cnt = 0; cnt < TABLE_MAX; cnt++) {
		point_index = INFLECTION_VOLTAGE_ARRAY[cnt+1];
		temp_cal_data =
		((long long)(candela_coeff_2p15[point_index])) *
		((long long)(bl_level));
		candela_level[cnt] = temp_cal_data;
	}

#ifdef SMART_DIMMING_DEBUG
	printk(KERN_INFO "\n candela_1:%llu  candela_3:%llu  candela_11:%llu ",
		candela_level[0], candela_level[1], candela_level[2]);
	printk(KERN_INFO "candela_23:%llu  candela_35:%llu  candela_51:%llu ",
		candela_level[3], candela_level[4], candela_level[5]);
	printk(KERN_INFO "candela_87:%llu  candela_151:%llu  candela_203:%llu ",
		candela_level[6], candela_level[7], candela_level[8]);
	printk(KERN_INFO "candela_255:%llu brightness_level %d\n", candela_level[9], pSmart->brightness_level);
#endif

	for (cnt = 0; cnt < TABLE_MAX; cnt++) {
		if (searching_function(candela_level[cnt],
			&(bl_index[cnt]), get_gamma_curve())) {
			pr_info("%s searching functioin error cnt:%d\n",
			__func__, cnt);
		}
	}

	/*
	*	Candela compensation
	*/

	for (cnt = 1; cnt < TABLE_MAX; cnt++) {
		table_index = find_candela_table_hmt(pSmart->brightness_level);

		if (table_index == -1) {
			table_index = get_ccg6_max_table_hmt() - 1;
			pr_info("%s fail candela table_index cnt : %d brightness %d\n",
				__func__, cnt, pSmart->brightness_level);
		}

		bl_index[TABLE_MAX - cnt] +=
			get_gradation_offset_hmt(table_index, cnt - 1);

		/* THERE IS M-GRAY0 target */
		if (bl_index[TABLE_MAX - cnt] == 0)
			bl_index[TABLE_MAX - cnt] = 1;
	}

#ifdef SMART_DIMMING_DEBUG
	printk(KERN_INFO "\n bl_index_1:%d  bl_index_3:%d  bl_index_11:%d",
		bl_index[0], bl_index[1], bl_index[2]);
	printk(KERN_INFO "bl_index_23:%d bl_index_35:%d  bl_index_51:%d",
		bl_index[3], bl_index[4], bl_index[5]);
	printk(KERN_INFO "bl_index_87:%d  bl_index_151:%d bl_index_203:%d",
		bl_index[6], bl_index[7], bl_index[8]);
	printk(KERN_INFO "bl_index_255:%d\n", bl_index[9]);
#endif
	/*Generate Gamma table*/
	for (cnt = 0; cnt < TABLE_MAX; cnt++)
		(void)Make_hexa[cnt](bl_index , pSmart, str);

	/* To avoid overflow */
	for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
		gamma_setting[cnt] = str[cnt];

	/*
	*	RGB compensation
	*/
	for (cnt = 0; cnt < RGB_COMPENSATION; cnt++) {
		table_index = find_candela_table_hmt(pSmart->brightness_level);

		if (table_index == -1) {
			table_index = get_ccg6_max_table_hmt() - 1;
			pr_info("%s fail RGB table_index cnt : %d brightness %d",
				__func__, cnt, pSmart->brightness_level);
		}

		if (cnt < 3) {
			level_V255 = gamma_setting[cnt * 2] << 8 | gamma_setting[(cnt * 2) + 1];
			level_V255 +=
				get_rgb_offset_hmt(table_index, cnt);
			level_255_temp_MSB = level_V255 / 256;

			gamma_setting[cnt * 2] = level_255_temp_MSB & 0xff;
			gamma_setting[(cnt * 2) + 1] = level_V255 & 0xff;
		} else {
			gamma_setting[cnt+3] += get_rgb_offset_hmt(table_index, cnt);
		}
	}
	/*subtration MTP_OFFSET value from generated gamma table*/
	mtp_offset_substraction(pSmart, gamma_setting);

	/* To avoid overflow */
	for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
		str[cnt] = gamma_setting[cnt];
}

static void generate_gamma_hmt(struct SMART_DIM *psmart, char *str, int size)
{
	int lux_loop;
	struct illuminance_table *ptable = (struct illuminance_table *)
						(&(psmart->hmt_gen_table));

	/* force copy for 150cd */
	if (psmart->brightness_level == 150) {
		memcpy(str, &(ptable[MAX_TABLE_HMT-1].gamma_setting), size);
		return;
	}

	/* searching already generated gamma table */
	for (lux_loop = 0; lux_loop < psmart->lux_table_max; lux_loop++) {
		if (ptable[lux_loop].lux == psmart->brightness_level) {
			memcpy(str, &(ptable[lux_loop].gamma_setting), size);
			break;
		}
	}

	/* searching fail... Setting 150CD value on gamma table */
	if (lux_loop == psmart->lux_table_max) {
		pr_info("%s searching fail lux : %d\n", __func__,
				psmart->brightness_level);
		memcpy(str, max_lux_table, size);
	}

#ifdef SMART_DIMMING_DEBUG
	if (lux_loop != psmart->lux_table_max)
		pr_info("%s searching ok index : %d lux : %d", __func__,
			lux_loop, ptable[lux_loop].lux);
#endif
}

static char hmt_150cd_lux_table[GAMMA_SET_MAX] = {0,};

void set_150cd_lux_table(char *para, int size)
{
	int i;

	for (i=0; i<size; i++) {
		pr_debug("%s : B4[%d] = 0x%x\n", __func__, i, para[i]);
		hmt_150cd_lux_table[i] = para[i];
	}
}

static int smart_dimming_init_hmt(struct SMART_DIM *psmart)
{
	int lux_loop;
	int id1, id2, id3;
#ifdef SMART_DIMMING_DEBUG
	int cnt;
	char pBuffer[256];
	memset(pBuffer, 0x00, 256);
#endif
	id1 = (psmart->ldi_revision & 0x00FF0000) >> 16;
	id2 = (psmart->ldi_revision & 0x0000FF00) >> 8;
	id3 = psmart->ldi_revision & 0xFF;

	pr_info("%s : ++\n",__func__);

	mtp_sorting(psmart);
	gamma_cell_determine(psmart->ldi_revision);
	set_max_lux_table();

#ifdef SMART_DIMMING_DEBUG
	print_RGB_offset(psmart);
#endif

	psmart->vregout_voltage = VREG0_REF_6P4;

	v255_adjustment(psmart);
	vt_adjustment(psmart);
	v203_adjustment(psmart);
	v151_adjustment(psmart);
	v87_adjustment(psmart);
	v51_adjustment(psmart);
	v35_adjustment(psmart);
	v23_adjustment(psmart);
	v11_adjustment(psmart);
	v3_adjustment(psmart);


	if (generate_gray_scale(psmart)) {
		pr_info(KERN_ERR "lcd smart dimming fail generate_gray_scale\n");
		return -EINVAL;
	}

	/*Generating lux_table*/
	for (lux_loop = 0; lux_loop < psmart->lux_table_max; lux_loop++) {
		/* To set brightness value */
		psmart->brightness_level = psmart->plux_table[lux_loop];
		/* To make lux table index*/
		psmart->hmt_gen_table[lux_loop].lux = psmart->plux_table[lux_loop];

#if defined(AID_OPERATION)
		gamma_init_hmt(psmart,
			(char *)(&(psmart->hmt_gen_table[lux_loop].gamma_setting)),
			GAMMA_SET_MAX);
#else
		pure_gamma_init(psmart,
			(char *)(&(psmart->hmt_gen_table[lux_loop].gamma_setting)),
			GAMMA_SET_MAX);
#endif
	}

	/* gamma gen for 150cd */
	/* set 150CD gamma table */
	memcpy(&(psmart->hmt_gen_table[lux_loop].gamma_setting),
			hmt_150cd_lux_table, GAMMA_SET_MAX);

	psmart->brightness_level = 150;
	psmart->hmt_gen_table[lux_loop].lux = 150;

	gamma_init_hmt_150cd(psmart,
			(char *)(&(psmart->hmt_gen_table[lux_loop].gamma_setting)),
			GAMMA_SET_MAX);

#ifdef SMART_DIMMING_DEBUG
	for (lux_loop = 0; lux_loop < psmart->lux_table_max; lux_loop++) {
		for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
			snprintf(pBuffer + strnlen(pBuffer, 256), 256, " %3d",
				psmart->hmt_gen_table[lux_loop].gamma_setting[cnt]);

		pr_info("lux : %3d  %s\n", psmart->plux_table[lux_loop], pBuffer);
		memset(pBuffer, 0x00, 256);
	}

	for (lux_loop = 0; lux_loop < psmart->lux_table_max; lux_loop++) {
		for (cnt = 0; cnt < GAMMA_SET_MAX; cnt++)
			snprintf(pBuffer + strnlen(pBuffer, 256), 256,
				" %02X",
				psmart->hmg_gen_table[lux_loop].gamma_setting[cnt]);

		pr_info("lux : %3d  %s\n", psmart->plux_table[lux_loop], pBuffer);
		memset(pBuffer, 0x00, 256);
	}
#endif

	pr_info("%s done\n",__func__);

	return 0;
}

static void wrap_generate_gamma_hmt(struct smartdim_conf * conf, int cd, char *cmd_str) {

	struct SMART_DIM *smart = conf->psmart;

	if (!smart) {
		pr_info("%s fail", __func__);
		return ;
	}

	smart->brightness_level = cd;
	generate_gamma_hmt(conf->psmart, cmd_str, GAMMA_SET_MAX);
}

static void wrap_smart_dimming_init_hmt(struct smartdim_conf * conf) {

	struct SMART_DIM *smart = conf->psmart;

	if (!smart) {
		pr_info("%s fail", __func__);
		return;
	}

	smart->plux_table = conf->lux_tab;
	smart->lux_table_max = conf->lux_tabsize;
	smart->ldi_revision = conf->man_id;
	smart_dimming_init_hmt(smart);
}

struct smartdim_conf *smart_get_conf_S6E3HA2_AMS567DJ01_hmt(void) {

	struct smartdim_conf * smartdim_conf_hmt;
	struct SMART_DIM *smart_hmt;

	smartdim_conf_hmt = kzalloc(sizeof(struct smartdim_conf), GFP_KERNEL);
	if (!smartdim_conf_hmt) {
		pr_info("%s allocation fail", __func__);
		goto out2;
	}

	smart_hmt = kzalloc(sizeof(struct SMART_DIM), GFP_KERNEL);
	if (!smart_hmt) {
		pr_info("%s allocation fail", __func__);
		goto out1;
	}

	smartdim_conf_hmt->psmart = smart_hmt;
	smartdim_conf_hmt->generate_gamma = wrap_generate_gamma_hmt;
	smartdim_conf_hmt->init = wrap_smart_dimming_init_hmt;
	smartdim_conf_hmt->get_min_lux_table = get_min_lux_table;
	smartdim_conf_hmt->mtp_buffer = (char *)(&smart_hmt->MTP_ORIGN);
	smartdim_conf_hmt->print_aid_log = print_aid_log_hmt;
	smartdim_conf_hmt->set_para_for_150cd = set_150cd_lux_table;

	return smartdim_conf_hmt;

out1:
	kfree(smartdim_conf_hmt);
out2:
	return NULL;
}
