#include "common.h"

extern s32 D_800D71F4;
extern s32 D_800D71F8;
extern s32 D_800D71FC;
extern s32 D_800D7200;
extern s32 D_800D7204;

void func_8005CA0C(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x68) != 0) {
        D_800D71F4 = *(u16 *)(*(u8 **)((u8 *)arg0 + 0x80) + 0xC) & 0x40;
        D_800D71F8 = (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x80) + 0xC) ^ 1) & 1;
        D_800D71FC = ((*(u32 *)(*(u8 **)((u8 *)arg0 + 0x80) + 0xC) >> 23) ^ 1) & 1;
        D_800D7200 = *(s32 *)(*(u8 **)((u8 *)arg0 + 0x80) + 0) & 0x80;
        D_800D7204 = (*(u16 *)(*(u8 **)((u8 *)arg0 + 0x80) + 0xC) & 0x1E00) >> 9;
    }
}
