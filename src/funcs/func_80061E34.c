#include "common.h"

typedef struct Node80061E34 {
    u8 pad[4];
    u8 b4;
    u8 b5;
    u8 pad2[0xE];
    struct Node80061E34 *next;
} Node80061E34;

extern Node80061E34 *D_800DACC0;

void func_80061E34(s32 arg0) {
    s32 temp_a1;
    Node80061E34 *var_v1;

    var_v1 = D_800DACC0;
    while (var_v1 != NULL) {
        temp_a1 = var_v1->b5;
        if ((temp_a1 & arg0) && !(var_v1->b4 & arg0)) {
            var_v1->b5 = temp_a1 & ~arg0;
        }
        var_v1 = var_v1->next;
    }
}
