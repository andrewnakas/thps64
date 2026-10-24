/* cflags: -O2 */
#include "common.h"

extern void func_8000CB00(void *);
extern void func_8000CB30(void *, void *);
extern u8 *D_800ECC34;

void func_800B02AC(void *a0) {
    func_8000CB00(a0);
    func_8000CB30(a0, D_800ECC34 + 0x20);
}
