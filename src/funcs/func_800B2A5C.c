/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} S40;

void func_80004ED0(void *, void *, s32);
void func_8009ECF8(void *, s32);
extern u8 D_800EA110[];
extern S40 D_800ECF40;
extern s32 D_800ECF50;
extern s32 D_800ECF70;
extern s32 D_800ECF7C;
extern s32 D_800ECF80;
extern u8 D_800ECF84[];
extern s32 D_800ECFA4;

void func_800B2A5C(void) {
    if (D_800ECF80 != 0) {
        func_80004ED0(D_800ECF84, NULL, 1);
        D_800ECFA4 = 0;
        D_800ECF80 = 0;
        D_800ECF7C = 0;
    }
    if (D_800ECF50 != 0) {
        D_800ECF40.unkC = 0;
        D_800ECF40.unk8 = 0;
        if (D_800ECF70 == 0) {
            func_8009ECF8(D_800EA110, D_800ECF50);
        }
        D_800ECF50 = 0;
    }
}
