#include "common.h"

typedef struct {
    u8 b[14];
} Blob8002C040;

void func_8002BFE4(void *);
extern Blob8002C040 D_800D3668;

void func_8002C040(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x248) = arg1;
    *(s32 *)((u8 *)arg0 + 0x244) = 0;
    *(s32 *)((u8 *)arg0 + 0x240) = 0;
    *(s32 *)((u8 *)arg0 + 0x24C) = 0;
    *(s32 *)((u8 *)arg0 + 0x250) = 0;
    func_8002BFE4(arg0);
    *(Blob8002C040 *)((u8 *)arg0 + 0x254) = D_800D3668;
}
