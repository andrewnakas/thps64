#include "common.h"

void func_8005CDF0(void);
void func_8005DE04(void *);
void func_8005E45C(void *);
void func_8005D2A0(void *);

void func_8004ADC4(u8 *arg0, s32 arg1) {
    if (*(s32 *)(arg0 + 0x280) == 0) {
        func_8005CDF0();
        *(s32 *)(arg0 + 0x288) = arg1;
    }
    func_8005DE04(arg0);
    if (*(u16 *)arg0 & 4) {
        func_8005E45C(arg0);
        func_8005D2A0(arg0);
    }
}
