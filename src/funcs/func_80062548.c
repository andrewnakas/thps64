#include "common.h"

typedef struct {
    u8 active;
    u8 pad1[0x11];
    u8 unk12;
    u8 unk13;
    u8 pad14[4];
    s32 *unk18;
    s32 *unk1C;
    s32 unk20;
    u8 pad24[4];
    s32 unk28;
    u8 pad2C[4];
    s32 unk30;
    s32 unk34;
    u8 pad38[3];
    u8 unk3B;
    u8 unk3C;
    u8 pad3D[0xB];
} Slot;

void func_8005E32C(s32);
void func_8005EA48(s32 *);
void func_800620D8(void);
void func_80062488(s32);
s32 func_80062F18(s32);
extern s32 D_800DAD70[];
extern Slot D_800DAF98[];

void func_80062548(s32 arg0, s32 arg1, s32 arg2) {
    s32 r;

    if (arg0 != -1) {
        Slot *b = D_800DAF98;
        Slot *t = b + arg0;
        if (t->active != 0) {
            s32 *base = t->unk1C;
            s32 idx = t->unk18[-1];
            s32 *p = (s32 *)((u8 *)base + base[1]);
            s32 **q;
            u32 n;
            u32 i;
            for (;;) {
                s32 len;
                if (*p == -1) break;
                p++;
                len = *p;
                p++;
                p = (s32 *)((u8 *)p + len);
            }
            {
                s32 *arr = p + idx + 2;
                n = arr[-1];
                i = 0;
                if (n != 0) {
                    q = (s32 **)arr;
                    do {
                        ((u16 *)*q)[8]--;
                        i++;
                        q++;
                    } while (i < n);
                }
            }
            if (arg2 == 0) {
                Slot *b2 = D_800DAF98;
                Slot *s = b2 + arg0;
                s->unk20 = 0;
                s->unk34 = 0;
                s->unk30 = 0;
                s->unk13 = 0;
                s->unk12 = 0;
                s->unk28 = 0;
                s->unk18 = 0;
                s->active = 0;
                s->unk3B = 0;
                s->unk3C = 0;
                r = func_80062F18(arg0);
                if (r != -1) {
                    func_8005E32C(r);
                    func_80062488(r & 0xFF);
                    D_800DAD70[r] = -1;
                }
                func_8005EA48(s->unk1C);
                s->unk1C = 0;
            }
            i = arg1;   /* through the loop counter: the game keeps i and q in a1/a3 */
            if (i != 0) {
                func_800620D8();
            }
        }
    }
}
