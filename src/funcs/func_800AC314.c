/* cflags: -O2 */
#include "common.h"

typedef struct {
    s8 unk0;
    s32 unk4;
} Arg_800AC6D4;

s32 func_800AC6D4(Arg_800AC6D4 *); /* extern */

void func_800AC314(s32 arg0) {
    Arg_800AC6D4 sp10;

    sp10.unk4 = arg0;
    sp10.unk0 = 0;
    func_800AC6D4(&sp10);
}
