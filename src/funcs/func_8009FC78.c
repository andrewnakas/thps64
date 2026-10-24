#include "common.h"

extern char D_800209B4[];
extern char D_800209B8[];
extern char D_800209BC[];
extern char D_800209C0[];

char *func_8009FC78(s32 arg0) {
    switch (arg0) {
    case 1:
        return D_800209B4;
    case 2:
        return D_800209B8;
    case 3:
        return D_800209BC;
    default:
        return D_800209C0;
    }
}
