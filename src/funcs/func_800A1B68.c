/* cflags: -O2 */
#include "common.h"

s32 func_8000A5AC(s32, s32, s32, s32, s32, s32); /* extern */
s32 func_800A0870(void *, s32, s32);            /* extern */
s32 func_800A0C6C(void *, s32);                 /* extern */
s32 func_800A3750(void *, s32 *, s32, s32, s32, void *, s32); /* extern */
extern s32 D_80020EE0;

typedef struct {
    u8 pad0[0x408];
    s32 arr[11];
    s32 idx;
} Obj800A1B68;

void func_800A1B68(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    void *temp_v0_2;

    temp_v0 = func_8000A5AC(arg1, arg2, 1, 0, (*(s32 *)((u8 *)arg0 + 0x438)), (*(s32 *)((u8 *)arg0 + 0x4EC)));
    if (temp_v0 == 0) {
        if ((*(s32 *)((u8 *)arg0 + 0x45C)) != 0) {
            ((Obj800A1B68 *)arg0)->arr[((Obj800A1B68 *)arg0)->idx] = *(s32 *)((u8 *)arg0 + 0x4D8);
        }
        temp_v0_2 = (*(void **)((u8 *)arg0 + 0x4F8));
        (*(s32 *)((u8 *)arg0 + 0xC)) = 0x1E;
        (*(s32 (**)(void *))((u8 *)temp_v0_2 + 0x2C))(arg0 + (*(s16 *)((u8 *)temp_v0_2 + 0x28)));
        func_800A0C6C(arg0, (*(s32 *)((u8 *)arg0 + 0x424)));
        func_800A3750(arg0, &D_80020EE0, (*(s32 *)((u8 *)arg0 + 0x434)), 0, 0, arg0 + 0x444, 0);
        (*(s32 *)((u8 *)arg0 + 0xC)) = 0x1E;
        return;
    }
    func_800A0870(arg0, temp_v0, (*(s32 *)((u8 *)arg0 + 0x424)));
}
