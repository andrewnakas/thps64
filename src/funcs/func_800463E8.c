#include "common.h"

extern void func_800461E8(void *);
extern void func_8006D1A0(void *);

void func_800463E8(void *arg0) {
    func_800461E8((u8 *)arg0 + 0xA1C);
    *(s32 *)((u8 *)arg0 + 0xED4) = 0;
    func_8006D1A0(arg0);
}
