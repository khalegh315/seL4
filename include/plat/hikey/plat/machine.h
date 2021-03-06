/*
 * Copyright 2016, General Dynamics C4 Systems
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(GD_GPL)
 */

#ifndef __PLAT_MACHINE_H
#define __PLAT_MACHINE_H

enum IRQConstants {
//  INTERRUPT_RESERVED         =   0,
//  INTERRUPT_RESERVED         =   1,
//  INTERRUPT_RESERVED         =   2,
//  INTERRUPT_RESERVED         =   3,
//  INTERRUPT_RESERVED         =   4,
//  INTERRUPT_RESERVED         =   5,
//  INTERRUPT_RESERVED         =   6,
//  INTERRUPT_RESERVED         =   7,
//  INTERRUPT_RESERVED         =   8,
//  INTERRUPT_RESERVED         =   9,
//  INTERRUPT_RESERVED         =  10,
//  INTERRUPT_RESERVED         =  11,
//  INTERRUPT_RESERVED         =  12,
//  INTERRUPT_RESERVED         =  13,
//  INTERRUPT_RESERVED         =  14,
//  INTERRUPT_RESERVED         =  15,
//  INTERRUPT_RESERVED         =  16,
//  INTERRUPT_RESERVED         =  17,
//  INTERRUPT_RESERVED         =  18,
//  INTERRUPT_RESERVED         =  19,
//  INTERRUPT_RESERVED         =  20,
//  INTERRUPT_RESERVED         =  21,
//  INTERRUPT_RESERVED         =  22,
//  INTERRUPT_RESERVED         =  23,
//  INTERRUPT_RESERVED         =  24,
//  INTERRUPT_RESERVED         =  25,
//  INTERRUPT_RESERVED         =  26,
    INTERRUPT_COREINTER0       =  27,
    INTERRUPT_COREINTER1       =  28,
    INTERRUPT_COREINTER2       =  29,
    INTERRUPT_COREINTER3       =  30,
    INTERRUPT_COREINTER4       =  31,
//  INTERRUPT_RESERVED         =  32,
//  INTERRUPT_RESERVED         =  33,
//  INTERRUPT_RESERVED         =  34,
//  INTERRUPT_RESERVED         =  35,
//  INTERRUPT_RESERVED         =  36,
//  INTERRUPT_RESERVED         =  37,
//  INTERRUPT_RESERVED         =  38,
    INTERRUPT_TSENSOR          =  39,
    INTERRUPT_RTC1             =  40,
//  INTERRUPT_RESERVED         =  41,
//  INTERRUPT_RESERVED         =  42,
//  INTERRUPT_RESERVED         =  43,
    INTERRUPT_RTC0             =  44,
    INTERRUPT_WDOG0            =  45,
    INTERRUPT_TIMER0           =  46,
    INTERRUPT_TIMER1           =  47,
    INTERRUPT_TIMER2           =  48,
    INTERRUPT_TIMER3           =  49,
    INTERRUPT_TIMER4           =  50,
    INTERRUPT_TIMER5           =  51,
    INTERRUPT_TIMER6           =  52,
    INTERRUPT_TIMER7           =  53,
    INTERRUPT_TIMER8           =  54,
    INTERRUPT_TIMER9           =  55,
    INTERRUPT_TIMER10          =  56,
    INTERRUPT_TIMER11          =  57,
    INTERRUPT_TIMER12          =  58,
    INTERRUPT_TIMER13          =  59,
    INTERRUPT_TIMER14          =  60,
    INTERRUPT_TIMER15          =  61,
    INTERRUPT_TIMER16          =  62,
    INTERRUPT_TIMER17          =  63,
//  INTERRUPT_RESERVED         =  64,
//  INTERRUPT_RESERVED         =  65,
//  INTERRUPT_RESERVED         =  66,
//  INTERRUPT_RESERVED         =  67,
    INTERRUPT_UART0            =  68,
    INTERRUPT_UART1            =  69,
    INTERRUPT_UART2            =  70,
    INTERRUPT_UART3            =  71,
    INTERRUPT_UART4            =  72,
//  INTERRUPT_RESERVED         =  73,
//  INTERRUPT_RESERVED         =  74,
//  INTERRUPT_RESERVED         =  75,
    INTERRUPT_I2C0             =  76,
    INTERRUPT_I2C1             =  77,
    INTERRUPT_I2C2             =  78,
    INTERRUPT_I2C3             =  79,
//  INTERRUPT_RESERVED         =  80,
//  INTERRUPT_RESERVED         =  81,
    INTERRUPT_SSP              =  82,
//  INTERRUPT_RESERVED         =  83,
    INTERRUPT_GPIO0            =  84,
    INTERRUPT_GPIO1            =  85,
    INTERRUPT_GPIO2            =  86,
    INTERRUPT_GPIO3            =  87,
    INTERRUPT_GPIO4            =  88,
    INTERRUPT_GPIO5            =  89,
    INTERRUPT_GPIO6            =  90,
    INTERRUPT_GPIO7            =  91,
    INTERRUPT_GPIO8            =  92,
    INTERRUPT_GPIO9            =  93,
    INTERRUPT_GPIO10           =  94,
    INTERRUPT_GPIO11           =  95,
    INTERRUPT_GPIO12           =  96,
    INTERRUPT_GPIO13           =  97,
    INTERRUPT_GPIO14           =  98,
    INTERRUPT_GPIO15           =  99,
    INTERRUPT_GPIO16           =  100,
    INTERRUPT_GPIO17           =  101,
    INTERRUPT_GPIO18           =  102,
    INTERRUPT_GPIO19           =  103,
    INTERRUPT_EMMC             =  104,
    INTERRUPT_SDMMC            =  105,
    INTERRUPT_SDIOMMC          =  106,
//  INTERRUPT_RESERVED         =  107,
//  INTERRUPT_RESERVED         =  108,
    INTERRUPT_USB2OTG          =  109,
    INTERRUPT_USB2OTG_BC       =  110,
    INTERRUPT_ADE_SEC          =  111,
    INTERRUPT_DDRC             =  112,
    INTERRUPT_AEDMAC0_NS       =  113,
//  INTERRUPT_RESERVED         =  114,
//  INTERRUPT_RESERVED         =  115,
    INTERRUPT_AEDMAC0_S        =  116,
//  INTERRUPT_RESERVED         =  117,
//  INTERRUPT_RESERVED         =  118,
//  INTERRUPT_RESERVED         =  119,
//  INTERRUPT_RESERVED         =  120,
//  INTERRUPT_RESERVED         =  121,
//  INTERRUPT_RESERVED         =  122,
//  INTERRUPT_RESERVED         =  123,
//  INTERRUPT_RESERVED         =  124,
//  INTERRUPT_RESERVED         =  125,
//  INTERRUPT_RESERVED         =  126,
//  INTERRUPT_RESERVED         =  127,
//  INTERRUPT_RESERVED         =  128,
//  INTERRUPT_RESERVED         =  129,
//  INTERRUPT_RESERVED         =  130,
    INTERRUPT_ACPU_PMUIRQ      =  131,
    INTERRUPT_ACPU_C0_AXI_E    =  132,
    INTERRUPT_ACPU_C1_AXI_E    =  133,
//  INTERRUPT_RESERVED         =  134,
    INTERRUPT_ACPU_CTIIRQ      =  135,
//  INTERRUPT_RESERVED         =  136,
//  INTERRUPT_RESERVED         =  137,
//  INTERRUPT_RESERVED         =  138,
//  INTERRUPT_RESERVED         =  139,
    INTERRUPT_ACPU_COMM_RXTX_COMB = 140,
    INTERRUPT_ACPU_SOFT_FIQ    =  141,
    INTERRUPT_G3D              =  142,
//  INTERRUPT_RESERVED         =  143,
//  INTERRUPT_RESERVED         =  144,
//  INTERRUPT_RESERVED         =  145,
    INTERRUPT_ADE              =  146,
    INTERRUPT_ADE_LDI          =  147,
    INTERRUPT_MIPI_DSI         =  148,
//  INTERRUPT_RESERVED         =  149,
//  INTERRUPT_RESERVED         =  150,
//  INTERRUPT_RESERVED         =  151,
    INTERRUPT_ISP              =  152,
    INTERRUPT_MIPI_CSI0        =  153,
    INTERRUPT_MIPI_CSI1        =  154,
    INTERRUPT_DIDACODEC        =  155,
    INTERRUPT_ACPU_Cluster0_IRQFIQOUT_CORE0 = 156,
    INTERRUPT_ACPU_Cluster1_IRQFIQOUT_CORE0 = 157,
//  INTERRUPT_RESERVED         =  158,
//  INTERRUPT_RESERVED         =  159,
    maxIRQ = 159
} platform_interrupt_t;

#define KERNEL_TIMER_IRQ        INTERRUPT_COREINTER0
#define KERNEL_PMU_IRQ          INTERRUPT_ACPU_PMUIRQ
#include <arch/machine/gic_pl390.h>

#endif  /* ! __PLAT_MACHINE_H */
