#include "common.h"

typedef struct {
    s32 state;
    u8 pad[0x18];
    u32 t1C;
    u32 t20;
    u8 pad2[0x28];
    s32 mode;
} St80044F78;

void func_8006F1A8(s32, s32, s32, s32);
void func_8006F23C(s32);
void func_8006F274(s32);
void func_80087194(s32, s32);
extern s32 D_800D1E88;
extern St80044F78 D_800DC618;
extern s32 D_800DE950;
extern s32 D_800E8FA8;

void func_80044F78(void) {
    St80044F78 *p;
    s32 mode;

    p = &D_800DC618;
    if (p->state == 2 && D_800DE950 != 0 && D_800E8FA8 != 0x14 && D_800E8FA8 != 0x16 && D_800E8FA8 != 0x15) {
        mode = p->mode;
        if ((mode == 0 && p->t1C - p->t20 < 0x5A) || mode == 1) {
            func_8006F1A8(0x80, 0x80, 0x80, 0);
            func_8006F23C(0xBC);
            func_8006F274(0);
            func_80087194(D_800D1E88, 4);
        }
    }
}
