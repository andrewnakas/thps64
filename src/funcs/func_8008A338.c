#include "common.h"
void func_800A773C(void *, f32, f32);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
void func_800A8678(void *, void *, f32, f32, s32, s32, f32, s32, s32, s32, s32, f32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800B231C(void *, s32, s32, s32, s32);
extern s32 D_800C0E20;
typedef struct {
    u8 pad_00[0xC];
    s32 field_0C;
    u8 pad_10[0x68];
} Entry8008A338;
extern Entry8008A338 D_800D5C1C[];
extern u8 D_800D0FC0[], D_800DE9F4[];
extern u8 D_8001F890[];
extern u8 D_8001F898[];
extern u8 D_8001F8B0[];
extern u8 D_8001F8C8[];
extern u8 D_8001F8EC[];
extern u8 D_8001F908[];
#define D_8001F930 (*(const f32 *)0x8001F930)
#define D_8001F934 (*(const f32 *)0x8001F934)
#define D_8001F938 (*(const f32 *)0x8001F938)
#define D_8001F93C (*(const f32 *)0x8001F93C)
#define D_8001F940 (*(const f32 *)0x8001F940)
#define D_8001F944 (*(const f32 *)0x8001F944)
#define D_8001F948 (*(const f32 *)0x8001F948)
#define D_8001F94C (*(const f32 *)0x8001F94C)
#define D_8001F950 (*(const f32 *)0x8001F950)
#define D_8001F954 (*(const f32 *)0x8001F954)

void func_8008A338(void *arg0) {

    Entry8008A338 *table = D_800D5C1C;
    register u8 *base __asm__("$18") = (u8 *)0x800C0000;
    s32 two, value_aa, value_50, one;
    register f32 zero __asm__("$f22");
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f22;
    f32 temp_f24;
    register void *object __asm__("$16");
    void *text;
    s32 bit_index;
    s32 row_value;

    /* Retain the high-address base for D_800C0E20 across the first draw path. */
    __asm__("" : "+r" (base));
    if (table[(*(s32 *)(base + 0xE20))].field_0C == 0) {
        u8 *flags;
        register u8 *selection_base __asm__("$19");
        u8 *context;
        temp_f20 = D_8001F930;
        temp_f22 = D_8001F934;
        func_800B1AC4(arg0 + 0x38, 10.0f, 18.0f, temp_f20, temp_f22);
        func_800B1AC4(arg0 + 0x74, 68.0f, 24.0f, temp_f20, temp_f22);
        func_800B1AC4(arg0 + 0x4C, 110.0f, 102.0f, temp_f20, temp_f22);
        func_800B1AC4(arg0 + 0x9C, 362.0f, 92.0f, temp_f20, temp_f22);
        func_800B1AC4(arg0 + 0xB0, 118.0f, 146.0f, temp_f20, temp_f22);
        func_800B1AC4(arg0 + 0x88, 336.0f, 262.0f, temp_f20, D_8001F938);
        func_800B1AC4(arg0 + 0x60, 115.0f, 330.0f, temp_f20, temp_f22);
        row_value = 0x6A;
        bit_index = 0;
        flags = D_800DE9F4;
        selection_base = base;
        context = D_800D0FC0;
        temp_f20_2 = D_8001F93C;
        do {
            s32 row = context[0x14];
            s32 offset = row * 0x14;
            s32 selection = *(s32 *)(selection_base + 0xE20);
            u8 *entry = (u8 *)((u32)(selection + offset) + (u32)flags);
            if (((s32) entry[0xC] >> bit_index) & 1) {
                func_800B1AC4(arg0 + 0xC4, 53.0f, (f32) row_value, temp_f20_2, temp_f20_2);
            }
            bit_index += 1;
            row_value += 0x3A;
        } while (bit_index < 5);
        return;
    }
    object = arg0 + 0x38;
    func_800B231C(object, 0x64, 0x64, 0x64, 0xFF);
    zero = 0.0f;
    __asm__("" : "+f" (zero));
    func_800B1AC4(object, zero, zero, 1.429f, D_8001F940);
    object = arg0 + 0x204;
    /* Each scale call shares one floating-point load between both arguments. */
    {
        register f32 size __asm__("$f0") = D_8001F944;
        register f32 argument_size __asm__("$5");
        register void *draw_arg __asm__("$4") = object;
        __asm__("" : "+r" (draw_arg), "+f" (size));
        argument_size = size;
        __asm__("" : "+r" (argument_size));
        func_800A773C(draw_arg, argument_size, argument_size);
    }
    func_800A7AF8(object, 0xFA, 0xB0, 0x47, 0xFF);
    func_800A7B10(object, 0xFA, 0xB0, 0x47, 0xFF);
    temp_f24 = D_8001F948;
    func_800A8678(object, arg0 + 0x102, temp_f24, 420.0f, (two = 2), 0, (temp_f20_3 = D_8001F94C), (value_aa = 0xAA), (value_50 = 0x50), (one = 1), 0, zero, 0, 0);
    {
        register f32 size __asm__("$f0") = D_8001F950;
        register f32 argument_size __asm__("$5");
        register void *draw_arg __asm__("$4") = object;
        __asm__("" : "+r" (draw_arg), "+f" (size));
        argument_size = size;
        __asm__("" : "+r" (argument_size));
        func_800A773C(draw_arg, argument_size, argument_size);
    }
    func_800A7AF8(object, 0xFC, 0xD6, 0x85, 0xFF);
    func_800A7B10(object, 0xFC, 0xD6, 0x85, 0xFF);
    func_800A8678(object, arg0 + 0x142, temp_f24, 395.0f, two, 0, temp_f20_3, value_aa, value_50, one, 0, zero, 0, 0);
    {
        register f32 size __asm__("$f0") = D_8001F954;
        register f32 argument_size __asm__("$5");
        register void *draw_arg __asm__("$4") = object;
        __asm__("" : "+r" (draw_arg), "+f" (size));
        argument_size = size;
        __asm__("" : "+r" (argument_size));
        func_800A773C(draw_arg, argument_size, argument_size);
    }
    func_800A8678(object, arg0 + 0x182, temp_f24, 370.0f, two, 0, temp_f20_3, value_aa, value_50, one, 0, zero, 0, 0);
    func_800A773C(object, 1.0f, 1.1f);
    func_800A7AF8(object, 0x9F, 0xBC, 0xF1, 0xFF);
    func_800A7B10(object, 0x9F, 0xBC, 0xF1, 0xFF);
    text = D_8001F890;
    func_800A8678(object, text, temp_f24, 280.0f, two, 0, temp_f20_3, value_aa, value_50, one, 0, zero, 0, 0);
    text = D_8001F898;
    func_800A8678(object, text, temp_f24, 255.0f, two, 0, temp_f20_3, value_aa, value_50, one, 0, zero, 0, 0);
    text = D_8001F8B0;
    func_800A8678(object, text, temp_f24, 230.0f, two, 0, temp_f20_3, value_aa, value_50, one, 0, zero, 0, 0);
    text = D_8001F8C8;
    func_800A8678(object, text, temp_f24, 205.0f, two, 0, temp_f20_3, value_aa, value_50, one, 0, zero, 0, 0);
    text = D_8001F8EC;
    func_800A8678(object, text, temp_f24, 180.0f, two, 0, temp_f20_3, value_aa, value_50, one, 0, zero, 0, 0);
    text = D_8001F908;
    func_800A8678(object, text, temp_f24, 155.0f, two, 0, temp_f20_3, value_aa, value_50, one, 0, zero, 0, 0);
}
