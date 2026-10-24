/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 padA;
    s32 unkC;
} Msg800AFAD0;

typedef struct {
    u8 pad0[0x88];
    s32 unk88;
} Tgt800AFAD0;

typedef struct {
    u8 pad0[0x8];
    Tgt800AFAD0 *unk8;
} Obj800AFAD0;

typedef struct {
    u8 pad0[0x2C];
    s32 unk2C;
} Clk800AFAD0;

extern void func_800AED54(Tgt800AFAD0 *, s32, Msg800AFAD0 *);
extern Msg800AFAD0 *func_800B0208(void);
extern Clk800AFAD0 *D_800ECC34;

void func_800AFAD0(Obj800AFAD0 *arg0, s32 arg1) {
    Msg800AFAD0 *m;
    s32 t;

    if (arg0->unk8 != NULL) {
        m = func_800B0208();
        if (m != NULL) {
            t = D_800ECC34->unk2C + arg0->unk8->unk88;
            m->unk8 = 0xC;
            m->unkC = arg1 & 0xFF;
            m->unk0 = 0;
            m->unk4 = t;
            func_800AED54(arg0->unk8, 3, m);
        }
    }
}
