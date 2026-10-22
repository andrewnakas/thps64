#include "common.h"

typedef struct {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s32 e;
    s32 f;
} Ent80027FF4;

s32 func_800A4350(void *, s32, s32, f32, f32);
s32 func_800A62C4(void *, s16, s16, s16, s32);
extern u8 D_800D0FE8;
extern f32 D_800D1E7C;
extern Ent80027FF4 D_800F6560[][2];
extern Ent80027FF4 D_800F65C0;

void func_80027FF4(u8 *arg0) {
    Ent80027FF4 *var_s1;
    s32 temp_s3;
    void *temp_s0;
    s32 g;

    temp_s3 = *(s8 *)(arg0 + 0xF14);
    g = D_800D0FE8;
    if (g == 3) {
        var_s1 = &D_800F65C0;
    } else {
        var_s1 = &D_800F6560[g][temp_s3];
    }
    temp_s0 = arg0 + 0x1B28;
    func_800A62C4(temp_s0, var_s1->a, var_s1->b, var_s1->c, var_s1->d);
    func_800A4350(temp_s0, var_s1->e, var_s1->f, 10.0f, D_800D1E7C);
    *(s16 *)(*(u8 **)(arg0 + 0x2248) + 0x208) = temp_s3;
}
