#include "common.h"

typedef struct {
    u16 unk0;
    u8 pad[0x12];
} Ent8002EAFC;

typedef struct {
    u8 pad0[0x10C];
    s32 unk10C;
    u8 pad110[0x5C0 - 0x110];
    s32 unk5C0;
    u8 pad5C4[0x5D0 - 0x5C4];
    Ent8002EAFC ent[1];
} Obj8002EAFC;

void func_8004A204(s32, u16, s32, s32, s32);
void func_8004AE2C(s32, u16, s32);

void func_8002EAFC(Obj8002EAFC *arg0) {
    s32 v;

    v = arg0->unk5C0;
    if (v == 0 || v == 20 || v == 15 || v == 16 || v == 19) {
        func_8004AE2C(arg0->unk10C, arg0->ent[arg0->unk5C0].unk0, 1);
    } else {
        func_8004A204(arg0->unk10C, arg0->ent[v].unk0, 0, -1, -1);
    }
}
