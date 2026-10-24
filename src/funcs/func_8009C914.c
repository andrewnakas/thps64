/* cflags: -O2 */
#include "common.h"

void func_8009C8EC(f32 (*)[4], f32 (*)[4]);

f32 (*func_8009C914(f32 (*dst)[4], f32 (*a)[4], f32 (*b)[4]))[4] {
    f32 m[4][4];
    s32 i;
    s32 j;

    i = 0;
    while (1) {
        if (i >= 4) {
            break;
        }
        for (j = 0; j < 3; j++) {
            m[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
        }
        i++;
    }
    m[3][0] += b[3][0];
    m[3][1] += b[3][1];
    m[3][2] += b[3][2];
    m[0][3] = m[1][3] = m[2][3] = 0.0f;
    m[3][3] = 1.0f;
    func_8009C8EC(dst, m);
    return dst;
}
