/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x1CC];
    u8 mq1CC[0x18];
    u8 mq1E4[0x2C];
    s32 unk210;
    s32 unk214;
    s32 unk218;
    s32 unk21C;
} Obj;

typedef struct {
    u8 pad0[0x2314];
    s32 unk2314;
} Glob;

void func_80004ED0(void *, void **, s32);
void func_80005070(void *, void *, s32);
void func_800A011C(Obj *);
void func_800BB430(Obj *, s32);
extern Glob D_800F0DD0;

void func_800BB390(Obj *arg0) {
    void *msg;

    while (1) {
        func_80004ED0(arg0->mq1CC, &msg, 1);
        if (arg0->unk218 != 0) {
            arg0->unk214 = 1;
            arg0->unk218 = 0;
            func_80005070(arg0->mq1E4, NULL, 1);
        }
        if (arg0->unk214 == 0) {
            func_800BB430(arg0, arg0->unk21C ^ 1);
            arg0->unk210 = 1;
        }
        if (D_800F0DD0.unk2314 == 0 && msg != NULL) {
            func_80005070(msg, NULL, 1);
        }
        func_800A011C(arg0);
    }
}
