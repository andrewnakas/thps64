#include "common.h"

typedef struct { u8 pad_000[0xFE]; u16 field_0FE; } State80089F54;
void func_800057E4(void *, void *);
extern s32 D_800C0E20, D_800DE7A0;
extern u8 D_8001F674[];
extern u8 D_8001F67C[];
extern u8 D_8001F6A0[];
extern u8 D_8001F6C0[];
extern u8 D_8001F6E8[];
extern u8 D_8001F6F4[];
extern u8 D_8001F70C[];
extern u8 D_8001F72C[];
extern u8 D_8001F7A8[];
extern u8 D_8001F74C[];
extern u8 D_8001F75C[];
extern u8 D_8001F780[];
extern u8 D_8001F798[];

void func_80089F54(State80089F54 *state) {
    void *source;
    s32 mode;
    switch (D_800C0E20) {
    case 0: state->field_0FE = 6; break;
    case 1: state->field_0FE = 7; break;
    case 2: state->field_0FE = 11; break;
    case 3: state->field_0FE = 9; break;
    case 4: state->field_0FE = 8; break;
    case 5: state->field_0FE = 10; break;
    case 6: state->field_0FE = 13; break;
    case 7: state->field_0FE = 12; break;
    case 8: state->field_0FE = 14; break;
    }
    mode = D_800DE7A0;
    if (mode == 7) {
        source = D_8001F674;
        func_800057E4((u8 *)state + 0x102, source);
        source = D_8001F67C;
        func_800057E4((u8 *)state + 0x142, source);
        source = D_8001F6A0;
        func_800057E4((u8 *)state + 0x182, source);
        source = D_8001F6C0;
        func_800057E4((u8 *)state + 0x1C2, source);
        return;
    }
    if (mode == 8) {
        source = D_8001F6E8;
        func_800057E4((u8 *)state + 0x102, source);
        source = D_8001F6F4;
        func_800057E4((u8 *)state + 0x142, source);
        source = D_8001F70C;
        func_800057E4((u8 *)state + 0x182, source);
        source = D_8001F72C;
        func_800057E4((u8 *)state + 0x1C2, source);
        return;
    }
    if (mode == 5) {
        source = D_8001F74C;
        func_800057E4((u8 *)state + 0x102, source);
    } else {
        source = D_8001F7A8;
        func_800057E4((u8 *)state + 0x102, source);
    }
    source = D_8001F75C;
    func_800057E4((u8 *)state + 0x142, source);
    source = D_8001F780;
    func_800057E4((u8 *)state + 0x182, source);
    source = D_8001F798;
    func_800057E4((u8 *)state + 0x1C2, source);
}
