#include "common.h"

typedef struct State800722EC State800722EC;
typedef struct VTable800722EC {
    u8 pad0[8];
    s16 unk8;
    u8 padA[2];
    void (*unkC)(void *, s32);
} VTable800722EC;
typedef struct Entry800722EC {
    u8 pad0[0xC];
    State800722EC *unkC;
} Entry800722EC;
struct State800722EC {
    u8 pad0[0x44];
    VTable800722EC *unk44;
    void *unk48;
    u8 pad4C[0x2BC];
    s32 unk308;
    u8 pad30C[0xC];
    u16 unk318;
    u8 pad31A[2];
    Entry800722EC *unk31C;
    State800722EC *unk320;
    s32 unk324;
};


void func_80039F88(s32);                               /* extern */
void func_8004A11C(void *, s32);                         /* extern */
void func_8004B264(void *, void *);                               /* extern */
void func_8004B4F8(void *);                            /* extern */
void func_8005EA48(void *);                               /* extern */
extern u8 D_8001D288;
extern u8 D_8001D2E0;
extern s32 D_800DDC50;
extern u8 D_800DDC60;

void func_800722EC(State800722EC *arg0, s32 arg1) {
    s32 firstHandle;
    s32 secondHandle;
    s32 index;
    VTable800722EC *firstTable;
    VTable800722EC *secondTable;
    State800722EC *firstObject;
    State800722EC *entry;

    arg0->unk48 = &D_8001D288;
    func_8004B264(arg0, &D_800DDC60);
    firstHandle = arg0->unk324;
    if (firstHandle != 0) {
        func_80039F88(firstHandle);
    }
    firstObject = arg0->unk320;
    if (firstObject != NULL) {
        firstTable = firstObject->unk44;
        firstTable->unkC((u8 *)firstObject + firstTable->unk8, 3);
    }
    index = 0;
    if (arg0->unk31C != 0) {
        while (1) {
            if (index >= (s32)arg0->unk318) {
                break;
            }
            entry = ((Entry800722EC *)((u8 *)arg0->unk31C + (index << 4)))->unkC;
            if (entry != NULL) {
                secondTable = entry->unk44;
                secondTable->unkC((u8 *)entry + secondTable->unk8, 3);
            }
            index += 1;
        }
        func_8005EA48(arg0->unk31C);
    }
    arg0->unk48 = &D_8001D2E0;
    D_800DDC50 -= 1;
    secondHandle = arg0->unk308;
    if (secondHandle != 0) {
        func_80039F88(secondHandle);
    }
    func_8004A11C(arg0, 0);
    if (arg1 & 1) {
        func_8004B4F8(arg0);
    }
}
