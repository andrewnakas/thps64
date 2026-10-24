/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: aln ratio 0.659; global-alloc priority: switch value 1.62 vs p <=1.47 even with loop-weighted stores, best 55/83. Equivalent C; only register allocation / scheduling / loop-invariant placement differ. */
/* Z2 near-miss 55/83. Only a v1/a2 swap: the switch value takes v1 and p a2; the game has p v1, switch value a2.
 * global.c priority floor_log2(refs)*refs/live: switch value 14 refs/26 insns (1.62) beats p (16 refs/57, live from
 * entry because the default path returns the uninitialized p + 3). Loop-weighting the store block with do-while(0)
 * macros raises p to 21 refs (1.47) but not past 1.62. */
#include "common.h"

extern u8 **D_800DACB0;

s32 *func_800617B8(s32 *arg0, s32 arg1) {
    u8 *e;
    u32 p;

    e = D_800DACB0[arg1];
    switch (*(u16 *)e) {
    case 1:
    case 7:
        e += *(u16 *)(e + 6) * 2 + 8;
        while (*e != 0xFF) {
            e++;
        }
        p = (u32)(e + 4);
        goto store;
    case 3:
    case 8:
    case 10:
    case 11:
    case 13:
    case 1000:
    case 1001:
        p = *(u16 *)(e + 2) * 2 + (u32)e + 7;
        goto store;
    case 5:
        p = *(u16 *)(e + 4) * 2 + (u32)e + 9;
        goto store;
    case 500:
    case 501:
        p = (u32)(e + 5);
    store:
        p &= ~3;
        arg0[0] = ((s32 *)p)[0] << 12;
        arg0[1] = ((s32 *)p)[1] << 12;
        arg0[2] = ((s32 *)p)[2] << 12;
        break;
    }
    return (s32 *)p + 3;
}
