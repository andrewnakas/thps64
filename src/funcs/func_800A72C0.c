/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 unk8;
    u8 padC[4];
    u8 unk10;
    u8 pad11[0xB];
    f32 unk1C;
    s32 unk20;
    u8 pad24[0x224 - 0x24];
    u8 unk224;
    u8 unk225;
    u8 unk226;
    u8 unk227;
    u8 unk228;
    u8 unk229;
    u8 unk22A;
    u8 unk22B;
    s32 unk22C;
    s16 unk230;
    s16 unk232;
    f32 unk234;
    f32 unk238;
    void *unk23C;
} Obj;

void func_800A773C(Obj *, f32, f32);
extern u8 D_80021BB0[];

Obj *func_800A72C0(Obj *arg0) {
    arg0->unk23C = D_80021BB0;
    arg0->unk22C = 0;
    arg0->unk226 = 0xFF;
    arg0->unk225 = 0xFF;
    arg0->unk224 = 0xFF;
    arg0->unk227 = 0xFF;
    arg0->unk22A = 0;
    arg0->unk229 = 0;
    arg0->unk228 = 0;
    arg0->unk22B = 0xFF;
    arg0->unk8 = 0;
    arg0->unk10 = 0;
    arg0->unk20 = 0;
    arg0->unk1C = 0.125f;
    func_800A773C(arg0, 1.0f, 1.0f);
    arg0->unk232 = 0xC8;
    arg0->unk230 = 0;
    arg0->unk234 = arg0->unk238 = 0.0f;
    return arg0;
}
