/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 off;
    s16 pad;
    void (*fn)(void *);
} VEnt800A1FB8;

void func_800A0C6C(u8 *, s32);
void func_800A0C8C(u8 *);
s32 func_800A2090(u8 *, u8 *);
void func_800A237C(u8 *, s32, s32, s32, s32, s32);
void func_800A2FE0(u8 *, u8 *, s32, u8 *, s32);
void func_800A3194(u8 *);
void func_800A3750(u8 *, s32, s32, s32, s32, u8 *, s32);

void func_800A1FB8(u8 *arg0) {
    u8 buf[0x68];
    VEnt800A1FB8 *v;

    if (func_800A2090(arg0, buf) != 0) {
        func_800A2FE0(arg0, buf, 0, arg0 + 0x480, 0);
        if (*(s32 *)(arg0 + 0x14) != 0) {
            *(s32 *)(arg0 + 8) = 0x16;
            func_800A0C8C(arg0);
            func_800A237C(arg0, *(s32 *)(arg0 + 0x498), 4, *(s32 *)(arg0 + 0x18), 1, 0);
            return;
        }
        *(s32 *)(arg0 + 8) = 0x14;
        v = (VEnt800A1FB8 *)(*(u8 **)(arg0 + 0x4F8) + 0x38);
        v->fn(arg0 + v->off);
        func_800A0C6C(arg0, *(s32 *)(arg0 + 0x420));
        func_800A3750(arg0, *(s32 *)(arg0 + 0x49C), *(s32 *)(arg0 + 0x434), 0, 0, arg0 + 0x444, 0);
        func_800A3194(arg0);
    }
}
