/* cflags: -O2 */
#include "common.h"

typedef struct Voice800AB78C Voice800AB78C;
typedef u8 *(*Op800AB78C)(Voice800AB78C *, u8 *);

struct Voice800AB78C {
    u8 pad0[4];
    u8 *cur;
    u8 pad8[4];
    s32 time;
    u8 pad10[0x34 - 0x10];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 id;
    u8 pad48[0x74 - 0x48];
    s32 owner;
    u8 pad78[0x9A - 0x78];
    u16 delta;
    u8 pad9C[0xAA - 0x9C];
    u16 unkAA;
    u16 fixed;
    u8 padAE[0xB7 - 0xAE];
    u8 reread;
    u8 padB8[0xBB - 0xB8];
    u8 note;
    u8 padBC[0xD2 - 0xBC];
    u8 running;
    u8 lastNote;
    u8 padD4[0x130 - 0xD4];
};

extern void func_800AC338(s32);
extern void func_800AD65C(Voice800AB78C *);
extern void func_800AD718(Voice800AB78C *);
extern s32 func_800AE1A0(void);
extern Op800AB78C D_800ECB44[];
extern s32 D_800FC2F0;
extern Voice800AB78C *D_800FC2F8;

s32 func_800AB78C(s32 arg0, s32 arg1) {
    Voice800AB78C *v;
    s32 i;
    s32 id;
    u8 *p;
    u8 *q;
    u8 c;
    s32 d;

    id = func_800AE1A0();
    i = 0;
    v = D_800FC2F8;
    for (; i < D_800FC2F0; i++, v++) {
        if (v->id != id || v->owner != arg0 || v->cur == NULL) {
            continue;
        }
    loop:
        {
            p = v->cur;
            if ((s8)p[0] < 0) {
                if (p[0] == 0xAB && p[1] == arg1) {
                    goto done;
                }
                v->cur = D_800ECB44[p[0] & 0x7F](v, p + 1);
            } else {
                v->cur = p + 1;
                if (v->running != 0) {
                    v->note = *v->cur++;
                    if ((s8)v->note < 0) {
                        v->note &= 0x7F;
                        v->running = 0;
                        v->lastNote = v->note;
                    }
                } else {
                    v->note = v->lastNote;
                }
                if (v->fixed == 0 || v->reread != 0) {
                    v->reread = 0;
                    c = *v->cur++;
                    if ((s8)c >= 0) {
                        v->delta = c;
                    } else {
                        v->delta = *v->cur++ + ((c & 0x7F) << 8);
                    }
                } else {
                    v->delta = v->fixed;
                }
                v->time += v->delta << 8;
            }
        }
        if (v->cur != NULL) {
            goto loop;
        }
    done:
        v->unk3C = v->time;
        if (v->cur != NULL) {
            u8 *r = v->cur;
            u8 *n;

            d = r[2];
            n = r + 3;
            if (d >= 0x80) {
                d &= 0x7F;
                d <<= 8;
                d |= r[3];
                n = r + 4;
            }
            q = n;
            v->delta = d;
            v->unkAA = 0;
            v->cur = q;
            v->time -= d << 8;
        }
        v->unk40 = v->time;
        if (v->unk38 != 0) {
            func_800AD65C(v);
        }
        if (v->unk34 != 0) {
            func_800AD718(v);
        }
    }
    func_800AC338(id);
    return id;
}
