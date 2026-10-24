/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    s32 unk10;
} Seg;

void func_80003520(s32, Seg *);
Seg *func_800BBE4C(void);

void func_800BBDE0(s32 arg0) {
    Seg *s = func_800BBE4C();
    s32 a;

    if (s == NULL) {
        a = arg0;
    } else {
        if ((arg0 & 0xFF000000) == 0xFF000000) {
            arg0 &= 0xFFFFFF;
            arg0 += 0x140000;
        }
        a = s->unk10;
        a += arg0;
        a -= s->unkC;
    }
    func_80003520(a, s);
}
