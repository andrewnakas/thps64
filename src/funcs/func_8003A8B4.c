#include "common.h"

typedef struct {
    u8 pad0[0xD0];
    s32 unkD0;
    u8 padD4[0xF8 - 0xD4];
    s32 unkF8;
} Obj3A8B4;

void func_8003A3E4(void);
void func_800A9220(void *, s32, s32);
extern u8 D_800EA9C0[];

void func_8003A8B4(Obj3A8B4 *arg0) {
    if (arg0->unkD0 != 0) {
        arg0->unkD0 = 0;
        func_8003A3E4();
        func_800A9220(D_800EA9C0, arg0->unkF8, 0);
    }
}
