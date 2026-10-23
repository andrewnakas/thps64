/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 id;
    u8 pad4[0xC];
    u8 unk10;
    u8 pad11[0x33];
} Slot80039F88;

typedef struct {
    s32 unk0;
    Slot80039F88 s[3];
} Slots80039F88;

typedef struct {
    s32 unk0;
    s32 unk4;
} Ent80039F88;

extern void func_800A9588(void *, s32);
extern void func_800AA8C8(void *, void *);
extern Slots80039F88 D_800D3F34;
extern Ent80039F88 D_800D4040[];
extern u8 D_800D45B8[];
extern u8 D_800EA9C0[];

void func_80039F88(s32 idx) {
    s32 id;
    Slots80039F88 *b;
    u8 k;
    Slot80039F88 *p0;
    Slot80039F88 *p;
    u8 *q0;
    u8 *q1;
    u8 *q2;

    id = D_800D45B8[idx];
    if (id != 0xFF) {
        if (D_800D4040[idx].unk0 < 0) {
            b = &D_800D3F34;
            k = D_800D45B8[idx];
            p0 = &b->s[0];
            if (k == b->s[0].id) {
                b->s[0].unk10 = 0;
                q0 = D_800EA9C0;
                func_800A9588(q0, k);
                func_800AA8C8(q0, p0);
            } else {
                p = &b->s[1];
                if (k == b->s[1].id) {
                    b->s[1].unk10 = 0;
                    q1 = D_800EA9C0;
                    func_800AA8C8(q1, p);
                    func_800A9588(q1, b->s[1].id);
                } else {
                    p = &b->s[2];
                    if (k == b->s[2].id) {
                        b->s[2].unk10 = 0;
                        q2 = D_800EA9C0;
                        func_800AA8C8(q2, p);
                        func_800A9588(q2, b->s[2].id);
                    }
                }
            }
        }
        func_800A9588(D_800EA9C0, id);
    }
}
