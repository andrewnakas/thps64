/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x44];
    s32 *vt;
    u8 pad48[0x8];
    u32 n;
    u8 pad54[0x14];
    s32 b[8];
    s32 a[8];
    s32 scaled;
    s32 len;
} Obj8007D91C;

s32 func_80049D60(s32);
void func_80079C10(Obj8007D91C *, s32, s32, s32, s32, u8, u8, u8, u8, u8);
extern s32 D_8001E2C0;

Obj8007D91C *func_8007D91C(Obj8007D91C *this, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, u8 arg6,
                           u8 arg7, u8 arg8, u8 arg9, u8 arg10) {
    u32 i;

    func_80079C10(this, arg1, arg2, arg3, arg5, arg6, arg7, arg8, arg9, arg10);
    this->vt = &D_8001E2C0;
    this->len = arg2;
    this->scaled = arg2 * arg4 / 256;
    for (i = 0; i < this->n; i++) {
        this->a[i] = func_80049D60(0x1000);
        this->b[i] = func_80049D60(0x32) + 0x32;
    }
    return this;
}
