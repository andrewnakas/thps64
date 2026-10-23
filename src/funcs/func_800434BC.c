#include "common.h"

typedef struct {
    s16 a;
    s16 b;
    s16 c;
} V3s;

extern V3s D_800D4918[];

void func_800434BC(u8 *arg0) {
    V3s *dst;
    s32 *dst2;
    V3s *src;
    s32 i;

    i = 0;
    dst = D_800D4918;
    dst2 = (s32 *)dst;
    src = (V3s *)arg0;
    do {
        dst->a = src->a;
        dst->b = src->b;
        dst->c = src->c;
        dst2[5] = *(s32 *)(arg0 + 0x14);
        arg0 += 4;
        dst2++;
        dst++;
        src++;
        i++;
    } while (i < 3);
}
