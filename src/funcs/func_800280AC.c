/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

s32 func_80024BBC(s32);                         /* extern */
s32 func_80024BC4(s32, s32);                    /* extern */
s32 func_800269C4(s32);                         /* extern */
s32 func_80026B88(s32);                         /* extern */
s32 func_80026D2C(s32);                         /* extern */
s32 func_80027D80(s32);                         /* extern */
s32 func_8004A544();                            /* extern */
s32 func_8004C880(s32);                         /* extern */
s32 func_8005C864(s32);                         /* extern */
extern s32 D_800D2838;
extern s32 D_800E9038;

void func_800280AC(s32 arg0) {
    s32 temp_s0;

    D_800D2838 = arg0;
    if (D_800E9038 == 0) {
        func_8004A544();
    }
    func_8004C880(arg0);
    func_800269C4(arg0);
    func_8005C864(arg0);
    func_80026B88(arg0);
    func_80026D2C(arg0);
    func_80027D80(arg0);
    temp_s0 = arg0 + 0x22D0;
    func_80024BC4(temp_s0, arg0 + 0x2290);
    func_80024BBC(temp_s0);
    D_800D2838 = 0;
}
