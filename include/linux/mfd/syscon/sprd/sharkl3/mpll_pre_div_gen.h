/*
 * Copyright (C) 2017 Spreadtrum Communications Inc.
 *
 * This file is dual-licensed: you can use it either under the terms
 * of the GPL or the X11 license, at your option. Note that this dual
 * licensing only applies to this file, and not this project as a
 * whole.
 *
 * updated at 2017-12-27 19:24:16
 *
 */


#ifndef MPLL_PRE_DIV_GEN_H
#define MPLL_PRE_DIV_GEN_H



#define REG_MPLL_PRE_DIV_GEN_SOFT_CNT_DONE0_CFG                (0x0020)
#define REG_MPLL_PRE_DIV_GEN_PLL_WAIT_SEL0_CFG                 (0x0024)
#define REG_MPLL_PRE_DIV_GEN_PLL_WAIT_SW_CTL0_CFG              (0x0028)
#define REG_MPLL_PRE_DIV_GEN_DIV_EN_SEL0_CFG                   (0x002C)
#define REG_MPLL_PRE_DIV_GEN_DIV_EN_SW_CTL0_CFG                (0x0030)
#define REG_MPLL_PRE_DIV_GEN_GATE_EN_SEL0_CFG                  (0x0034)
#define REG_MPLL_PRE_DIV_GEN_GATE_EN_SW_CTL0_CFG               (0x0038)
#define REG_MPLL_PRE_DIV_GEN_MONITOR_WAIT_EN_STATUS0_CFG       (0x003C)
#define REG_MPLL_PRE_DIV_GEN_MONITOR_DIV_AUTO_EN_STATUS0_CFG   (0x0040)
#define REG_MPLL_PRE_DIV_GEN_MONITOR_GATE_AUTO_EN_STATUS0_CFG  (0x0044)

/* REG_MPLL_PRE_DIV_GEN_SOFT_CNT_DONE0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_SOFT_CNT_DONE0_CFG_MPLL0_SOFT_CNT_DONE                           BIT(2)
#define BIT_MPLL_PRE_DIV_GEN_SOFT_CNT_DONE0_CFG_MPLL1_SOFT_CNT_DONE                           BIT(1)
#define BIT_MPLL_PRE_DIV_GEN_SOFT_CNT_DONE0_CFG_MPLL2_SOFT_CNT_DONE                           BIT(0)

/* REG_MPLL_PRE_DIV_GEN_PLL_WAIT_SEL0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_PLL_WAIT_SEL0_CFG_MPLL0_WAIT_AUTO_GATE_SEL                       BIT(2)
#define BIT_MPLL_PRE_DIV_GEN_PLL_WAIT_SEL0_CFG_MPLL1_WAIT_AUTO_GATE_SEL                       BIT(1)
#define BIT_MPLL_PRE_DIV_GEN_PLL_WAIT_SEL0_CFG_MPLL2_WAIT_AUTO_GATE_SEL                       BIT(0)

/* REG_MPLL_PRE_DIV_GEN_PLL_WAIT_SW_CTL0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_PLL_WAIT_SW_CTL0_CFG_MPLL0_WAIT_FORCE_EN                         BIT(2)
#define BIT_MPLL_PRE_DIV_GEN_PLL_WAIT_SW_CTL0_CFG_MPLL1_WAIT_FORCE_EN                         BIT(1)
#define BIT_MPLL_PRE_DIV_GEN_PLL_WAIT_SW_CTL0_CFG_MPLL2_WAIT_FORCE_EN                         BIT(0)

/* REG_MPLL_PRE_DIV_GEN_DIV_EN_SEL0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_DIV_EN_SEL0_CFG_MPLL2_DIV_675M_AUTO_GATE_SEL                     BIT(0)

/* REG_MPLL_PRE_DIV_GEN_DIV_EN_SW_CTL0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_DIV_EN_SW_CTL0_CFG_MPLL2_DIV_675M_FORCE_EN                       BIT(0)

/* REG_MPLL_PRE_DIV_GEN_GATE_EN_SEL0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_GATE_EN_SEL0_CFG_CGM_MPLL0_1200M_CPU_AUTO_GATE_SEL               BIT(3)
#define BIT_MPLL_PRE_DIV_GEN_GATE_EN_SEL0_CFG_CGM_MPLL1_1500M_CPU_AUTO_GATE_SEL               BIT(2)
#define BIT_MPLL_PRE_DIV_GEN_GATE_EN_SEL0_CFG_CGM_MPLL2_1350M_CPU_AUTO_GATE_SEL               BIT(1)
#define BIT_MPLL_PRE_DIV_GEN_GATE_EN_SEL0_CFG_CGM_MPLL2_675M_AON_AUTO_GATE_SEL                BIT(0)

/* REG_MPLL_PRE_DIV_GEN_GATE_EN_SW_CTL0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_GATE_EN_SW_CTL0_CFG_CGM_MPLL0_1200M_CPU_FORCE_EN                 BIT(3)
#define BIT_MPLL_PRE_DIV_GEN_GATE_EN_SW_CTL0_CFG_CGM_MPLL1_1500M_CPU_FORCE_EN                 BIT(2)
#define BIT_MPLL_PRE_DIV_GEN_GATE_EN_SW_CTL0_CFG_CGM_MPLL2_1350M_CPU_FORCE_EN                 BIT(1)
#define BIT_MPLL_PRE_DIV_GEN_GATE_EN_SW_CTL0_CFG_CGM_MPLL2_675M_AON_FORCE_EN                  BIT(0)

/* REG_MPLL_PRE_DIV_GEN_MONITOR_WAIT_EN_STATUS0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_MONITOR_WAIT_EN_STATUS0_CFG_MONITOR_WAIT_EN_STATUS(x)            (((x) & 0x7))

/* REG_MPLL_PRE_DIV_GEN_MONITOR_DIV_AUTO_EN_STATUS0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_MONITOR_DIV_AUTO_EN_STATUS0_CFG_MONITOR_DIV_AUTO_EN_STATUS       BIT(0)

/* REG_MPLL_PRE_DIV_GEN_MONITOR_GATE_AUTO_EN_STATUS0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_MONITOR_GATE_AUTO_EN_STATUS0_CFG_MONITOR_GATE_AUTO_EN_STATUS(x)  (((x) & 0xF))


#endif /* MPLL_PRE_DIV_GEN_H */

