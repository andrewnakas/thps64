/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

typedef struct VT {
    u8 pad0[0x30];
    s16 unk30;
    u8 pad32[2];
    void (*unk34)(void *, s32, void *, void *);
} VT;

typedef struct Ent {
    u8 pad0[4];
    u8 unk4[0x18];
    struct Ent *unk1C;
    u8 pad20[0x28];
    VT *unk48;
    u8 pad4C[6];
    u16 unk52;
} Ent;

void func_80046FBC(f32 *, void *, void *);
s32 func_800474C8(f32 *);
extern u8 D_800D6188[];

void func_800493E8(s32 arg0, void *arg1, void *arg2, s32 arg3, Ent *arg4, Ent *arg5) {
    f32 v[4];
    s32 n;
    VT *vt;

    while (1) {
        if (arg4 == NULL) {
            break;
        }
        if (arg4 != arg5 && !(arg4->unk52 & 0x40)) {
            func_80046FBC(v, arg2, arg4->unk4);
            n = arg0 - arg0 * func_800474C8(v) / arg3;
            if (n > 0) {
                vt = arg4->unk48;
                vt->unk34((u8 *)arg4 + vt->unk30, n, D_800D6188, arg1);
            }
        }
        arg4 = arg4->unk1C;
    }
}
