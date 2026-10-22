#include "common.h"
typedef struct { s32 unk0; s32 unk4; } Unk800847E8;
extern Unk800847E8 D_800E8A58[];
s32 func_800420D8(s32, s32);
s32 func_800847E8(void *arg0, s32 arg1) {
    s32 *var_s0;
    Unk800847E8 *var_s1 = D_800E8A58;
    if (var_s1->unk4 != -1) {
        s32 temp_s2 = -1;
        var_s0 = &var_s1->unk4;
        do {
            if (func_800420D8(arg1, var_s1->unk0) == 0) {
                return *var_s0;
            }
            var_s0 += 2;
            var_s1++;
        } while (*var_s0 != temp_s2);
    }
    return -1;
}
