/* cflags: -O2 */
#include "common.h"

void func_800B3360(void);
void func_800B34DC(void);
void func_800B3690(s32);
void func_800B3F00(s32, s32);
extern s32 D_800EA550;
extern s32 D_800F30E4;
extern u32 D_800F5664;

void func_800BB430(u8 *arg0, s32 arg1) {
    if (D_800F30E4 != 0) {
        func_800B3690(1);
        return;
    }
    func_800B3F00(arg1, 0);
    *(s32 *)(arg0 + 0x21C) = arg1;
    func_800B34DC();
    if (D_800EA550 != 0 && *(s32 *)(arg0 + 0x1C8) != 0) {
        return;
    }
    if (D_800F5664 % 100 == 0) {
        func_800B3360();
    }
    if (D_800F5664 % 502 == 0) {
        func_800B3690(0);
    }
}
