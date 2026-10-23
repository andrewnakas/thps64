/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_800A773C(void *, f32, s32);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
typedef struct Obj8003C764 Obj8003C764;
void func_800A8678(Obj8003C764 *, void *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);

struct Obj8003C764 {
    u8 pad0[0x240];
    s8 unk240;
    u8 pad241[0x258 - 0x241];
    f32 unk258;
    f32 unk25C;
    u8 pad260[0x264 - 0x260];
    s32 unk264;
    u8 pad268[0x26C - 0x268];
    u8 unk26C[1][0x40];
};

void func_8003C764(Obj8003C764 *arg0) {
    if (arg0->unk240 == -1) {
        arg0->unk240 = 0;
    }
    func_800A7AF8(arg0, 0xC4, 0xD9, 0xF9, 0xFF);
    func_800A7B10(arg0, 0xC4, 0xD9, 0xF9, 0xFF);
    func_800A773C(arg0, 1.5f, arg0->unk264);
    func_800A8678(arg0, arg0->unk26C[arg0->unk240], arg0->unk258, arg0->unk25C, 2, 0, 1.0f, 0x64, 0x64, 0, 0, 0, 0, 0);
}
