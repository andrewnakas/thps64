#include "common.h"

typedef struct {
    u8 pad[0x18];
    s32 *list;
    u8 pad2[0x48 - 0x1C];
} Ent800DAF98;

extern Ent800DAF98 D_800DAF98[];

s32 func_800636A8(void *arg0) {
    return D_800DAF98[*(u8 *)((u8 *)arg0 + 0x1B)].list[*(u16 *)((u8 *)arg0 + 0x16)];
}
