/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Unk_800B260C_38;

s32 func_800B2848(void *, s32); /* extern */
s32 func_800B2860(void *); /* extern */

u8 *func_800B260C(u8 *arg0) {
    Unk_800B260C_38 *t;

    func_800B2848(arg0, 0);
    func_800B2860(arg0 + 0xC);
    *(s32 *)(arg0 + 0x38) = 0x10;
    t = (Unk_800B260C_38 *)(arg0 + 0x38);
    *(s32 *)(arg0 + 8) = 0;
    t->unk4 = 0x14;
    t->unkC = 0;
    t->unk8 = 0;
    return arg0;
}
