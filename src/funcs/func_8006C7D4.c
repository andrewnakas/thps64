/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

s32 func_80022F6C(s32, s32, s32, s32);
void func_80024B88(void *, s32, s32, s32);
void func_80024B98(void *, s32, s32, s32);
void func_80024BA8(void *);
void func_8004BA74(void *);
void func_8004C14C(void *);
void func_8005BED8(void *);
void func_800654C8(void);
void func_8006A994(s32);
void func_8006AB44(void *, s32, s32, s32);
void func_8006B78C(void *, s32);
void func_80073340(void);
void func_8007D6B8(s16 *);
void func_8007D6E0(s16 *);
void func_800916B0(void *);
void func_8009556C();

typedef struct {
    s16 x50;
    s16 x52;
    s32 x54;
} Seg8006C7D4;

typedef struct {
    s32 x0;
    u8 pad4[0xC];
    s32 *x10;
    s32 x14;
    s32 x18;
    u8 pad1C[4];
    s32 x20;
    u8 pad24[0x4C - 0x24];
    s32 x4C;
    Seg8006C7D4 seg[5];
    u8 pad78[0x84 - 0x78];
    s16 x84;
    s16 x86;
    s16 x88;
} State8006C7D4;

extern u8 *D_800D61A8;
extern s32 D_800DC614;
extern State8006C7D4 D_800DC618;
extern State8006C7D4 D_800DC6D8;
extern s32 D_800DE520;
extern s32 D_800DE524;
extern s32 D_800DE9A8;
extern s32 D_800E8FA8;

#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define ABS(x) ((x) >= 0 ? (x) : -(x))

void func_8006C7D4(u8 *arg0) {
    s16 pos[3];
    s16 rot[3];
    s32 v[3];
    State8006C7D4 *s;
    State8006C7D4 *st;
    s32 near;
    s32 n;
    s32 a;
    s32 b;

    func_80073340();
    if (arg0 == D_800D61A8) {
        s = &D_800DC618;
    } else {
        s = &D_800DC6D8;
    }
    if (D_800E8FA8 == 0x14 || D_800E8FA8 == 0x16 || D_800E8FA8 == 0x15) {
        if (s->x20 == 0) {
            func_8009556C();
            func_8006AB44(arg0, 2, 1, 0x7FFFFFFF);
        }
    }
    if (s->x20 != 0) {
        func_8006B78C(arg0, 1);
        s->x20--;
        near = ABS(func_80022F6C(-S32(arg0, 0x8D8), S32(arg0, 0x84), S32(arg0, 0x8D0), S32(arg0, 0x8C))) < 40000;
        if (S32(arg0, 0x82C) == 4 && (near || *(u16 *)(arg0 + 0x21E) == 0x3A) && D_800DE520 < 200) {
            {
                s32 x = s->x84;
                s32 y = s->x86;
                s32 z = s->x88;
                pos[0] = x;
                pos[1] = y;
                pos[2] = z;
            }
            func_8007D6E0(pos);
            {
                s16 x = 0x1C2;
                s16 y = 0x384;
                rot[0] = x;
                rot[1] = y;
                rot[2] = 0;
            }
            func_8007D6B8(rot);
            D_800DE524 = 0;
            v[2] = 0;
            v[0] = 0;
            v[1] = 0x19000;
            D_800DE524 = 1;
            func_80024BA8(arg0 + 0x22D0);
            func_80024B98(arg0 + 0x22D0, 0xFF, 0xFF, 0);
            func_80024B88(arg0 + 0x22D0, 0xFF, 0, 0);
        }
        if (S32(arg0, 0x82C) != 0 || ABS(S32(arg0, 0x8) - S32(arg0, 0x3DC)) > 0x40) {
            S32(arg0, 0x3DC) = S32(arg0, 0x8);
            func_8005BED8(arg0);
        } else {
            S32(arg0, 0x120) = S32(arg0, 0x4);
            S32(arg0, 0x128) = S32(arg0, 0xC);
        }
        func_8004BA74(arg0);
        func_800654C8();
        func_8004C14C(arg0);
        return;
    }
    n = s->x4C;
    if (n >= 1 && n <= 4) {
        if (s->seg[n].x54 != 0) {
            a = s->seg[n].x50;
            b = s->seg[n].x52;
            if (b != 0x7FFFFFFF) {
                s->x20 = b - a + 1;
            }
            s->x4C++;
            D_800DC614++;
            func_8006A994(a);
            return;
        }
    }
    if (arg0 == D_800D61A8) {
        st = &D_800DC618;
    } else {
        st = &D_800DC6D8;
    }
    if (st->x0 == 1 && st->x18 != 0x20) {
        *st->x10++ = st->x14;
        st->x14 = 0;
        st->x18 = 0x20;
    }
    st->x0 = 0;
    D_800DC614 = 0;
    if (D_800DE9A8 == 1 || arg0 == D_800D61A8) {
        func_800916B0(st);
    }
}
