#include "common.h"

void func_80001A30(s32 *, void *);
void func_8007EBE4(void *);
void func_8009C8EC(s32 *, s32 *);
void func_8009C914(s32 *, u8 *, s32);
void func_8009CB68(s32 *, s32 *);
extern s32 D_800F32B8;

void func_80084CB8(u8 *arg0, s32 arg1, s32 arg2) {
    s32 mtx[16];
    s32 zero[4];
    s32 tmp[16];
    s32 i;
    u8 *src;
    u8 *dst;
    u8 *obj;
    s32 offset;
    s32 bit;
    s32 *out;

    func_8007EBE4(*(void **) (arg0 + 0xC00));
    obj = *(u8 **) (arg0 + 0xC00);
    offset = D_800F32B8 * 0x600;
    i = 0;
    bit = 1;
    out = tmp;
    dst = arg0 + offset;
    src = *(u8 **) (obj + 0x214);
    while (1) {
        if (i >= *(s32 *) (arg0 + 0xC0C)) {
            break;
        }
        if (arg2 & (bit << i)) {
            zero[2] = 0;
            zero[1] = 0;
            zero[0] = 0;
            func_8009CB68(mtx, zero);
        } else {
            func_8009C914(out, src, arg1);
            func_8009C8EC(mtx, out);
        }
        func_80001A30(mtx, dst);
        dst += 0x40;
        src += 0x40;
        i++;
    }
}
