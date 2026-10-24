/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Acmd800B10AC;

typedef struct {
    u8 pad0[0x14];
    s32 state;
    u8 pad18[0x20 - 0x18];
    f32 delta;
    s32 first;
} Rs800B10AC;

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x18 - 0x8];
    s32 unk18;
    u8 pad1C[0x24 - 0x1C];
    Rs800B10AC *rs;
} Fx800B10AC;

typedef struct {
    u8 pad0[0x18];
    s32 unk18;
} Buf800B10AC;

extern s32 func_80003520(s32);
extern f32 func_8000F770(Fx800B10AC *, s32);
extern Acmd800B10AC *func_800B12A0(Buf800B10AC *, s32, s32, s32, s32);

static inline Acmd800B10AC *pull(Buf800B10AC *arg0, Fx800B10AC *arg1, s32 arg2, s32 arg3, s32 n) {
    Acmd800B10AC *p;
    f32 pitch;
    f32 k;
    f32 f;
    f32 delta;
    s32 cnt;
    s32 s;
    s32 al;
    s32 len;
    s32 ip;


    if (arg1->rs != NULL) {
        len = arg1->unk4 - arg1->unk0;
        k = 32768.0f;
        delta = func_8000F770(arg1, 0xB8);
        delta /= len;
        delta = (s32)(delta * k);
        delta /= 32768.0f;
        pitch = 1.0 - delta;
        f = arg1->rs->delta + pitch * n;
        cnt = f;
        arg1->rs->delta = f - cnt;
        s = arg0->unk18 + (arg1->unk18 - arg1->unk4) * 2;
        al = (s & 7) >> 1;
        p = func_800B12A0(arg0, s - al * 2, 0x2E0, cnt + al, arg3);
        ip = pitch * k;
        arg2 >>= 8;
        {
            Acmd800B10AC *_a = p++;
            _a->w0 = (func_80003520(arg1->rs->state) & 0xFFFFFF) | 0x05000000;
            _a->w1 = (arg1->rs->first << 30) | ((ip & 0xFFFF) << 14) | ((al * 2 | 0x2E0) << 2) | (arg2 & 3);
        }
        arg1->rs->first = 0;
        arg1->unk18 += cnt - n;
    } else {
        p = func_800B12A0(arg0, arg0->unk18 - arg1->unk4 * 2, arg2, 0xB8, arg3);
    }
    return p;
}

Acmd800B10AC *func_800B10AC(Buf800B10AC *arg0, Fx800B10AC *arg1, s32 arg2, s32 arg3) {
    s32 n = 0xB8;
    return pull(arg0, arg1, arg2, arg3, n);
}
