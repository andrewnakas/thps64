/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x30];
    f32 unk30;
    u8 pad34[0x78 - 0x34];
    void *unk78;
    u8 pad7C[0xA6 - 0x7C];
    u16 unkA6;
    u8 padA8[0xCB - 0xA8];
    u8 unkCB;
    u8 unkCC;
    u8 padCD[0x130 - 0xCD];
} Voice800ABB80;

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0x18 - 0x14];
    struct {
        s32 unk0;
        s32 unk4;
    } entries[1];
} Bank800ABB80;

extern s32 func_800ADEEC(Voice800ABB80 *, Bank800ABB80 *, s32, s32, s32, s32);
extern s32 func_800AE068(Bank800ABB80 *, s32, s32, s32, s32, s32, f32);
extern s32 D_800FC2F0;
extern Voice800ABB80 *D_800FC2FC;
extern s32 D_800FC314;
extern Bank800ABB80 *D_800FC324;
extern Bank800ABB80 *D_800FC328;

s32 func_800ABB80(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6) {
    Bank800ABB80 *bank;
    Voice800ABB80 *v;
    s32 i;
    s32 ret;

    if (D_800FC328 != NULL) {
        bank = D_800FC328;
        D_800FC328 = NULL;
    } else {
        bank = D_800FC324;
        if (bank == NULL) {
            D_800FC314 = 0;
            return 0;
        }
    }
    if (D_800FC314 == 0) {
        D_800FC314 = bank->unk10;
    }
    i = 4;
    if (arg3 != 0) {
        v = D_800FC2FC;
        for (; i < D_800FC2F0; i++, v++) {
            if (v->unkA6 == arg0 && v->unk78 == bank) {
                if (arg4 == -1) {
                    arg4 = bank->entries[arg0].unk4;
                }
                v->unk30 = arg6;
                if (arg5 < 0) {
                    arg5 = 0;
                } else if (arg5 >= 0x80) {
                    arg5 = 0x7F;
                }
                v->unkCB = arg5;
                v->unkCC = 0xFF;
                ret = func_800ADEEC(v, bank, arg0, arg1, arg2, arg4);
                D_800FC314 = 0;
                return ret;
            }
        }
    }
    ret = func_800AE068(bank, arg0, arg1, arg2, arg4, arg5, arg6);
    D_800FC314 = 0;
    return ret;
}
