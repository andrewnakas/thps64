/* cflags: -O2 */
#include "common.h"

extern u8 D_800ECEF4[];
extern void func_800B260C(void *);

void func_800B27FC(void) {
    func_800B260C(D_800ECEF4);
}
