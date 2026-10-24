/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: documentation only, never a match: uses GCC inline asm (gte_ctc2_tr*, cpu_get_fp) for the three
 * PSX GTE control writes (ctc2 $zero -> $5/$6/$7) and for one read of the caller's $fp, which src/funcs does not
 * allow. Structural ratio 0.427 (immediates masked): frame 0x80 vs 0x90 (the game spills &sp30/&sp40), s-reg
 * assignment differs throughout (fp is reused here after copying the caller's value to s5). */
/* Builds PSX-style POLY_FT4 text quads (0x28 bytes, tag 0x09000000) from the 0x20-byte text entries in
 * D_800DCC20 (list ends at the first entry whose word 0 is non-zero) and links them into an ordering table.
 * PSX leftovers: func_800434BC is the port's "SetRotMatrix" (copies the camera matrix to D_800D4918), but the
 * translation is still cleared with three real ctc2 writes to GTE control regs 5-7 (TRX/TRY/TRZ), which on the
 * VR4300 only hit the COP2 latch. For 3D entries (byte 0x10 set) the PSX code projected the position with the
 * GTE and read the screen XY (SXY2) into a variable; in the port that GTE read is gone and the variable is never
 * assigned, so the game uses whatever the caller left in $fp (callee-saved, never written here): x = fp & 0xFFFF,
 * y = fp >> 16. cpu_get_fp() reproduces that by reading $fp once on entry (nothing in this function or its callees
 * changes $fp, so that is the value at every use in the game). The stack copy `unused` (sp+0x20) is never read. */
#include "common.h"

typedef struct {
    u32 tag;     /* 0x00: OT link (low 24 bits) | length in the top byte */
    s32 rgbc;    /* 0x04: colour + code */
    s16 x0, y0;  /* 0x08 */
    u32 uv0;     /* 0x0C: u0 v0 clut */
    s16 x1, y1;  /* 0x10 */
    u32 uv1;     /* 0x14: u1 v1 tpage */
    s16 x2, y2;  /* 0x18 */
    u32 uv2;     /* 0x1C */
    s16 x3, y3;  /* 0x20 */
    u16 uv3;     /* 0x24 */
    u16 pad26;
} PolyFT4_8006F574;

typedef struct {
    s32 x, y, z;
} V3i8006F574;

typedef struct {
    s32 end;      /* 0x00: non-zero ends the list */
    u16 x;        /* 0x04 */
    u16 y;        /* 0x06 */
    u8 *text;     /* 0x08 */
    s32 rgbc;     /* 0x0C */
    u8 is3d;      /* 0x10 */
    u8 narrow;    /* 0x11 */
    u8 pad12[2];
    V3i8006F574 pos; /* 0x14 */
} TextEnt8006F574;

typedef struct {
    u8 pad0[2];
    u8 width;     /* 0x02 */
    u8 pad3;
    u8 *uv;       /* 0x04: 0x0C bytes copied to uv0/uv1/uv2 + uv3 */
} Glyph8006F574;

extern s32 D_800DE148;
extern u8 D_800DE218[]; /* 0xA4-byte camera entries: matrix at +0, position at -0x70 */
extern TextEnt8006F574 D_800DCC20[];
extern u8 D_800DD8A0[];  /* character -> glyph index, 0xFF = space */
extern Glyph8006F574 *D_800DDA20;
extern u8 *D_800D0FA8;   /* primitive buffer cursor */
extern u8 *D_800DE9A4;   /* primitive buffer end */
extern u8 *D_800D0F9C;   /* ordering table */
extern u8 *D_800D8434;   /* +8: near z, +0xA: far z (u16) */
void func_800434BC(u8 *);
V3i8006F574 func_80046FBC(V3i8006F574 *, V3i8006F574 *);
V3i8006F574 func_80046DAC(V3i8006F574 *, s32 *);
void func_80043244(s32 *);

/* GTE control register 5: TRX (translation vector X) */
static inline void gte_ctc2_trx(s32 v) {
    __asm__ volatile("ctc2 %z0, $5" : : "dJ"(v));
}

/* GTE control register 6: TRY (translation vector Y) */
static inline void gte_ctc2_try(s32 v) {
    __asm__ volatile("ctc2 %z0, $6" : : "dJ"(v));
}

/* GTE control register 7: TRZ (translation vector Z) */
static inline void gte_ctc2_trz(s32 v) {
    __asm__ volatile("ctc2 %z0, $7" : : "dJ"(v));
}

/* The caller's $30 (fp/s8), standing in for the never-assigned screen-XY variable. */
static inline u32 cpu_get_fp(void) {
    u32 v;
    __asm__ volatile("move %0, $30" : "=r"(v));
    return v;
}

void func_8006F574(void) {
    u32 sxy;
    V3i8006F574 cam;
    V3i8006F574 rel;
    V3i8006F574 sh;
    V3i8006F574 unused;
    s32 shift;
    s32 z;
    u8 *cpos;
    TextEnt8006F574 *e;
    u8 *s;
    s32 rgbc;
    s32 x;
    s32 y;
    s32 y5;
    s32 y2;
    u32 c;
    u32 g;
    Glyph8006F574 *gl;
    u8 *uv;
    s32 w;
    s32 hgt;
    s32 b14;
    PolyFT4_8006F574 *p;
    u8 *ot;
    s32 xr;
    s32 yb;

    sxy = cpu_get_fp();
    func_800434BC(D_800DE218 + D_800DE148 * 0xA4);
    gte_ctc2_trx(0);
    gte_ctc2_try(0);
    gte_ctc2_trz(0);
    cpos = D_800DE218 - 0x74 + D_800DE148 * 0xA4;
    cam.x = *(s32 *)(cpos + 4) << 12;
    cam.y = *(s32 *)(cpos + 8) << 12;
    cam.z = *(s32 *)(cpos + 0xC) << 12;

    for (e = D_800DCC20; e->end == 0; e++) {
        s = e->text;
        if (e->is3d) {
            rel = func_80046FBC(&e->pos, &cam);
            shift = 12;
            sh = func_80046DAC(&rel, &shift);
            unused = sh;
            rgbc = e->rgbc;
            func_80043244(&z);
            if (z < *(u16 *)(D_800D8434 + 8) || *(u16 *)(D_800D8434 + 0xA) < z) {
                continue;
            }
            x = sxy & 0xFFFF;
            y = sxy >> 16;
        } else {
            x = e->x;
            y = e->y;
            rgbc = e->rgbc;
        }
        y5 = y + 5;
        y2 = y + 2;
        for (;;) {
            c = *s;
            if (c == 0) {
                break;
            }
            g = D_800DD8A0[c & 0x7F];
            s++;
            if (c == 0x5F) {
                g = D_800DD8A0[0x2D];
            }
            if (g == 0xFF) {
                x += 5;
                continue;
            }
            gl = &D_800DDA20[g];
            uv = gl->uv;
            if (gl->width < 4) {
                x++;
            }
            p = (PolyFT4_8006F574 *)D_800D0FA8;
            if (D_800DE9A4 < (u8 *)(p + 1)) {
                return;
            }
            D_800D0FA8 = (u8 *)(p + 1);
            p->tag = 0x09000000;
            p->rgbc = rgbc;
            p->uv0 = *(u32 *)(uv + 0);
            p->uv1 = *(u32 *)(uv + 4);
            p->uv2 = *(u32 *)(uv + 8);
            p->uv3 = *(u16 *)(uv + 0xA);
            b14 = ((u8 *)p)[0x14];
            w = b14 - ((u8 *)p)[0xC];
            hgt = ((u8 *)p)[0x1D] - ((u8 *)p)[0xD];
            if (e->narrow) {
                w = (w * 55) >> 5;
                hgt = (hgt * 55) >> 5;
                ((u8 *)p)[0x14] = b14 - 1;
                ((u8 *)p)[0x24]--;
                ((u8 *)p)[0x1D]--;
                ((u8 *)p)[0x25]--;
            }
            p->x0 = x;
            if (g == 0x1E) {
                if (c == 0x5F) {
                    p->y0 = y5;
                    xr = x + w;
                    p->x1 = xr;
                    p->y1 = y5;
                    p->x2 = x;
                    yb = y + (hgt + 5);
                } else {
                    p->y0 = y2;
                    xr = x + w;
                    p->x1 = xr;
                    p->y1 = y2;
                    p->x2 = x;
                    yb = y + (hgt + 2);
                }
            } else {
                p->y0 = y;
                xr = x + w;
                p->x1 = xr;
                p->y1 = y;
                p->x2 = x;
                yb = y + hgt;
            }
            p->y2 = yb;
            p->x3 = xr;
            p->y3 = yb;
            if (e->is3d) {
                ot = D_800D0F9C + (z & 0x3FFC);
                p->tag = ((*(u32 *)(ot + 0x8C) >> 8) << 8) | ((u8 *)p)[3];
                *(u32 *)(ot + 0x8C) = ((u32)p << 8) | ot[0x8F];
            } else {
                ot = D_800D0F9C;
                p->tag = ((*(u32 *)(ot + 0x84) >> 8) << 8) | ((u8 *)p)[3];
                *(u32 *)(ot + 0x84) = ((u32)p << 8) | ot[0x87];
            }
            x = x + 3 + w;
            if (w < 4) {
                x++;
            }
        }
    }
}
