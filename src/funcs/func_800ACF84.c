/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad[0x1C];
} E1C;

extern void func_800AFC80(E1C *, s32);
extern void func_800AFD10(E1C *);
extern E1C *D_800FC2F4;

void func_800ACF84(u8 *arg0, s32 arg1) {
    if (arg0[0xC9] != 0) {
        func_800AFD10(&D_800FC2F4[arg1]);
    }
    arg0[0xC9] = 1;
    func_800AFC80(&D_800FC2F4[arg1], *(s32 *)(arg0 + 8));
    *(s32 *)(arg0 + 8) = 0;

}
