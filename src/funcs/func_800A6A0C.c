/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x8];
} Ent800A6A0C;

typedef struct {
    Ent800A6A0C *unk0;
    u8 unk4;
} Obj800A6A0C;

extern void func_8009ECF8(void *, void *);
extern void func_800B4888(void *, s32);
extern u8 D_800EA110[];
extern u8 D_800ECFE0[];

void func_800A6A0C(Obj800A6A0C *arg0) {
    s32 i;

    if (arg0->unk4 != 0) {
        i = 0;
        while (1) {
            if (i >= arg0->unk4) break;
            {
                Ent800A6A0C *e = &arg0->unk0[i];
                if (e->unk0 != -1) {
                    func_800B4888(D_800ECFE0, e->unk0);
                }
            }
            i++;
        }
        func_8009ECF8(D_800EA110, arg0->unk0);
        arg0->unk0 = NULL;
        arg0->unk4 = 0;
    }
}
