#include "common.h"

extern u8 D_800D0FC0[];
extern u8 D_800D1E90[];
extern u8 D_80016DC0[];
extern u8 D_800D2090[];
extern u8 D_800D22D0[];
extern u8 D_800D2510[];
void func_8009BCE0(void *);
void func_800B3950(void *);
void func_800A72C0(void *);

void func_800243A8(void) {
    u8 *p;
    u8 *q;

    p = D_800D0FC0;
    func_8009BCE0(p + 0x40);
    q = D_800D1E90;
    func_800B3950(q);
    *(void **)(q + 0x1C4) = D_80016DC0;
    func_800A72C0(D_800D2090);
    func_800A72C0(D_800D22D0);
    func_800A72C0(D_800D2510);
}
