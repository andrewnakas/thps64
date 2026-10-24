/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    u16 unkA;
    s32 unkC;
    s32 unk10;
} Msg;

extern void func_800AED54(u8 *, s32, Msg *);
extern Msg *func_800B0208(void);
extern s32 func_800B0330(s32, s32);
extern u8 *D_800ECC34;

void func_800AFBD0(u8 *arg0, s16 arg1, s32 arg2) {
    Msg *m;
    s32 t;

    if (*(u8 **)(arg0 + 8) != NULL) {
        m = func_800B0208();
        if (m != NULL) {
            t = *(s32 *)(D_800ECC34 + 0x2C) + *(s32 *)(*(u8 **)(arg0 + 8) + 0x88);
            m->unk8 = 0xB;
            m->unkC = arg1;
            m->unk4 = t;
            m->unk10 = func_800B0330(arg2, t);
            m->unk0 = 0;
            func_800AED54(*(u8 **)(arg0 + 8), 3, m);
        }
    }

}
