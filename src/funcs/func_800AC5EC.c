/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 a;
    s32 b;
} Item;

void func_800AC680(Item *);
extern s32 D_800FC330;
extern s32 D_800FC334;
extern s32 D_800FC338;
extern Item *D_800FC33C;

void func_800AC5EC(void) {
    while (D_800FC330 != D_800FC334) {
        func_800AC680(&D_800FC33C[D_800FC330]);
        if (++D_800FC330 == D_800FC338) {
            D_800FC330 = 0;
        }
    }
}
