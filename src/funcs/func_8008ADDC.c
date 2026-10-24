/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_8008A338(u8 *);
void func_8008A8A4(u8 *);
void func_800B1AC4(u8 *, f32, f32, f32, f32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BEF70(s32, s32, s32);
extern s32 D_800DE7A0;

void func_8008ADDC(u8 *arg0) {
    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    if (D_800DE7A0 == 1) {
        func_8008A338(arg0);
    }
    if (D_800DE7A0 == 2 || D_800DE7A0 == 4 || D_800DE7A0 == 3 || D_800DE7A0 == 8 || D_800DE7A0 == 5 ||
        D_800DE7A0 == 7) {
        func_8008A8A4(arg0);
    }
    if (*(s32 *)(arg0 + 0xF0) != 0) {
        func_800B1AC4(arg0 + 0xD8, 162.0f, 420.0f, 1.0f, 1.8f);
    }
    func_800BE5A4();
}
