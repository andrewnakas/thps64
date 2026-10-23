/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 unk4;
    u8 pad5[0x1B];
} E4D80e;

typedef struct {
    u8 pad0[0x58];
    E4D80e e[(0x154 - 0x58) / 0x20];
    u8 pad[0x154 - 0x58 - ((0x154 - 0x58) / 0x20) * 0x20];
} E4D80;

typedef struct {
    u8 pad0[8];
    u8 unk8;
    u8 pad9[0xB];
} E9F4;

typedef struct {
    u8 pad0[0x40];
    char buf[0x20];
    u8 unk60;
    u8 unk61;
    u8 pad62[6];
    s32 unk68;
} O3E910;

extern void func_800057E4(char *, char *, ...);
extern char D_8001A304[];
extern char D_8001A324[];
extern char D_8001A33C[];
extern E4D80 D_800D4D80[];
extern s32 D_800DE7A0;
extern E9F4 D_800DE9F4[];

void func_8003E910(O3E910 *o) {
    s32 n;

    if (o->unk68 == 0) {
        if (D_800DE7A0 == 1) {
            char *fmt = D_8001A304;
            n = D_800D4D80[o->unk60].e[o->unk61].unk4;
            func_800057E4(o->buf, fmt, n - D_800DE9F4[o->unk60].unk8, n);
            return;
        }
        func_800057E4(o->buf, D_8001A324);
        return;
    }
    func_800057E4(o->buf, D_8001A33C, D_800D4D80[o->unk60].e[o->unk61].unk0, n);
}
