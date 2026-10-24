/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 unk0;
    u8 pad4[0x40];
    s32 unk44;
} Obj;

extern void (*D_800FC32C)(s32, s32);

u8 *func_800AB410(Obj *arg0, u8 *arg1) {
    s32 c = *arg1++;

    if (*arg1++ & 0x80) {
        arg1++;
    }
    if ((arg0->unk0 & 3) == 2 && D_800FC32C != NULL) {
        D_800FC32C(arg0->unk44, c);
    }
    return arg1;
}
