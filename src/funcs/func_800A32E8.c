/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Obj;

void func_800A059C(Obj *);
void func_800A05D8(Obj *);
void func_800A3378(Obj *);
void func_800A3700(Obj *);
void func_800A3744(Obj *);

void func_800A32E8(Obj *arg0) {
    func_800A059C(arg0);
    switch (arg0->unk10) {
    case 50:
        func_800A3378(arg0);
        break;
    case 51:
        func_800A3700(arg0);
        break;
    case 52:
        func_800A3744(arg0);
        break;
    }
    func_800A05D8(arg0);
}
