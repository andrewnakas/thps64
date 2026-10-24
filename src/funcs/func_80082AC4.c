/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

s32 func_80046524();                            /* extern */
s32 func_800493A4();                            /* extern */
s32 func_8004A89C(s32 *);                       /* extern */
s32 func_8004AB58();                            /* extern */
s32 func_8004ACF0(s32 *);                       /* extern */
s32 func_8004AD90(s32);                         /* extern */
s32 func_80062A90();                            /* extern */
s32 func_80068988();                            /* extern */
s32 func_8006A148();                            /* extern */
s32 func_8006D4B0();                            /* extern */
s32 func_8006FA6C();                         /* extern */
s32 func_80079728();                            /* extern */
s32 func_800797D8();                            /* extern */
s32 func_8007AF5C();                            /* extern */
extern s32 D_800D6180;
extern s32 D_800D61A8;
extern s32 D_800DC5A0;
extern s32 D_800DDC60;
extern s32 D_800DE144;
extern s32 D_800DE7A4;
extern void *D_800DE7A8;
extern void *D_800DE7AC;
extern s32 D_800DE808;
extern s32 D_800DE80C;
extern s32 D_800DE820;
extern s32 D_800DE84C;
extern s32 D_800DE948;
extern s32 D_800DE9AC;
extern s32 D_800DE9B0;
extern s32 D_800DE9B4;
extern s32 D_800E9038;

void func_80082AC4(void) {
    s32 temp_a0;
    s32 var_v1;
    void *temp_a0_2;
    void *temp_v1;

    D_800DE948 += 1;
    temp_a0 = D_800DE80C & 1;
    D_800DE80C += 1;
    if (temp_a0 == 0) {
        D_800DE808 += 1;
        func_8006FA6C();
        var_v1 = 0;
        if ((D_800E9038 != 0) || (D_800DE820 != 0)) {
            var_v1 = 1;
        }
        if (var_v1 == 0) {
            func_800493A4();
            func_8004AD90(D_800DDC60);
            func_8004AD90(D_800D6180);
            func_8004A89C(&D_800D61A8);
            func_8007AF5C();
            func_80068988();
            func_8004A89C(&D_800DC5A0);
            func_8006A148();
            func_8004ACF0(&D_800D6180);
            func_8004ACF0(&D_800DE7A4);
            func_8004A89C(&D_800DDC60);
            func_8004AB58();
            func_800797D8();
            if ((D_800DE9AC == 1) && (D_800DE9B0 < 0x28) && ((*(s32 *)((u8 *)D_800DE7A8 + 0x82C)) == 0) && ((D_800DE7AC == NULL) || ((*(s32 *)((u8 *)D_800DE7AC + 0x82C)) == 0))) {
                temp_a0_2 = (*(void **)((u8 *)D_800DE7A8 + 0x2D0));
                (*(s32 *)((u8 *)temp_a0_2 + 0x668)) = (s32) ((*(s32 *)((u8 *)temp_a0_2 + 0x668)) + D_800DE9B4);
                if (D_800DE7AC != NULL) {
                    temp_v1 = (*(void **)((u8 *)D_800DE7AC + 0x2D0));
                    (*(s32 *)((u8 *)temp_v1 + 0x668)) = (s32) ((*(s32 *)((u8 *)temp_v1 + 0x668)) + D_800DE9B4);
                }
            }
        } else if (D_800DE9AC == 1) {
            func_8004A89C(&D_800DE144);
        }
        func_80046524();
        func_8006D4B0();
        if (D_800DE84C == 0) {
            func_80062A90();
            func_80079728();
        }
    }
}
