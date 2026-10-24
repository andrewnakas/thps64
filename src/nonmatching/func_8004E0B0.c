/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: 11/684 positional instructions agree (target723); typed rewrite preserves the state machine, but register allocation, redundant sign guards and control-flow layout differ. */
#include "common.h"
#include "layout.h"

typedef struct { s32 x, y, z; } Vec4E0B0;
typedef struct {
    s32 unk0, unk4;
    u8 pad8[4];
    s32 unkC, unk10;
    u8 pad14[4];
    s32 unk18, unk1C;
    u8 pad20[0x2C - 0x20];
} Row4E0B0;
typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x1C - 0x10];
    s32 unk1C;
    u8 pad20[4];
    s32 unk24;
    u8 pad28[0x154 - 0x28];
} Stat4E0B0;
typedef struct {
    u8 unk0;
    u8 pad1[0x80 - 1];
    u8 unk80;
    u8 pad81[0x90 - 0x81];
    u8 unk90;
    u8 pad91[0xA0 - 0x91];
    u8 unkA0;
    u8 padA1[0xB0 - 0xA1];
    u8 unkB0;
} Input4E0B0;

ASSERT_SIZE(Vec4E0B0, 12);
ASSERT_SIZE(Row4E0B0, 0x2C);
ASSERT_SIZE(Stat4E0B0, 0x154);
ASSERT_OFFSET(Input4E0B0, unk80, 0x80);
ASSERT_OFFSET(Input4E0B0, unk90, 0x90);
ASSERT_OFFSET(Input4E0B0, unkA0, 0xA0);
ASSERT_OFFSET(Input4E0B0, unkB0, 0xB0);

s32 func_80022E54(void *, void *);
void func_80039E60(s32, s32, s32);
Vec4E0B0 *func_80047244(Vec4E0B0 *, s32 *);
void func_800472C0(void *, Vec4E0B0 *);
void func_8004A204(void *, s32, s32, s32, s32);
void func_8004BD2C(void *);
void func_8004C9E8(void *);
void func_8004CACC(void *, s32, s32, s32, s32);
void func_8004D048(void *, s32, s32);
s32 func_8004D2D4(void *);
void func_8004D398(void *, s32);
void func_8004DED8(void *);
void func_8004F030(void *, s32);
extern u8 D_8001B980[];
extern Stat4E0B0 D_800D4D80[];
extern Row4E0B0 D_800D63F8[];
extern u16 D_800D6F7C[];
extern s32 D_800D6F9C[];
extern s32 D_800D6FC8, D_800DE86C, D_800DE994;

#define I32(off) (*(s32 *)(arg0 + (off)))
#define S16(off) (*(s16 *)(arg0 + (off)))
#define U8(off) (*(u8 *)(arg0 + (off)))
#define S8(off) (*(s8 *)(arg0 + (off)))

void func_8004E0B0(u8 *arg0) {
    Vec4E0B0 tmp;
    s32 sp28;
    s32 var_a0_2;
    Row4E0B0 *row;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_6;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_s0_2;
    s32 temp_s0_5;
    s32 temp_s0_6;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_5;
    s32 var_a0;
    s32 var_a1;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v0_7;
    s32 var_v1;
    s32 var_v1_4;
    s8 temp_a0_4;
    s8 temp_a0_5;
    u8 temp_v1_3;
    u8 temp_v1_4;
    Row4E0B0 *temp_s0;
    u8 *temp_s0_3;
    Row4E0B0 *temp_s0_4;
    volatile Input4E0B0 *temp_v1_6;

    if ((((*(volatile Input4E0B0 **)(arg0 + 0x964))->unk0 != 0) || (I32(0x408) = 0, ((*(volatile Input4E0B0 **)(arg0 + 0x964))->unk0 != 0))) && (I32(0x450) == 0) && ((I32(0x82C) != 2) || (I32(0x88) <= 0)) && (I32(0x40C) == 0)) {
        temp_v0 = I32(0x804);
        temp_v0_2 = temp_v0 - 1;
        if (temp_v0 > 0) {
            I32(0x804) = temp_v0_2;
            if (temp_v0_2 > 0) {
                I32(0x7D4) = 0;
                goto block_132;
            }
        }
        if ((I32(0x7D8) != 0) && (I32(0x7D4) == 0)) {
            I32(0x804) = 0;
            var_a0 = 0x2710;
            if (I32(0x82C) == 0) {
                I32(0x424) = 0;
                I32(0x420) = 0;
            }
            temp_v1 = I32(0x460);
            temp_a1 = temp_v1 & 0xFF;
            if ((temp_v1 & 0x4000) || (temp_v1 & 0x2000)) {
                var_a0 = U8(0x226) - D_800D63F8[temp_a1].unk18;
            }
            var_v1 = 0;
            if (I32(0x818) != 0) {
                if (I32(0x820) > 0) {
                    var_v1 = (I32(0x81C) & 0xFFF) < 0xED4;
                } else if ((I32(0x81C) & 0xFFF) >= 0x12D) {
                    var_v1 = 1;
                }
            }
            if (((I32(0x454) != 0) && (I32(0x458) == 0) && (S16(0x21C) < var_a0)) || (var_v1 != 0)) {
                func_8004D398(arg0, 0);
                I32(0x318) = (s32) (I32(0x318) + 1);
                return;
            }
            var_s2 = 0;
            if (I32(0x454) != 0) {
                func_8004F030(arg0, temp_a1);
                I32(0x45C) = 1;
                var_s2 = 0;
            }
            var_s0 = 0;
            if (I32(0x34C) != 0) {
                temp_a2 = I32(0x370);
                if ((temp_a2 != 0) && ((D_800DE994 - I32(0x36C)) < 0x23)) {
                    temp_a1_2 = I32(0x360);
                    if ((temp_a1_2 != 0) && ((D_800DE994 - I32(0x364)) < 0x2D)) {
                        var_s0 = D_800D4D80[I32(0x3E0)].unkC + (temp_a1_2 << 8) + (temp_a2 * 0x10) + 3;
                        var_s2 = 0x20;
                        if (D_800D63F8[32].unk0 > 0) {
                            row = &D_800D63F8[32];
loop_36:
                            temp_a0 = row->unk0;
                            row++;
                            if ((temp_a0 & 0xFFFFF) != var_s0) {
                                var_s2 += 1;
                                if (row->unk0 > 0) {
                                    goto loop_36;
                                }
                            } else {
                                var_s0 = temp_a0;
                            }
                            if (D_800D63F8[var_s2].unk0 <= 0) {
                                goto block_39;
                            }
                        } else {
block_39:
                            var_s2 = 0;
                        }
                    }
                }
            }
            if (I32(0x88) < 0) {
                var_v0 = I32(0x8EC);
                if (var_v0 < 0) {
                    var_v0 = -var_v0;
                }
                if (var_v0 < 0xBB8) {
                    var_v0_2 = I32(0x8E0);
                    if (var_v0_2 < 0) {
                        var_v0_2 = -var_v0_2;
                    }
                    if ((var_v0_2 < 0x800) && ((*(volatile Input4E0B0 **)(arg0 + 0x964))->unkA0 != 0)) {
                        I32(0x228) = 0x10000;
                        I32(0x340) = 0;
                        if ((I32(0x858) != 0) || (func_8004C9E8(arg0), (I32(0x858) != 0))) {
                            if ((var_s2 != 0) && (var_s0 & 0x02000000)) {
                                temp_s0 = &D_800D63F8[var_s2];
                                func_8004CACC(arg0, var_s2, temp_s0->unkC, temp_s0->unk1C, 0);
                                temp_s0_2 = temp_s0->unk4;
                                func_8004D2D4(arg0);
                                func_8004A204(arg0, temp_s0_2, 0, -1, -1);
                                I32(0x460) = (s32) (I32(0x460) | 0x4800);
                                func_80039E60(0xA2, 0x2710, 0);
                            } else {
                                func_8004CACC(arg0, 0x4F, (s32)D_8001B980, 0x3E8, 0);
                                func_8004D2D4(arg0);
                                func_8004A204(arg0, 0x22, 8, -1, -1);
                                I32(0x460) = (s32) (I32(0x460) | 0x4800);
                            }
                            func_8004D048(arg0, 8, 0x7AD);
                            func_80039E60(0x26, 0x2710, 0);
                            I32(0x4) = (s32) I32(0x7EC);
                            I32(0x8) = (s32) I32(0x7F0);
                            I32(0xC) = (s32) I32(0x7F4);
                            I32(0x8) = (s32) (I32(0x8) - 0x1E);
                            func_8004DED8(arg0);
                            I32(0x808) = (s32) I32(0x7E0);
                            I32(0x84) = 0;
                            I32(0x88) = (s32) -I32(0x88);
                            I32(0x8C) = 0;
                            return;
                        }
                        goto block_132;
                    }
                    goto block_55;
                }
                goto block_55;
            }
block_55:
            if (I32(0x858) != 0) {
                if ((var_s2 == 0) || (D_800D63F8[var_s2].unk0 & 0x02000000)) {
                    var_s2 = 0;
                }
                func_8004BD2C(arg0);
                I32(0x2FC) = 0;
                I32(0x4) = (s32) I32(0x7EC);
                I32(0x8) = (s32) I32(0x7F0);
                I32(0xC) = (s32) I32(0x7F4);
                I32(0x8) = (s32) (I32(0x8) + 0xFFFE7000);
                I32(0x7D8) = 0;
                I32(0x808) = (s32) I32(0x7E0);
                I32(0x7D4) = 1;
                I32(0x9D0) = (s32) I32(0x4);
                I32(0x9D4) = (s32) I32(0x8);
                I32(0x9D8) = (s32) I32(0xC);
                I32(0x9C4) = (s32) I32(0x4);
                I32(0x9C8) = (s32) I32(0x8);
                I32(0x9CC) = (s32) I32(0xC);
                if (I32(0x7E0) != I32(0x7DC)) {
                    temp_v0_3 = I32(0x9E8) - 0x1E;
                    I32(0x9E8) = temp_v0_3;
                    if (temp_v0_3 < 0) {
                        I32(0x9E8) = 0;
                    }
                    I32(0x7DC) = (s32) I32(0x7E0);
                    I32(0x9E0) = 0;
                } else {
                    I32(0x9E8) = (s32) (I32(0x9E8) + 0x28);
                }
                /* Both sign guards in the original assembly require an integer
                 * to be simultaneously positive and negative, so neither stores. */
                temp_a2_2 = I32(0x9E8) + 0x3C;
                var_v0_3 = D_800D6FC8;
                if (var_v0_3 == 0) {
                    temp_a0_2 = D_800D4D80[I32(0x3E0)].unk24;
                    temp_v1_3 = (*(u8 **)(arg0 + 0x290))[3];
                    var_v0_4 = temp_v1_3 + 3;
                    if ((I32(0x34C) != 0) || (var_v0_4 = temp_v1_3 + 3, (D_800DE86C != 0))) {
                        var_v0_3 = temp_a0_2 + var_v0_4;
                    } else {
                        var_v0_3 = temp_a0_2 + temp_v1_3;
                    }
                }
                I32(0x9E0) = (s32) ((((I32(0x9E0) * (0x64 - (var_v0_3 * 0xF))) / 100) * temp_a2_2) / 80);
                I32(0x304) = (s32) (I32(0x304) + 1);
                tmp.x = I32(0x7F8);
                tmp.y = I32(0x7FC);
                tmp.z = I32(0x800);
                var_v0_5 = D_800D6FC8 + 5;
                if (D_800D6FC8 == 0) {
                    temp_a0_3 = D_800D4D80[I32(0x3E0)].unk1C;
                    temp_v1_4 = (*(u8 **)(arg0 + 0x290))[1];
                    var_v0_6 = temp_v1_4 + temp_a0_3;
                    if ((I32(0x34C) != 0) || (var_v0_6 = temp_v1_4 + temp_a0_3, (D_800DE86C != 0))) {
                        var_v0_5 = var_v0_6 + 8;
                    } else {
                        var_v0_5 = temp_a0_3 + temp_v1_4 + 5;
                    }
                }
                sp28 = var_v0_5;
                func_80047244(&tmp, &sp28);
                func_800472C0(arg0 + 0x84, &tmp);
                temp_v1_5 = I32(0x308);
                switch (temp_v1_5) {                /* switch 1; irregular */
                case 0:                             /* switch 1 */
                    var_a0_2 = 5;
block_93:
                    func_80039E60(var_a0_2, 0x2710, 0);
                    break;
                case 2:                             /* switch 1 */
                    var_a0_2 = 0x26;
                    goto block_93;
                case 1:                             /* switch 1 */
                    var_a0_2 = 0x24;
                    goto block_93;
                }
                func_8004D048(arg0, 4, 0x828);
                I32(0x51C) = (s32) (I32(0x51C) + 1);
                I32(0x454) = 1;
                I32(0x330) = (s32) (I32(0x330) + 1);
                func_8004DED8(arg0);
                temp_s0_3 = arg0 + 0x7F8;
                func_80022E54(temp_s0_3, arg0 + 0x8D0);
                var_v1_4 = func_80022E54(temp_s0_3, arg0 + 0x8DC);
                I32(0x418) = 0;
                if (var_s2 != 0) {
                    func_80039E60(0xA2, 0x2710, 0);
                    I32(0x460) = 0x80001000;
                    temp_s0_4 = &D_800D63F8[var_s2];
                    func_8004CACC(arg0, var_s2, temp_s0_4->unkC, temp_s0_4->unk1C, 0);
                    I32(0x45C) = 1;
                    I32(0x3E4) = 0;
                    I32(0x9EC) = 0;
                    temp_s2 = temp_s0_4->unk10;
                    if (temp_s2 == 0) {
                        temp_s0_5 = temp_s0_4->unk4;
                        func_8004D2D4(arg0);
                        func_8004A204(arg0, temp_s0_5, 0, -1, -1);
                        return;
                    }
                    temp_s0_6 = temp_s0_4->unk4;
                    func_8004D2D4(arg0);
                    func_8004A204(arg0, temp_s0_6, 0, temp_s2, -1);
                    return;
                }
                var_v0_7 = var_v1_4;
                if (var_v1_4 < 0) {
                    var_v0_7 = -var_v0_7;
                }
                if (var_v0_7 < 0xB33) {
                    temp_v1_6 = (*(volatile Input4E0B0 **)(arg0 + 0x964));
                    var_s0_2 = 6;
                    if ((temp_v1_6->unkB0 != 0) || (S8(0x98D) >= 0x29)) {
                        var_s0_2 = 7;
                        if ((temp_v1_6->unk80 != 0) || (temp_a0_4 = S8(0x98C), ((temp_a0_4 < -0x28) != 0))) {
                            I32(0x418) = -0xB4;
                        } else {
                            var_s0_2 = 7;
                            if (temp_v1_6->unk90 == 0) {
                                var_s0_2 = 4;
                                if (temp_a0_4 >= 0x29) {
                                    var_s0_2 = 7;
                                    goto block_109;
                                }
                            } else {
block_109:
                                I32(0x418) = 0xB4;
                            }
                        }
                    }
                    if (((*(volatile Input4E0B0 **)(arg0 + 0x964))->unkA0 != 0) || (S8(0x98D) < -0x28)) {
                        var_s0_2 = 8;
                        if ((*(volatile Input4E0B0 **)(arg0 + 0x964))->unk80 == 0) {
                            temp_a0_5 = S8(0x98C);
                            if ((temp_a0_5 >= -0x28) && ((*(volatile Input4E0B0 **)(arg0 + 0x964))->unk90 == 0)) {
                                var_s0_2 = 5;
                                if (temp_a0_5 >= 0x29) {
                                    var_s0_2 = 8;
                                }
                            }
                        }
                    }
                } else {
                    temp_a0_6 = I32(0x208);
                    if (temp_a0_6 & 2) {
                        var_v1_4 = -var_v1_4;
                    }
                    I32(0x208) = (s32) (temp_a0_6 & ~2);
                    var_s0_2 = 3;
                    if (var_v1_4 < 0) {
                        var_s0_2 = 2;
                    }
                }
                I32(0x9EC) = var_s0_2;
                I32(0x460) = 0x80001000;
                func_8004CACC(arg0, var_s0_2 + 0x42, D_800D6F9C[var_s0_2], (s32) D_800D6F7C[var_s0_2], 0);
                I32(0x45C) = 1;
                switch (var_s0_2) {                 /* switch 2 */
                case 2:                             /* switch 2 */
                    func_8004D2D4(arg0);
                    func_8004A204(arg0, 0x11, 1, 8, -1);
                    I32(0x3E4) = 2;
                    return;
                case 3:                             /* switch 2 */
                    func_8004D2D4(arg0);
                    func_8004A204(arg0, 0x11, 0, -1, -1);
                    I32(0x3E4) = 1;
                    return;
                case 4:                             /* switch 2 */
                    func_8004D2D4(arg0);
                    var_a1 = 0x43;
block_131:
                    func_8004A204(arg0, var_a1, 0, -1, -1);
                    I32(0x3E4) = 0;
                    return;
                case 5:                             /* switch 2 */
                    func_8004D2D4(arg0);
                    var_a1 = 0x44;
                    goto block_131;
                case 6:                             /* switch 2 */
                    func_8004D2D4(arg0);
                    var_a1 = 0x46;
                    goto block_131;
                case 8:                             /* switch 2 */
                    func_8004D2D4(arg0);
                    var_a1 = 0x39;
                    goto block_131;
                case 7:                             /* switch 2 */
                    func_8004D2D4(arg0);
                    var_a1 = 0x3A;
                    goto block_131;
                }
            } else {
                goto block_132;
            }
        } else {
            goto block_132;
        }
    } else {
block_132:
        I32(0x7D8) = 0;
    }
}
