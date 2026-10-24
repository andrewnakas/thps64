/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 base;
    u8 pad4[0x24];
    s32 locked;
} Dev800B2CF0;

typedef struct {
    s32 pad0;
    u8 *data;
} Page800B2CF0;

extern void func_80000B08(s32, s32, s32);
extern void func_80004ED0(void *, s32, s32);
extern void func_80005070(void *, s32, s32);
extern void func_80005720(u8 *, u8 *, u32);
extern void func_800B2A5C(void);
extern void func_800B2BF4(s32, void *, void *, s32);
extern Page800B2CF0 *func_800B2EA0(Dev800B2CF0 *, s32, s32, s32);
extern void func_800BC0F4(void *);
extern u8 D_800ECF40[];
extern u8 D_800ECF50[];
extern u8 D_800ECF54[];
extern s32 D_800ECF70;
extern s32 D_800ECF74;
extern s32 D_800ECF78;
extern s32 D_800ECF7C;
extern s32 D_800ECF80;
extern u8 D_800ECF84[];
extern s32 D_800ECFA0;
extern s32 D_800ECFA4;
extern u8 D_800F0DD0[];

s32 func_800B2CF0(Dev800B2CF0 *arg0, s32 arg1, u32 arg2, u8 *arg3) {
    s32 off;
    s32 page;
    s32 in;
    u32 n;
    s32 ok;
    Page800B2CF0 *p;
    u8 *dst;

    if (arg0->locked != 0) {
        func_80005070(D_800ECF54, 0, 1);
        if (D_800ECF74 != 0 && D_800ECF70 != 0) {
            func_800BC0F4(D_800F0DD0);
            func_800B2A5C();
            func_800B2BF4(D_800ECF78, D_800ECF40, D_800ECF50, 1);
            D_800ECF74 = 0;
        }
    }
    dst = arg3;
    ok = 1;
    off = arg1 - arg0->base;
    while (1) {
        if (arg2 == 0) break;
        if (D_800ECF80 != 0) {
            func_80004ED0(D_800ECF84, 0, 1);
            D_800ECF80 = 0;
            func_80000B08(D_800ECF7C, D_800ECFA4, D_800ECFA0);
            D_800ECFA4 = 0;
        }
        page = off & ~0x3FFF;
        in = off - page;
        n = 0x4000 - in;
        if (arg2 < n) {
            n = arg2;
        }
        p = func_800B2EA0(arg0, page, 0, n < arg2);
        if (p == NULL) {
            ok = 0;
            break;
        }
        func_80005720(dst, p->data + in, n);
        off += n;
        dst += n;
        arg2 -= n;
    }
    do {
        if (arg0->locked != 0) {
            func_80004ED0(D_800ECF54, 0, 1);
        }
        return ok;
    } while (0);
}
