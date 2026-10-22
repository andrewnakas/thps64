#include "common.h"

typedef struct {
    u8 pad0[0x5C0];
    s32 unk5C0;
    u8 pad5C4[0x828 - 0x5C4];
    s16 unk828[5];
    u8 unk832;
    u8 pad833[1];
    s32 unk834;
} Struct8002E818;

s16 func_8002E8F8(Struct8002E818 *);                          /* extern */
s32 func_8002EA7C(Struct8002E818 *);                      /* extern */

void func_8002E818(Struct8002E818 *arg0) {
    s32 temp_v1;
    u8 temp_a0;
    u8 var_v0;

    if ((arg0->unk832 >= 5U) || (arg0->unk834 >= 0x32)) {
        arg0->unk832 = 0U;
        arg0->unk834 = 0;
        func_8002EA7C(arg0);
    }
    arg0->unk828[arg0->unk832] = func_8002E8F8(arg0);
    temp_a0 = arg0->unk832;
    if (arg0->unk828[temp_a0] != -0x2D) {
        if ((temp_a0 == 0) && ((temp_v1 = arg0->unk5C0, (temp_v1 == 0xE)) || (temp_v1 == 0x1A) || (temp_v1 == 0x1B) || (temp_v1 == 0x1C) || (temp_v1 == 0x1D))) {
            var_v0 = arg0->unk832 + 1;
        } else {
            var_v0 = arg0->unk832 + 2;
        }
        arg0->unk832 = var_v0;
    }
}
