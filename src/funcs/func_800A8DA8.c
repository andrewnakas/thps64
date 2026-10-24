/* cflags: -O2 */
#include "common.h"

s32 func_8009E0F0(void *, s32, s32);    /* extern */

typedef struct {
    s32 id;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s8 unk14;
    s8 unk15;
    s8 unk16;
    s8 pad17;
    s32 unk18;
    s32 unk1C;
    s32 pad20;
} Ent800A8DA8;

typedef struct {
    u8 pad0[0x78];
    s32 w78[200];
    u8 pad398[0x19C];
    Ent800A8DA8 ents[200];
} Obj800A8DA8;

void *func_800A8DA8(void *arg0) {
    s32 i;

    (*(s32 *)((u8 *)arg0 + 0x4C)) = 0x64;
    (*(s32 *)((u8 *)arg0 + 0x50)) = -1;
    (*(s32 *)((u8 *)arg0 + 0x68)) = -1;
    (*(s32 *)((u8 *)arg0 + 0)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x48)) = 0;
    (*(s32 *)((u8 *)arg0 + 4)) = 0;
    (*(s8 *)((u8 *)arg0 + 0x533)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x64)) = 0x6590;
    (*(s8 *)((u8 *)arg0 + 0x398)) = 0;
    (*(s8 *)((u8 *)arg0 + 0x399)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x54)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x5C)) = 0;
    (*(s8 *)((u8 *)arg0 + 0x60)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x6C)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x2158)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x39C)) = 0;
    (*(s8 *)((u8 *)arg0 + 0x530)) = 0;
    (*(s8 *)((u8 *)arg0 + 0x531)) = 0;
    (*(s8 *)((u8 *)arg0 + 0x532)) = 0;
    func_8009E0F0((u8 *)arg0 + 0x3A0, 0, 0x190);
    *(s32 *)((u8 *)arg0 + 0x2154) = 0;
    for (i = 0; i < 0xC8; i++) {
        ((Obj800A8DA8 *)arg0)->ents[i].id = i;
        ((Obj800A8DA8 *)arg0)->ents[i].unk4 = 0;
        ((Obj800A8DA8 *)arg0)->ents[i].unk8 = 0;
        ((Obj800A8DA8 *)arg0)->ents[i].unkC = -0xF;
        ((Obj800A8DA8 *)arg0)->ents[i].unk15 = 0x7F;
        ((Obj800A8DA8 *)arg0)->ents[i].unk10 = -1;
        ((Obj800A8DA8 *)arg0)->ents[i].unk16 = 0;
        ((Obj800A8DA8 *)arg0)->ents[i].unk18 = 0;
        ((Obj800A8DA8 *)arg0)->ents[i].unk1C = 0;
        ((Obj800A8DA8 *)arg0)->ents[i].unk14 = 0;
        ((Obj800A8DA8 *)arg0)->w78[i] = -1;
    }
    return arg0;
}
