#include "common.h"

s32 func_800849FC(void *, s32);                       /* extern */
void func_80084A14(void *, s32, s32);                     /* extern */
s32 func_8009B7D8(void *, void *, s32, s32);               /* extern */
s32 func_8009B898(void *, s32, s32);                               /* extern */
void func_8009ECF8(void *, s32);                          /* extern */
extern s32 D_800EA110[];

s32 func_80084914(void *arg0, s32 arg1) {
    s32 sp10[2];
    s32 *buf;
    s32 block;
    s32 offset;
    s32 base;
    s32 result;

    block = func_8009B898(arg0, arg1, 4);
    if (block != 0) {
        offset = func_800849FC(arg0, arg1);
        base = *(s32 *) ((u8 *) arg0 + 4);
        base += offset;
        buf = sp10;
        func_80084A14(buf, block, base);
        result = func_8009B7D8(arg0, buf, 2, 8);
        func_8009ECF8(&D_800EA110, block);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}
