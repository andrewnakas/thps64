/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad[0x18];
    s32 v18;
    u8 v1C;
    u8 pad2[3];
} Ent334C4;

typedef struct {
    u8 pad[0x40];
    Ent334C4 e[8];
    u8 pad2[0x14];
} Row334C4;

typedef struct {
    u8 pad[8];
    u8 v8;
    u8 pad2[0x14 - 9];
} Tab334C4;

s32 func_800057E4(char *, char *, ...);
extern char D_80019BA0[];
extern char D_80019BB0[];
extern Row334C4 D_800D4D80[];
extern Tab334C4 D_800DE9F4[];
void func_800334C4(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x4C) == 0) {
        func_800057E4((char *)(arg0 + 0x4D8), D_80019BA0, D_800D4D80[arg0[0x3C]].e[arg0[0x3E]].v1C - D_800DE9F4[arg0[0x3C]].v8);
    } else {
        func_800057E4((char *)(arg0 + 0x4D8), D_80019BB0, D_800D4D80[arg0[0x3C]].e[arg0[0x3E]].v18);
    }
}
