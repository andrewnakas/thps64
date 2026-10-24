/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 quot;
    s32 rem;
} Div_8009F1D0;

Div_8009F1D0 func_8009F1D0(s32 num, s32 denom) {
    Div_8009F1D0 r;

    r.quot = num / denom;
    r.rem = num % denom;
    return r;
}
