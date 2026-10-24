#include "common.h"

void func_8009BF50(void *arg0) {
    s32 var_v1;
    void *var_v0;

    var_v1 = 7;
    var_v0 = arg0 + 0xA64;
    (*(s16 *)((u8 *)arg0 + 0xE24)) = 0;
    (*(s16 *)((u8 *)arg0 + 0xE20)) = 0;
    (*(s16 *)((u8 *)arg0 + 0xE22)) = 0;
    (*(s16 *)((u8 *)arg0 + 0xE26)) = 0;
    do {
        (*(s8 *)((u8 *)var_v0 + 0x250)) = 0;
        var_v1 -= 1;
        var_v0 -= 0x17C;
    } while (var_v1 >= 0);
}
