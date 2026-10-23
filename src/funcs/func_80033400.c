/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad[0x18];
    s32 v18;
    u8 v1C;
    u8 pad2[3];
} Ent33400;

typedef struct {
    u8 pad[0x40];
    Ent33400 e[8];
    u8 pad2[0x14];
} Row33400;

typedef struct {
    u8 pad[8];
    u8 v8;
    u8 pad2[0x14 - 9];
} Tab33400;

s32 func_800057E4(char *, char *, ...);
extern char D_80019BA0[];
extern char D_80019BB0[];
extern Row33400 D_800D4D80[];
extern Tab33400 D_800DE9F4[];

void func_80033400(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x50) == 0) {
        func_800057E4((char *)(arg0 + 0x4E8), D_80019BA0, D_800D4D80[arg0[0x3D]].e[arg0[0x3F]].v1C - D_800DE9F4[arg0[0x3D]].v8);
    } else {
        func_800057E4((char *)(arg0 + 0x4E8), D_80019BB0, D_800D4D80[arg0[0x3D]].e[arg0[0x3F]].v18);
    }
}
