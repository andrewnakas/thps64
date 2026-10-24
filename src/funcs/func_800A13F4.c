/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x10];
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x3D0];
    u8 unk3EC[0x2C];
    s32 unk418;
    u8 pad41C[0x18];
    s32 unk434;
    u8 pad438[0x84];
    s32 unk4BC;
    u16 unk4C0;
    u8 unk4C2[4];
    u8 unk4C6[2];
} Menu;

s32 func_8000B470(void *, void *, s32);
s32 func_80009EA0(void *, u16, s32, void *, void *);
void func_800A0870(Menu *, s32, s32);
void func_800A08F0(Menu *, s32, s32, s32);
void func_800A3194(Menu *);
extern s32 D_800EA550;

void func_800A13F4(Menu *arg0) {
    u8 buf[0x68];
    s32 r;

    if (arg0->unk18 == 0) {
        r = func_8000B470(arg0->unk3EC, buf, arg0->unk434);
        if (r == 0) {
            r = func_8000B470(arg0->unk3EC, buf, arg0->unk434);
            if (r != 0) {
                func_800A0870(arg0, r, 0);
                return;
            }
            r = func_80009EA0(buf, arg0->unk4C0, arg0->unk4BC, arg0->unk4C6, arg0->unk4C2);
            if (r != 0) {
                func_800A0870(arg0, r, arg0->unk418);
                arg0->unk0 = 0xA;
            } else {
                arg0->unk0 = 0xA;
                D_800EA550 = arg0->unk418;
                arg0->unk14--;
            }
        } else {
            func_800A08F0(arg0, r, D_800EA550, arg0->unk418);
            arg0->unk0 = 0xA;
        }
    } else {
        arg0->unk0 = 0xA;
        D_800EA550 = arg0->unk418;
    }
    func_800A3194(arg0);
}
