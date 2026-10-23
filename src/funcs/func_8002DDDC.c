#include "common.h"

void func_800A7B28(s32, s32, s32, s32, s32);
void func_800A85C8(s32, f32, f32, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800A8678(s32, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
extern char D_80019960[];
extern char D_8001996C[];
extern char D_8001998C[];
extern char D_8001999C[];

void func_8002DDDC(s32 arg0) {
    char *p;
    s32 q;

    func_800A7B28(arg0 + 0x130, 0xFC, 0xC2, 0x6B, 0xFF);
    p = D_8001998C;
    func_800A85C8(arg0 + 0x130, 0.9f, 1.5f, p, 132.0f, 280.0f, 2, 0, 5.0f, 0xAA, 0x3C, 0, 0, 0, 0, 0);
    q = arg0 + 0x370;
    p = D_8001999C;
    func_800A8678(q, p, 132.0f, 250.0f, 2, 0, 2.0f, 0xAA, 0x1E, 0, 0, 0, 0, 0);
    p = D_80019960;
    func_800A8678(q, p, 132.0f, 230.0f, 2, 0, 2.0f, 0xAA, 0x1E, 0, 0, 0, 0, 0);
    p = D_8001996C;
    func_800A8678(q, p, 132.0f, 210.0f, 2, 0, 2.0f, 0xAA, 0x1E, 0, 0, 0, 0, 0);
}
