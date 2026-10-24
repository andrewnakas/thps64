#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_80073EA0;

typedef struct {
    s32 unk0;
    V3_80073EA0 eye;
    s32 unk10;
    V3_80073EA0 at;
    u8 pad20[0x14];
    u8 mtx[0x70];
} Cam_80073EA0;

typedef struct {
    s32 x, y, z, w;
} Q_80073EA0;

void func_800230FC(void *, V3_80073EA0 *);
void func_80067A48(Q_80073EA0 *, void *);
extern V3_80073EA0 D_800DE134;
extern s32 D_800DE148;
extern Cam_80073EA0 D_800DE1A4[];

void func_80073EA0(u8 *o) {
    s32 flag;
    u8 *t;
    Q_80073EA0 q;

    t = *(u8 **)(o + 0x4B4);
    flag = 0;
    if (t != NULL) {
        flag = *(s32 *)(t + 0x82C) == 5;
    }
    if (flag) {
        D_800DE1A4[D_800DE148].eye.x = (*(s32 *)(o + 0x4D0) + *(s32 *)(o + 0x710)) >> 12;
        D_800DE1A4[D_800DE148].eye.y = (*(s32 *)(o + 0x4D4) + *(s32 *)(o + 0x714)) >> 12;
        D_800DE1A4[D_800DE148].eye.z = (*(s32 *)(o + 0x4D8) + *(s32 *)(o + 0x718)) >> 12;
        *(Q_80073EA0 *)(o + 0x554) = *(Q_80073EA0 *)(o + 0x700);
    } else {
        D_800DE1A4[D_800DE148].eye.x = (*(s32 *)(o + 4) + *(s32 *)(o + 0x6F0)) >> 12;
        D_800DE1A4[D_800DE148].eye.y = (*(s32 *)(o + 8) + *(s32 *)(o + 0x6F4)) >> 12;
        D_800DE1A4[D_800DE148].eye.z = (*(s32 *)(o + 0xC) + *(s32 *)(o + 0x6F8)) >> 12;
        *(Q_80073EA0 *)(o + 0x700) = *(Q_80073EA0 *)(o + 0x554);
        *(s32 *)(o + 0x710) = (D_800DE1A4[D_800DE148].eye.x << 12) - *(s32 *)(o + 0x4D0);
        *(s32 *)(o + 0x714) = (D_800DE1A4[D_800DE148].eye.y << 12) - *(s32 *)(o + 0x4D4);
        *(s32 *)(o + 0x718) = (D_800DE1A4[D_800DE148].eye.z << 12) - *(s32 *)(o + 0x4D8);
    }
    D_800DE1A4[D_800DE148].at.x = (*(s32 *)(o + 0x500) + D_800DE134.x) >> 12;
    D_800DE1A4[D_800DE148].at.y = (*(s32 *)(o + 0x504) + D_800DE134.y) >> 12;
    D_800DE1A4[D_800DE148].at.z = (*(s32 *)(o + 0x508) + D_800DE134.z) >> 12;
    func_80067A48((Q_80073EA0 *)(o + 0x554), D_800DE1A4[D_800DE148].mtx);
    func_800230FC(D_800DE1A4[D_800DE148].mtx, &D_800DE1A4[D_800DE148].eye);
}
