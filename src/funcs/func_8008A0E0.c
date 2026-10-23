#include "common.h"

typedef struct {
    u8 pad_000[0xF4];
    u16 field_0F4, field_0F6, field_0F8, field_0FA;
    u16 field_0FC, field_0FE, field_100;
} State8008A0E0;

void func_800057E4(void *, void *);
extern u8 D_8001F7DC[];
extern u8 D_8001F7EC[];
extern u8 D_8001F7FC[];
extern u8 D_8001F818[];
extern u8 D_8001F828[];
extern u8 D_8001F840[];
extern u8 D_8001F854[];
extern u8 D_8001F864[];
extern u8 D_8001F87C[];
extern s32 D_800C0E20;

void func_8008A0E0(State8008A0E0 *arg0) {
    void *source;
    void *destination;

    s32 selection;
    arg0->field_0FE = 0xC4;
    selection = D_800C0E20;
    if (selection == 0) {
        arg0->field_0F4 = 0xAF;
        arg0->field_0F6 = 0xC8;
        arg0->field_0F8 = 0xA8;
        arg0->field_0FA = 0xB2;
        arg0->field_0FC = 0xC3;
        arg0->field_100 = 0xC0;
        return;
    } else if (selection == 1) {
        arg0->field_0F4 = 0xB1;
        arg0->field_0F6 = 0xCC;
        arg0->field_0F8 = 0xAC;
        arg0->field_0FA = 0xC1;
        arg0->field_0FC = 0xB9;
        arg0->field_100 = 0xBE;
        return;
    } else if (selection == 2) {
        arg0->field_0F4 = 0xA6;
        arg0->field_0F6 = 0xCA;
        arg0->field_0F8 = 0xAD;
        arg0->field_0FA = 0xB4;
        arg0->field_0FC = 0xB7;
        arg0->field_100 = 0xBD;
        return;
    } else if (selection == 3) {
        arg0->field_0FE = 9;
        source = D_8001F7DC;
        func_800057E4((u8 *)arg0 + 0x102, source);
        source = D_8001F7EC;
        func_800057E4((u8 *)arg0 + 0x142, source);
        destination = (u8 *)arg0 + 0x182;
        source = D_8001F7FC;
        func_800057E4(destination, source);
        return;
    } else if (selection == 4) {
        arg0->field_0F4 = 0xA7;
        arg0->field_0F6 = 0xCB;
        arg0->field_0F8 = 0xAE;
        arg0->field_0FA = 0xBA;
        arg0->field_0FC = 0xB6;
        arg0->field_100 = 0xBB;
        return;
    } else if (selection == 5) {
        arg0->field_0F4 = 0xA9;
        arg0->field_0F6 = 0xCD;
        arg0->field_0F8 = 0xAE;
        arg0->field_0FA = 0xC2;
        arg0->field_0FC = 0xB5;
        arg0->field_100 = 0xBC;
        return;
    } else if (selection == 6) {
        arg0->field_0FE = 0xD;
        source = D_8001F818;
        func_800057E4((u8 *)arg0 + 0x102, source);
        source = D_8001F828;
        func_800057E4((u8 *)arg0 + 0x142, source);
        destination = (u8 *)arg0 + 0x182;
        source = D_8001F840;
        func_800057E4(destination, source);
        return;
    } else if (selection == 7) {
        arg0->field_0F4 = 0xAB;
        arg0->field_0F6 = 0xC9;
        arg0->field_0F8 = 0xB0;
        arg0->field_0FA = 0xB3;
        arg0->field_0FC = 0xB8;
        arg0->field_100 = 0xBF;
        return;
    } else if (selection == 8) {
        arg0->field_0FE = 0xE;
        source = D_8001F854;
        func_800057E4((u8 *)arg0 + 0x102, source);
        source = D_8001F864;
        func_800057E4((u8 *)arg0 + 0x142, source);
        destination = (u8 *)arg0 + 0x182;
        source = D_8001F87C;
        func_800057E4(destination, source);
        return;
    }
    return;
}
