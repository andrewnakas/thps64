/* cflags: -O2 -fno-schedule-insns */
#include "common.h"

extern s32 func_800B432C(void);
extern void func_800B3260(s32);
extern void func_800B3360(void);
extern u8 D_800FC371;
extern u8 D_800FC370;
extern s32 D_800FC36C;

void func_800B32EC(void) {
    s32 i;
    s32 r;
    D_800FC371 = 0;
    r = func_800B432C();
    i = 0;
    D_800FC36C = r;
    do {
        func_800B3260(i);
        i++;
    } while (i < 4);
    D_800FC370 = 0xFF;
    func_800B3360();
}
