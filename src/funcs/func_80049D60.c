/* cflags: -fexpensive-optimizations */
#include "common.h"

extern s32 D_800FA970;
extern s32 D_800FA974;
extern s32 D_800FA978;

s32 func_80049D60(s32 arg0) {
    D_800FA970 = D_800FA970 * D_800FA974 + D_800FA978;
    D_800FA974 = (D_800FA974 ^ D_800FA970) + (D_800FA970 >> 4);
    D_800FA978 = D_800FA978 + (0xEFEFEFF0 + (D_800FA970 >> 3));
    return ((D_800FA970 & 0xFFFF) * arg0) >> 16;
}
