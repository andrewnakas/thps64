/* cflags: -O2 */
#include "common.h"

typedef struct {
    char name[0x10];
    f32 val;
    u8 pad14[0x18];
} Item_8009C3A8;

typedef struct {
    u8 pad0[0x14];
    s32 sel;
    s32 count;
    Item_8009C3A8 items[8];
} Menu_8009C3A8;

typedef struct {
    u8 pad0[0x10];
    s8 unk10;
    u8 pad11[0x22F];
    Menu_8009C3A8 menus[1];
} Ui_8009C3A8;

void func_800057E4(char *, char *, ...);
void func_800A602C(void *);
void func_800A773C(Ui_8009C3A8 *, f32, f32);
void func_800A7B50(Ui_8009C3A8 *, f32, f32, void *, s32, s32, s32);
void func_800BE7D0(s32, s32, s32, s32, s32, s32, s32, s32);
extern char D_800208A4[];
extern char D_800208B8[];

void func_8009C3A8(Ui_8009C3A8 *u) {
    char buf[0x20];
    Menu_8009C3A8 *m;
    s32 i;
    s32 y;
    s32 t;
    Item_8009C3A8 *it;

    if (*(s16 *)((u8 *)u + 0xE22) < 0) {
        return;
    }
    m = &u->menus[*(s16 *)((u8 *)u + 0xE24)];
    func_800A602C((u8 *)u + 0xE2C);
    func_800BE7D0(0x32, 0xFA, 0x82 - m->count * 15, 0xBE, 0x7F, 0x7F, 0x7F, 0x96);
    if (*(s16 *)((u8 *)u + 0xE20) == 0) {
        func_800BE7D0(0x32, 0xFA, 0x82, 0xAA, 0xFF, 0xFF, 0xFF, 0xFF);
        func_800A7B50(u, 60.0f, 150.0f, D_800208A4, 1, 0, 0);
        return;
    }
    if (*(s16 *)((u8 *)u + 0xE26) != 0) {
        t = 0x7A - m->sel * 15;
        func_800BE7D0(0x3C, 0xF0, t, t + 12, 0xFF, 0xFF, 0xFF, 0xFF);
    } else {
        func_800BE7D0(0x3A, 0xF0, 0x8C, 0xAA, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_800A773C(u, 1.5f, 1.5f);
    func_800A7B50(u, 60.0f, 165.0f, m, 1, 0, 0);
    func_800A773C(u, 1.0f, 1.0f);
    u->unk10 = 0;
    i = 0;
    while (1) {
        if (i >= m->count) break;
        it = &m->items[i];
        func_800057E4(buf, D_800208B8, it->name, it->val);
        func_800A7B50(u, 80.0f, 0x87 - i * 15, buf, 1, 0, 0);
        i++;
    }
}
