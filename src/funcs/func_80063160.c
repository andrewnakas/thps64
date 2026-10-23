#include "common.h"

typedef struct {
    u8 pad[0x13];
    u8 active;
    u8 pad2[0x48 - 0x14];
} Ent_63160;

void func_80062EBC(void);
void func_8006305C(void);
void func_80062548(s32, s32, s32);
void func_800620D8(void);
extern Ent_63160 D_800DAF98[];

void func_80063160(void) {
    s32 i;
    Ent_63160 *e;

    func_80062EBC();
    func_8006305C();
    i = 0;
    e = D_800DAF98;
    do {
        if (e->active == 0) {
            func_80062548(i, 1, 0);
        }
        i++;
        e++;
    } while (i < 40);
    func_800620D8();
}
