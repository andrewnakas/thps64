/* cflags: -O2 */
#include "common.h"

typedef struct { s32 a; s32 b; } P800BACE0;

s32 func_800BACE0(P800BACE0 **arg0, s32 arg1) {
    P800BACE0 *p = &(*arg0)[arg1];
    if (p->a != 0) {
        return p->b;
    }
    return 0;
}
