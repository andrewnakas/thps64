#include "common.h"

typedef struct {
    u8 pad[0xC];
    s32 vC;
    u8 pad2[0x154 - 0x10];
} Row4C3D8;

void func_80039E60(s32, s32, s32);
s32 func_80049D60(s32);
extern s32 D_800C0E20;
extern Row4C3D8 D_800D4D80[];
extern s32 D_800D7204;

void func_8004C3D8(u8 *arg0) {
    s32 id;
    s32 v;

    switch (D_800D7204) {
    case 7:
        func_80039E60(0x35, 10000, 0);
        break;
    case 9:
        id = 0x28;
        if (D_800C0E20 == 8) {
            id = 0x89;
        }
        func_80039E60(id, 10000, 0);
        break;
    }
    v = D_800D4D80[*(s32 *)(arg0 + 0x3E0)].vC;
    if (v == 0x9000 || v == 0xB000) {
        id = 0x1F;
    } else {
        id = func_80049D60(3) + 0x1C;
    }
    func_80039E60(id, 10000, 0);
}
