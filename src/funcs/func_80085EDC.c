/* cflags: -fexpensive-optimizations */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx85EDC;

typedef struct {
    u8 pad0[4];
    s32 unk4;
} Sub85EDC;

typedef struct {
    s16 unk0;
    u8 pad2[0x178 - 0x2];
    Sub85EDC *unk178;
    u8 pad17C[4];
    Sub85EDC *unk180;
    Sub85EDC *unk184;
    u8 pad188[0x608 - 0x188];
    u8 unk608[0x1388 - 0x608];
    s32 unk1388;
} Obj85EDC;

void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A85C8(void *, f32, f32, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800B8414(s32, f32, f32, f32, f32, s32, f32, s32, f32);
void func_800B9DE0(s32);
extern char D_8001ED40[];
extern char D_8001ED48[];
extern char D_8001ED54[];
extern f32 D_800E8E08;
extern f32 D_800E8E0C;
extern f32 D_800E8E10;
extern f32 D_800E8E14;
extern f32 D_800E8E18;
extern f32 D_800E8E1C;
extern s32 D_800F3298;
extern Gfx85EDC *D_800F36A4;

void func_80085EDC(Obj85EDC *arg0) {
    f32 scale;
    f32 off;
    f32 size;
    s32 t;
    u8 *txt;
    char *str;
    Gfx85EDC *g;

    scale = 0.65f;
    off = 20.0f;
    txt = arg0->unk608;
    func_800A7AF8(txt, 200, 150, 0, 255);
    str = D_8001ED40;
    func_800A85C8(txt, scale, scale, str, D_800E8E08 + off, D_800F3298 - D_800E8E0C, 0, 0, 1.0f, 255, 0, 1, 1, 0, 0, 0);
    str = D_8001ED48;
    func_800A85C8(txt, scale, scale, str, D_800E8E10 + off, D_800F3298 - D_800E8E14, 0, 0, 1.0f, 255, 0, 1, 1, 0, 0, 0);
    str = D_8001ED54;
    func_800A85C8(txt, scale, scale, str, D_800E8E18 + off, D_800F3298 - D_800E8E1C, 0, 0, 1.0f, 255, 0, 1, 1, 0, 0, 0);
    size = 14.0f;

    t = arg0->unk178->unk4;
    g = D_800F36A4++;
    g->w0 = 0xE7000000;
    g->w1 = 0;
    g = D_800F36A4++;
    g->w0 = 0xE3000A01;
    g->w1 = 0x100000;
    func_800B9DE0(t);
    g = D_800F36A4++;
    g->w0 = 0xFCFFFFFF;
    g->w1 = 0xFFFCF238;
    func_800B8414(arg0->unk178->unk4, D_800E8E08, D_800E8E08 + size, (f32)D_800F3298 - (D_800E8E0C + size), (f32)D_800F3298 - D_800E8E0C, 0, 1.0f, 0, 1.0f);

    t = arg0->unk180->unk4;
    g = D_800F36A4++;
    g->w0 = 0xE7000000;
    g->w1 = 0;
    g = D_800F36A4++;
    g->w0 = 0xE3000A01;
    g->w1 = 0x100000;
    func_800B9DE0(t);
    g = D_800F36A4++;
    g->w0 = 0xFCFFFFFF;
    g->w1 = 0xFFFCF238;
    func_800B8414(arg0->unk180->unk4, D_800E8E10, D_800E8E10 + size, (f32)D_800F3298 - (D_800E8E14 + size), (f32)D_800F3298 - D_800E8E14, 0, 1.0f, 0, 1.0f);

    t = arg0->unk184->unk4;
    g = D_800F36A4++;
    g->w0 = 0xE7000000;
    g->w1 = 0;
    g = D_800F36A4++;
    g->w0 = 0xE3000A01;
    g->w1 = 0x100000;
    func_800B9DE0(t);
    g = D_800F36A4++;
    g->w0 = 0xFCFFFFFF;
    g->w1 = 0xFFFCF238;
    func_800B8414(arg0->unk184->unk4, D_800E8E18, D_800E8E18 + size, (f32)D_800F3298 - (D_800E8E1C + size), (f32)D_800F3298 - D_800E8E1C, 0, 1.0f, 0, 1.0f);
    arg0->unk0 = 0;
    arg0->unk1388 = 0;
}
