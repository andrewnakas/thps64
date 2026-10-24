/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
} Obj800AB9E0;

extern s32 func_800ADF98(Obj800AB9E0 *, s32, s32, s32, s32);
extern s32 D_800FC314;
extern Obj800AB9E0 *D_800FC324;
extern Obj800AB9E0 *D_800FC328;

s32 func_800AB9E0(s32 arg0) {
    Obj800AB9E0 *p;
    s32 r;

    p = D_800FC328;
    if (p != NULL) {
        D_800FC328 = NULL;
    } else {
        p = D_800FC324;
        if (p == NULL) {
            D_800FC314 = 0;
            return 0;
        }
    }
    if (D_800FC314 == 0) {
        D_800FC314 = p->unk10;
    }
    r = func_800ADF98(p, arg0, 0x80, 0x80, -1);
    D_800FC314 = 0;
    return r;
}
