/* cflags: -O2 */
#include "common.h"

extern void func_800A059C(s32 *);
extern void func_800A05D8(s32 *);
extern void func_800A1244(s32 *);
extern void func_800A1334(s32 *);
extern void func_800A13F4(s32 *);
extern void func_800A15C8(s32 *);

void func_800A119C(s32 *arg0) {
    func_800A059C(arg0);
    switch (*arg0) {
    case 10:
        func_800A1244(arg0);
        break;
    case 11:
        func_800A15C8(arg0);
        break;
    case 12:
        func_800A1334(arg0);
        break;
    case 13:
        func_800A13F4(arg0);
        break;
    }
    func_800A05D8(arg0);
}
