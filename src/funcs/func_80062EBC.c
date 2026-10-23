#include "common.h"

typedef struct {
    u8 pad[0x15];
    u8 b;
    u8 pad2[3];
} Slot;

extern s32 D_800DE318;
extern Slot D_800DADA4[];
extern s32 D_800DAD94;
extern void func_80062A90(void);

void func_80062EBC(void) {
    while (D_800DE318 != 0 || D_800DADA4[D_800DAD94].b != 0) {
        func_80062A90();
    }
}
