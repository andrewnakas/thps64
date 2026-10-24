/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    s32 unk10;
} Obj800B4818;

extern void func_8009E334(s32);
extern void func_800B4738(s32, Obj800B4818 *);
extern void func_800B5A4C(s32);
extern void func_800BC0F4(void *);
extern u8 D_800F0DD0[];

void func_800B4818(s32 arg0, Obj800B4818 *arg1) {
    s32 t;

    if (--arg1->unkC == 0) {
        func_800BC0F4(D_800F0DD0);
        func_800B4738(arg0, arg1);
        t = arg1->unk10;
        if (t != 0) {
            func_800B5A4C(t);
            func_8009E334(t);
        }
    }
}
