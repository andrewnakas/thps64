#include "common.h"

typedef struct ShortVec80073D68 { s16 x, y, z; } ShortVec80073D68;
typedef struct ByteVec80073D68 { s8 x, y, z; } ByteVec80073D68;
typedef struct Node80073D68 {
    u8 pad0[0x1C];
    struct Node80073D68 *unk1C;
    u8 pad20[0x30];
    u16 unk50;
} Node80073D68;
typedef struct State80073D68 {
    u8 pad0[0x5F6];
    ShortVec80073D68 unk5F6;
    ByteVec80073D68 unk5FC;
    ShortVec80073D68 unk600;
} State80073D68;


extern Node80073D68 *D_800D6180;
extern Node80073D68 *D_800DDC60;
extern ShortVec80073D68 D_800FBBC0;
extern ByteVec80073D68 D_800FBBC8;
extern ShortVec80073D68 D_800FBBD0;
extern ShortVec80073D68 D_800FBBD8;
extern ShortVec80073D68 D_800FBBE0;

void func_80073D68(State80073D68 *arg0, s32 arg1, s32 arg2) {
    Node80073D68 *var_v1;
    Node80073D68 *var_v1_2;

    switch (arg2) {   
    case 0:
        arg0->unk5F6 = D_800FBBE0;
        arg0->unk5FC = D_800FBBC8;
        arg0->unk600 = D_800FBBC0;
        break;
    case 1:
        arg0->unk5F6 = D_800FBBD8;
        arg0->unk5FC = D_800FBBC8;
        arg0->unk600 = D_800FBBC0;
        break;
    case 2:
        arg0->unk5F6 = D_800FBBD0;
        arg0->unk5FC = D_800FBBC8;
        arg0->unk600 = D_800FBBC0;
        break;
    }
    var_v1 = D_800DDC60;
    if (var_v1 != NULL) {
        do {
            var_v1->unk50 = (u16) (var_v1->unk50 | 2);
            var_v1 = var_v1->unk1C;
        } while (var_v1 != NULL);
    }
    var_v1_2 = D_800D6180;
    if (var_v1_2 != NULL) {
        do {
            var_v1_2->unk50 = (u16) (var_v1_2->unk50 | 2);
            var_v1_2 = var_v1_2->unk1C;
        } while (var_v1_2 != NULL);
    }
}
