#include "common.h"

extern char D_8001CB18[];
extern u8 D_800D6180[];
void func_8004B264(void *, void *);
void func_80039F88(void *);
void func_80072D84(void *, s32);
void func_8004B4F8(void *);

void func_80065AB8(void *arg0, s32 arg1) {
    *(char **)((u8 *)arg0 + 0x48) = D_8001CB18;
    func_8004B264(arg0, D_800D6180);
    if (*(void **)((u8 *)arg0 + 0x33C) != NULL) {
        func_80039F88(*(void **)((u8 *)arg0 + 0x33C));
        *(void **)((u8 *)arg0 + 0x33C) = NULL;
    }
    func_80072D84(arg0, 0);
    if (arg1 & 1) {
        func_8004B4F8(arg0);
    }
}
