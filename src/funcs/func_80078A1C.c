/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_8006F9F8(u16, u16, char *, u8, u8, u8, s32);
extern char D_8001DF28[];
extern char D_8001DF30[];
extern char D_8001DF34[];
extern char D_8001DF38[];
extern char D_8001DF3C[];
extern char D_8001DF44[];
extern char D_8001DF54[];

void func_80078A1C(s32 x, s32 y, u8 r, u8 g, u8 b) {
    func_8006F9F8(x, y, D_8001DF28, r, g, b, 0);
    func_8006F9F8(x + 0x14, y + 8, D_8001DF30, r, g, b, 0);
    func_8006F9F8(x + 0x14, y + 0x10, D_8001DF34, r, g, b, 0);
    func_8006F9F8(x + 0x14, y + 0x18, D_8001DF38, r, g, b, 0);
    func_8006F9F8(x, y + 0x28, D_8001DF3C, r, g, b, 0);
    func_8006F9F8(x, y + 0x30, D_8001DF44, r, g, b, 0);
    func_8006F9F8(x, y + 0x38, D_8001DF54, r, g, b, 0);
    func_8006F9F8(x + 0x14, y + 0x40, D_8001DF30, r, g, b, 0);
    func_8006F9F8(x + 0x14, y + 0x48, D_8001DF34, r, g, b, 0);
    func_8006F9F8(x + 0x14, y + 0x50, D_8001DF38, r, g, b, 0);
}
