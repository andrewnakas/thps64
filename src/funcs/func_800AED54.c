/* cflags: -O2 */
#include "common.h"

typedef struct Msg {
    struct Msg *next;
} Msg;

typedef struct {
    u8 pad0[0x48];
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    u8 pad54[6];
    s16 unk5A;
    u8 pad5C[0x1C];
    s32 unk78;
    Msg *unk7C;
    Msg *unk80;
    s32 unk84;
} Obj;

void func_800AF5A4(Obj *, s32, Msg *);

s32 func_800AED54(Obj *arg0, s32 arg1, Msg *arg2) {
    switch (arg1) {
    case 3:
        if (arg0->unk80 != NULL) {
            arg0->unk80->next = arg2;
        } else {
            arg0->unk7C = arg2;
        }
        arg0->unk80 = arg2;
        break;
    case 4:
        arg0->unk78 = 1;
        arg0->unk84 = 0;
        arg0->unk5A = 1;
        arg0->unk4C = 0;
        arg0->unk50 = 1;
        arg0->unk48 = 0;
        func_800AF5A4(arg0, 4, arg2);
        break;
    case 9:
        arg0->unk84 = 1;
        break;
    default:
        func_800AF5A4(arg0, arg1, arg2);
        break;
    }
    return 0;
}
