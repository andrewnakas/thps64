/* cflags: -O2 */
#include "common.h"

s32 func_800057E4(s32, char *, ...);
void func_8009FD60(s32, s32 *);
void func_800A0B0C(void *, u8 *, void *, s32);
extern s32 D_80020DAC;
extern char D_80021000[];
extern char D_80021008[];

void func_800A2F04(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    char name[0x18];
    u8 tag[8];
    u8 *e;

    e = *(u8 **)(arg0 + 0x4B4) + arg1 * 0x28;
    func_800A0B0C(arg0, e + 0xE, name, 0x10);
    func_800A0B0C(arg0, e + 0xA, tag, 4);
    if (tag[0] != 0 && tag[0] != 0x20 && *(s32 *)(arg0 + 0x464) != 0) {
        func_800057E4(arg2, D_80021000, name, tag);
    } else {
        func_800057E4(arg2, D_80021008, name);
    }
    if (arg3 != 0) {
        func_8009FD60(arg3, &D_80020DAC);
    }
}
