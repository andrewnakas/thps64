/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

u32 func_8000574C(char *);
void func_800057E4(s32, char *, ...);
void func_8009FD60(s32, char *);
s32 func_8009FD8C(char *, char *);
void func_800A0B0C(void *, void *, char *, s32);
extern char D_800193A0[];
extern char D_800193A8[];
extern char D_800193AC[];
extern char D_800193B0[];
extern char D_800193C0[];
extern char D_800193C4[];
extern char D_800193D8[];
extern char D_800193E0[];

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[0x20];
} E8002B3F0;

typedef struct {
    u8 pad0[0x464];
    s32 unk464;
    u8 pad468[0x4B4 - 0x468];
    E8002B3F0 *unk4B4;
    u8 pad4B8[0x4E4 - 0x4B8];
    s32 unk4E4;
} O8002B3F0;

void func_8002B3F0(O8002B3F0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    char name[0x18];
    char tag[8];
    E8002B3F0 *e;
    char *s;
    char *tp;

    e = &arg0->unk4B4[arg1];
    func_800A0B0C(arg0, (u8 *)e + 0xE, name, 0x10);
    tp = tag;
    func_800A0B0C(arg0, (u8 *)e + 0xA, tp, 4);
    if (e->unk4 == arg0->unk4E4) {
        if (arg0->unk464 != 0) {
            s = D_800193A0;
            func_800057E4(arg2, s, name, tp);
        } else {
            if (func_8000574C(name) >= 4) {
                s = D_800193A8;
                func_800057E4(arg2, s, name + 3);
            } else {
                s = D_800193A8;
                func_800057E4(arg2, s, name);
            }
        }
        if (arg3 != 0) {
            char *t = tag;
            if (func_8009FD8C(t, s = D_800193AC) == 0) {
                s = D_800193B0;
                func_8009FD60(arg3, s);
            } else if (func_8009FD8C(t, s = D_800193C0) == 0) {
                s = D_800193C4;
                func_8009FD60(arg3, s);
            } else {
                s = D_800193D8;
                func_8009FD60(arg3, s);
            }
        }
    } else {
        s = D_800193A0;
        func_800057E4(arg2, s, name, tp);
        if (arg3 != 0) {
            s = D_800193E0;
            func_8009FD60(arg3, s);
        }
    }
}
