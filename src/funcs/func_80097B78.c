/* compiler: cc1plus */
/* C++ destructor (g++ 2.x, `this` + __in_chrg): store this class's vtable (D_80020860, vptr at 0x2C), run the body
 * (a scoped 8-byte guard object around two calls on the member at 0x1AC of the global D_800D3130), then the
 * compiler-generated member and base destruction: the array of 3 x 0x14-byte members at 0x44 back to front (g++'s
 * vec-delete shape: null test, then end pointer down to the base), the 0x14-byte member at 0x30, and last the base
 * destructor func_800394A8 with the caller's __in_chrg unchanged. Written as an extern "C" function with the calls
 * spelled out because cc1plus 2.8.1 cannot bind a destructor to a game symbol (asm labels on destructors fail). */
#include "common.h"

extern "C" u8 D_80020860[];   /* vtable */

struct Res {
    u8 pad[0x1AC];
    u8 sub[0x10];
    /* an inline member: `this` reaches it as a plain pointer, so the game's lui/addiu D_800D3130 + addiu 0x1AC */
    u8 *get() { return sub; }
};
extern "C" Res D_800D3130;

extern "C" void func_8008BB50(void *);              /* guard constructor */
extern "C" void func_800A73EC(void *, s32);
extern "C" void func_8008B490(void *, void *, s32);
extern "C" void func_8008BB2C(void *, s32);         /* guard destructor */
extern "C" void func_800B19C0(void *, s32);         /* destructor of the 0x14-byte members */
extern "C" void func_800394A8(void *, s32);         /* base class destructor */

extern "C" void func_80097B78(u8 *self, s32 inChrg) {
    *(u8 **)(self + 0x2C) = D_80020860;
    {
        s32 guard[2];
        u8 *res;

        func_8008BB50(guard);
        res = D_800D3130.get();
        func_800A73EC(res, 0x501);
        func_8008B490(guard, res, 0x501);
        func_8008BB2C(guard, 2);
    }
    {
        u8 *first = self + 0x44;

        if (first != 0) {
            u8 *p = self + 0x80;

            if (first != p) {
                u8 *base = first;

                do {
                    p -= 0x14;
                    func_800B19C0(p, 2);
                } while (base != p);
            }
        }
    }
    func_800B19C0(self + 0x30, 2);
    func_800394A8(self, inChrg);
}
