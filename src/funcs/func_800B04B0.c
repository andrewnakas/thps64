/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 time;
} Evt;

typedef struct {
    u8 pad0[4];
    Evt *unk4;
    Evt *unk8;
    Evt *unkC;
    u8 pad10[0x20];
    s64 now;
} Clock;

void func_8001062C(char *, void *);
extern char D_80021DC0[];
extern char D_80021DCC[];
extern char D_80021DD8[];
extern char D_80021DE4[];
extern Clock *D_800ECC34;

s32 func_800B04B0(Evt **out) {
    s32 best;
    s32 d;
    s32 ret;

    *out = NULL;
    func_8001062C(D_80021DC0, out);
    func_8001062C(D_80021DCC, D_800ECC34->unkC);
    best = 0x7FFFFFFF;
    if (D_800ECC34->unkC != NULL) {
        d = D_800ECC34->unkC->time - (s32)D_800ECC34->now;
        if (d < best) {
            *out = D_800ECC34->unkC;
            best = d;
        }
    }
    func_8001062C(D_80021DD8, D_800ECC34->unk4);
    if (D_800ECC34->unk4 != NULL) {
        d = D_800ECC34->unk4->time - (s32)D_800ECC34->now;
        if (d < best) {
            *out = D_800ECC34->unk4;
            best = d;
        }
    }
    func_8001062C(D_80021DE4, D_800ECC34->unk8);
    if (D_800ECC34->unk8 != NULL) {
        if ((s64)D_800ECC34->unk8->time - D_800ECC34->now < (s64)best) {
            *out = D_800ECC34->unk8;
        }
    }
    return ret;
}
