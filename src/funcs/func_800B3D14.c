/* cflags: -O2 */
#include "common.h"

typedef struct {
    u16 button;
    s8 x;
    s8 y;
    u8 err;
    u8 pad;
} Pad_800B3D14;

typedef struct {
    u8 state;
    u8 present;
    u8 pad2[2];
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Ctl_800B3D14;

typedef struct {
    u8 data[0x18];
} Q_800B3D14;

void func_80001EC0(void *, void *, s32);
void func_80002E00(s32, void *, s32);
void func_80004ED0(void *, void *, s32);
void func_800077C0(void *, u8 *, void *);
void func_80007C10(void *, u64, u64, void *, void *);
void *func_8009E6B4(void *, s32, s32);
extern s32 D_800EA110;
extern s32 D_800ECFC4;
extern Q_800B3D14 D_800ECFC8;
extern s32 D_800FC610;
extern s32 D_800FC630;
extern Ctl_800B3D14 D_800FC580[];
extern Pad_800B3D14 *D_800FC640[2];
extern u8 D_800FC648;

void func_800B3D14(void) {
    Q_800B3D14 q;
    u8 timer[0x20];
    s32 msg;
    s32 m2;
    s32 i;
    s32 bits;

    D_800FC640[0] = func_8009E6B4(&D_800EA110, 0x18, 0x10);
    D_800FC640[1] = func_8009E6B4(&D_800EA110, 0x18, 0x10);
    func_80001EC0(&q, &msg, 2);
    func_80007C10(timer, 5000, 0, &q, &msg);
    func_80004ED0(&q, &m2, 1);
    func_80001EC0(&D_800ECFC8, &D_800FC610, 8);
    func_80002E00(5, &D_800ECFC8, 0x33333333);
    func_800077C0(&D_800ECFC8, &D_800FC648, &D_800FC630);
    bits = D_800FC648;
    i = 0;
    while (1) {
        if (i >= 5) break;
        D_800FC580[i].unkC = 0;
        D_800FC580[i].unkE = 0;
        D_800FC580[i].unk4 = 0;
        D_800FC580[i].unk8 = 0;
        D_800FC580[i].unk14 = 0;
        D_800FC580[i].unk18 = 0;
        D_800FC580[i].unk10 = 0;
        D_800FC580[i].present = 0;
        D_800FC580[i].state = 0xFF;
        i++;
    }
    i = 0;
    while (1) {
        if (i >= 4) break;
        if ((bits >> i) & 1) {
            D_800FC580[i].present = 1;
            D_800FC580[i].state = 0;
            D_800ECFC4++;
        }
        D_800FC640[0][i].button = 0;
        D_800FC640[0][i].x = D_800FC640[0][i].y = 0;
        D_800FC640[0][i].err = 0;
        D_800FC640[1][i].button = 0;
        D_800FC640[1][i].x = D_800FC640[1][i].y = 0;
        D_800FC640[1][i].err = 0;
        i++;
    }
}
