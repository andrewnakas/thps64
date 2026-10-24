/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad[0x1C4];
    void *vt;
    s32 x;
} S800C05D0;

S800C05D0 *func_8009FF00(S800C05D0 *);
extern u8 D_80022190[];

S800C05D0 *func_800C05D0(S800C05D0 *arg0) {
    func_8009FF00(arg0);
    arg0->vt = D_80022190;
    arg0->x = 0;
    return arg0;
}
