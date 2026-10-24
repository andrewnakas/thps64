/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
/* NON_MATCHING: aln 0.873. Equivalent C; the D_800DCC1E branch masks v only in the call arm (game: andi in the beqz slot for both arms, same 16 bits stored), plus mflo/div temp registers in the lerps. */
/* Z3 251/274 (from G15 235): `do { } while (0);` around the first D_800DCAAC store and around the k = ... % 20
   statement (loop-note trick) fixes the s-reg order of the hoisted values and the rgb_set block. Left: the
   D_800DCC1E branch (game masks v with andi in the beqz slot and both arms use the masked value; ours masks only in
   the call arm), and mflo/div temp registers (v0 vs v1/t0) in the lerps. G15 notes below. */
/* G15 near-miss 235/274 (from C4's 223). Fixed: lerps written `(b - a) * t / dur + a` (game loads the 2nd field
 * first); all 5 loop invariants now hoisted like the game (loop.c: a constant is moved only if threshold*savings*
 * life >= loop insns; 100 and 0x100 get the needed life as parameters of static inlines: rgb_set(k, 100, 100) and
 * draw_(x, y, img, 0x100, frame)); D_800DCAAC volatile keeps the game's second (else-arm) store. Left: s-reg order
 * of the hoisted values (game s5=%hi(D_800DCAAC), s6=100, s7=0x2C000000; ours s7/s5/s6), the else-arm store uses the
 * unmasked sum (game: andi a0 in the beqz slot, masked a0 for both call and store), mflo/div register choices. */
#include "common.h"

typedef struct {
    u16 dur;
    u8 b2;
    u8 b3;
    u16 a4;
    u16 a6;
    u8 r0, g0, b0;
    u8 r1, g1, b1;
    u16 hE;
    u16 h10;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    u8 b1A;
    u8 pad1B;
    u16 h1C;
} Anim6D5B0;

typedef struct Node6D5B0 {
    void *p0;
    u16 t;
    u8 pad6[2];
    s16 x;
    s16 y;
    s32 vC;
    Anim6D5B0 *anim;
    struct Node6D5B0 *next;
} Node6D5B0;

typedef struct {
    u8 r, g, b;
} Rgb6D5B0;

void func_8006DF40(s32, s32, void *, s32, s32, s32, s32);
void func_8006EA0C(s32);
extern u32 D_800D613C;
extern Node6D5B0 *D_800DCAA0;
extern u8 D_800DCAA4;
extern u32 D_800DCAA8;
extern volatile u16 D_800DCAAC;
extern u8 D_800DCC1E;
extern Rgb6D5B0 D_800FBB90;

static inline void rgb_set(u8 r, u8 g, u8 b) {
    D_800FBB90.r = r;
    D_800FBB90.g = g;
    D_800FBB90.b = b;
}

static inline void draw_(s32 x, s32 y, void *img, s32 sc, s32 frame) {
    func_8006DF40(x, y, img, frame, 0, sc, 1);
}

void func_8006D5B0(void) {
    Node6D5B0 *n;
    Anim6D5B0 *a;
    s32 cnt;
    s32 off;
    u16 dur;
    u16 v;
    u8 r, g, b;
    u32 c;
    s32 k;
    s32 x, y;

    cnt = 0;
    for (n = D_800DCAA0; n != NULL; n = n->next) {
        if (n->vC != 0) {
            cnt++;
        }
    }
    off = (cnt - 1) << 4;
    n = D_800DCAA0;
    while (1) {
        if (n == NULL) {
            break;
        }
        a = n->anim;
        if (a->b1A == 0 || ((n->t / a->b1A) & 1)) {
            dur = a->dur;
            D_800DCAA4 = a->b3;
            v = (a->a6 - a->a4) * n->t / dur + a->a4;
            do { D_800DCAAC = v; } while (0);
            if (D_800DCC1E) {
                func_8006EA0C(v);
            } else {
                D_800DCAAC = v;
            }
            r = (a->r1 - a->r0) * n->t / dur + a->r0;
            g = (a->g1 - a->g0) * n->t / dur + a->g0;
            b = (a->b1 - a->b0) * n->t / dur + a->b0;
            c = (b << 16) | (g << 8) | r;
            D_800DCAA8 = c;
            if (a->b2) {
                D_800DCAA8 = c | 0x2E000000;
            } else {
                D_800DCAA8 = c | 0x2C000000;
            }
            if (a->h1C) {
                do { k = (D_800D613C % 20) * 12; } while (0);
                rgb_set(k, 100, 100);
                c = (100 << 16) | (100 << 8) | (u8)k;
                D_800DCAA8 = c | 0x2C000000;
            }
            x = a->x0 + (a->x1 - a->x0) * n->t / dur + n->x;
            y = a->y0 + (a->y1 - a->y0) * n->t / dur + n->y;
            if (n->vC) {
                y += off;
                off -= 0x20;
            }
            draw_(x, y, n->p0, 0x100, a->hE + (a->h10 - a->hE) * n->t / dur);
        }
        n = n->next;
    }
}
