/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void **unkC;
    s32 unk10;
    u8 pad14[0x10];
    void *unk24;
    void *unk28;
    void *unk2C;
    void **unk30;
    u8 pad34[0x18];
    s32 unk4C;
    s32 unk50;
} Obj37C84;

void func_8009ECF8(void *, void *, ...);
void func_800B4888(void *, s32);
extern u8 D_800EA110[];
extern u8 D_800ECFE0[];

void func_80037C84(Obj37C84 *arg0) {
    s32 i;
    s32 n;
    u8 *p;

    if (arg0->unk4 != 0) {
        func_800B4888(D_800ECFE0, arg0->unk8);
        arg0->unk4 = 0;
    }
    i = 0;
    while (1) {
        if (i < arg0->unk10) {
        func_8009ECF8(D_800EA110, arg0->unkC[i]);
        i++;
        } else break;
    }
    p = D_800EA110;
    func_8009ECF8(p, arg0->unk2C);
    arg0->unk2C = 0;
    func_8009ECF8(p, arg0->unkC);
    arg0->unkC = 0;
    arg0->unk10 = 0;
    func_8009ECF8(p, arg0->unk24);
    arg0->unk24 = 0;
    func_8009ECF8(p, arg0->unk28);
    arg0->unk28 = 0;
    if (arg0->unk30 != 0) {
        n = arg0->unk4C * arg0->unk50;
        i = 0;
        if (n > 0) {
            do {
                func_8009ECF8(D_800EA110, arg0->unk30[i]);
                i++;
                n = arg0->unk4C * arg0->unk50;
            } while (i < n);
        }
        func_8009ECF8(D_800EA110, arg0->unk30);
        arg0->unk30 = 0;
    }
    arg0->unk0 = -1;
}
