#include "common.h"

extern void *D_800DACC0;

void func_80061E7C(s32 arg0) {
    void *var_v1;

    var_v1 = D_800DACC0;
    if (var_v1 != NULL) {
        do {
            (*(u8 *)((u8 *)(var_v1) + 4)) = (u8) ((*(u8 *)((u8 *)(var_v1) + 4)) & ~arg0);
            var_v1 = (*(void **)((u8 *)(var_v1) + 0x14));
        } while (var_v1 != NULL);
    }
}
