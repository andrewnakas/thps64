#include "common.h"

extern s32 D_800D613C;

void func_8004606C(void *arg0) {
    s32 var_a2;
    void *var_a1;

    var_a2 = 0;
    if ((*(s32 *)((u8 *)(arg0) + 0x388)) > 0) {
        var_a1 = arg0;
        do {
            if ((s32) (*(u16 *)((u8 *)((*(void **)((u8 *)(var_a1) + 0x208))) + 6)) >= (*(s32 *)((u8 *)(var_a1) + 0x204))) {
                (*(s32 *)((u8 *)(var_a1) + 0x204)) = 0;
            }
            var_a2 += 1;
            var_a1 += 0x14;
        } while (var_a2 < (*(s32 *)((u8 *)(arg0) + 0x388)));
    }
    (*(s32 *)((u8 *)(arg0) + 0x4BC)) = (s32) D_800D613C;
}
