/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i_8004D048;

typedef struct {
    u8 pad0[0x208];
    s32 unk208;
    u8 pad20C[0x21E - 0x20C];
    u16 unk21E;
    u8 pad220[0x328 - 0x220];
    s32 unk328;
    u8 pad32C[0x358 - 0x32C];
    s32 unk358;
    s32 unk35C;
    s32 pad360;
    s32 unk364;
    s32 unk368;
    s32 unk36C;
    s32 pad370;
    s32 unk374;
    s32 unk378;
    u8 pad37C[0x82C - 0x37C];
    s32 state;
    u8 pad830[0x8D0 - 0x830];
    Vec3i_8004D048 unk8D0;
    Vec3i_8004D048 unk8DC;
    Vec3i_8004D048 unk8E8;
    Vec3i_8004D048 unk8F4;
} Obj_8004D048;

s32 func_80022E14(s32, s32);
Vec3i_8004D048 func_80046D28(Vec3i_8004D048 *);
void func_8004CACC(void *, s32, char *, s32, s32);
void func_8005BE8C(void *);
extern char D_8001B94C[];

void func_8004D048(Obj_8004D048 *arg0, s32 arg1) {
    Vec3i_8004D048 tmp;
    Vec3i_8004D048 r;

    if (arg0->state == 4 && arg1 == 1) {
        arg0->unk35C = 0;
        arg0->unk358 = 0;
        arg0->unk378 = 0;
        arg0->unk374 = 0;
        arg0->unk368 = 0;
        arg0->unk36C = 0;
        arg0->unk364 = 0;
    }
    if (arg0->state != arg1) {
        if (arg1 == 1 && arg0->state != 2) {
            arg0->unk328++;
        }
        if (arg1 == 2 && arg0->state != 1) {
            arg0->unk328++;
        }
    }
    if (arg0->state != 2 && arg1 == 2) {
        arg0->unk8F4 = arg0->unk8D0;
        arg0->unk8F4.x = -func_80022E14(arg0->unk8F4.x, 0x32C8);
        arg0->unk8F4.y = func_80022E14(arg0->unk8F4.y, 0x32C8);
        arg0->unk8F4.z = -func_80022E14(arg0->unk8F4.z, 0x32C8);
    }
    if (arg0->state == 5 && arg1 == 1) {
        func_8004CACC(arg0, 0x40, D_8001B94C, 0x1F4, 0);
        if (arg0->unk21E == 0x23 && !(arg0->unk208 & 2)) {
            tmp = arg0->unk8DC;
            arg0->unk8DC = arg0->unk8E8;
            arg0->unk8E8 = func_80046D28(&tmp);
        } else if (arg0->unk21E != 0x23 && (arg0->unk208 & 2)) {
            tmp = arg0->unk8DC;
            arg0->unk8DC = arg0->unk8E8;
            r = func_80046D28(&tmp);
            arg0->unk8E8 = r;
        } else {
            tmp = arg0->unk8DC;
            r = func_80046D28(&arg0->unk8E8);
            arg0->unk8DC = r;
            arg0->unk8E8 = tmp;
        }
    }
    func_8005BE8C(arg0);
    arg0->state = arg1;
}
