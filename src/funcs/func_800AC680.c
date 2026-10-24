#include "common.h"

typedef struct { u8 type; s32 val; } M800AC680;
void func_800AE384(s32, s32, s32);

void func_800AC680(M800AC680 *arg0) {
    switch (arg0->type) {
    case 0:
        func_800AE384(arg0->val, -2, 1);
        break;
    case 1:
        func_800AE384(arg0->val, -2, 0);
        break;
    case 2:
        break;
    }
}
