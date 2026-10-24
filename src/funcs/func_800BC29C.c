/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} Arg_800BC2C8;

s32 func_800BC6E4(s32, void *, Arg_800BC2C8 *); /* extern */
void func_800BC2C8(void);

void func_800BC29C(s32 arg0, s32 arg1, s32 arg2) {
    Arg_800BC2C8 sp10;

    sp10.unk4 = arg1;
    sp10.unk0 = arg2;
    func_800BC6E4(arg0, func_800BC2C8, &sp10);
}
