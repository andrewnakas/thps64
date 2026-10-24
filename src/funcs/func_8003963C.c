#include "common.h"

extern f32 D_800D0FEC;

typedef struct {
    s32 unk0;
    s32 id;
    u8 pad8[0xC];
    u8 vol;
    u8 pad15[0x44 - 0x15];
} Chan_8003963C;

typedef struct {
    Chan_8003963C ch[3];
    u8 padCC[0x109 - 0xCC];
    u8 div;
} Obj_8003963C;

static __inline__ u8 calc(Obj_8003963C *arg0, u16 arg1) {
    s32 n;
    s32 x = arg1;

    n = x / arg0->div;
    if (n >= 0x100) {
        f32 c;
        f32 t;
        u32 v;
        u32 m;

        t = D_800D0FEC * 255.0f;
        if (!(t >= (c = 2147483648.0f))) {
            v = (s32) t;
        } else {
            f32 d = t - c;
            m = 0x80000000;
            v = (s32) d | m;
        }
        return v;
    }
    if (n < 0) {
        return 0;
    }
    {
        f32 c;
        f32 t;
        u32 v;
        u32 m;

        c = (f32) n;
        t = D_800D0FEC;
        t *= c;
        if (!(t >= (c = 2147483648.0f))) {
            v = (s32) t;
        } else {
            f32 d = t - c;
            m = 0x80000000;
            v = (s32) d | m;
        }
        return v;
    }
}

void func_8003963C(Obj_8003963C *arg0, s32 arg1, s32 arg2, s32 arg3) {
    switch (arg1) {
    case 0:
        break;
    case 1:
        arg2 &= 0xFF;
        if (arg0->ch[0].id == arg2) {
            u8 *p = &arg0->ch[0].vol;
            if (arg2 != 0x23) {
                *p = calc(arg0, arg3);
            } else {
                arg0->ch[0].vol = 0;
            }
        } else if (arg0->ch[1].id == arg2) {
            arg0->ch[1].vol = calc(arg0, arg3);
        } else if (arg0->ch[2].id == arg2) {
            arg0->ch[2].vol = calc(arg0, arg3);
        }
        break;
    }
}
