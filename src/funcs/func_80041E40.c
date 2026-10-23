#include "common.h"

void func_80040C60(void *);
void func_80040EAC(void *);
void func_800411EC(void *);
extern s32 D_800DE7A0;

void func_80041E40(void *arg0) {
    switch (D_800DE7A0) {
    case 1:
        func_80040C60(arg0);
    case 3:
        func_80040EAC(arg0);
        func_800411EC(arg0);
        break;
    case 2:
    case 5:
    case 7:
    case 8:
        func_80040EAC(arg0);
        break;
    }
}
