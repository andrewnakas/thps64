/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} Ent800BAC04;

typedef struct {
    Ent800BAC04 *unk0;
    u8 pad4[0x4];
    s32 unk8;
} Obj800BAC04;

extern void func_800B81F0(s32, s32);
extern void func_800BC0F4(void *);
extern u8 D_800F0DD0[];

void func_800BAC04(Obj800BAC04 *arg0, s32 arg1) {
    Ent800BAC04 *e;

    e = &arg0->unk0[arg1];
    if (--e->unk0 == 0) {
        func_800BC0F4(D_800F0DD0);
        if (e->unk4 != 0) {
            func_800B81F0(e->unk4, 3);
        }
        arg0->unk8--;
    }
}
