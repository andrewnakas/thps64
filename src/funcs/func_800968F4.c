/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
/* K19: instruction-for-instruction MATCH per match.py, but gate fails "own .rodata 0x30": tools/match.py jump_tables() assembles jt.s with the default ASFLAGS (-m4100) instead of the per-file -Wa,-no-m4100 set, so the 2 mflo->mult hazard nops are missing there, the table label offsets are off by 8 and the jtbl remap is refused. Restore to src/funcs once jump_tables() honours the per-file asflags. */
#include "common.h"

void func_80034C44(s32, f32, f32, f32, f32, s32);
void func_8006DF40(s32, s32, s32, s32, s32, s32, s32);
void func_8006F1A8(s32, s32, s32, s32);
void func_8006F23C(s32);
void func_8006F274(s32);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Ent_968F4;

typedef struct {
    u8 pad0[0x214];
    s32 unk214;
} Player_968F4;

typedef struct {
    u8 pad0[0x24];
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u8 pad2A[0x20C - 0x2A];
    Ent_968F4 *unk20C;
    s32 unk210;
    u8 pad214[4];
    s32 unk218;
    s32 unk21C;
    s32 unk220;
    s32 unk224;
    f32 unk228;
    f32 unk22C;
    s32 unk230;
    s32 unk234;
    u8 pad238[2];
    u16 unk23A;
    u8 pad23C[0x280 - 0x23C];
    u32 unk280;
} Obj_968F4;

extern Player_968F4 *D_800E8E80[];
extern Ent_968F4 D_800E93E0[];
extern s32 D_800E95C0;
extern s32 D_800E95C4;

void func_800968F4(Obj_968F4 *arg0) {
    Ent_968F4 *slots[5];
    Ent_968F4 *e;
    s32 a, b;
    f32 f;
    s32 n;
    s32 da, db;
    f32 df;
    s32 a2, b2;
    f32 f2;
    s32 i;
    s32 j;
    s32 m;
    s32 cnt;
    s32 k;

    arg0->unk280++;
    if (arg0->unk280 < 60) {
        D_800E95C4 = 1;
    } else {
        D_800E95C4 = 0;
    }
    if (arg0->unk210 * 20 + 80 < arg0->unk280) {
        D_800E95C0 = 1;
    } else {
        D_800E95C0 = 0;
    }
    a = arg0->unk218;
    b = arg0->unk21C;
    f = arg0->unk228;
    if (arg0->unk280 > 60) {
        n = arg0->unk280 - 60;
        a2 = arg0->unk220;
        da = (a2 - a) * n / 20;
        b2 = arg0->unk224;
        db = (b2 - b) * n / 20;
        f2 = arg0->unk22C;
        df = (f2 - f) * (f32)n * 0.05f;
        if (n < 20) {
            a += da;
            b += db;
            f += df;
        } else {
            a = a2;
            b = b2;
            f = f2;
        }
    }
    {
        u16 v = arg0->unk23A;
        arg0->unk24 = v;
        arg0->unk26 = v;
        arg0->unk28 = v;
    }
    func_80034C44(0xD5108E8C, a, b, f, 1.0f, 0);
    cnt = 0;
    slots[0] = NULL;
    slots[1] = NULL;
    slots[2] = NULL;
    slots[3] = NULL;
    slots[4] = NULL;
    arg0->unk20C = D_800E93E0;
    for (i = 0; i < 5; i++) {
        if (D_800E8E80[i] != NULL) {
            if (i == 4) {
                slots[4] = &arg0->unk20C[D_800E8E80[4]->unk214];
            } else {
                {
                    s32 idx = D_800E8E80[i]->unk214;
                    s32 base = (s32)arg0->unk20C;
                    e = (Ent_968F4 *)((idx << 4) + base);
                }
                if (e->unk0 == 1) {
                    slots[i] = e;
                }
            }
        } else {
            slots[i - 1] = &arg0->unk20C[D_800E8E80[i - 1]->unk214];
            break;
        }
    }
    for (j = 0; j < 5; j++) {
        if (slots[j] != NULL) {
            cnt++;
        }
    }
    k = 0;
    for (m = 0; m < arg0->unk210; m++) {
        if (slots[m] != NULL) {
            k++;
        }
    }
    if (k * 20 + 80 < arg0->unk280 && slots[arg0->unk210] != NULL) {
        switch (cnt) {
        case 1:
            arg0->unk230 = 0x82;
            arg0->unk234 = 0x78;
            break;
        case 2:
            switch (k) {
            case 0:
                arg0->unk230 = 0x82;
                arg0->unk234 = 0x55;
                break;
            case 1:
                arg0->unk230 = 0x82;
                arg0->unk234 = 0x9B;
                break;
            }
            break;
        case 3:
            switch (k) {
            case 0:
                arg0->unk230 = 0x82;
                arg0->unk234 = 0x40;
                break;
            case 1:
                arg0->unk230 = 0x82;
                arg0->unk234 = 0x78;
                break;
            case 2:
                arg0->unk230 = 0x82;
                arg0->unk234 = 0xB0;
                break;
            }
            break;
        case 4:
            switch (k) {
            case 0:
                arg0->unk230 = 0x82;
                arg0->unk234 = 0x32;
                break;
            case 1:
                arg0->unk230 = 0x96;
                arg0->unk234 = 0x5C;
                break;
            case 2:
                arg0->unk230 = 0x82;
                arg0->unk234 = 0x86;
                break;
            case 3:
                arg0->unk230 = 0x96;
                arg0->unk234 = 0xB0;
                break;
            }
            break;
        case 5:
            switch (k) {
            case 0:
                arg0->unk230 = 0x82;
                arg0->unk234 = 0x32;
                break;
            case 1:
                arg0->unk230 = 0x96;
                arg0->unk234 = 0x55;
                break;
            case 2:
                arg0->unk230 = 0x82;
                arg0->unk234 = 0x78;
                break;
            case 3:
                arg0->unk230 = 0x96;
                arg0->unk234 = 0x9B;
                break;
            case 4:
                arg0->unk230 = 0x82;
                arg0->unk234 = 0xBE;
                break;
            }
            break;
        }
        func_8006F274(1);
        func_8006F23C(0xE0);
        func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
        e = slots[arg0->unk210];
        if (e->unk8 == 0) {
            func_8006DF40(arg0->unk230, arg0->unk234, e->unk4, 0, 0, 0x100, 0);
        } else if (e->unkC == 0) {
            func_8006DF40(arg0->unk230, arg0->unk234 - 8, e->unk4, 0, 0, 0x100, 0);
            func_8006DF40(arg0->unk230, arg0->unk234 + 8, slots[arg0->unk210]->unk8, 0, 0, 0x100, 0);
        } else {
            func_8006DF40(arg0->unk230, arg0->unk234 - 16, e->unk4, 0, 0, 0x100, 0);
            func_8006DF40(arg0->unk230, arg0->unk234, slots[arg0->unk210]->unk8, 0, 0, 0x100, 0);
            func_8006DF40(arg0->unk230, arg0->unk234 + 16, slots[arg0->unk210]->unkC, 0, 0, 0x100, 0);
        }
    }
}
