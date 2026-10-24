/* Recurring helper macros / static inlines from matched files, gathered so new files stop re-inventing them.
 * Each is copied from the matched file named in its comment (only the name changed where noted); the codegen
 * notes are what made those files match. Include after common.h. Nothing here emits code unless used.
 */
#ifndef HELPERS_H
#define HELPERS_H

/* ---- raw field access by offset (S32 etc. in func_8002B6D0, func_8002C950, func_80030EA4, func_8003CFA0,
 * func_800406F0, func_80044750, func_80031F7C, func_80057EAC, func_8006C7D4). Prefer a struct for new code:
 * GCC 2.8 lets struct fields and globals not alias, casts through u8 * do (scheduling differs). */
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))   /* (same shape, added for completeness) */
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))

/* ---- float -> unsigned. GCC 2.8 makes its own rodata for `(u32)f`; the game's code is this hand-written
 * branch with the 2^31 constant (a literal maps to the game's rodata through match.py). */

/* func_80039D2C (setvol; func_8003A598 is the same with the scale taken from D_800D0FEC):
 * *p = (u32)(x * 127.0f), the goto shape and the 0x80000000 in its own local are needed. */
static __inline__ void f2u_store_u8_x127(u8 *p, f32 x) {
    f32 f = x * 127.0f;
    u32 v;
    u32 m;
    f32 g;
    if (f >= 2147483648.0f) {
        goto big;
    }
    v = (s32)f;
    goto end;
big:
    g = f - 2147483648.0f;
    m = 0x80000000;
    v = (s32)g;
    v |= m;
end:
    *p = v;
}

/* func_800226A0 (f2i): float -> s32 with the out-of-range case giving 0x80000000 */
static inline void f2i_sat(s32 *d, f32 f) {
    s32 v;

    if (f < -2147483648.0f) {
        v = 0x80000000;
    } else if (f > 2147483648.0f) {
        v = 0x80000000;
    } else {
        v = (s32)f;
    }
    *d = v;
}

/* func_80032450 (U2F): u32 -> f32 by hand, 2^32 added when the top bit is set (statement expression) */
#define U2F(u) ({ f64 _d = (s32)(u); if ((s32)(u) < 0) { _d += 4294967296.0; } (f32)_d; })

/* ---- colours: func_8007DFA0 / func_8007E050 (PACK): r in the low byte */
#define PACK_RGB(r, g, b) ((((b) & 0xFF) << 16) | (((g) & 0xFF) << 8) | ((r) & 0xFF))

/* ---- varargs as the game's printf-style functions walk them: func_800AA1E8 / func_800AA354 / func_800AA4A0 */
typedef char *va_list;
#define va_start(ap, last) (ap = (char *)&last + sizeof(last))
#define va_arg(ap, T) (((T *)(ap = (char *)((((s32)ap + 4 - 1) & -4) + 4)))[-1])
#define va_end(ap)

/* ---- message-queue lock pair: func_8009F080 / func_8009F0EC / func_8009EAE0 / func_8009E524 (lockXXXX /
 * unlockXXXX): func_80005070(q, 0, 1) to take, func_80004ED0(q, 0, 1) to give back (both blocking).
 * Opt-in (it declares those two functions): #define HELPERS_MQLOCK before including. */
#ifdef HELPERS_MQLOCK
typedef struct {
    s32 h;
} MqLock;

void func_80004ED0(s32, s32, s32);
void func_80005070(s32, s32, s32);

static __inline__ void mq_lock(MqLock *l, s32 h) {
    l->h = h;
    func_80005070(h, 0, 1);
}

static __inline__ void mq_unlock(MqLock *l) {
    func_80004ED0(l->h, 0, 1);
}
#endif

#endif
