/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 *unk0;
    s32 unk4;
} Obj800B5A4C;

extern void func_8009ECF8(void *, void *);
extern void func_800B6398(Obj800B5A4C *);
extern u8 D_800EA110[];

void func_800B5A4C(Obj800B5A4C *arg0) {
    s32 i;

    func_800B6398(arg0);
    if (arg0->unk0 != NULL) {
        for (i = 0; i < arg0->unk4; i++) {
            func_8009ECF8(D_800EA110, (void *)arg0->unk0[i]);
        }
        func_8009ECF8(D_800EA110, arg0->unk0);
        arg0->unk0 = NULL;
    }
}
