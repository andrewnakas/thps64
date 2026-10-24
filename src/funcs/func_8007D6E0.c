#include "common.h"

typedef struct { s16 a, b, c; } Vec3s;
extern Vec3s D_800DE56C;

void func_8007D6E0(Vec3s *a0) {
    D_800DE56C = *a0;
}
