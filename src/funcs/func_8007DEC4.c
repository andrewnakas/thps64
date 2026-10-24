#include "common.h"

typedef struct {
    u8 pad0[0xA4];
    s32 unkA4;
    s32 unkA8;
    s16 unkAC;
    s16 unkAE;
} Obj8007DEC4;

void func_8007DEC4(Obj8007DEC4 *arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, u8 arg10) {
    arg0->unkA4 = (arg1 << 16) | (arg4 << 8) | (arg3 & 0xFF);
    arg0->unkA8 = (arg2 << 16) | ((arg6 & 0xFF) << 8) | (arg5 & 0xFF);
    arg0->unkAC = ((arg8 & 0xFF) << 8) | (arg7 & 0xFF);
    arg0->unkAE = ((arg10 & 0xFF) << 8) | (arg9 & 0xFF);
}
