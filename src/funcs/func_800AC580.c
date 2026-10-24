/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 a;
    s32 b;
} Item;

void *func_800B1850(s32);
extern s32 D_800FC330;
extern s32 D_800FC334;
extern s32 D_800FC338;
extern Item *D_800FC33C;

void func_800AC580(s32 arg0) {
    if (arg0 < 0x40) {
        arg0 = 0x40;
    } else if (arg0 > 0x400) {
        arg0 = 0x400;
    }
    D_800FC33C = (Item *)func_800B1850(arg0 * sizeof(Item));
    D_800FC338 = arg0;
    D_800FC334 = 0;
    D_800FC330 = 0;
}
