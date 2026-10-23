/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad[0x2C];
    u32 *colors;
    u8 pad2[0x48 - 0x30];
} Entry48;

typedef struct {
    u8 pad[0x28];
    s16 off;
    s16 pad2;
    void (*fn)(void *);
} VT;

extern Entry48 D_800DAF98[];

void func_8004BBD4(u8 *arg0, u8 *arg1, u8 *arg2) {
    u32 *tbl;
    s32 n;
    s32 i;
    u32 m;
    VT *vt;

    n = *(u16 *)arg1;
    if (n & 0x800) {
        tbl = D_800DAF98[arg2[0x1B]].colors;
        *(s32 *)(arg0 + 0x974) = 0;
        if (n & 0x10) {
            n = 3;
        } else {
            n = 4;
        }
        i = 0;
        while (1) {
            if (i >= n) break;
            m = tbl[arg1[i + 8]] & 0xFFFFFF;
            *(s32 *)(arg0 + 0x974) = *(s32 *)(arg0 + 0x974) + (m & 0xFF) + ((m >> 8) & 0xFF) + (m = m >> 16);
            i++;
        }
        *(s32 *)(arg0 + 0x974) = *(s32 *)(arg0 + 0x974) / (n * 3);
    } else {
        u32 c = *(u32 *)(arg1 + 8) & 0xFFFFFF;
        *(s32 *)(arg0 + 0x974) = (s32)((c & 0xFF) + ((c >> 8) & 0xFF) + (c >> 16)) / 3;
    }
    *(s32 *)(arg0 + 0x974) = *(s32 *)(arg0 + 0x974) * 3;
    vt = *(VT **)(arg0 + 0x48);
    vt->fn(arg0 + vt->off);
}
