#include "common.h"

void func_800A773C(void *, f32, f32);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
void func_800A8678(void *, void *, f32, f32, s32, s32, f32, s32, s32, s32, s32, f32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800B231C(void *, s32, s32, s32, s32);
#define D_8001F958 (*(const f32 *)0x8001F958)
#define D_8001F95C (*(const f32 *)0x8001F95C)
#define D_8001F960 (*(const f32 *)0x8001F960)
#define D_8001F964 (*(const f32 *)0x8001F964)
#define D_8001F968 (*(const f32 *)0x8001F968)
#define D_8001F96C (*(const f32 *)0x8001F96C)
#define D_8001F970 (*(const f32 *)0x8001F970)
extern s32 D_800DE7A0;

void func_8008A8A4(void *arg0) {
    f32 zero;
    s32 alpha;
    s32 mode;
    s32 seven;
    s32 style;
    s32 value_aa;
    s32 value_50;
    s32 value_one;
    register f32 size __asm__("$f0");
    register f32 argument_size __asm__("$5");
    void *draw_arg;
    f32 first_f20;
    f32 shared_f20;
    f32 first_f22;
    f32 shared_f22;
    f32 selected_size;
    void *object;

    object = (u8 *)arg0 + 0x38;
    alpha = 0xFF;
    func_800B231C(object, 0x64, 0x64, 0x64, alpha);
    zero = 0.0f;
    first_f22 = D_8001F958;
    first_f20 = D_8001F95C;
    func_800B1AC4(object, zero, zero, first_f22, first_f20);
    func_800B1AC4(object, zero, zero, first_f22, first_f20);
    object = (u8 *)arg0 + 0x204;
    /* Preserve the float load and the shared argument value. */
    size = D_8001F960;
    draw_arg = object;
    __asm__("" : "+r" (draw_arg), "+f" (size));
    argument_size = size;
    __asm__("" : "+r" (argument_size));
    func_800A773C(draw_arg, argument_size, argument_size);
    func_800A7AF8(object, 0xDC, 0x93, 0x28, alpha);
    func_800A7B10(object, 0xEF, 0xA8, 0x36, alpha);
    shared_f22 = D_8001F964;
    func_800A8678(object, (u8 *)arg0 + 0x102, shared_f22, 390.0f, (style = 2), 0, (shared_f20 = D_8001F968), (value_aa = 0xAA), (value_50 = 0x50), (value_one = 1), 0, zero, 0, 0);
    /* Keep the mode comparison setup before loading its default size. */
    mode = D_800DE7A0;
    seven = 7;
    __asm__("" : "+r" (mode), "+r" (seven));
    selected_size = D_8001F96C;
    if (mode == seven) {
        selected_size = D_8001F970;
    }
    func_800A773C(object, selected_size, 1.4f);
    func_800A7AF8(object, 0xC8, 0xE5, 0xFC, alpha);
    func_800A7B10(object, 0xA0, 0xB7, 0xD2, alpha);
    func_800A8678(object, (u8 *)arg0 + 0x142, shared_f22, 260.0f, style, 0, shared_f20, value_aa, value_50, value_one, 0, zero, 0, 0);
    func_800A8678(object, (u8 *)arg0 + 0x182, shared_f22, 230.0f, style, 0, shared_f20, value_aa, value_50, value_one, 0, zero, 0, 0);
    func_800A8678(object, (u8 *)arg0 + 0x1C2, shared_f22, 200.0f, style, 0, shared_f20, value_aa, value_50, value_one, 0, zero, 0, 0);
}
