/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x20];
    u8 *unk20;
    u8 pad24[0x24];
} Tbl8004A204;

typedef struct {
    u8 pad0[0x1B];
    u8 unk1B;
    u8 pad1C[0x21C - 0x1C];
    s16 unk21C;
    u16 unk21E;
    s8 unk220;
    s8 unk221;
    s8 unk222;
    s8 unk223;
    s16 unk224;
    u8 unk226;
    s8 unk227;
} Obj8004A204;

extern Tbl8004A204 D_800DAF98[];

void func_8004A204(Obj8004A204 *arg0, s32 idx, s32 lo, s32 hi, s32 arg4) {
    Obj8004A204 *o;
    Tbl8004A204 *tbl;
    u32 k;
    u8 n;
    u32 m;
    s32 m1;

    o = arg0;
    o->unk21E = idx;
    k = o->unk21E;
    tbl = D_800DAF98;
    if (k >= *(u32 *)tbl[o->unk1B].unk20) {
        o->unk21E = 0x2E;
    }
    o->unk226 = tbl[o->unk1B].unk20[o->unk21E * 8 + 0xB];
    m1 = -1;
    if (lo == m1) {
        lo += o->unk226;
    }
    if (hi == m1) {
        hi += o->unk226;
    }
    if (lo < 0) {
        lo = 0;
    }
    if (hi < 0) {
        hi = 0;
    }
    m = o->unk226;
    if (lo >= (s32)m) {
        lo = m - 1;
    }
    if (hi >= (s32)m) {
        hi = m - 1;
    }
    o->unk220 = 0;
    if (lo >= hi) {
        if (hi < lo) {
            o->unk221 = m1;
        } else {
            o->unk221 = 0;
        }
    } else {
        o->unk221 = 1;
    }
    o->unk21C = lo;
    o->unk222 = hi;
    o->unk223 = arg4;
    o->unk224 = 0;
    o->unk227 = (o->unk21C == o->unk222);
}
