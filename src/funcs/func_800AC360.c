/* cflags: -O2 */
#include "common.h"

typedef struct { s8 type; s32 val; } M800AC360;
void func_800AC6D4(M800AC360 *);
extern s32 D_800FC320;

void func_800AC360(s32 arg0) {
    M800AC360 m;

    m.type = 2;
    m.val = arg0;
    D_800FC320 = arg0;
    func_800AC6D4(&m);
}
