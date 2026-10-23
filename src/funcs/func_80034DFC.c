/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u16 flags;
    u8 pad[2];
    s32 x, y, z;
    u8 pad2[0x52 - 0x10];
    u16 f52;
} Sub34DFC;

typedef struct {
    void *p0;
    u8 *p4;
    Sub34DFC *p8;
    u8 pad[0x78 - 0xC];
    s32 v78;
    u8 pad2[0xD0 - 0x7C];
    s8 vD0;
    u8 padD1;
    u8 vD2;
    u8 padD3;
    u8 vD4;
    u8 pad3[3];
} Ent34DFC;

s32 func_80084724(void *);
void func_80039168(void *);
void func_80084274(void *, void *, f32 *, s32);
s32 func_8008464C(void);
extern s32 D_800D36EC;
extern Ent34DFC D_800F78C0[];

void func_80034DFC(u8 *arg0) {
    s32 old;
    s32 i;
    s32 a3;
    f32 pad[16];
    f32 v[3];
    f32 fx, fy, fz;
    Sub34DFC *sp;

    old = func_80084724(0);
    i = 0;
    while (1) {
        if (i >= D_800D36EC) break;
        if (D_800F78C0[i].vD0 != -1) goto next;
        if (D_800F78C0[i].vD2 != 0) goto next;
        if (D_800F78C0[i].p8->f52 & 0x40) {
            D_800F78C0[i].vD2 = 1;
            goto next;
        }
        if (D_800F78C0[i].p8->flags & 0x200) goto next;
        if (D_800F78C0[i].p0 == 0) goto next;
        func_80084724(D_800F78C0[i].p0);
        func_80039168(D_800F78C0[i].p0);
        a3 = 0;
        if (D_800F78C0[i].vD4 != 0) {
            a3 = D_800F78C0[i].v78;
        }
        sp = D_800F78C0[i].p8;
        fx = sp->x * 0.000244140625f;
        fy = sp->y * 0.000244140625f;
        fz = sp->z * 0.000244140625f;
        v[0] = fx;
        v[1] = fy;
        v[2] = fz;
        func_80084274(arg0, D_800F78C0[i].p4, v, a3);
        *(s16 *)(D_800F78C0[i].p4 + 0x38) = 0;
    next:
        i++;
    }
    func_80084724((void *)old);
    *(s32 *)(arg0 + 0xF8) = func_8008464C();
}
