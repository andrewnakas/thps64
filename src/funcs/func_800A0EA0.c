/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} Obj;

void func_800A059C(Obj *);
void func_800A05D8(Obj *);
void func_800A0F30(Obj *);
void func_800A0FB0(Obj *);
void func_800A100C(Obj *);

void func_800A0EA0(Obj *arg0) {
    func_800A059C(arg0);
    switch (arg0->unk4) {
    case 40:
        func_800A0F30(arg0);
        break;
    case 41:
        func_800A0FB0(arg0);
        break;
    case 42:
        func_800A100C(arg0);
        break;
    }
    func_800A05D8(arg0);
}
