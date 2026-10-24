/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */

#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x10];
} Lap4CED0;

typedef struct {
    u8 pad0[0x84];
    u8 unk84[0x34C - 0x84];
    s32 unk348_pad;
} Dummy4CED0;

void *func_80022E54(void *, void *);
s32 func_800233B8(void *);
void func_8003A310(s32);
void func_8003A334(s32);
void func_8004634C(void *);
void func_8004C63C(void *, s32, s32, s32, s32);
void func_8005C690(void *, s32, s32, s32);
extern s32 D_800DE7A0;

#define I(o) (*(s32 *)(arg0 + (o)))

static inline s32 bonus_8004CED0(u8 *arg0, s32 sum, s32 n) {
    if (I(0x424) < 3) {
        return sum * (n + I(0x424)) / 2;
    } else {
        s32 t = n - 2;
        return sum * (t + I(0x424) * 2) >> 1;
    }
}

void func_8004CED0(u8 *arg0) {
    s32 len;
    s32 i;
    s32 sum;
    s32 n;
    s32 pad[2];

    if (D_800DE7A0 == 7) {
        I(0x428) = 0;
    }
    I(0x858) = 0;
    I(0x424) = 0;
    I(0x420) = 0;
    I(0x3D4) = 0;
    I(0x3D8) = 0;
    I(0x818) = 0;
    I(0x380) = 0;
    I(0x37C) = 0;
    I(0x348) = 0;
    I(0x34C) = 0;
    func_8004C63C(arg0, 0, 0, 0, 10);
    len = func_800233B8(func_80022E54(arg0 + 0x84, arg0 + 0x84)) << 6;
    i = 0;
    n = I(0xDA4);
    sum = i;
    if (n > 0) {
        do {
            sum += ((Lap4CED0 *)(arg0 + 0xC18))[i].unk0;
            i++;
        } while (i < n);
    }
    sum = bonus_8004CED0(arg0, sum, I(0xDA4) * 2);
    if (sum != 0) {
        func_8003A334(sum);
    } else {
        func_8003A310(len >> 12);
    }
    for (i = 0; i < 80; i++) {
        ((s32 *)(arg0 + 0x520))[i] -= ((s32 *)(arg0 + 0x660))[i];
        ((s32 *)(arg0 + 0x660))[i] = 0;
    }
    func_8004634C(arg0);
    I(0x45C) = 0;
    I(0x460) = 0;
    func_8005C690(arg0, 8, 1, 150);
}
