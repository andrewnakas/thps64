#include "common.h"

typedef struct Node {
    s32 unk0;
    u8 pad4[3];
    u8 unk7;
    u8 pad8[2];
    u16 unkA;
    u8 padC[8];
    struct Node *next;
} Node;

void func_8005F2F8(s32);
void func_800601A0(s32, s32, s32);
void func_800617B8(void *, s32);
void func_80068800(s32, s32);
void func_80069998(s32);
s32 func_8009E30C(s32);
extern s16 **D_800DACB0;
extern Node *D_800DACC0;
extern s32 D_800DE524;

void func_8005F634(s32 arg0) {
    u8 sp10[0x10];
    Node *p;

    switch (*D_800DACB0[arg0]) {
    case 1:
    case 5:
    case 7:
        func_8005F2F8(arg0);
        break;
    case 6:
        if (arg0 != 0xFFFF) {
            for (p = D_800DACC0; p != NULL; p = p->next) {
                if (p->unkA == arg0) {
                    goto found;
                }
            }
        }
        p = NULL;
    found:
        p->unk7++;
        func_800601A0(p->unk0, arg0, 0);
        break;
    case 0x1F5:
        func_800617B8(sp10, arg0);
        D_800DE524 = 1;
        break;
    case 10:
    case 11:
        func_80068800(func_8009E30C(0x28), arg0);
        break;
    case 12:
    case 14:
        func_80069998(arg0);
        break;
    }
}
