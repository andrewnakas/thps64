#include "common.h"

typedef struct {
    u8 pad_000[0x524];
    s32 field_524;
    u8 pad_528[4];
    u16 field_52C, field_52E, field_530, field_532;
    u8 pad_534[0x28];
    s32 field_55C;
} State80088F48;

void func_80087ED8(void *);                            /* extern */
void func_80088744(void *);                            /* extern */
void func_800B1AC4(void *, f32, f32, f32, f32);        /* extern */
void func_800BE3D8(void);                                  /* extern */
void func_800BE5A4(void);                                  /* extern */
void func_800BEF70(s32, s32, s32);                           /* extern */
#define D_8001F018 (*(const f32 *)0x8001F018)
#define D_8001F01C (*(const f32 *)0x8001F01C)

void func_80088F48(State80088F48 *arg0) {
    f32 temp_f20;
    s32 first;
    s32 second;

    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    func_800B1AC4((u8 *)arg0 + 0x34, 34.0f, 0.0f, 0.925f, D_8001F018);
    func_80087ED8(arg0);
    func_80088744(arg0);
    if ((arg0->field_524 != 0) && (arg0->field_55C != 0)) {
        first = arg0->field_52C;
        second = arg0->field_52E;
        temp_f20 = D_8001F01C;
        func_800B1AC4((u8 *)arg0 + 0x48, (f32)first, (f32)second, temp_f20, temp_f20);
        func_800B1AC4((u8 *)arg0 + 0x5C, (f32) arg0->field_530, (f32) arg0->field_532, temp_f20, temp_f20);
    }
    func_800BE5A4();
}
