#include "common.h"

extern char D_80021658[];
extern char D_8002165C[];
extern char D_80021664[];
extern char D_80021668[];
extern char D_8002166C[];
extern char D_80021674[];
extern char D_8002168C[];
extern char D_800216A0[];

typedef struct {
    u8 pad0[0x430];
    u32 unk430;
} Obj;

void func_800A3BD4(Obj *arg0, char **arg1, s32 *arg2) {
    switch (arg0->unk430) {
    case 0:
        arg1[0] = D_80021658;
        *arg2 = 1;
        break;
    case 1:
        arg1[0] = D_80021658;
        arg1[1] = D_8002165C;
        *arg2 = 2;
        break;
    case 3:
        arg1[0] = D_80021664;
        arg1[1] = D_80021668;
        *arg2 = 2;
        break;
    case 4:
        arg1[0] = D_8002166C;
        arg1[1] = D_8002165C;
        *arg2 = 2;
        break;
    case 5:
        arg1[0] = D_80021658;
        arg1[1] = D_80021674;
        *arg2 = 2;
        break;
    case 6:
        arg1[0] = D_80021674;
        *arg2 = 1;
        break;
    case 7:
        arg1[0] = D_8002166C;
        arg1[1] = D_80021674;
        *arg2 = 2;
        break;
    case 8:
        arg1[0] = D_8002166C;
        arg1[1] = D_8002168C;
        arg1[2] = D_80021674;
        *arg2 = 3;
        break;
    case 9:
        arg1[0] = D_800216A0;
        arg1[1] = D_80021674;
        *arg2 = 2;
        break;
    }
}
