/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: 294/554 positional instructions; target 671. The compiler
 * shares repeated division tails and magic constants; frame/registers differ.
 * Based on Claude F4's draft; Codex audited all control-flow blocks against asm.
 * 58E3C..591C0: mode handles and all 15 switch entries (including defaults).
 * 591C0..5955C: engine start/update/stop; unsigned halfword clamps and decay.
 * 5955C..5989C: surface volume/pitch; signed clamps, full-width cached stores.
 * Table stride 0x154, field +0x1C is signed word; controller +1 is unsigned byte.
 * Both dot-product arguments are p+0x84 (591DC..591EC, 59564..5956C).
 */
#include "common.h"

typedef struct {
    u8 pad[0x1C];
    s32 f1C;
    u8 pad2[0x154 - 0x20];
} S4D80;

extern s32 func_80022E54(void *, void *);
extern s32 func_800233B8(s32);
extern s32 func_80039E60(s32, s32, s32);
extern void func_80039F88(s32);
extern void func_8003A148(s32, u32);
extern void func_8003A178(s32, u32);
extern s32 func_8003A1AC(s32, u32, u32);
extern void func_8003A2D4(s32);
extern s32 D_800C0E20;
extern S4D80 D_800D4D80[];
extern s32 D_800D6FC8;
extern s32 D_800DE86C;

#define W(o) (*(s32 *)(p + (o)))
#define U(o) (*(u32 *)(p + (o)))

void func_80058E3C(u8 *p) {
    s32 id;
    s32 s;
    s32 x;
    s32 a;
    s32 b;
    s32 d;
    u8 *v;
    u16 r16;
    s32 spd;
    s32 t;
    s32 q;
    s32 s3;

    if (W(0x82C) == 5) {
        if (W(0x7BC) == 0) {
            W(0x7BC) = func_80039E60(0xF, 10000, 0);
        }
    } else if (W(0x7BC) != 0) {
        func_80039F88(W(0x7BC));
        W(0x7BC) = 0;
    }
    if (W(0x82C) == 4) {
        if (W(0x7C0) == 0) {
            if (W(0x3E4) != 0) {
                if (W(0x308) == 0 || W(0x308) == 2) {
                    id = 0xB;
                } else {
                    goto other;
                }
            } else if (W(0x308) == 0 || W(0x308) == 2) {
                id = 0xD;
            } else {
            other:
                id = 0xC;
                if (D_800C0E20 == 8) {
                    id = 0xAA;
                }
            }
            W(0x7C0) = func_80039E60(id, 10000, 0);
        }
    } else if (W(0x7C0) != 0) {
        func_80039F88(W(0x7C0));
        W(0x7C0) = 0;
    }
    if (W(0x82C) == 0) {
        if (W(0x7C4) != 0) {
            if (W(0x828) != W(0x824) || W(0x450) != 0) {
                func_80039F88(W(0x7C4));
                W(0x7C4) = 0;
            }
        }
        if (W(0x7C4) == 0 && W(0x450) == 0) {
            W(0x828) = W(0x824);
            W(0x850) = 100;
            W(0x854) = 100;
            switch (W(0x828)) {
                case 2:
                    W(0x7C4) = func_80039E60(1, 10000, 0);
                    W(0x850) = 100;
                    W(0x854) = 100;
                    break;
                case 5:
                    W(0x7C4) = func_80039E60(0x3D, 10000, 0);
                    break;
                case 3:
                    W(0x7C4) = func_80039E60(0x21, 10000, 0);
                    break;
                case 13:
                    W(0x7C4) = func_80039E60(0x38, 10000, 0);
                    W(0x850) = 40;
                    W(0x854) = 100;
                    break;
                case 4:
                    if (D_800C0E20 == 7) {
                        W(0x7C4) = func_80039E60(0xA9, 10000, 0);
                        W(0x850) = 50;
                        W(0x854) = 110;
                    } else {
                        W(0x7C4) = func_80039E60(0x38, 10000, 0);
                        W(0x850) = 40;
                        W(0x854) = 90;
                    }
                    break;
                case 6:
                    W(0x7C4) = func_80039E60(0x48, 10000, 0);
                    break;
                case 8:
                    W(0x7C4) = func_80039E60(0x39, 10000, 0);
                    W(0x850) = 50;
                    W(0x854) = 110;
                    break;
                case 11:
                    W(0x7C4) = func_80039E60(0x36, 10000, 0);
                    W(0x850) = 90;
                    W(0x854) = 70;
                    break;
                case 1:
                    if (D_800C0E20 == 8) {
                        W(0x7C4) = func_80039E60(0xAB, 10000, 0);
                        W(0x850) = 150;
                        W(0x854) = 100;
                    } else {
                        W(0x7C4) = func_80039E60(0x49, 10000, 0);
                    }
                    break;
                case 12:
                    id = 0x37;
                    if (D_800C0E20 == 8) {
                        id = 0x8F;
                    }
                    W(0x7C4) = func_80039E60(id, 10000, 0);
                    W(0x850) = 50;
                    W(0x854) = 100;
                    break;
                case 10:
                    W(0x7C4) = func_80039E60(0x47, 10000, 0);
                    W(0x850) = 75;
                    W(0x854) = 150;
                    break;
                case 14:
                    W(0x7C4) = func_80039E60(0x69, 10000, 0);
                    break;
                case 15:
                    W(0x7C4) = func_80039E60(0x77, 10000, 0);
                    W(0x850) = 60;
                    W(0x854) = 150;
                    break;
                default:
                    W(0x7C4) = func_80039E60(0, 10000, 0);
                    W(0x850) = 70;
                    break;
            }
        }
    } else if (W(0x7C4) != 0) {
        func_80039F88(W(0x7C4));
        W(0x7C4) = 0;
    }
    if (U(0x82C) - 1u < 2 || W(0x82C) == 8) {
        if (W(0x7C8) == 0) {
            v = p + 0x84;
            s = func_800233B8(func_80022E54(v, v)) << 6;
            if (W(0x82C) == 8) {
                s = 300000;
            }
            x = s * 200;
            d = D_800D6FC8;
            if (d == 0) {
                a = D_800D4D80[W(0x3E0)].f1C;
                b = (*(u8 **)(p + 0x290))[1];
                if (W(0x34C) != 0 || D_800DE86C != 0) {
                    spd = b + a + 53;
                } else {
                    spd = a + b + 50;
                }
            } else {
                spd = d + 50;
            }
            t = x / ((spd << 12) * 45 / 448);
            r16 = (u16)t * 2 / 3;
            W(0x7C8) = func_8003A1AC(7, r16, r16);
            func_8003A2D4(W(0x7C8));
            x = s << 11;
            d = D_800D6FC8;
            if (d == 0) {
                a = D_800D4D80[W(0x3E0)].f1C;
                b = (*(u8 **)(p + 0x290))[1];
                if (W(0x34C) != 0 || D_800DE86C != 0) {
                    q = x / (((b + a + 53) << 12) * 45 / 28);
                } else {
                    q = x / (((a + b + 50) << 12) * 45 / 28);
                }
            } else {
                q = x / (((d + 50) << 12) * 45 / 28);
            }
            if ((u16)q < 0x191) {
                q = 0x190;
            }
            if ((u16)q >= 0x400) {
                q = 0x3FF;
            }
            W(0x7CC) = (u16)q;
            W(0x7D0) = (u16)t;
            func_8003A178(W(0x7C8), (u16)q);
        } else if (U(0x7D0) != 0) {
            U(0x7D0) = U(0x7D0) - (U(0x7D0) >> 5);
            func_8003A148(W(0x7C8), U(0x7D0));
        }
    } else if (W(0x7C8) != 0) {
        func_80039F88(W(0x7C8));
        W(0x7C8) = 0;
    }
    if (W(0x7C4) != 0) {
        v = p + 0x84;
        s = func_800233B8(func_80022E54(v, v));
        s3 = s << 6;
        func_8003A2D4(W(0x7C4));
        x = s << 17;
        d = D_800D6FC8;
        if (d == 0) {
            a = D_800D4D80[W(0x3E0)].f1C;
            b = (*(u8 **)(p + 0x290))[1];
            if (W(0x34C) != 0 || D_800DE86C != 0) {
                q = x / (((b + a + 53) << 12) * 45 / 28);
            } else {
                q = x / (((a + b + 50) << 12) * 45 / 28);
            }
        } else {
            q = x / (((d + 50) << 12) * 45 / 28);
        }
        /* 800596C8..800596D4: ((64*s3 - s3)*4 + s3)*8. */
        x = s3 * 2024;
        d = D_800D6FC8;
        if (d == 0) {
            a = D_800D4D80[W(0x3E0)].f1C;
            b = (*(u8 **)(p + 0x290))[1];
            if (W(0x34C) != 0 || D_800DE86C != 0) {
                t = x / (((b + a + 53) << 12) * 45 / 448);
            } else {
                t = x / (((a + b + 50) << 12) * 45 / 448);
            }
        } else {
            t = x / (((d + 50) << 12) * 45 / 448);
        }
        t = t * W(0x850) / 100;
        func_8003A148(W(0x7C4), t);
        if (q < 0x2BD) {
            q = 0x2BC;
        }
        if (q >= 0x400) {
            q = 0x3FF;
        }
        q = q * W(0x854) / 100;
        func_8003A178(W(0x7C4), (u16)q);
        W(0x7CC) = q;
        W(0x7D0) = t;
    }
}
