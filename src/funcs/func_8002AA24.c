#include "common.h"

void func_800394A8(void *, s32);
void func_800A735C(void *, s32);
void func_800B19C0(void *, s32);
extern u8 D_80019270[];

void func_8002AA24(u8 *arg0, s32 arg1) {
    u8 *end;
    u8 *beg;

    *(u8 **)(arg0 + 0x2C) = D_80019270;
    end = arg0 + 0x80;
    func_800A735C(end, 2);
    beg = arg0 + 0x58;
    if (beg != NULL) {
        if (beg != end) {
            u8 *b = beg;
            do {
                end -= 0x14;
                func_800B19C0(end, 2);
            } while (b != end);
        }
    }
    func_800B19C0(arg0 + 0x44, 2);
    func_800B19C0(arg0 + 0x30, 2);
    func_800394A8(arg0, arg1);
}
