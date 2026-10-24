#include "common.h"

typedef struct { s16 a[3]; } S8007D6B8;
extern S8007D6B8 D_800DE574;

void func_8007D6B8(S8007D6B8 *arg0) {
    D_800DE574 = *arg0;
}
