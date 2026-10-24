/* cflags: -fcse-follow-jumps -fcse-skip-blocks */
#include "common.h"

typedef struct {
    u8 n;
    u8 pad1;
    u8 port[2];
    u8 pad4[0x16 - 4];
    s8 b16;
    u8 pad17;
    s16 h18;
} Ctl3B578;

typedef struct {
    u8 pad0[0x30];
    s16 h30;
    u8 pad32[2];
    s32 v34;
    s32 v38;
    u8 pad3C[0x48 - 0x3C];
    u8 a48[0x76 - 0x48];
    s8 b76;
    u8 pad77;
    f32 f78;
    s32 v7C;
    u8 pad80[0x2C0 - 0x80];
    u8 menu[4];
} Obj3B578;

void func_80039E60(s32, s32, s32);
void func_8003B1B8(Obj3B578 *);
s8 func_8003C580(void *, s32, void *);
s32 func_8003C6B4(void *, void *);
s32 func_8003C8DC(void *, s32);
s32 func_8003FF2C(s32);
s32 func_800B4264(s32, s32);
extern s32 D_8001A050;
extern Ctl3B578 D_800D0FC0;
extern s8 D_800D0FD6;
extern s32 D_800D3120;
extern s32 D_800D3124;
extern void *D_800D3128;
extern f32 D_800F5668;

s32 func_8003B578(Obj3B578 *o) {
    s32 sp10;
    s32 sel;
    s32 any;
    s32 t;
    s32 p1;
    s32 p2;

    p1 = D_800D0FC0.port[0];
    p2 = D_800D0FC0.port[1];
    sel = func_8003C6B4(o->menu, &sp10);
    any = 0;
    if (func_8003FF2C(p1) != 0 || func_8003FF2C(p2) != 0) {
        any = 1;
    }
    if (any) {
        if (func_8003C8DC(o->menu, 3) != 0) {
            func_80039E60(0x91, 0x2710, 0);
            o->v34 = o->v34 == 0;
        } else if (func_8003C8DC(o->menu, 4) != 0) {
            func_80039E60(0x91, 0x2710, 0);
            o->v38 = o->v38 == 0;
        }
    }
    if (sel != o->h30) {
        switch (sel) {
        case 0x55:
            func_80039E60(0x91, 0x2710, 0);
            D_800D0FD6 = 0;
            sel = 0x1C;
            break;
        case 0x56:
            func_80039E60(0x91, 0x2710, 0);
            D_800D0FD6 = 1;
            sel = 0x1C;
            break;
        case 0x57:
            func_80039E60(0x91, 0x2710, 0);
            sel = 0x19;
            break;
        case 0x58:
            t = 0;
            if (func_800B4264(p1, 0x8000) != 0 || func_800B4264(p2, 0x8000) != 0) {
                t = 1;
            }
            if (t) {
                func_80039E60(0x91, 0x2710, 0);
                o->v34 = o->v34 == 0;
            }
            sel = 0;
            break;
        case 0x59:
            t = 0;
            if (func_800B4264(p1, 0x8000) != 0 || func_800B4264(p2, 0x8000) != 0) {
                t = 1;
            }
            if (t) {
                func_80039E60(0x91, 0x2710, 0);
                o->v38 = o->v38 == 0;
            }
            sel = 0;
            break;
        case 0x5A:
            func_80039E60(0x91, 0x2710, 0);
            D_800D3120 = 0x18;
            D_800D3124 = 0x18;
            D_800D3128 = &D_8001A050;
            D_800D0FC0.b16 = 0x1F;
            D_800D0FC0.h18 = 2;
            sel = 9;
            break;
        case 4:
            func_80039E60(0x93, 0x2710, 0);
            break;
        default:
            sel = 0;
            break;
        }
    }
    o->f78 += D_800F5668;
    any = 0;
    if (o->f78 > 0.5) {
        o->f78 = o->f78 - 0.5;
        o->v7C = o->v7C == 0;
    }
    if (func_800B4264(p1, 0x4000) != 0 || func_800B4264(p2, 0x4000) != 0) {
        any = 1;
    }
    if (any) {
        func_80039E60(0x93, 0x2710, 0);
        sel = 4;
    }
    o->h30 = sel;
    o->b76 = func_8003C580(o->menu, 7, o->a48);
    func_8003B1B8(o);
    return sel;
}
