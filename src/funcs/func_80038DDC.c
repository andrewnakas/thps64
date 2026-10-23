/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[6];
    s16 x6;
    u8 pad8[4];
    u8 xC;
    u8 xD;
    u8 xE;
    u8 xF;
} Elem38DDC;

typedef struct {
    s32 unk0;
    u8 *unk4;
    Elem38DDC *unk8;
    s32 *unkC;
} Ctx38DDC;

s32 func_80039328(Ctx38DDC *, s32);
void func_8003934C(Ctx38DDC *, s32);

void func_80038DDC(void *arg0, u8 *arg1, s32 arg2, u8 arg3) {
    Ctx38DDC ctx;
    Ctx38DDC *c;
    s32 v;
    Elem38DDC *e;
    s32 n;
    s32 i;
    s32 old;

    old = arg1[0x3E];
    if (arg2 != old) {
        v = (*(s32 ***)((u8 *)arg0 + 4))[0][*(s16 *)(arg1 + 2)];
        c = &ctx;
        func_8003934C(c, v);
        ctx.unkC = (s32 *)(ctx.unk4 + func_80039328(c, 2));
        ctx.unk8 = (Elem38DDC *)(ctx.unkC + 2);
        e = ctx.unk8;
        n = *ctx.unkC;
        arg1[0x3E] = arg2;
        if (old != 2) {
            i = 0;
            while (1) {
                if (i >= n) break;
                e[i].xD = e[i].xF;
                if (old == 1) {
                    e[i].xE = ((u8 *)&e[i].x6)[1];
                } else {
                    e[i].xC = ((u8 *)&e[i].x6)[1];
                }
                i++;
            }
        }
        if (arg2 != 2) {
            i = 0;
            while (1) {
                if (i >= n) break;
                e[i].xF = e[i].xD;
                e[i].xD = 0;
                if (arg2 == 1) {
                    e[i].x6 = e[i].xE;
                    e[i].xE = 0;
                    e[i].xC = arg3;
                } else {
                    e[i].x6 = e[i].xC;
                    e[i].xC = 0;
                    e[i].xE = arg3;
                }
                i++;
            }
        }
    }
}
