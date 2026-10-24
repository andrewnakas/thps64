/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 frame;
    u8 pad8[0x48];
    s32 unk50;
    u8 pad54[0x18];
    s32 state;
    f32 t70;
    f32 t74;
    s32 buf[200];
    u8 pad398;
    u8 idx;
    u8 pad39A[2];
    f32 chance;
    u16 sfx[0x48];
    u8 pad430[0x100];
    u8 nsfx;
    u8 pad531;
    u8 cur;
    u8 pad533[0x1C21];
    s32 unk2154;
    s32 fade;
    f32 ftime;
    f32 vol;
    f32 step;
    s32 unk2168;
} Snd_800A9D98;

f32 func_8009F274(void);
s32 func_800A9220(Snd_800A9D98 *, s32, f32);
void func_800AA0F4(Snd_800A9D98 *);
void func_800AA1E8(Snd_800A9D98 *, s32, ...);
void func_800AA914(Snd_800A9D98 *);
void func_800ABE14(s32, s32);
void func_800ABFC4(s32, u8);
extern f32 D_800F5668;

void func_800A9D98(Snd_800A9D98 *s) {
    f32 f;
    u32 v;
    u8 t;

    s->frame++;
    if (s->fade == 0 && s->state == 0 && s->nsfx == 0 && s->unk2154 == 0) {
        return;
    }
    if (s->nsfx != 0 && s->chance > 0.0f && func_8009F274() <= s->chance) {
        func_800AA1E8(s, 1, s->sfx[s->cur]);
        t = s->cur + 1;
        s->cur = t;
        s->cur = t % s->nsfx;
    }
    if (s->fade == 1) {
        s->ftime -= D_800F5668;
        if (s->ftime > 0.0f) {
            f = s->vol - s->step;
            s->vol = f;
            if (f >= 2147483648.0f) {
                goto big1;
            }
            v = (s32)f;
            goto end1;
        big1:
            v = (s32)(f - 2147483648.0f);
            v |= 0x80000000;
        end1:
            func_800ABFC4(s->unk50, v);
        } else {
            func_800ABE14(s->unk50, 0);
            s->fade = 0;
        }
    }
    if (s->fade == 2) {
        s->ftime -= D_800F5668;
        if (s->ftime > 0.0) {
            f = s->vol - s->step;
            s->vol = f;
            if (f >= 2147483648.0f) {
                goto big2;
            }
            v = (s32)f;
            goto end2;
        big2:
            v = (s32)(f - 2147483648.0f);
            v |= 0x80000000;
        end2:
            func_800ABFC4(s->unk50, v);
        } else {
            func_800A9220(s, s->unk2168, 0.0f);
            s->fade = 0;
        }
    }
    if (s->state == 3) {
        s->t74 -= D_800F5668;
        if (s->t74 <= 0.0f) {
            s->state = 0;
            s->buf[s->idx] = -1;
            s->idx = (u8)(s->idx + 1) % 200;
            func_800AA0F4(s);
        }
    }
    if (s->state == 4) {
        s->t70 -= D_800F5668;
        if (s->t70 <= 0.0) {
            s->state = 0;
            s->buf[s->idx] = -1;
            s->idx = (u8)(s->idx + 1) % 200;
            func_800AA0F4(s);
        }
    }
    if (s->unk2154 != 0) {
        func_800AA914(s);
    }
}
