#include "common.h"

typedef struct Table7AC04 {
    u8 pad0[8];
    s16 unk8;
    u8 padA[2];
    void (*unkC)(void *, s32);
} Table7AC04;
typedef struct Node7AC04 { u8 pad0[0x44]; Table7AC04 *unk44; } Node7AC04;

typedef struct State8007AC04 {
    u8 pad0[0x44];
    void * unk44;
    s32 unk48;
    u8 pad4C[0xC];
    void * unk58;
    Node7AC04 ** unk5C;
} State8007AC04;

void func_8005EA48(void *);
extern u8 D_8001E158;
extern u8 D_8001E388;
extern s32 D_800DE520;

void func_8007AC04(State8007AC04 *arg0, s32 arg1) {
    s32 var_s0;
    Table7AC04 *temp_v0;
    Node7AC04 *temp_v1;

    arg0->unk44 = &D_8001E158;
    var_s0 = 0;
    if (arg0->unk48 > 0) {
        do {
            temp_v1 = arg0->unk5C[var_s0];
            if (temp_v1 != NULL) {
                temp_v0 = temp_v1->unk44;
                temp_v0->unkC((u8 *)temp_v1 + temp_v0->unk8, 3);
            }
            var_s0 += 1;
        } while (var_s0 < arg0->unk48);
    }
    func_8005EA48(arg0->unk5C);
    func_8005EA48(arg0->unk58);
    arg0->unk44 = &D_8001E388;
    D_800DE520 -= 1;
    if (arg1 & 1) {
        func_8005EA48(arg0);
    }
}
