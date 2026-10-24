/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x18];
    u8 *unk18;
} Sub800AAEB4;

typedef struct {
    u8 pad0[0x74];
    Sub800AAEB4 *unk74;
} Obj800AAEB4;

extern void func_800AAAE0(Obj800AAEB4 *, u8 *);

u8 *func_800AAEB4(Obj800AAEB4 *arg0, u8 *arg1) {
    u32 n;

    n = *arg1++;
    if (n & 0x80) {
        n &= 0x7F;
        n <<= 8;
        n |= *arg1++;
    }
    func_800AAAE0(arg0, arg0->unk74->unk18 + n * 7);
    return arg1;
}
