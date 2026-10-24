/* cflags: -O2 */
#include "common.h"
#include "types/object.h"

extern s32 D_800EA550;

void func_800A237C(Menu *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 i;

    arg0->unk498 = arg1;
    arg0->unk408[5] = arg2;
    arg0->unk18 = arg3;
    arg0->unk468 = 0;
    arg0->unk46C = arg4;
    arg0->unk470 = arg5;
    D_800EA550 = 3;
    if (arg0->unk14 != 0 && arg0->unk18 != -1) {
        i = arg0->unk18;
        while (arg0->unk4B4[i].unk24 == 0) {
            i = (i + 1) % arg0->unk14;
            arg0->unk18 = i;
        }
    }
}
