/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* cflags: -fcse-follow-jumps -fcse-skip-blocks */
#include "common.h"

typedef struct {
    u8 a, b, c;
} Ch6984;

typedef struct {
    u8 pad0[8];
    f32 x;
    f32 y;
    f32 sx;
    f32 sy;
    f32 time;
    f32 t0;
    s32 state;
    Ch6984 ch[20];
    s32 n;
    s16 off[20];
    char text[0x608 - 0x8C];
    u8 obj[1];
} Pop6984;

extern f32 D_800F5668;
extern f32 D_800E8E20;
extern f32 D_800E8E24;
extern u8 D_800EA9C0[];
void func_8009E0F0(void *, s32, s32);
u32 func_8009F40C(void);
f32 func_8009F2CC(void);
void func_800A96BC(void *, s32);
u32 func_8000574C(char *);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A773C(void *, f32, f32);
void func_800A8678(void *, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, Ch6984 *, s16 *);

void func_80086984(Pop6984 *o) {
    Ch6984 *cp;
    s16 *op;
    s32 i;
    f32 nx;
    f32 dx;
    u32 r;
    f32 f;
    u32 k;
    s32 nn;

    cp = NULL;
    o->time += D_800F5668;
    op = cp;
    if (o->state == 0) {
        o->sx += 0.0065f;
        o->sy += 0.0065f;
        nx = o->x + (D_800E8E20 - o->x) * D_800F5668;
        dx = nx - o->x;
        o->x = nx;
        o->y = o->y + (D_800E8E24 - o->y) * D_800F5668;
        func_8009E0F0(o->off, 0, 0x28);
        if (o->x > 320.0) {
            return;
        }
        if (o->y > 240.0) {
            return;
        }
        i = 0;
        while (1) {
            if (i >= 20) break;
            r = func_8009F40C() & 0xFF;
            if (r < 0x7F) {
                r += 100;
            }
            o->ch[i].a = r;
            o->ch[i].b = r - 40;
            o->ch[i].c = 0;
            f = func_8009F2CC();
            if (o->ch[i].a > 0x80) {
                o->off[i] = dx * (f * 16.0);
            } else {
                o->off[i] = -(s32)(dx * (f * 16.0));
            }
            i++;
        }
        cp = o->ch;
        op = o->off;
        if (dx < 0.1) {
            o->n = 0;
            o->state = 1;
            o->t0 = o->time;
            func_800A96BC(D_800EA9C0, 0x49);
            for (k = 0; k < func_8000574C(o->text) + 1; k++) {
                o->off[k] = 0;
            }
        }
    } else if (o->state == 1) {
        func_800A7AF8(o->obj, 0xFF, 0xC8, 0, 0xFF);
        if (o->time > o->t0 + 0.1 && o->n < func_8000574C(o->text) + 1) {
            if (o->n - 1 >= 0) {
                o->off[o->n - 1] = 0;
            }
            nn = o->n;
            o->off[nn] -= 5;
            o->n = nn + 1;
            op = o->off;
        } else if (o->time > o->t0 + 4.0) {
            o->sx *= 0.75;
            o->sy *= 0.75;
        }
    }
    if (!(o->sx < 0.01) || o->state != 1) {
        func_800A773C(o->obj, o->sx, o->sy);
        func_800A8678(o->obj, o->text, o->x, o->y, 2, 2, 1.0f, 0xFF, 100, 1, 1, 0, cp, op);
    }
}
