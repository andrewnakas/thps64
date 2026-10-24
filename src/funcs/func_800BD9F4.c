/* cflags: -O2 */
#include "common.h"

extern s32 D_800FC8C0;
extern u8 *D_800FC8B8[];
extern s32 D_800F32B8;
extern u8 D_800FC910[];

u8 *func_800BD9F4(void) {
    s32 n = D_800FC8C0;
    if (n >= 500) {
        return D_800FC910;
    }
    D_800FC8C0 = n + 1;
    return D_800FC8B8[D_800F32B8] + n * 64;
}
