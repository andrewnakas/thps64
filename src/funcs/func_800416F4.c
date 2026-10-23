#include "common.h"

typedef struct {
    u8 pad[0x18];
    s32 f18;
} S1E68;

typedef struct {
    u8 pad[0x2A];
    u16 f2A;
    u16 pad2C;
    u16 f2E;
    u8 pad30[0x78 - 0x30];
} S5C1C;

extern S1E68 D_800D1E68;
extern f32 D_800D1E7C;
extern s32 D_800D1E64;
extern s32 D_800C0E20;
extern s32 D_800DE9A8;
extern s32 D_800DE7A0;
extern S5C1C D_800D5C1C[];
extern char D_8001A55C[];
extern char D_8001A568[];
extern char D_8001A574[];
extern char D_8001A580[];
extern char D_8001A58C[];
extern char D_8001A598[];
extern char D_8001A5A0[];
extern char D_8001A5AC[];
extern char D_8001A5B4[];
extern void func_8009FD60(void *, char *);
extern void func_800B1A80(void *, u16);
extern void func_80041AAC(u8 *);

#define H(o) (*(u16 *)(p + (o)))

void func_800416F4(u8 *p, s32 mode) {
    if (*(s32 *)(p + 0x38) == mode) {
        return;
    }
    D_800D1E7C = 625.0f;
    switch (mode) {
        case 50: {
            S1E68 *s;
            char *t;
            s32 v;
            s = &D_800D1E68;
            t = D_8001A55C;
            func_8009FD60(s, t);
            if (D_800DE9A8 == 1) {
                s->f18 = 0x13;
            } else {
                s->f18 = 0x14;
            }
            D_800D1E64 = 0xA7;
            D_800C0E20 = 0;
            func_800B1A80(p + 0x31C, H(0x2F4));
            break;
        }
        case 51: {
            S1E68 *s;
            char *t;
            s32 v;
            s = &D_800D1E68;
            t = D_8001A568;
            func_8009FD60(s, t);
            if (D_800DE9A8 == 1) {
                s->f18 = 0xE;
            } else {
                s->f18 = 0xF;
            }
            D_800D1E64 = 0xA1;
            D_800C0E20 = 1;
            func_800B1A80(p + 0x31C, H(0x2F6));
            break;
        }
        case 52: {
            S1E68 *s;
            char *t;
            s32 v;
            s = &D_800D1E68;
            t = D_8001A574;
            func_8009FD60(s, t);
            if (D_800DE9A8 == 1) {
                s->f18 = 0x37;
            } else {
                s->f18 = 0x38;
            }
            D_800C0E20 = 2;
            func_800B1A80(p + 0x31C, H(0x2F8));
            break;
        }
        case 53: {
            S1E68 *s;
            char *t;
            s32 v;
            s = &D_800D1E68;
            t = D_8001A580;
            func_8009FD60(s, t);
            {
                s32 d = D_800DE9A8;
                if (d == (v = 1)) {
                    s->f18 = 0;
                } else {
                    s->f18 = v;
                }
            }
            D_800D1E64 = 0xA2;
            D_800C0E20 = 3;
            func_800B1A80(p + 0x31C, H(0x2FA));
            break;
        }
        case 54: {
            S1E68 *s;
            char *t;
            s32 v;
            s = &D_800D1E68;
            t = D_8001A58C;
            func_8009FD60(s, t);
            if (D_800DE9A8 == 1) {
                s->f18 = 4;
            } else {
                s->f18 = 5;
            }
            D_800D1E64 = 0xA3;
            D_800C0E20 = 4;
            func_800B1A80(p + 0x31C, H(0x2FC));
            break;
        }
        case 55: {
            S1E68 *s;
            char *t;
            s32 v;
            s = &D_800D1E68;
            t = D_8001A598;
            func_8009FD60(s, t);
            if (D_800DE9A8 == 1) {
                s->f18 = 0x31;
            } else {
                s->f18 = 0x32;
            }
            D_800D1E64 = 0xA4;
            D_800C0E20 = 5;
            func_800B1A80(p + 0x31C, H(0x2FE));
            break;
        }
        case 56: {
            S1E68 *s;
            char *t;
            s32 v;
            s = &D_800D1E68;
            t = D_8001A5A0;
            func_8009FD60(s, t);
            if (D_800DE9A8 == 1) {
                s->f18 = 0xA;
            } else {
                s->f18 = 0xB;
            }
            D_800D1E64 = 0xA4;
            D_800C0E20 = 6;
            func_800B1A80(p + 0x31C, H(0x300));
            break;
        }
        case 57: {
            S1E68 *s;
            char *t;
            s32 v;
            s = &D_800D1E68;
            t = D_8001A5AC;
            func_8009FD60(s, t);
            if (D_800DE9A8 == 1) {
                s->f18 = 0x3E;
            } else {
                s->f18 = 0x3F;
            }
            D_800D1E64 = 0xA5;
            D_800C0E20 = 7;
            func_800B1A80(p + 0x31C, H(0x302));
            break;
        }
        case 58: {
            S1E68 *s;
            char *t;
            s32 v;
            s = &D_800D1E68;
            t = D_8001A5B4;
            func_8009FD60(s, t);
            if (D_800DE9A8 == 1 || D_800DE7A0 == 7) {
                s->f18 = 0x19;
            } else {
                s->f18 = 0x1A;
            }
            D_800D1E64 = 0xA5;
            D_800C0E20 = 8;
            func_800B1A80(p + 0x31C, H(0x304));
            break;
        }
    }
    H(0x2A8) = D_800D5C1C[D_800C0E20].f2A;
    H(0x2AA) = D_800D5C1C[D_800C0E20].f2E;
    func_80041AAC(p);
}
