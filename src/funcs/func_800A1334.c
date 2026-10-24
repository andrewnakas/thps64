/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 off;
    s16 pad;
    void (*fn)(void *, s32, char *, s32);
} VEnt800A1334;

s32 func_800057E4(char *, char *, ...);
void func_800A0C6C(u8 *, s32);
void func_800A3750(u8 *, char *, s32, s32, s32, u8 *, s32);
extern char D_80020DA0[];
extern s32 D_800EA550;

void func_800A1334(u8 *arg0) {
    char buf[0x18];
    VEnt800A1334 *v;
    char *name;

    if (*(s32 *)(arg0 + 0x18) == -1) {
        *(s32 *)arg0 = 0xA;
        D_800EA550 = *(s32 *)(arg0 + 0x418);
        return;
    }
    v = (VEnt800A1334 *)(*(u8 **)(arg0 + 0x4F8) + 0x40);
    v->fn(arg0 + v->off, *(s32 *)(arg0 + 0x18), buf, 0);
    name = (char *)(arg0 + 0x1C);
    func_800057E4(name, D_80020DA0, buf);
    func_800A0C6C(arg0, D_800EA550);
    func_800A3750(arg0, name, *(s32 *)(arg0 + 0x434), 3, 1, arg0 + 0x444, 0);
    *(s32 *)arg0 = 0xD;
}
