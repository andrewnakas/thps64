/* cflags: -O2 */
#include "common.h"

extern void func_800A059C(u8 *);
extern void func_800A05D8(u8 *);
extern void func_800A180C(u8 *, s32);
extern void func_800A1B1C(u8 *);
extern void func_800A1DE4(u8 *);

void func_800A177C(u8 *arg0) {
    func_800A059C(arg0);
    switch (*(s32 *)(arg0 + 0xC)) {
    case 30:
        func_800A180C(arg0, 1);
        break;
    case 31:
        func_800A1B1C(arg0);
        break;
    case 32:
        func_800A1DE4(arg0);
        break;
    }
    func_800A05D8(arg0);

}
