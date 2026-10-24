/* cflags: -O2 */
#include "common.h"

typedef struct {
    void **items;
    s32 count;
} Arr;

void func_80005070(void *, void *, s32);

void func_800BCA1C(void *arg0, Arr *arg1, void *arg2) {
    s32 i = 0;
    s32 n = arg1->count;
    s32 off;

    while (1) {
        if (i >= n) {
            break;
        }
        off = i * 4;
        if (i >= arg1->count) {
            arg1->count = i - 1;
        }
        i++;
        func_80005070(*(void **)((u8 *)arg1->items + off), arg2, 0);
    }
}
