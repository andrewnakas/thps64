/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 off;
    s16 pad;
    void (*fn)(void *);
} VEnt800A1244;

void func_800A04D8(u8 *, s32);
void func_800A0C6C(u8 *, s32);
s32 func_800A1504(u8 *, u8 *);
void func_800A237C(u8 *, char *, s32, s32, s32, s32);
void func_800A2FE0(u8 *, u8 *, s32, s32, s32);
void func_800A3194(u8 *);
void func_800A3750(u8 *, char *, s32, s32, s32, u8 *, s32);
extern char D_80020D74[];
extern char D_80020D84[];

void func_800A1244(u8 *arg0) {
    u8 buf[0x68];
    VEnt800A1244 *v;

    if (func_800A1504(arg0, buf) != 0) {
        func_800A04D8(arg0, *(s32 *)(arg0 + 0x434));
        func_800A2FE0(arg0, buf, 1, 0, 1);
        if (*(s32 *)(arg0 + 0x14) != 0) {
            *(s32 *)arg0 = 0xC;
            func_800A237C(arg0, D_80020D74, 1, -1, 0, 1);
            return;
        }
        *(s32 *)arg0 = 0xA;
        v = (VEnt800A1244 *)(*(u8 **)(arg0 + 0x4F8) + 0x38);
        v->fn(arg0 + v->off);
        func_800A0C6C(arg0, *(s32 *)(arg0 + 0x418));
        func_800A3750(arg0, D_80020D84, *(s32 *)(arg0 + 0x434), 0, 0, arg0 + 0x444, 0);
        func_800A3194(arg0);
    }
}
