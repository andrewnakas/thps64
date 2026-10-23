#include "common.h"

typedef struct {
    s32 x, y, z;
} V3i;

typedef struct {
    s16 x, y, z, w;
} V3s;

s32 func_80022E54(V3i *, V3i *);
V3i func_80046D28(V3i *);
V3i func_80046F58(V3i *, s32 *);
void func_8004A204(u8 *, s32, s32, s32, s32);
void func_8004D2D4(u8 *);
void func_8004D398(u8 *, s32);
void func_8005BE8C(u8 *);

void func_8005427C(u8 *arg0, V3s arg1) {
    V3i pos;
    V3i tmp;
    V3i r;
    V3i v;
    s32 k;
    V3i *p;

    if (*(s32 *)(arg0 + 0x450) == 0 && *(s32 *)(arg0 + 0x82C) != 2) {
        p = (V3i *)(arg0 + 0x8E8);
        {
            s32 x = arg1.x;
            s32 y = arg1.y;
            s32 z = arg1.z;
            pos.x = x;
            pos.y = y;
            pos.z = z;
        }
        if (func_80022E54(p, &pos) < 2000 && *(s32 *)(arg0 + 0x8EC) >= -1999) {
            func_8004D398(arg0, 0);
            *(s32 *)(arg0 + 0x228) = 0x10000;
            func_8004D2D4(arg0);
            func_8004A204(arg0, 0x38, 0, -1, -1);
            *(s32 *)(arg0 + 0x344) = 9;
            tmp = *(V3i *)(arg0 + 0x8D0);
            r = func_80046D28(p);
            *(V3i *)(arg0 + 0x8D0) = r;
            *(V3i *)(arg0 + 0x8E8) = tmp;
            func_8005BE8C(arg0);
            v = func_80046D28((V3i *)(arg0 + 0x8D0));
            k = 10;
            r = func_80046F58(&v, &k);
            *(V3i *)(arg0 + 0x84) = r;
            *(s32 *)(arg0 + 0x88) = 0;
        }
    }
}
