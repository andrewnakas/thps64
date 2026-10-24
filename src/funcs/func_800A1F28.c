/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x8];
    s32 unk8;
} Obj800A1F28;

extern void func_800A059C(Obj800A1F28 *);
extern void func_800A05D8(Obj800A1F28 *);
extern void func_800A1FB8(Obj800A1F28 *);
extern void func_800A21C4(Obj800A1F28 *);
extern void func_800A21E8(Obj800A1F28 *);

void func_800A1F28(Obj800A1F28 *arg0) {
    func_800A059C(arg0);
    switch (arg0->unk8) {
    case 20:
        func_800A1FB8(arg0);
        break;
    case 21:
        func_800A21C4(arg0);
        break;
    case 22:
        func_800A21E8(arg0);
        break;
    }
    func_800A05D8(arg0);
}
