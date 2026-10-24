/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 b[0x100];
} Blk;

void func_800A7760(u8 *arg0, Blk *arg1) {
    *(Blk *)(arg0 + 0x124) = *arg1;
    *(s32 *)(arg0 + 0x20) = 5;

}
