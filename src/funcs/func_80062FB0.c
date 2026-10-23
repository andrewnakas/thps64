#include "common.h"

s32 *func_8005EAB4(s32, s32, s32);
extern s32 *D_800DAD9C;

void func_80062FB0(u8 *arg0, u8 *arg1) {
    u8 *p;
    s32 *node;
    s32 len;
    u32 n;
    u32 cnt;
    u32 i;
    u32 j;

    p = arg0 + *(s32 *)(arg0 + 4);
    while (1) {
        if (*(s32 *)p == -1) {
            break;
        }
        p += 4;
        len = *(s32 *)p;
        p += 4;
        p += len;
    }
    node = func_8005EAB4(8, 0, 1);
    node[1] = (s32)D_800DAD9C;
    node[0] = (s32)arg1;
    D_800DAD9C = node;
    n = *(u32 *)arg1;
    arg1 += 4;
    i = 0;
    while (1) {
        if (!(i < n)) {
            break;
        }
        arg1 += 8;
        cnt = *(u32 *)arg1;
        arg1 += 4;
        j = 0;
        while (1) {
            if (!(j < cnt)) {
                break;
            }
            j++;
            arg1 += 8;
        }
        i++;
    }
}
