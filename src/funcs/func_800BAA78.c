/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} Ent800BAA78;

typedef struct {
    Ent800BAA78 *unk0;
    s32 unk4;
} Obj800BAA78;

extern Ent800BAA78 *func_8009E6B4(void *, s32, s32);
extern u8 D_800EA110[];
extern s32 D_800EED04;

void func_800BAA78(Obj800BAA78 *arg0, s32 arg1) {
    s32 i;

    arg0->unk0 = func_8009E6B4(D_800EA110, arg1 * 8, 4);
    for (i = 0; i < arg1; i++) {
        arg0->unk0[i].unk0 = 0;
    }
    arg0->unk4 = arg1;
    D_800EED04 = 1;
}
