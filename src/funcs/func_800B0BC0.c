/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Acmd;

typedef struct {
    s32 a;
    s32 b;
    s16 g0;
    s16 g1;
    s16 g2;
    u8 padE[0x12];
    s32 unk20;
    s32 unk24;
} Tap_800B0BC0;

typedef struct {
    u8 pad0[0x14];
    s32 base;
    s32 cur;
    s32 len;
    Tap_800B0BC0 *taps;
    u8 ntaps;
} Rev_800B0BC0;

Acmd *func_800B0600(void);
Acmd *func_800B10AC(Rev_800B0BC0 *, Tap_800B0BC0 *, s16, Acmd *);
Acmd *func_800B12A0(Rev_800B0BC0 *, s32, s16, s32, Acmd *);
Acmd *func_800B13C8(Rev_800B0BC0 *, s32, s16, Acmd *);
Acmd *func_800B14E0(s32, s16, Acmd *);
extern u8 *D_800ECC34;

Acmd *func_800B0BC0(void) {
    Rev_800B0BC0 *r;
    Acmd *cmd;
    Tap_800B0BC0 *t;
    s16 in;
    s16 out;
    s16 tmp;
    s16 i;
    s32 last;
    s32 p0;
    s32 p1;
    s32 end;
    s32 wrap;
    s16 buf;

    buf = 0x930;
    in = 0;
    out = 0x170;
    i = 0;
    r = *(Rev_800B0BC0 **)(*(u8 **)(D_800ECC34 + 0x48) + 0x20);
    last = 0;
    cmd = func_800B0600();
    { Acmd *_a = cmd++; _a->w0 = 0x0C00DA83; _a->w1 = 0x07C007C0; }
    { Acmd *_a = cmd++; _a->w0 = 0x0C005A82; _a->w1 = 0x093007C0; }
    cmd = func_800B13C8(r, r->cur, 0x7C0, cmd);
    { Acmd *_a = cmd++; _a->w0 = 0x02000930; _a->w1 = 0x170; }
    for (i = 0; i < r->ntaps; i++) {
        t = &r->taps[i];
        p0 = r->cur - t->a * 2;
        p1 = r->cur - t->b * 2;
        if (p0 == last) {
            tmp = out;
            out = in;
            in = tmp;
        } else {
            cmd = func_800B12A0(r, p0, in, 0xB8, cmd);
        }
        cmd = func_800B10AC(r, t, out, cmd);
        if (t->g0 != 0) {
            { Acmd *_a = cmd++; _a->w0 = (u16)t->g0 | 0x0C000000; _a->w1 = (in << 16) | ((u32)out & 0xFFFF); }
            if (t->unk24 == 0 && t->unk20 == 0) {
                cmd = func_800B13C8(r, p1, out, cmd);
            }
        }
        if (t->g1 != 0) {
            cmd->w0 = (u16)t->g1 | 0x0C000000;
            cmd->w1 = (out << 16) | ((u32)in & 0xFFFF);
            cmd = func_800B13C8(r, p0, in, cmd + 1);
        }
        if (t->unk20 != 0) {
            cmd = func_800B14E0(t->unk20, out, cmd);
        }
        if (t->unk24 == 0) {
            cmd = func_800B13C8(r, p1, out, cmd);
        }
        if (t->g2 != 0) {
            { Acmd *_a = cmd++; _a->w0 = (u16)t->g2 | 0x0C000000; _a->w1 = (out << 16) | buf; }
        }
        last = r->cur + t->b * 2;
    }
    end = r->cur + 0x170;
    wrap = r->len * 2;
    r->cur = end;
    if ((u32)(r->base + wrap) < (u32)end) {
        r->cur = end - wrap;
    }
    { Acmd *_a = cmd++; _a->w0 = 0x0A000000 | ((u32)buf & 0xFFFFFF); _a->w1 = 0x07C00170; }
    return cmd;
}
