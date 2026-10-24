/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 unk4[0x68];
    s16 unk6C;
    u8 pad6E[0x12];
} E80;

extern void func_8000C4B0(u8 *);
extern void func_8000C900(s32, u8 *, s32);
extern s32 D_800FC36C;
extern E80 D_800FC380[];

void func_800B345C(s32 arg0, s32 arg1) {
    E80 *e = &D_800FC380[arg0];

    if (e->unk6C == 2) {
        if (arg1 != 0) {
            func_8000C900(D_800FC36C, e->unk4, arg0);
        }
        func_8000C4B0(e->unk4);
        if (arg1 != 0) {
            func_8000C4B0(e->unk4);
            func_8000C4B0(e->unk4);
        }
    }

}
