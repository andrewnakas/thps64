/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad[0x24];
} Ent;

s32 func_8009FD8C(s32, Ent *);
extern s32 D_800DC954;
extern s32 D_800DC958;
extern Ent D_800DCAB4[];

void func_8006EAB8(s32 arg0) {
    s32 i;

    for (i = 0; i < D_800DC954; i++) {
        if (func_8009FD8C(arg0, &D_800DCAB4[i]) == 0) {
            break;
        }
    }
    D_800DC958 = i;
}
