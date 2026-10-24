/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: the CPU function is only the first 50 instructions (0x80097B78-0x80097C3C, ends at jr $ra); the
 * remaining 61 words of the 0x1BC unit (0x80097C40-0x80097D30) are RSP microcode text, not CPU code, so C cannot cover the unit. See below. */
/* The "mfc0/mtc0" in this unit are NOT executed by the VR4300. From 0x80097C40 (D_80097C40) on, the words are RSP
 * code: they decode as RSP COP0 accesses ($4 SP_STATUS, $5 SP_DMA_FULL, $6 SP_DMA_BUSY, $7 SP_SEMAPHORE,
 * $11 DPC_STATUS; mtc0 $0/$1/$2 = SP_MEM_ADDR/SP_DRAM_ADDR/SP_RD_LEN, i.e. a DMA-start routine), jal/j targets
 * 0x84001120/0x8400114C/0x840010BC are IMEM 0x1120/0x114C/0x10BC (= 0x80097CE0/0x80097D0C/0x80097C7C if
 * 0x80097C40 is IMEM 0x1080, where task ucode text is loaded after rspboot), and the first instructions read
 * OSTask data_ptr/data_size (0x30/0x34($at)). That is the start of a graphics microcode's text segment, which
 * continues through func_80097D34 (whose words include COP2 vector ops 0x4A......, lqv 0xE8......); its branch
 * "back into func_80097B78" is RSP-relative. So no inline-asm CP0 helpers belong here: wrapping those words as
 * CPU mfc0/mtc0 would not be equivalent, and microcode is data (rule: no .word blobs), so it is left to the asm.
 * The C below is behaviour-equivalent to the CPU function only: 49 of its 50 instructions line up with
 * 0x80097B78..0x80097C3C (structural ratio 0.863 with immediates masked; the game forms &D_800D3130 then adds
 * 0x1AC separately, and keeps this+0x44 in v0/s1 where we use s1/s0). No inline asm is needed or used. Looks like a C++ destructor (vtable at 0x2C, member array of 3 x 0x14
 * at 0x44 destroyed back to front, member at 0x30, then the base destructor with the in-charge flag). */
#include "common.h"

extern u8 D_80020860[];  /* vtable for this class */
extern u8 D_800D3130[];
void func_8008BB50(void *);
void func_800A73EC(void *, s32);
void func_8008B490(void *, void *, s32);
void func_8008BB2C(void *, s32);
void func_800B19C0(void *, s32);
void func_800394A8(void *, s32);

void func_80097B78(u8 *this, s32 inChrg) {
    s32 guard[2]; /* 8-byte local object (sp+0x10), constructed by func_8008BB50, destroyed by func_8008BB2C(.., 2) */
    u8 *res;
    u8 *first;
    u8 *p;

    *(u8 **)(this + 0x2C) = D_80020860;
    func_8008BB50(guard);
    res = D_800D3130 + 0x1AC;
    func_800A73EC(res, 0x501);
    func_8008B490(guard, res, 0x501);
    func_8008BB2C(guard, 2);
    first = this + 0x44;
    if (first != NULL) {
        p = this + 0x80;
        while (p != first) {
            p -= 0x14;
            func_800B19C0(p, 2);
        }
    }
    func_800B19C0(this + 0x30, 2);
    func_800394A8(this, inChrg);
}
