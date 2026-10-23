#include "common.h"

typedef struct {
    u8 pad0[8];
    s16 unk8;
    s16 padA;
    void (*unkC)(void *, s32);
} VtblEntry8004B330;

typedef struct {
    u8 pad0[0x44];
    VtblEntry8004B330 *unk44;
} Obj8004B330;

void func_8005EA48(void *);
extern s32 D_8001B460[];
extern s32 D_8001B4A0[];

void func_8004B330(void *arg0, s32 arg1) {
    Obj8004B330 *o;

    *(s32 **)((u8 *)arg0 + 0x48) = D_8001B460;
    o = *(Obj8004B330 **)((u8 *)arg0 + 0x14C);
    if (o != NULL) {
        o->unk44->unkC((u8 *)o + o->unk44->unk8, 3);
    }
    *(s32 **)((u8 *)arg0 + 0x48) = D_8001B4A0;
    if (arg1 & 1) {
        func_8005EA48(arg0);
    }
}
