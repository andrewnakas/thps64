/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_800A773C(void *, f32, f32);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
void func_800A8678(void *, void *, f32, f32, s32, s32, f32, s32, s32, s32, s32, f32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800B231C(void *, s32, s32, s32, s32);
extern s32 D_800DE7A0;

void func_8008A8A4(u8 *arg0) {
    void *object;
    f32 scale;

    object = arg0 + 0x38;
    func_800B231C(object, 100, 100, 100, 0xFF);
    func_800B1AC4(object, 0.0f, 0.0f, 1.429f, 2.981f);
    func_800B1AC4(object, 0.0f, 0.0f, 1.429f, 2.981f);
    object = arg0 + 0x204;
    func_800A773C(object, 1.5f, 1.5f);
    func_800A7AF8(object, 0xDC, 0x93, 0x28, 0xFF);
    func_800A7B10(object, 0xEF, 0xA8, 0x36, 0xFF);
    func_800A8678(object, arg0 + 0x102, 330.0f, 390.0f, 2, 0, 5.0f, 0xAA, 0x50, 1, 0, 0.0f, 0, 0);
    scale = (D_800DE7A0 == 7) ? 1.07f : 1.1f;
    func_800A773C(object, scale, 1.4f);
    func_800A7AF8(object, 0xC8, 0xE5, 0xFC, 0xFF);
    func_800A7B10(object, 0xA0, 0xB7, 0xD2, 0xFF);
    func_800A8678(object, arg0 + 0x142, 330.0f, 260.0f, 2, 0, 5.0f, 0xAA, 0x50, 1, 0, 0.0f, 0, 0);
    func_800A8678(object, arg0 + 0x182, 330.0f, 230.0f, 2, 0, 5.0f, 0xAA, 0x50, 1, 0, 0.0f, 0, 0);
    func_800A8678(object, arg0 + 0x1C2, 330.0f, 200.0f, 2, 0, 5.0f, 0xAA, 0x50, 1, 0, 0.0f, 0, 0);
}
