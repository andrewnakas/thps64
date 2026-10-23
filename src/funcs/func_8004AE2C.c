#include "common.h"
typedef struct { u8 pad[0xB]; u8 v; } Ent_F2;
typedef struct { u8 pad[0x20]; u8 *ents; u8 pad2[0x24]; } Tab_F2;
typedef struct {
    u8 pad[0x1B]; u8 idx; u8 pad1[0x21C - 0x1C];
    u16 f21C; u16 f21E; u8 f220; u8 f221; u8 pad2[2]; u16 f224; u8 f226; u8 f227;
} Obj_F2;
extern Tab_F2 D_800DAF98[];
void func_8004AE2C(Obj_F2 *arg0, u16 arg1, u8 arg2) {
    arg0->f21E = arg1;
    arg0->f226 = ((Ent_F2 *)(D_800DAF98[arg0->idx].ents + arg0->f21E * 8))->v;
    arg0->f220 = 1;
    arg0->f221 = arg2;
    arg0->f21C = 0;
    arg0->f224 = 0;
    arg0->f227 = 0;
}
