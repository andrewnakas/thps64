#include "common.h"

s32 func_80024D20(void *);                      /* extern */
s32 func_80024FAC(void *);                      /* extern */
s32 func_80035228(void *);                      /* extern */
void *func_800BAB04(void *, s32);            /* extern */
extern s32 D_800170B8;
extern s32 D_800D27A0;
extern s32 D_800EECF0;

void *func_80025348(void *arg0, s32 arg1) {
    s32 var_v0;

    (*(void **)((u8 *)(arg0) + 0)) = &D_800170B8;
    var_v0 = 7;
    do {
        var_v0 -= 1;
    } while (var_v0 != -1);
    (*(s32 *)((u8 *)(arg0) + 0x464)) = arg1;
    (*(s8 *)((u8 *)(arg0) + 0x475)) = 0;
    D_800D27A0 = (*(s32 *)((u8 *)(func_800BAB04(&D_800EECF0, 0x4CB)) + 4));
    (*(f32 *)((u8 *)(arg0) + 0x46C)) = (f32) 0.012499999f;
    (*(f32 *)((u8 *)(arg0) + 0x468)) = (f32) 8.0f;
    func_80024D20(arg0);
    func_80024FAC(arg0);
    func_80035228(arg0);
    return arg0;
}
