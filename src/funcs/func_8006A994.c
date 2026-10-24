/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 pad4[2];
} E8006A994;

void func_8004A89C(s32 *);
void func_8004ACF0(s32 *);
void func_8004AD90(s32);
void func_8006B78C(void *, s32);
extern s32 D_800D6180;
extern s32 *D_800D61A8;
extern s32 D_800DC610;
extern s32 D_800DC614;
extern struct {
    u8 pad0[0x50];
    E8006A994 arr[1];
} D_800DC618;
extern s16 D_800DC668;
extern s32 D_800DDC60;

void func_8006A994(void) {
    s32 i;
    s32 *b;
    s32 *a;
    s32 n;
    s32 k;

    k = D_800DC614;
    if (k == 1) {
        n = D_800DC668 - 1;
        if (D_800DC668 == 1) {
            return;
        }
        a = D_800D61A8;
        b = (s32 *)a[7];
        D_800DC610 = 1;
        for (i = 0; i < n; i++) {
            func_8004AD90(D_800DDC60);
            func_8004AD90(D_800D6180);
            func_8006B78C(a, -1);
            if (b != NULL) {
                func_8006B78C(b, -1);
            }
            func_8004ACF0(&D_800D6180);
            func_8004A89C(&D_800DDC60);
        }
        D_800DC610 = 0;
    } else {
        n = D_800DC618.arr[k - 1].unk0 - D_800DC618.arr[k - 2].unk2 - 2;
        a = D_800D61A8;
        b = (s32 *)a[7];
        D_800DC610 = 1;
        for (i = 0; i < n; i++) {
            func_8004AD90(D_800DDC60);
            func_8004AD90(D_800D6180);
            func_8006B78C(a, -1);
            if (b != NULL) {
                func_8006B78C(b, -1);
            }
            func_8004ACF0(&D_800D6180);
            func_8004A89C(&D_800DDC60);
        }
        D_800DC610 = 0;
    }
}
