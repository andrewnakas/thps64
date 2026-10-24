/* cflags: -O2 */
#include "common.h"

typedef struct { u8 b; s32 v; } Arg800AC6D4;
extern void func_800AC6D4(Arg800AC6D4 *);

void func_800AC338(s32 a0) {
    Arg800AC6D4 s;
    s.b = 1;
    s.v = a0;
    func_800AC6D4(&s);
}
