/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u16 unk0;
    u8 pad2[0x1C];
    s8 unk1E;
    u8 pad1F;
} Frame;

typedef struct Anim {
    u8 pad0[4];
    u16 unk4;
    u16 unk6;
    u8 pad8[8];
    Frame *unk10;
    struct Anim *unk14;
    struct Anim *unk18;
} Anim;

void func_8005EA48(Anim *, u32);
extern Anim *D_800DCAA0;

void func_8006D4B0(void) {
    s32 step;
    u32 t;
    Frame *f;
    Anim *p;
    Anim *next;

    p = D_800DCAA0;
    next = NULL;
    if (p != NULL) {
        next = p->unk14;
    }
    while (1) {
        if (p == NULL) {
            break;
        }
        f = p->unk10;
        t = p->unk4;
        if (t >= f->unk0) {
            step = f->unk1E;
            if (step == 0) {
                if (p->unk14 != NULL) {
                    p->unk14->unk18 = p->unk18;
                }
                if (p->unk18 != NULL) {
                    p->unk18->unk14 = p->unk14;
                }
                if (p == D_800DCAA0) {
                    D_800DCAA0 = p->unk14;
                }
                func_8005EA48(p, t);
            } else if (step != 0x7F) {
                p->unk10 = f + step;
                p->unk4 = 0;
                p->unk6++;
            }
        } else {
            p->unk4 = t + 1;
            p->unk6++;
        }
        p = next;
        if (next == NULL) {
            break;
        }
        next = next->unk14;
    }
}
