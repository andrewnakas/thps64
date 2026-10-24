/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 *unk0;
    s32 unk4;
} Stack800BC8B8;

typedef struct {
    u8 pad0[0x80];
    s32 unk80;
} Sub800BC8B8;

typedef struct {
    u8 pad0[0x1E0];
    Stack800BC8B8 unk1E0;
    u8 pad1E8[0x34];
    s32 unk21C;
    u8 pad220[0x18];
    s32 unk238;
    u8 pad23C[0x18];
    s32 unk254;
    u8 pad258[0xC];
    Sub800BC8B8 *unk264;
    s32 unk268;
} Obj800BC8B8;

extern void func_80005070(s32, s32, s32);

void func_800BC8B8(Obj800BC8B8 *arg0) {
    s32 ok;
    s32 n;
    s32 x;
    Stack800BC8B8 *s;

    if (arg0->unk1E0.unk4 != 0) {
        ok = 0;
        if (arg0->unk21C == 0 && arg0->unk238 == 0 && arg0->unk268 == 0 &&
            (arg0->unk264 == NULL || arg0->unk264->unk80 != 0) && arg0->unk254 == 0) {
            ok = 1;
        }
        s = &arg0->unk1E0;
        if (ok != 0) {
            while (1) {
                n = s->unk4;
                if (n == 0) break;
                x = arg0->unk1E0.unk0[n - 1];
                s->unk4 = n - 1;
                func_80005070(x, 0, 0);
            }
        }
    }
}
