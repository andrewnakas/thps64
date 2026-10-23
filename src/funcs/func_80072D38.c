#include "common.h"

typedef struct State80072D38 {
    u16 unk0;
    u8 pad2[0x50];
    u16 unk52;
} State80072D38;

s32 func_8004AEE0(void *);
void func_80072CE8(void *);

void func_80072D38(State80072D38 *arg0) {
    if (func_8004AEE0(arg0) == 0) {
        func_80072CE8(arg0);
        arg0->unk52 = (u16) (arg0->unk52 | 0x40);
        arg0->unk0 = (u16) (arg0->unk0 | 1);
    }
}
