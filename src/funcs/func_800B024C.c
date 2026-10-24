/* cflags: -O2 */
#include "common.h"

extern void func_8000CB00(s32);
extern void func_8000CB30(s32, u8 *);
extern u8 *D_800ECC34;

void func_800B024C(void) {
    s32 p;

    while ((p = *(s32 *)(D_800ECC34 + 0x20)) != 0) {
        func_8000CB00(p);
        func_8000CB30(p, D_800ECC34 + 0x10);
    }
}
