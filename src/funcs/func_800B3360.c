/* cflags: -O2 */
#include "common.h"

s32 func_8000AE60(s32, u8 *);
void func_800B3130(s32);
extern s32 D_800F30E4;
extern s32 D_800FC36C;
extern u8 D_800FC370;

void func_800B3360(void) {
    u8 buttons[8];
    s32 i;
    s32 bit;

    if (D_800F30E4 == 0 && func_8000AE60(D_800FC36C, buttons) != -1 && buttons[0] != D_800FC370) {
        i = 0;
        while (1) {
            if (i >= 4) {
                break;
            }
            bit = 1 << i;
            if (D_800FC370 == 0xFF || (D_800FC370 & bit) != (buttons[0] & bit)) {
                func_800B3130(i);
            }
            i++;
        }
        D_800FC370 = buttons[0];
    }
}
