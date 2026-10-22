#include "common.h"

void func_8004B468(void *, s32);                         /* extern */
void func_8006278C(s32, s32, s32);                           /* extern */
void func_80062EBC();                                  /* extern */
typedef struct { u8 pad0[0x18]; s32 *unk18; u8 pad1C[0x2C]; } Unk80084E24;
extern Unk80084E24 D_800DAF98[];

void func_80084E24(void *arg0, s32 arg1) {
    Unk80084E24 *temp_a0;
    s32 *temp_v0;
    u8 temp_v1;

    func_8006278C(arg1, 0, 1);
    func_80062EBC();
    func_8004B468(*(s32 *) ((u8 *) arg0 + 0xC00), arg1);
    temp_a0 = D_800DAF98;
    temp_v1 = *(u8 *) (*(s32 *) ((u8 *) arg0 + 0xC00) + 0x1B);
    temp_v0 = temp_a0[temp_v1].unk18;
    *(s32 *) ((u8 *) arg0 + 0xC0C) = temp_v0[-1];
}
