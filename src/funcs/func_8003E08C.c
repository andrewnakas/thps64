#include "common.h"

extern char D_800D4764[];
extern char D_8001A214[];
extern void func_800057E4(char *, char *, ...);

char *func_8003E08C(s32 arg0) {
    char *fmt;
    char *p;

    p = D_800D4764;
    fmt = D_8001A214;
    func_800057E4(p, fmt, arg0);
    return p;
}
