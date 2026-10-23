/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0xA];
    s16 a;
    u8 padC[2];
    s16 b;
    u8 pad10[0x14];
} Item;

typedef struct {
    u8 pad0[0x10];
    s32 count;
    Item *items;
    u8 pad18[0xC];
} Ent;

void func_8005EA48(Item *);
void func_8007F198(s16, s16);
extern s32 D_800DC954;
extern s32 D_800DC958;
extern Ent D_800DCAB4[];

void func_8006E590(void) {
    s32 i;

    for (i = 0; i < D_800DCAB4[D_800DC958].count; i++) {
        func_8007F198(D_800DCAB4[D_800DC958].items[i].a, D_800DCAB4[D_800DC958].items[i].b);
    }
    func_8005EA48(D_800DCAB4[D_800DC958].items);
    D_800DCAB4[D_800DC958].items = NULL;
    if (D_800DC958 == D_800DC954 - 1) {
        while (1) {
            if (D_800DC954 <= 0) {
                break;
            }
            D_800DC954--;
            if (D_800DCAB4[D_800DC954 - 1].items != NULL) {
                break;
            }
        }
    }
}
