#include "common.h"

typedef struct Vec800704C4 { s32 x, y, z; } Vec800704C4;
typedef struct State800704C4 {
    s32 unk0, unk4, unk8, unkC;
    u8 pad10[0xC];
    struct State800704C4 *unk1C;
    u8 pad20[0x1A];
    u16 unk3A;
    u8 pad3C[0x2DC];
    s32 unk318;
} State800704C4;

s32 func_80022EF4(s32, s32, s32, s32);              /* extern */
void func_80039E60(s32, s32, s32);                         /* extern */
s32 func_80047C34(void *, void *);                  /* extern */
s32 func_80049D60(s32);                               /* extern */
extern State800704C4 *D_800D61A8;
extern s32 D_800DC618;
extern s32 D_800DC6D8;

void func_800704C4(State800704C4 *arg0, Vec800704C4 arg1) {
    s32 dz0;
    s32 dz1;
    s32 dx0;
    s32 dx1;
    s32 found;
    s32 vx, vz;
    State800704C4 *first;
    State800704C4 *second;

    found = 0;
    if ((D_800DC618 != 2) && (D_800DC6D8 != 2)) {
        first = D_800D61A8;
        second = first->unk1C;
        if (func_80047C34(&arg0->unk4, &first->unk4) < 0x7D0) {
            vz = arg1.z;
            vx = arg1.x;
            dx0 = first->unk4 - arg0->unk4;
            dz0 = first->unkC - arg0->unkC;
            if (func_80022EF4(vx - vz, dx0, vx + vz, dz0) > 0) {
                found = func_80022EF4(arg1.z + arg1.x, dx0, arg1.z - arg1.x, dz0) > 0;
            }
        }
        if (second != NULL && found == 0) {
            if (func_80047C34(&arg0->unk4, &second->unk4) < 0x7D0) {
                vz = arg1.z;
                vx = arg1.x;
                dx1 = second->unk4 - arg0->unk4;
                dz1 = second->unkC - arg0->unkC;
                if (func_80022EF4(vx - vz, dx1, vx + vz, dz1) > 0 &&
                    func_80022EF4(arg1.z + arg1.x, dx1, arg1.z - arg1.x, dz1) > 0) {
                    found = 1;
                }
            }
        }
        if (found != 0) {
            if (arg0->unk318 == 0) {
                switch (arg0->unk3A) {
                case 0xD5: func_80039E60(func_80049D60(3) + 0x6E, 0x2710, 0); break;
                case 0xD6: func_80039E60(0x7A, 0x2710, 0); break;
                case 0xD7: func_80039E60(0x82, 0x2710, 0); break;
                case 0xD8: func_80039E60(0x78, 0x2710, 0); break;
                }
                arg0->unk318 = 1;
            }
        } else {
            arg0->unk318 = 0;
        }
    }
}
