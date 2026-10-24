/* cflags: -O2 */
#include "common.h"

typedef struct { s32 *data; s32 count; } A800BD62C;
void func_8009E1D4(void *, void *, s32);

void func_800BD62C(A800BD62C *arg0, s32 arg1) {
    func_8009E1D4(&arg0->data[arg1], &arg0->data[arg1 + 1], (arg0->count - arg1 - 1) * 4);
    arg0->count--;
}
