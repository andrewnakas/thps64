#include "common.h"

u32 func_80047C34(s32, void *);                     /* extern */
s32 func_800669CC(void *);                      /* extern */
s32 func_80066C40();                            /* extern */
extern void *D_800D61A8;
extern s32 D_800DE524;
extern s32 D_800DE7A0;
extern s32 D_800DE9A8;

void func_800670E8(void *arg0) {
    s32 var_v0;
    s32 mask;
    void *temp_v0;

    func_80066C40();
    if (D_800DE9A8 == 1) {
        if (!((*(u16 *)((u8 *)(arg0) + 0)) & 1)) {
            var_v0 = (u32) (*(u32 *)((u8 *)(arg0) + 0x164)) < 0x1F41U;
            goto block_7;
        }
    } else if (D_800DE7A0 != 7) {
        mask = 0x41;
        if (((*(u16 *)((u8 *)(arg0) + 0)) & mask) != mask) {
            if ((u32) (*(u32 *)((u8 *)(arg0) + 0x164)) >= 0x1F41U) {
                var_v0 = func_80047C34((*(s32 *)((u8 *)(D_800D61A8) + 0x1C)) + 4, arg0 + 4) < 0x1F41U;
block_7:
                if (var_v0 == 0) {
                    temp_v0 = (*(void **)((u8 *)(arg0) + 0x48));
                    (*(s32 (**)(void *))((u8 *)(temp_v0) + 0x3C))(arg0 + (*(s16 *)((u8 *)(temp_v0) + 0x38)));
                    return;
                }
                goto block_9;
            }
            goto block_9;
        }
    } else {
block_9:
        func_800669CC(arg0);
        if ((*(u8 *)((u8 *)(arg0) + 0x211)) == 0) {
            D_800DE524 = 1;
        }
    }
}
