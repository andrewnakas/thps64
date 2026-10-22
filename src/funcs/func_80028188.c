#include "common.h"

s32 func_80024C3C(void *, s32);             /* extern */
s32 func_8004B4F8(void *);                      /* extern */
s32 func_8004C688(void *, s32);             /* extern */
s32 func_800631CC(s32);                         /* extern */
s32 func_80084EA0(void *);                      /* extern */
s32 func_800A415C(void *, s32);             /* extern */
s32 func_800A5FD0(void *, s32);             /* extern */
extern s32 D_80017290;

void func_80028188(void *arg0, s32 arg1) {
    void *temp_v0;
    void *temp_v1;

    (*(void **)((u8 *)(arg0) + 0x48)) = &D_80017290;
    temp_v1 = (*(void **)((u8 *)(arg0) + 0x2248));
    if (temp_v1 != NULL) {
        temp_v0 = (*(void **)((u8 *)(temp_v1) + 0x48));
        (*(s32 (**)(void *, s32))((u8 *)(temp_v0) + 0xC))(temp_v1 + (*(s16 *)((u8 *)(temp_v0) + 8)), 3);
    }
    func_800631CC((*(s32 *)((u8 *)(arg0) + 0x224C)));
    func_80024C3C(arg0 + 0x22D0, 2);
    func_800A5FD0(arg0 + 0x2270, 2);
    func_800A415C(arg0 + 0x1B28, 2);
    func_80084EA0(arg0 + 0xF18);
    func_8004C688(arg0, 0);
    if (arg1 & 1) {
        func_8004B4F8(arg0);
    }
}
