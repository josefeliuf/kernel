/*
 * Driver header file for pin controller driver
 *
 * Copyright (C) 2015 Spreadtrum
 * Baolin Wang <baolin.wang@spreadtrum.com>
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2. This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#ifndef __SC9853I_PINS_H__
#define __SC9853I_PINS_H__

#include <dt-bindings/pinctrl/sc9853i_pinctrl.h>
#include <linux/pinctrl/pinctrl.h>

#define PINCTRL_REG_MISC_OFFSET 0x420

struct sprd_pin_data {
	const char *name;
	unsigned int num;
	/* 1 means control pins, 0 means common pins */
	unsigned int mode;
	/* for control pins configuration */
	unsigned long bit_offset;
	unsigned long bit_width;
	unsigned int reg;
};

static const struct sprd_pin_data sprd_soc_pin_info[] = {
	SPRD_PINCTRL_PIN(SC9853_ORP_URXD_PIN_IN_SEL),
	SPRD_PINCTRL_PIN(SC9853_WPD_IO_1_4PD),
	SPRD_PINCTRL_PIN(SC9853_WPD_IO_1_3PD),
	SPRD_PINCTRL_PIN(SC9853_WPD_IO_1_2PD),
	SPRD_PINCTRL_PIN(SC9853_WPD_IO_1_1PD),
	SPRD_PINCTRL_PIN(SC9853_WPD_IO_1_0PD),
	SPRD_PINCTRL_PIN(SC9853_WPD_NF1PD),
	SPRD_PINCTRL_PIN(SC9853_WPD_NF0PD),
	SPRD_PINCTRL_PIN(SC9853_WPD_ADPD),
	SPRD_PINCTRL_PIN(SC9853_WPD_IO_2_1PD),
	SPRD_PINCTRL_PIN(SC9853_WPD_SIM2PD),
	SPRD_PINCTRL_PIN(SC9853_WPD_SIM1PD),
	SPRD_PINCTRL_PIN(SC9853_WPD_SIM0PD),
	SPRD_PINCTRL_PIN(SC9853_WPD_SDPD),
	SPRD_PINCTRL_PIN(SC9853_WPD_CAMPD),
	SPRD_PINCTRL_PIN(SC9853_SD1_D1_CTRL),
	SPRD_PINCTRL_PIN(SC9853_SIMDA2_CTRL),
	SPRD_PINCTRL_PIN(SC9853_SDA1_CTRL),
	SPRD_PINCTRL_PIN(SC9853_U1TXD_CTRL),
	SPRD_PINCTRL_PIN(SC9853_SL_SIM2),
	SPRD_PINCTRL_PIN(SC9853_SL_SIM1),
	SPRD_PINCTRL_PIN(SC9853_SL_SIM0),
	SPRD_PINCTRL_PIN(SC9853_SL_SD),
	SPRD_PINCTRL_PIN(SC9853_MS_SD),
	SPRD_PINCTRL_PIN(SC9853_SPSPI_CLK_PIN_IN_SEL),
	SPRD_PINCTRL_PIN(SC9853_SPSPI_CSN_PIN_IN_SEL),
	SPRD_PINCTRL_PIN(SC9853_SPSPI_DO_PIN_IN_SEL),
	SPRD_PINCTRL_PIN(SC9853_SPSPI_DI_PIN_IN_SEL),
	SPRD_PINCTRL_PIN(SC9853_ADI_SYNC_PIN_OUT_SEL),
	SPRD_PINCTRL_PIN(SC9853_CMRST_SEL),
	SPRD_PINCTRL_PIN(SC9853_CMPD_SEL),
	SPRD_PINCTRL_PIN(SC9853_UART5_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_SIM2_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_SIM1_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_SIM0_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_UART1_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_UART4_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_UART3_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_UART2_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_UART0_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_UART24_LOOP_SEL),
	SPRD_PINCTRL_PIN(SC9853_UART23_LOOP_SEL),
	SPRD_PINCTRL_PIN(SC9853_UART14_LOOP_SEL),
	SPRD_PINCTRL_PIN(SC9853_UART13_LOOP_SEL),
	SPRD_PINCTRL_PIN(SC9853_WDRST_OUT_SEL),
	SPRD_PINCTRL_PIN(SC9853_IIS2_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_IIS1_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_IIS0_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_IIS23_LOOP_SEL),
	SPRD_PINCTRL_PIN(SC9853_IIS13_LOOP_SEL),
	SPRD_PINCTRL_PIN(SC9853_IIS12_LOOP_SEL),
	SPRD_PINCTRL_PIN(SC9853_IIS03_LOOP_SEL),
	SPRD_PINCTRL_PIN(SC9853_IIS02_LOOP_SEL),
	SPRD_PINCTRL_PIN(SC9853_IIS01_LOOP_SEL),
	SPRD_PINCTRL_PIN(SC9853_IIS6_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_IIS5_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_IIS4_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_IIS3_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_I2C_INF4_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_I2C_INF3_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_I2C_INF2_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_I2C_INF1_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_VSD1_MS),
	SPRD_PINCTRL_PIN(SC9853_VSD_MS),
	SPRD_PINCTRL_PIN(SC9853_VSIM2_MS),
	SPRD_PINCTRL_PIN(SC9853_VSIM1_MS),
	SPRD_PINCTRL_PIN(SC9853_VSIM0_MS),
	SPRD_PINCTRL_PIN(SC9853_I2C_INF0_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_GPIO_INF7_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_GPIO_INF6_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_GPIO_INF5_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_GPIO_INF4_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_GPIO_INF3_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_GPIO_INF2_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_GPIO_INF1_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_GPIO_INF0_SYS_SEL),
	SPRD_PINCTRL_PIN(SC9853_CARD_DET_SEL),
	SPRD_PINCTRL_PIN(SC9853_SIM0_DET_SEL),
	SPRD_PINCTRL_PIN(SC9853_AP_SIM0_BD_EB),
	SPRD_PINCTRL_PIN(SC9853_AP_EMMC_BD_EB),
	SPRD_PINCTRL_PIN(SC9853_AP_SDIO2_BD_EB),
	SPRD_PINCTRL_PIN(SC9853_AP_SDIO1_BD_EB),
	SPRD_PINCTRL_PIN(SC9853_AP_SDIO0_BD_EB),
	SPRD_PINCTRL_PIN(SC9853_PUBCP_SDIO0_BD_EB),
	SPRD_PINCTRL_PIN(SC9853_PUBCP_SIM1_BD_EB),
	SPRD_PINCTRL_PIN(SC9853_PUBCP_SIM0_BD_EB),
	SPRD_PINCTRL_PIN(SC9853_TEST_DBG_MODE4),
	SPRD_PINCTRL_PIN(SC9853_TEST_DBG_MODE3),
	SPRD_PINCTRL_PIN(SC9853_TEST_DBG_MODE2),
	SPRD_PINCTRL_PIN(SC9853_TEST_DBG_MODE1),
	SPRD_PINCTRL_PIN(SC9853_TEST_DBG_MODE0),
	SPRD_PINCTRL_PIN(SC9853_SP_EIC_DPAD3_SEL),
	SPRD_PINCTRL_PIN(SC9853_SP_EIC_DPAD2_SEL),
	SPRD_PINCTRL_PIN(SC9853_SP_EIC_DPAD1_SEL),
	SPRD_PINCTRL_PIN(SC9853_SP_EIC_DPAD0_SEL),
	SPRD_PINCTRL_PIN(SC9853_SP_EIC_DPAD7_SEL),
	SPRD_PINCTRL_PIN(SC9853_SP_EIC_DPAD6_SEL),
	SPRD_PINCTRL_PIN(SC9853_SP_EIC_DPAD5_SEL),
	SPRD_PINCTRL_PIN(SC9853_SP_EIC_DPAD4_SEL),
	SPRD_PINCTRL_PIN(SC9853_SD0_D0),
	SPRD_PINCTRL_PIN(SC9853_SD0_D1),
	SPRD_PINCTRL_PIN(SC9853_SD0_CLK0),
	SPRD_PINCTRL_PIN(SC9853_SD0_CMD),
	SPRD_PINCTRL_PIN(SC9853_SD0_D2),
	SPRD_PINCTRL_PIN(SC9853_SD0_D3),
	SPRD_PINCTRL_PIN(SC9853_EXTINT5),
	SPRD_PINCTRL_PIN(SC9853_EXTINT6),
	SPRD_PINCTRL_PIN(SC9853_EXT_RST_B),
	SPRD_PINCTRL_PIN(SC9853_AUD_SCLK),
	SPRD_PINCTRL_PIN(SC9853_DCDC_ARM_EN0),
	SPRD_PINCTRL_PIN(SC9853_CLK_32K),
	SPRD_PINCTRL_PIN(SC9853_CHIP_SLEEP),
	SPRD_PINCTRL_PIN(SC9853_AUD_ADD0),
	SPRD_PINCTRL_PIN(SC9853_AUD_DAD0),
	SPRD_PINCTRL_PIN(SC9853_AUD_ADSYNC),
	SPRD_PINCTRL_PIN(SC9853_AUD_DAD1),
	SPRD_PINCTRL_PIN(SC9853_AUD_DASYNC),
	SPRD_PINCTRL_PIN(SC9853_ADI_SCLK),
	SPRD_PINCTRL_PIN(SC9853_ADI_D),
	SPRD_PINCTRL_PIN(SC9853_DCDC_ARM_EN1),
	SPRD_PINCTRL_PIN(SC9853_SENSOR_HUB_ACTION),
	SPRD_PINCTRL_PIN(SC9853_PTEST),
	SPRD_PINCTRL_PIN(SC9853_ANA_INT),
	SPRD_PINCTRL_PIN(SC9853_DSI_TE),
	SPRD_PINCTRL_PIN(SC9853_LCM_RSTN),
	SPRD_PINCTRL_PIN(SC9853_PWMA),
	SPRD_PINCTRL_PIN(SC9853_EXTINT10),
	SPRD_PINCTRL_PIN(SC9853_EXTINT9),
	SPRD_PINCTRL_PIN(SC9853_EMMC_CLK),
	SPRD_PINCTRL_PIN(SC9853_EMMC_RSTB),
	SPRD_PINCTRL_PIN(SC9853_EMMC_CMD),
	SPRD_PINCTRL_PIN(SC9853_EMMC_D0),
	SPRD_PINCTRL_PIN(SC9853_EMMC_D1),
	SPRD_PINCTRL_PIN(SC9853_EMMC_D2),
	SPRD_PINCTRL_PIN(SC9853_EMMC_D3),
	SPRD_PINCTRL_PIN(SC9853_EMMC_D4),
	SPRD_PINCTRL_PIN(SC9853_EMMC_D5),
	SPRD_PINCTRL_PIN(SC9853_EMMC_D6),
	SPRD_PINCTRL_PIN(SC9853_EMMC_D7),
	SPRD_PINCTRL_PIN(SC9853_EMMC_STROBE),
	SPRD_PINCTRL_PIN(SC9853_EXTINT11),
	SPRD_PINCTRL_PIN(SC9853_EXTINT7),
	SPRD_PINCTRL_PIN(SC9853_EXTINT8),
	SPRD_PINCTRL_PIN(SC9853_SD1_CMD),
	SPRD_PINCTRL_PIN(SC9853_SD1_D0),
	SPRD_PINCTRL_PIN(SC9853_SD1_D1),
	SPRD_PINCTRL_PIN(SC9853_SD1_CLK),
	SPRD_PINCTRL_PIN(SC9853_SD1_D2),
	SPRD_PINCTRL_PIN(SC9853_SD1_D3),
	SPRD_PINCTRL_PIN(SC9853_U0TXD),
	SPRD_PINCTRL_PIN(SC9853_U0RXD),
	SPRD_PINCTRL_PIN(SC9853_U0CTS),
	SPRD_PINCTRL_PIN(SC9853_U0RTS),
	SPRD_PINCTRL_PIN(SC9853_IIS0DI),
	SPRD_PINCTRL_PIN(SC9853_IIS0DO),
	SPRD_PINCTRL_PIN(SC9853_IIS0CLK),
	SPRD_PINCTRL_PIN(SC9853_IIS0LRCK),
	SPRD_PINCTRL_PIN(SC9853_CLK_AUX0),
	SPRD_PINCTRL_PIN(SC9853_RFCTL19),
	SPRD_PINCTRL_PIN(SC9853_RFCTL18),
	SPRD_PINCTRL_PIN(SC9853_WIFI_COEXIST),
	SPRD_PINCTRL_PIN(SC9853_BEIDOU_COEXIST),
	SPRD_PINCTRL_PIN(SC9853_MTCK_ARM),
	SPRD_PINCTRL_PIN(SC9853_MTMS_ARM),
	SPRD_PINCTRL_PIN(SC9853_MTRST_N_ARM),
	SPRD_PINCTRL_PIN(SC9853_MTDO_ARM),
	SPRD_PINCTRL_PIN(SC9853_MTDI_ARM),
	SPRD_PINCTRL_PIN(SC9853_U3TXD),
	SPRD_PINCTRL_PIN(SC9853_U3RXD),
	SPRD_PINCTRL_PIN(SC9853_U3CTS),
	SPRD_PINCTRL_PIN(SC9853_U3RTS),
	SPRD_PINCTRL_PIN(SC9853_KEYOUT0),
	SPRD_PINCTRL_PIN(SC9853_KEYOUT1),
	SPRD_PINCTRL_PIN(SC9853_KEYOUT2),
	SPRD_PINCTRL_PIN(SC9853_KEYIN0),
	SPRD_PINCTRL_PIN(SC9853_KEYIN1),
	SPRD_PINCTRL_PIN(SC9853_KEYIN2),
	SPRD_PINCTRL_PIN(SC9853_SDA1),
	SPRD_PINCTRL_PIN(SC9853_SCL1),
	SPRD_PINCTRL_PIN(SC9853_EXTINT1),
	SPRD_PINCTRL_PIN(SC9853_EXTINT0),
	SPRD_PINCTRL_PIN(SC9853_EXTINT12),
	SPRD_PINCTRL_PIN(SC9853_EXTINT15),
	SPRD_PINCTRL_PIN(SC9853_CMPD1),
	SPRD_PINCTRL_PIN(SC9853_CMPD0),
	SPRD_PINCTRL_PIN(SC9853_CMRST1),
	SPRD_PINCTRL_PIN(SC9853_CMRST0),
	SPRD_PINCTRL_PIN(SC9853_CMMCLK1),
	SPRD_PINCTRL_PIN(SC9853_CMMCLK),
	SPRD_PINCTRL_PIN(SC9853_SDA0),
	SPRD_PINCTRL_PIN(SC9853_SCL0),
	SPRD_PINCTRL_PIN(SC9853_RFSEN0),
	SPRD_PINCTRL_PIN(SC9853_RFSCK0),
	SPRD_PINCTRL_PIN(SC9853_RFSDA0),
	SPRD_PINCTRL_PIN(SC9853_RFSEN1),
	SPRD_PINCTRL_PIN(SC9853_RFSCK1),
	SPRD_PINCTRL_PIN(SC9853_RFSDA1),
	SPRD_PINCTRL_PIN(SC9853_RFFE0_SDA),
	SPRD_PINCTRL_PIN(SC9853_RFFE0_SCK),
	SPRD_PINCTRL_PIN(SC9853_RFFE1_SDA),
	SPRD_PINCTRL_PIN(SC9853_RFFE1_SCK),
	SPRD_PINCTRL_PIN(SC9853_RF_LVDS0_DAC_ON),
	SPRD_PINCTRL_PIN(SC9853_RF_LVDS0_ADC_ON),
	SPRD_PINCTRL_PIN(SC9853_RFCTL0),
	SPRD_PINCTRL_PIN(SC9853_RFCTL1),
	SPRD_PINCTRL_PIN(SC9853_RFCTL2),
	SPRD_PINCTRL_PIN(SC9853_RFCTL3),
	SPRD_PINCTRL_PIN(SC9853_RFCTL4),
	SPRD_PINCTRL_PIN(SC9853_RFCTL5),
	SPRD_PINCTRL_PIN(SC9853_RFCTL6),
	SPRD_PINCTRL_PIN(SC9853_RFCTL7),
	SPRD_PINCTRL_PIN(SC9853_RFCTL8),
	SPRD_PINCTRL_PIN(SC9853_RFCTL9),
	SPRD_PINCTRL_PIN(SC9853_RFCTL10),
	SPRD_PINCTRL_PIN(SC9853_RFCTL11),
	SPRD_PINCTRL_PIN(SC9853_RFCTL12),
	SPRD_PINCTRL_PIN(SC9853_RFCTL13),
	SPRD_PINCTRL_PIN(SC9853_RFCTL14),
	SPRD_PINCTRL_PIN(SC9853_RFCTL15),
	SPRD_PINCTRL_PIN(SC9853_RFCTL16),
	SPRD_PINCTRL_PIN(SC9853_RFCTL17),
	SPRD_PINCTRL_PIN(SC9853_SD2_CMD),
	SPRD_PINCTRL_PIN(SC9853_SD2_D0),
	SPRD_PINCTRL_PIN(SC9853_SD2_D1),
	SPRD_PINCTRL_PIN(SC9853_SD2_CLK),
	SPRD_PINCTRL_PIN(SC9853_SD2_D2),
	SPRD_PINCTRL_PIN(SC9853_SD2_D3),
	SPRD_PINCTRL_PIN(SC9853_U4TXD),
	SPRD_PINCTRL_PIN(SC9853_U4RXD),
	SPRD_PINCTRL_PIN(SC9853_U2TXD),
	SPRD_PINCTRL_PIN(SC9853_U2RXD),
	SPRD_PINCTRL_PIN(SC9853_U1TXD),
	SPRD_PINCTRL_PIN(SC9853_U1RXD),
	SPRD_PINCTRL_PIN(SC9853_SDA4),
	SPRD_PINCTRL_PIN(SC9853_SCL4),
	SPRD_PINCTRL_PIN(SC9853_SCL2),
	SPRD_PINCTRL_PIN(SC9853_SDA2),
	SPRD_PINCTRL_PIN(SC9853_IIS3DI),
	SPRD_PINCTRL_PIN(SC9853_IIS3DO),
	SPRD_PINCTRL_PIN(SC9853_IIS3CLK),
	SPRD_PINCTRL_PIN(SC9853_IIS3LRCK),
	SPRD_PINCTRL_PIN(SC9853_IIS1DI),
	SPRD_PINCTRL_PIN(SC9853_IIS1DO),
	SPRD_PINCTRL_PIN(SC9853_IIS1CLK),
	SPRD_PINCTRL_PIN(SC9853_IIS1LRCK),
	SPRD_PINCTRL_PIN(SC9853_SPI0_CSN),
	SPRD_PINCTRL_PIN(SC9853_SPI0_DO),
	SPRD_PINCTRL_PIN(SC9853_SPI0_DI),
	SPRD_PINCTRL_PIN(SC9853_SPI0_CLK),
	SPRD_PINCTRL_PIN(SC9853_SIMCLK2),
	SPRD_PINCTRL_PIN(SC9853_SIMDA2),
	SPRD_PINCTRL_PIN(SC9853_SIMRST2),
	SPRD_PINCTRL_PIN(SC9853_SIMCLK1),
	SPRD_PINCTRL_PIN(SC9853_SIMDA1),
	SPRD_PINCTRL_PIN(SC9853_SIMRST1),
	SPRD_PINCTRL_PIN(SC9853_SIMCLK0),
	SPRD_PINCTRL_PIN(SC9853_SIMDA0),
	SPRD_PINCTRL_PIN(SC9853_SIMRST0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD0_D0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD0_D1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD0_CLK0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD0_CMD),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD0_D2),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD0_D3),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD_MS),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EXTINT5),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EXTINT6),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EXT_RST_B),
	SPRD_PINCTRL_PIN(SC9853_GROUP_AUD_SCLK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_DCDC_ARM_EN0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_CLK_32K),
	SPRD_PINCTRL_PIN(SC9853_GROUP_CHIP_SLEEP),
	SPRD_PINCTRL_PIN(SC9853_GROUP_AUD_ADD0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_AUD_DAD0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_AUD_ADSYNC),
	SPRD_PINCTRL_PIN(SC9853_GROUP_AUD_DAD1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_AUD_DASYNC),
	SPRD_PINCTRL_PIN(SC9853_GROUP_ADI_SCLK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_ADI_D),
	SPRD_PINCTRL_PIN(SC9853_GROUP_DCDC_ARM_EN1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SENSOR_HUB_ACTION),
	SPRD_PINCTRL_PIN(SC9853_GROUP_PTEST),
	SPRD_PINCTRL_PIN(SC9853_GROUP_ANA_INT),
	SPRD_PINCTRL_PIN(SC9853_GROUP_DSI_TE),
	SPRD_PINCTRL_PIN(SC9853_GROUP_LCM_RSTN),
	SPRD_PINCTRL_PIN(SC9853_GROUP_PWMA),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EXTINT10),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EXTINT9),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EMMC_CLK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EMMC_RSTB),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EMMC_CMD),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EMMC_D0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EMMC_D1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EMMC_D2),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EMMC_D3),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EMMC_D4),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EMMC_D5),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EMMC_D6),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EMMC_D7),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EMMC_STROBE),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EXTINT11),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EXTINT7),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EXTINT8),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD1_CMD),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD1_D0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD1_D1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD1_CLK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD1_D2),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD1_D3),
	SPRD_PINCTRL_PIN(SC9853_GROUP_KEYOUT0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_KEYOUT1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_KEYOUT2),
	SPRD_PINCTRL_PIN(SC9853_GROUP_KEYIN0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_KEYIN1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_KEYIN2),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SDA1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SCL1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EXTINT1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EXTINT0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EXTINT12),
	SPRD_PINCTRL_PIN(SC9853_GROUP_EXTINT15),
	SPRD_PINCTRL_PIN(SC9853_GROUP_U0TXD),
	SPRD_PINCTRL_PIN(SC9853_GROUP_U0RXD),
	SPRD_PINCTRL_PIN(SC9853_GROUP_U0CTS),
	SPRD_PINCTRL_PIN(SC9853_GROUP_U0RTS),
	SPRD_PINCTRL_PIN(SC9853_GROUP_IIS0DI),
	SPRD_PINCTRL_PIN(SC9853_GROUP_IIS0DO),
	SPRD_PINCTRL_PIN(SC9853_GROUP_IIS0CLK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_IIS0LRCK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_CLK_AUX0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL19),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL18),
	SPRD_PINCTRL_PIN(SC9853_GROUP_WIFI_COEXIST),
	SPRD_PINCTRL_PIN(SC9853_GROUP_BEIDOU_COEXIST),
	SPRD_PINCTRL_PIN(SC9853_GROUP_MTCK_ARM),
	SPRD_PINCTRL_PIN(SC9853_GROUP_MTMS_ARM),
	SPRD_PINCTRL_PIN(SC9853_GROUP_MTRST_N_ARM),
	SPRD_PINCTRL_PIN(SC9853_GROUP_MTDO_ARM),
	SPRD_PINCTRL_PIN(SC9853_GROUP_MTDI_ARM),
	SPRD_PINCTRL_PIN(SC9853_GROUP_U3TXD),
	SPRD_PINCTRL_PIN(SC9853_GROUP_U3RXD),
	SPRD_PINCTRL_PIN(SC9853_GROUP_U3CTS),
	SPRD_PINCTRL_PIN(SC9853_GROUP_U3RTS),
	SPRD_PINCTRL_PIN(SC9853_GROUP_CLK_AUX0_SEL),
	SPRD_PINCTRL_PIN(SC9853_GROUP_CMPD1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_CMPD0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_CMRST1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_CMRST0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_CMMCLK1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_CMMCLK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SDA0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SCL0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_CLK_AUX2_SEL),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFSEN0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFSCK0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFSDA0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFSEN1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFSCK1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFSDA1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFFE0_SDA),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFFE0_SCK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFFE1_SDA),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFFE1_SCK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RF_LVDS0_DAC_ON),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RF_LVDS0_ADC_ON),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL2),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL3),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL4),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL5),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL6),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL7),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL8),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL9),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL10),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL11),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL12),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL13),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL14),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL15),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL16),
	SPRD_PINCTRL_PIN(SC9853_GROUP_RFCTL17),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD2_CMD),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD2_D0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD2_D1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD2_CLK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD2_D2),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SD2_D3),
	SPRD_PINCTRL_PIN(SC9853_GROUP_U4TXD),
	SPRD_PINCTRL_PIN(SC9853_GROUP_U4RXD),
	SPRD_PINCTRL_PIN(SC9853_GROUP_U2TXD),
	SPRD_PINCTRL_PIN(SC9853_GROUP_U2RXD),
	SPRD_PINCTRL_PIN(SC9853_GROUP_U1TXD),
	SPRD_PINCTRL_PIN(SC9853_GROUP_U1RXD),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SDA4),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SCL4),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SCL2),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SDA2),
	SPRD_PINCTRL_PIN(SC9853_GROUP_IIS3DI),
	SPRD_PINCTRL_PIN(SC9853_GROUP_IIS3DO),
	SPRD_PINCTRL_PIN(SC9853_GROUP_IIS3CLK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_IIS3LRCK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_IIS1DI),
	SPRD_PINCTRL_PIN(SC9853_GROUP_IIS1DO),
	SPRD_PINCTRL_PIN(SC9853_GROUP_IIS1CLK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_IIS1LRCK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SPI0_CSN),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SPI0_DO),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SPI0_DI),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SPI0_CLK),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SIMCLK2),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SIMDA2),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SIMRST2),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SIMCLK1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SIMDA1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SIMRST1),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SIMCLK0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SIMDA0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SIMRST0),
	SPRD_PINCTRL_PIN(SC9853_GROUP_SIM_MS),
	SPRD_PINCTRL_PIN(SC9853_GROUP_CLK_AUX1_SEL),
};

#endif /* __SC9853I_PINS_H__ */
