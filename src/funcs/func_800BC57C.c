/* cflags: -O2 */
#include "common.h"

void func_80004ED0(u8 *, u32 *, s32);
void func_800A011C(u8 *);
void func_800BC764(u8 *, u32);
void func_800BCAA8(u8 *);
void func_800BCB0C(u8 *);
void func_800BCC48(u8 *);
void func_800BCDEC(u8 *);

void func_800BC57C(u8 *arg0) {
    u32 msg;

    while (1) {
        func_80004ED0(arg0 + 0x270, &msg, 1);
        switch (msg) {
        case 3:
            func_800BCB0C(arg0);
            break;
        case 1:
            func_800BCC48(arg0);
            break;
        case 2:
            func_800BCDEC(arg0);
            break;
        case 4:
            func_800BCAA8(arg0);
            break;
        default:
            func_800BC764(arg0, msg);
            break;
        }
        func_800A011C(arg0);
    }
}
