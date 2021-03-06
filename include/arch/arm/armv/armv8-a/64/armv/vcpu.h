/*
 * Copyright 2018, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(DATA61_GPL)
 */

#ifndef __ARCH_ARMV_VCPU_H_
#define __ARCH_ARMV_VCPU_H_

#include <config.h>

#ifdef CONFIG_ARM_HYPERVISOR_SUPPORT

#include <arch/object/vcpu.h>

/* Note that the HCR_DC for ARMv8 disables S1 translation if enabled */
/* Trap WFI/WFE/SMC and override CPSR.AIF */
#define HCR_COMMON ( HCR_TWI | HCR_TWE | HCR_VM | HCR_RW | HCR_AMO | HCR_IMO | HCR_FMO )

/* Allow native tasks to run at EL0, but restrict access */
#define HCR_NATIVE ( HCR_COMMON | HCR_TGE | HCR_TVM | HCR_TTLB | HCR_DC \
                   | HCR_TAC | HCR_SWIO |  HCR_TSC | HCR_IMO | HCR_FMO | HCR_AMO)
#define HCR_VCPU   ( HCR_COMMON)

#define SCTLR_EL1_UCI       BIT(26)     /* Enable EL0 access to DC CVAU, DC CIVAC, DC CVAC,
                                           and IC IVAU in AArch64 state   */
#define SCTLR_EL1_C         BIT(2)      /* Enable data and unified caches */
#define SCTLR_EL1_I         BIT(12)     /* Enable instruction cache       */
#define SCTLR_EL1_CP15BEN   BIT(5)      /* AArch32 CP15 barrier enable    */
#define SCTLR_EL1_UTC       BIT(15)     /* Enable EL0 access to CTR_EL0   */
#define SCTLR_EL1_NTWI      BIT(16)     /* WFI executed as normal         */
#define SCTLR_EL1_NTWE      BIT(18)     /* WFE executed as normal         */

/* Disable MMU, SP alignment check, and alignment check */
/* A57 default value */
#define SCTLR_EL1_RES      0x30d00800   /* Reserved value */
#define SCTLR_EL1          ( SCTLR_EL1_RES | SCTLR_EL1_CP15BEN | SCTLR_EL1_UTC \
                           | SCTLR_EL1_NTWI | SCTLR_EL1_NTWE )
#define SCTLR_EL1_NATIVE   (SCTLR_EL1 | SCTLR_EL1_C | SCTLR_EL1_I | SCTLR_EL1_UCI)
#define SCTLR_EL1_VM       (SCTLR_EL1 | SCTLR_EL1_UCI)
#define SCTLR_DEFAULT      SCTLR_EL1_NATIVE

#define UNKNOWN_FAULT       0x2000000
#define ESR_EC_TFP          0x7         /* Trap instructions that access FPU registers */
#define ESR_EC_CPACR        0x18        /* Trap access to CPACR                        */
#define ESR_EC(x)           (((x) & 0xfc000000) >> 26)

#define VTCR_EL2_T0SZ(x)    (x)
#define VTCR_EL2_SL0(x)     ((x) << 6)
#define VTCR_EL2_IRGN0(x)   ((x) << 8)
#define VTCR_EL2_ORGN0(x)   ((x) << 10)
#define VTCR_EL2_SH0(x)     ((x) << 12)
#define VTCR_EL2_TG0(x)     ((x) << 14)
#define VTCR_EL2_PS(x)      ((x) << 16)

/* Physical address size */
#define PS_4G               0
#define PS_64G              0b001
#define PS_1T               0b010
#define PS_4T               0b011
#define PS_16T              0b100
#define PS_256T             0b101

/* Translation granule size */
#define TG0_4K              0
#define TG0_64K             0b01
#define TG0_16K             0b10

/* Shareability attributes */
#define SH0_NONE            0
#define SH0_OUTER           0b10
#define SH0_INNER           0b11

/* Cacheability attributes */
#define NORMAL_NON_CACHEABLE    0
#define NORMAL_WB_WA_CACHEABLE  0b01 /* write-back, write-allocate      */
#define NORMAL_WT_CACHEABLE     0b10 /* write-through                   */
#define NORMAL_WB_NWA_CACHEABLE 0b11 /* write-back, no write-allocate   */

/* Start level  */
#define SL0_4K_L2       0           /* 4K, start at level 2 */
#define SL0_4K_L1       0b01        /* 4K, start at level 1 */
#define SL0_4K_L0       0b10        /* 4K, start at level 0 */

#define REG_SCTLR_EL1       "sctlr_el1"
#define REG_TTBR0_EL1       "ttbr0_el1"
#define REG_TTBR1_EL1       "ttbr1_el1"
#define REG_TCR_EL1         "tcr_el1"
#define REG_MAIR_EL1        "mair_el1"
#define REG_AMAIR_EL1       "amair_el1"
#define REG_CONTEXTIDR_EL1  "contextidr_el1"
#define REG_ACTLR_EL1       "actlr_el1"
#define REG_AFSR0_EL1       "afsr0_el1"
#define REG_AFSR1_EL1       "afsr1_el1"
#define REG_ESR_EL1         "esr_el1"
#define REG_FAR_EL1         "far_el1"
#define REG_ISR_EL1         "isr_el1"
#define REG_VBAR_EL1        "vbar_el1"
#define REG_TPIDR_EL0       "tpidr_el0"
#define REG_TPIDR_EL1       "tpidr_el1"
#define REG_TPIDRRO_EL0     "tpidrro_el0"
#define REG_SP_EL1          "sp_el1"
#define REG_ELR_EL1         "elr_el1"
#define REG_SPSR_EL1        "spsr_el1"
#define REG_CPACR_EL1       "cpacr_el1"
#define REG_CNTV_TVAL_EL0   "cntv_tval_el0"
#define REG_CNTV_CTL_EL0    "cntv_ctl_el0"
#define REG_HCR_EL2         "hcr_el2"
#define REG_VTCR_EL2        "vtcr_el2"

/* for EL1 SCTLR */
static inline word_t
getSCTLR(void)
{
    return readSystemControlRegister();
}

static inline void
setSCTLR(word_t sctlr)
{
    writeSystemControlRegister(sctlr);
}

static inline word_t
readTTBR0(void)
{
    word_t reg;
    MRS(REG_TTBR0_EL1, reg);
    return reg;
}

static inline void
writeTTBR0(word_t reg)
{
    MSR(REG_TTBR0_EL1, reg);
}

static inline word_t
readTTBR1(void)
{
    word_t reg;
    MRS(REG_TTBR1_EL1, reg);
    return reg;
}

static inline void
writeTTBR1(word_t reg)
{
    MSR(REG_TTBR1_EL1, reg);
}

static inline word_t
readTCR(void)
{
    word_t reg;
    MRS(REG_TCR_EL1, reg);
    return reg;
}

static inline void
writeTCR(word_t reg)
{
    MSR(REG_TCR_EL1, reg);
}

static inline word_t
readMAIR(void)
{
    word_t reg;
    MRS(REG_MAIR_EL1, reg);
    return reg;
}

static inline void
writeMAIR(word_t reg)
{
    MSR(REG_MAIR_EL1, reg);
}

static inline word_t
readAMAIR(void)
{
    word_t reg;
    MRS(REG_AMAIR_EL1, reg);
    return reg;
}

static inline void
writeAMAIR(word_t reg)
{
    MSR(REG_AMAIR_EL1, reg);
}

static inline word_t
readCIDR(void)
{
    uint32_t reg;
    MRS(REG_CONTEXTIDR_EL1, reg);
    return (word_t)reg;
}

static inline void
writeCIDR(word_t reg)
{
    MSR(REG_CONTEXTIDR_EL1, (uint32_t)reg);
}

static inline word_t
readACTLR(void)
{
    word_t reg;
    MRS(REG_ACTLR_EL1, reg);
    return reg;
}

static inline void
writeACTLR(word_t reg)
{
    MSR(REG_ACTLR_EL1, reg);
}

static inline word_t
readAFSR0(void)
{
    uint32_t reg;
    MRS(REG_AFSR0_EL1, reg);
    return (word_t)reg;
}

static inline void
writeAFSR0(word_t reg)
{
    MSR(REG_AFSR0_EL1, (uint32_t)reg);
}

static inline word_t
readAFSR1(void)
{
    uint32_t reg;
    MRS(REG_AFSR1_EL1, reg);
    return (word_t)reg;
}

static inline void
writeAFSR1(word_t reg)
{
    MSR(REG_AFSR1_EL1, (uint32_t)reg);
}

static inline word_t
readESR(void)
{
    uint32_t reg;
    MRS(REG_ESR_EL1, reg);
    return (word_t)reg;
}

static inline void
writeESR(word_t reg)
{
    MSR(REG_ESR_EL1, (uint32_t)reg);
}

static inline word_t
readFAR(void)
{
    word_t reg;
    MRS(REG_FAR_EL1, reg);
    return reg;
}

static inline void
writeFAR(word_t reg)
{
    MSR(REG_FAR_EL1, (uint32_t)reg);
}

/* ISR is read-only */
static inline word_t
readISR(void)
{
    uint32_t reg;
    MRS(REG_ISR_EL1, reg);
    return (word_t)reg;
}

static inline word_t
readVBAR(void)
{
    word_t reg;
    MRS(REG_VBAR_EL1, reg);
    return reg;
}

static inline void
writeVBAR(word_t reg)
{
    MSR(REG_VBAR_EL1, reg);
}

static inline word_t
readTPIDR_EL0(void)
{
    word_t reg;
    MRS(REG_TPIDR_EL0, reg);
    return reg;
}

static inline void
writeTPIDR_EL0(word_t reg)
{
    MSR(REG_TPIDR_EL0, reg);
}

static inline word_t
readTPIDR_EL1(void)
{
    word_t reg;
    MRS(REG_TPIDR_EL1, reg);
    return reg;
}

static inline void
writeTPIDR_EL1(word_t reg)
{
    MSR(REG_TPIDR_EL1, reg);
}

static inline word_t
readTPIDRRO_EL0(void)
{
    word_t reg;
    MRS(REG_TPIDRRO_EL0, reg);
    return reg;
}

static inline void
writeTPIDRRO_EL0(word_t reg)
{
    MSR(REG_TPIDRRO_EL0, reg);
}

static inline word_t
readSP_EL1(void)
{
    word_t reg;
    MRS(REG_SP_EL1, reg);
    return reg;
}

static inline void
writeSP_EL1(word_t reg)
{
    MSR(REG_SP_EL1, reg);
}

static inline word_t
readELR_EL1(void)
{
    word_t reg;
    MRS(REG_ELR_EL1, reg);
    return reg;
}

static inline void
writeELR_EL1(word_t reg)
{
    MRS(REG_ELR_EL1, reg);
}

static inline word_t
readSPSR_EL1(void)
{
    word_t reg;
    MRS(REG_SPSR_EL1, reg);
    return reg;
}

static inline void
writeSPSR_EL1(word_t reg)
{
    MSR(REG_SPSR_EL1, reg);
}

static inline word_t
readCPACR_EL1(void)
{
    word_t reg;
    MRS(REG_CPACR_EL1, reg);
    return reg;
}

static inline void
writeCPACR_EL1(word_t reg)
{
    MSR(REG_CPACR_EL1, reg);
}

static inline word_t
readCNTV_TVAL_EL0(void)
{
    word_t reg;
    MRS(REG_CNTV_TVAL_EL0, reg);
    return reg;
}

static inline void
writeCNTV_TVAL_EL0(word_t reg)
{
    MSR(REG_CNTV_TVAL_EL0, reg);
}

static inline word_t
readCNTV_CTL_EL0(void)
{
    word_t reg;
    MRS(REG_CNTV_CTL_EL0, reg);
    return reg;
}

static inline void
writeCNTV_CTL_EL0(word_t reg)
{
    MSR(REG_CNTV_CTL_EL0, reg);
}

static word_t
vcpu_hw_read_reg(word_t reg_index)
{
    word_t reg = 0;
    switch (reg_index) {
    case seL4_VCPUReg_SCTLR:
        return getSCTLR();
    case seL4_VCPUReg_TTBR0:
        return readTTBR0();
    case seL4_VCPUReg_TTBR1:
        return readTTBR1();
    case seL4_VCPUReg_TCR:
        return readTCR();
    case seL4_VCPUReg_MAIR:
        return readMAIR();
    case seL4_VCPUReg_AMAIR:
        return readAMAIR();
    case seL4_VCPUReg_CIDR:
        return readCIDR();
    case seL4_VCPUReg_ACTLR:
        return readACTLR();
    case seL4_VCPUReg_CPACR:
        return readCPACR_EL1();
    case seL4_VCPUReg_AFSR0:
        return readAFSR0();
    case seL4_VCPUReg_AFSR1:
        return readAFSR1();
    case seL4_VCPUReg_ESR:
        return readESR();
    case seL4_VCPUReg_FAR:
        return readFAR();
    case seL4_VCPUReg_ISR:
        return readISR();
    case seL4_VCPUReg_VBAR:
        return readVBAR();
    case seL4_VCPUReg_TPIDR_EL0:
        return readTPIDR_EL0();
    case seL4_VCPUReg_TPIDR_EL1:
        return readTPIDR_EL1();
    case seL4_VCPUReg_TPIDRRO_EL0:
        return readTPIDRRO_EL0();
    case seL4_VCPUReg_CNTV_TVAL:
        return readCNTV_TVAL_EL0();
    case seL4_VCPUReg_CNTV_CTL:
        return readCNTV_CTL_EL0();
    case seL4_VCPUReg_CNTV_CVAL:
        return 0;
    case seL4_VCPUReg_SP_EL1:
        return readSP_EL1();
    case seL4_VCPUReg_ELR_EL1:
        return readELR_EL1();
    case seL4_VCPUReg_SPSR_EL1:
        return readSPSR_EL1();
    default:
        fail("ARM/HYP: Invalid register index");
    }

    return reg;
}

static void
vcpu_hw_write_reg(word_t reg_index, word_t reg)
{
    switch (reg_index) {
    case seL4_VCPUReg_SCTLR:
        return setSCTLR(reg);
    case seL4_VCPUReg_TTBR0:
        return writeTTBR0(reg);
    case seL4_VCPUReg_TTBR1:
        return writeTTBR1(reg);
    case seL4_VCPUReg_TCR:
        return writeTCR(reg);
    case seL4_VCPUReg_MAIR:
        return writeMAIR(reg);
    case seL4_VCPUReg_AMAIR:
        return writeAMAIR(reg);
    case seL4_VCPUReg_CIDR:
        return writeCIDR(reg);
    case seL4_VCPUReg_ACTLR:
        return writeACTLR(reg);
    case seL4_VCPUReg_CPACR:
        return writeCPACR_EL1(reg);
    case seL4_VCPUReg_AFSR0:
        return writeAFSR0(reg);
    case seL4_VCPUReg_AFSR1:
        return writeAFSR1(reg);
    case seL4_VCPUReg_ESR:
        return writeESR(reg);
    case seL4_VCPUReg_FAR:
        return writeFAR(reg);
    case seL4_VCPUReg_ISR:
        /* ISR is read-only */
        return;
    case seL4_VCPUReg_VBAR:
        return writeVBAR(reg);
    case seL4_VCPUReg_TPIDR_EL0:
        return writeTPIDR_EL0(reg);
    case seL4_VCPUReg_TPIDR_EL1:
        return writeTPIDR_EL1(reg);
    case seL4_VCPUReg_TPIDRRO_EL0:
        return writeTPIDRRO_EL0(reg);
    case seL4_VCPUReg_CNTV_TVAL:
        return writeCNTV_TVAL_EL0(reg);
    case seL4_VCPUReg_CNTV_CTL:
        return writeCNTV_CTL_EL0(reg);
    case seL4_VCPUReg_CNTV_CVAL:
        return;
    case seL4_VCPUReg_SP_EL1:
        return writeSP_EL1(reg);
    case seL4_VCPUReg_ELR_EL1:
        return writeELR_EL1(reg);
    case seL4_VCPUReg_SPSR_EL1:
        return writeSPSR_EL1(reg);
    default:
        fail("ARM/HYP: Invalid register index");
    }

    return;
}

static inline void
vcpu_init_vtcr(void)
{
    /* Set up the stage-2 translation control register for cores supporting 44-bit PA */
    uint32_t vtcr_el2 = VTCR_EL2_T0SZ(20);                   // 44-bit input IPA
    vtcr_el2 |= VTCR_EL2_SL0(SL0_4K_L0);                     // 4KiB, start at level 0
    vtcr_el2 |= VTCR_EL2_IRGN0(NORMAL_WB_WA_CACHEABLE);      // inner write-back, read/write allocate
    vtcr_el2 |= VTCR_EL2_ORGN0(NORMAL_WB_WA_CACHEABLE);      // outer write-back, read/write allocate
    vtcr_el2 |= VTCR_EL2_SH0(SH0_INNER);                     // inner shareable
    vtcr_el2 |= VTCR_EL2_TG0(TG0_4K);                        // 4KiB page size
    vtcr_el2 |= VTCR_EL2_PS(PS_16T);                         // 44-bit PA size
    vtcr_el2 |= BIT(31);                                     // reserved as 1

    MSR(REG_VTCR_EL2, vtcr_el2);
    isb();
}

static inline void
armv_vcpu_boot_init(void)
{
    word_t hcr_el2 = 0;

    vcpu_init_vtcr();

    hcr_el2 = HCR_NATIVE;
    MSR(REG_HCR_EL2, hcr_el2);
    isb();

    /* set the SCTLR_EL1 for running native seL4 threads */
    MSR(REG_SCTLR_EL1, SCTLR_EL1_NATIVE);
    isb();
}

static inline void
armv_vcpu_enable(vcpu_t *vcpu)
{
    MSR(REG_HCR_EL2, HCR_VCPU);
    isb();
    vcpu_hw_write_reg(seL4_VCPUReg_SCTLR, vcpu->regs[seL4_VCPUReg_SCTLR]);
    isb();

    set_gic_vcpu_ctrl_hcr(vcpu->vgic.hcr);
#ifdef CONFIG_HAVE_FPU
    vcpu_hw_write_reg(seL4_VCPUReg_CPACR, vcpu->regs[seL4_VCPUReg_CPACR]);
#endif
}

static inline void
armv_vcpu_disable(vcpu_t *vcpu)
{

    uint32_t hcr;
    dsb();
    if (likely(vcpu)) {
        hcr = get_gic_vcpu_ctrl_hcr();
        vcpu->vgic.hcr = hcr;
        vcpu->regs[seL4_VCPUReg_SCTLR] = vcpu_hw_read_reg(seL4_VCPUReg_SCTLR);
#ifdef CONFIG_HAVE_FPU
        vcpu->regs[seL4_VCPUReg_CPACR] = vcpu_hw_read_reg(seL4_VCPUReg_CPACR);
#endif
        isb();
    }
    /* Turn off the VGIC */
    set_gic_vcpu_ctrl_hcr(0);
    isb();

    /* Stage 1 MMU off */
    setSCTLR(SCTLR_DEFAULT);
    isb();
    MSR(REG_HCR_EL2, HCR_NATIVE);
    isb();

#ifdef CONFIG_HAVE_FPU
    /* Allow FPU instructions in EL0 and EL1 for native
     * threads by setting the CPACR_EL1. The CPTR_EL2 is
     * used to trap the FPU instructions to EL2.
     */
    enableFpuEL01();
#endif
}

static inline void
armv_vcpu_init(vcpu_t *vcpu)
{
    vcpu->regs[seL4_VCPUReg_SCTLR] = SCTLR_EL1_VM;
}

static inline bool_t
armv_handleVCPUFault(word_t hsr)
{
#ifdef CONFIG_HAVE_FPU
    if ((ESR_EC(hsr) == ESR_EC_TFP || ESR_EC(hsr) == ESR_EC_CPACR) && !isFpuEnable()) {
        handleFPUFault();
        setNextPC(NODE_STATE(ksCurThread), getRestartPC(NODE_STATE(ksCurThread)));
        return true;
    }
#endif

    if (hsr == UNKNOWN_FAULT) {
        handleUserLevelFault(0, 0);
        return true;
    }

    return false;
}

#endif /* End of CONFIG_ARM_HYPERVISOR_SUPPORT */

#endif

