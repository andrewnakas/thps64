/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 *data;
    s32 count;
    s32 cap;
} Vec;

extern void func_80005720(s32 *, s32 *, s32);
extern s32 *func_8009E6B4(u8 *, s32, s32);
extern void func_8009ECF8(u8 *, s32 *);
extern u8 D_800EA110[];

void func_800BD5A0(Vec *arg0, s32 arg1) {
    s32 *p;

    if (arg0->cap < arg1) {
        p = func_8009E6B4(D_800EA110, arg1 * 4, 4);
        func_80005720(p, arg0->data, arg0->count * 4);
        func_8009ECF8(D_800EA110, arg0->data);
        arg0->data = p;
        arg0->cap = arg1;
    }

}
