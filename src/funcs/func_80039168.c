#include "common.h"

void func_8003912C(void *);

void func_80039168(void *arg0) {
    if (++*(u16 *)((u8 *)arg0 + 0x54) == 0) {
        func_8003912C(arg0);
        ++*(u16 *)((u8 *)arg0 + 0x54);
    }
}
