/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x40];
    char *name;
    u8 pad44[0x154 - 0x44];
} Ent45A70;

typedef struct {
    u8 pad0[0x208];
    u32 pad208 : 30;
    u32 bit1 : 1;
    u32 bit0 : 1;
    u8 pad20C[0x3E0 - 0x20C];
    s32 v3E0;
    u8 pad3E4[0x424 - 0x3E4];
    s32 v424;
    u8 pad428[0x82C - 0x428];
    s32 v82C;
    u8 pad830[0xA24 - 0x830];
    u16 vA24;
} P45A70;

typedef struct {
    u8 pad0[0x14];
    char *name;
} Item45A70;

typedef struct {
    P45A70 *p;
    u8 pad4[0x1E4 - 4];
    Item45A70 items[1];
} O45A70;

s32 func_800057E4(char *, char *, ...);
void func_8006F23C(s32);
s32 func_8006D9F8(char *);
extern char D_8001B1A0[];
extern char D_8001B268[];
extern char D_8001B270[];
extern char D_8001B274[];
extern char D_8001B27C[];
extern char D_8001B284[];
extern char D_8001B290[];
extern s32 D_800DE93C;
extern Ent45A70 D_800D4D80[];

#define STR(o, off) ((char *)(o) + (off))
#define CNT(o) (*(s32 *)((u8 *)(o) + 0x388))
#define NAME(o, i) (*(char **)((u8 *)(o) + 0x1F8 + (i) * 0x14))

void func_80045A70(u8 *o) {
    char buf[0x100];
    char *s;
    P45A70 *p;
    s32 n;
    s32 k;
    s32 w;
    s32 line;
    s32 i;
    s32 flag;
    char *fmt;
    u8 c;

    STR(o, 0x3F0)[0] = 0;
    STR(o, 0x454)[0] = 0;
    n = (*(P45A70 **)o)->v424;
    if (n > 0 && ((*(P45A70 **)o)->v82C != 2 || n >= 2)) {
        s = STR(o, 0x38C) + func_800057E4(STR(o, 0x38C), D_8001B270, n * 180);
    } else {
        s = STR(o, 0x38C);
    }
    k = D_800DE93C * 2 + (*(P45A70 **)o)->vA24;
    line = 0;
    switch (k) {
    case 2 ... 3:
    case 6 ... 7:
        w = 160;
        break;
    default:
        w = 320;
        break;
    }
    if (CNT(o) == 0) {
        STR(o, 0x38C)[0] = 0;
        return;
    }
    p = *(P45A70 **)o;
    flag = p->bit1;
    c = D_800D4D80[p->v3E0].name[0];
    fmt = 0;
    if (c == 'R' || c == 'r') {
        fmt = (char *)1;
    }
    if (flag != (s32)fmt) {
        fmt = D_8001B268;
    } else {
        fmt = D_8001B1A0;
    }
    func_800057E4(s, D_8001B274, fmt, NAME(o, 0));
    func_8006F23C(0xBC);
    for (i = 1; i < CNT(o); i++) {
        func_800057E4(buf, D_8001B27C, s, NAME(o, i));
        if (w < func_8006D9F8(buf)) {
            line++;
            if (line == 1) {
                s = STR(o, 0x3F0);
            } else if (line == 2) {
                s = STR(o, 0x454);
            }
            if (line == 3) {
                func_800057E4(s, D_8001B284, s);
                return;
            }
            func_800057E4(s, D_8001B290, NAME(o, i));
        } else {
            func_800057E4(s, buf);
        }
    }
}
