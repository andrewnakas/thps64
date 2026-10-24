/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i_80063830;

typedef struct {
    u16 unk0;
    u8 pad2[0xE];
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u8 pad16[0x84 - 0x16];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    u8 pad90[0x2A4 - 0x90];
    s32 unk2A4;
    u8 pad2A8[0x322 - 0x2A8];
    s16 unk322;
    u16 unk324;
    u8 pad326[0x32E - 0x326];
    s16 unk32E;
    s16 unk330;
    s16 unk332;
} Unk80063830;

static inline void setv(Unk80063830 *o, s32 x, s32 y, s32 z) {
    o->unk84 = x;
    o->unk88 = y;
    o->unk8C = z;
}

void func_80039E60(s32, s32, s32);
s32 func_800474C8(Vec3i_80063830 *);
s32 func_80049D60(s32);
void func_8004C3D8(void *);
void func_8005C690(void *, s32, s32, s32);
extern s32 D_800C0E20;

void func_80063830(Unk80063830 *arg0, void *arg1, Vec3i_80063830 *arg2) {
    Vec3i_80063830 sp10;
    s32 d;
    s32 y;
    s32 snd;
    s32 v;
    s32 fl;
    s16 r;
    s32 px;
    s32 pz;

    fl = arg0->unk2A4;
    if (fl & 0x10) {
        if (fl & 0x20) {
            return;
        }
        sp10 = *arg2;
        sp10.y = 0;
        d = func_800474C8(&sp10);
        arg0->unk2A4 |= 0x20;
        arg0->unk322 = 0;
        arg0->unk0 |= 0x20;
        arg0->unk330 = func_80049D60(0x1000);
        r = (func_80049D60(2) << 11) - 0x400;
        arg0->unk32E = arg0->unk10 + r;
        r = (func_80049D60(2) << 11) - 0x400;
        arg0->unk332 = arg0->unk14 + r;
        switch (arg0->unk324) {
        case 1:
            snd = 0x68;
            goto play;
        case 3:
            snd = 0x28;
        play:
            func_80039E60(snd, 10000, 0);
            func_8004C3D8(arg1);
            func_8005C690(arg1, 6, 1, 0x78);
            y = -0x40000;
            if (d < 0x28) {
                y = -0x20000;
            }
            if (d < 0x12) {
                arg0->unk330 = arg0->unk12 + func_80049D60(0x400) - 0x200;
                arg0->unk32E = (arg0->unk10 + 0x200) & 0xC00;
                arg0->unk332 = (arg0->unk14 + 0x200) & 0xC00;
            }
            setv(arg0, arg2->x, y, arg2->z);
            break;
        case 2:
        case 4:
        case 5:
            if (arg0->unk324 == 2) {
                snd = 0x6A;
                if (D_800C0E20 == 0) {
                    snd = func_80049D60(2) + 0x53;
                }
                func_80039E60(snd, 10000, 0);
            } else if (arg0->unk324 == 4) {
                func_8004C3D8(arg1);
                func_80039E60(0x52, 10000, 0);
            }
            func_8005C690(arg1, 2, 1, 0xB4);
            setv(arg0, arg2->x + (arg2->x >> 1), -0x50000, arg2->z + (arg2->z >> 1));
            if (((arg0->unk32E) >= 0 ? (arg0->unk32E) : -(arg0->unk32E)) == 0x800 && arg0->unk332 == 0) {
                arg0->unk332 = arg0->unk14;
            }
            if (arg0->unk32E == 0) {
                if (((arg0->unk332) >= 0 ? (arg0->unk332) : -(arg0->unk332)) == 0x800) {
                    arg0->unk32E = arg0->unk10;
                }
            }
            break;
        default:
            setv(arg0, arg2->x, -0x40000, arg2->z);
            break;
        }
    }
}
