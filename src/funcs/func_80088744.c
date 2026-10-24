/* cflags: -fexpensive-optimizations -Wa,-O0 */
#include "common.h"

void func_800A7B28(void *, s32, s32, s32, s32);
void func_800A8678(void *, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, f32, s32, s32);
extern char D_8001EFCC[];
extern char D_8001EFD0[];

void func_80088744(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x550) != 0) {
        func_800A7B28(arg0 + 0x2B0, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A8678(arg0 + 0x2B0, D_8001EFCC, 440.0f, 170.0f, 0, 0, 5.0f, 0xAA, 0x50, 1, 0, 0.0f, 0, 0);
    } else {
        func_800A7B28(arg0 + 0x2B0, 0xF, 0x4A, 0x7B, 0xFF);
        func_800A8678(arg0 + 0x2B0, D_8001EFD0, 440.0f, 170.0f, 0, 0, 5.0f, 0xAA, 0x50, 1, 0, 0.0f, 0, 0);
    }
    if (*(s32 *)(arg0 + 0x554) != 0) {
        func_800A7B28(arg0 + 0x2B0, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A8678(arg0 + 0x2B0, D_8001EFCC, 440.0f, 140.0f, 0, 0, 5.0f, 0xAA, 0x50, 1, 0, 0.0f, 0, 0);
    } else {
        func_800A7B28(arg0 + 0x2B0, 0xF, 0x4A, 0x7B, 0xFF);
        func_800A8678(arg0 + 0x2B0, D_8001EFD0, 440.0f, 140.0f, 0, 0, 5.0f, 0xAA, 0x50, 1, 0, 0.0f, 0, 0);
    }
}
