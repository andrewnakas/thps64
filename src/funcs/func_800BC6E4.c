/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    void *unk8;
} Msg800BC6E4;

extern void func_80001EC0(void *, void *, s32);
extern void func_80004ED0(void *, s32, s32);
extern void func_80005070(void *, void *, s32);

void func_800BC6E4(u8 *arg0, s32 arg1, s32 arg2) {
    u8 sp10[0x18];
    Msg800BC6E4 msg;
    u8 sp38[0x8];
    u8 *q = sp10;

    func_80001EC0(q, sp38, 1);
    msg.unk0 = arg1;
    msg.unk4 = arg2;
    msg.unk8 = q;
    func_80005070(arg0 + 0x270, &msg, 1);
    func_80004ED0(q, 0, 1);
}
