/* cflags: -O2 */
/* D3: arg0 is a C++-style `this` (Obj555C *const): its stack-home reload is RTX_UNCHANGING so sched2 hoists it above the gfx stores like the game. (G5 draft otherwise unchanged.) */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx555C;

typedef struct Mesh555C {
    s32 unk0;
    s32 unk4;
    struct Mesh555C *unk8;
} Mesh555C;

typedef struct Node555C {
    s32 unk0;
    Mesh555C *unk4;
    u8 pad8[4];
    s32 unkC;
    struct Node555C *unk10;
} Node555C;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Ent555C;

typedef struct {
    u8 pad0[0x38];
    s32 unk38;
    u8 pad3C[0x84 - 0x3C];
    Node555C *unk84;
    Node555C *unk88;
    u8 pad8C[0x1898 - 0x8C];
    Ent555C unk1898[0x40];
    s32 unk1C98;
} Obj555C;

void func_800B9DE0(s32);
extern s32 D_800EECE8;
extern Gfx555C *D_800F36A4;
extern u32 D_800F5628;

void func_800B555C(Obj555C *const arg0, s32 arg1, s32 arg2) {
    Node555C *n;
    Mesh555C *m;
    Ent555C *e;
    s32 last;
    s32 lastTex;
    s32 i;
    s32 clr;
    s32 set;
    s32 flags;

    {

        Gfx555C *_g = D_800F36A4++;

        _g->w0 = 0xE7000000;

        _g->w1 = 0;

    }
    if (D_800F5628 == 0x170000) {
        {
            Gfx555C *_g = D_800F36A4++;
            _g->w0 = 0xD9000000;
            _g->w1 = 0;
        }
        {
            Gfx555C *_g = D_800F36A4++;
            _g->w0 = 0xD9FFFFFF;
            _g->w1 = 0x230005;
        }
    }
    if (arg0->unk38 != 0) {
        set = 0x200;
        clr = 0x400;
    } else {
        clr = 0x200;
        set = 0x400;
    }
    {
        Gfx555C *_g = D_800F36A4++;
        _g->w0 = (~clr & 0xFFFFFF) | 0xD9000000;
        _g->w1 = 0;
    }
    {
        Gfx555C *_g = D_800F36A4++;
        _g->w0 = 0xD9FFFFFF;
        _g->w1 = set;
    }
    last = 0;
    n = arg0->unk84;
    D_800EECE8 = -1;
    while (1) {
        if (n == NULL) {
            break;
        }
        func_800B9DE0(n->unk0);
        m = n->unk4;
        while (1) {
            if (m == NULL) {
                break;
            }
            if (m->unk4 != last) {
                last = m->unk4;
                {
                    Gfx555C *_g = D_800F36A4++;
                    _g->w0 = 0xDA380003;
                    _g->w1 = last;
                }
            }
            {
                Gfx555C *_g = D_800F36A4++;
                _g->w0 = 0xDE000000;
                _g->w1 = m->unk0;
            }
            m = m->unk8;
        }
        n->unkC = 0;
        n = n->unk10;
    }
    if (arg2 != 0) {
        D_800EECE8 = -1;
        n = arg0->unk88;
        while (1) {
            if (n == NULL) {
                break;
            }
            func_800B9DE0(n->unk0);
            m = n->unk4;
        while (1) {
            if (m == NULL) {
                break;
            }
                if (m->unk4 != last) {
                    last = m->unk4;
                    {
                        Gfx555C *_g = D_800F36A4++;
                        _g->w0 = 0xDA380003;
                        _g->w1 = last;
                    }
                }
                {
                    Gfx555C *_g = D_800F36A4++;
                    _g->w0 = 0xDE000000;
                    _g->w1 = m->unk0;
                }
                m = m->unk8;
            }
            n->unkC = 0;
            n = n->unk10;
        }
    }
    if (arg1 != 0) {
        lastTex = D_800EECE8 = -1;
        i = 0;
        while (1) {
            if (i >= arg0->unk1C98) {
                break;
            }
            e = &arg0->unk1898[i];
            if (e->unk0 != last) {
                last = e->unk0;
                {
                    Gfx555C *_g = D_800F36A4++;
                    _g->w0 = 0xDA380003;
                    _g->w1 = last;
                }
            }
            if (e->unk4 != lastTex) {
                lastTex = e->unk4;
                if (lastTex != 0) {
                    func_800B9DE0(lastTex);
                } else {
                    D_800EECE8 = -1;
                    {
                        Gfx555C *_g = D_800F36A4++;
                        _g->w0 = 0xE7000000;
                        _g->w1 = 0;
                    }
                    {
                        Gfx555C *_g = D_800F36A4++;
                        _g->w0 = 0xD7000000;
                        _g->w1 = 0;
                    }
                    flags = e->unkC;
                    if (flags & 0x1000) {
                        {
                            Gfx555C *_g = D_800F36A4++;
                            _g->w0 = 0xFCFFFFFF;
                            _g->w1 = 0xFFFE7838;
                        }
                        if (D_800F5628 & 0x10000) {
                            Gfx555C *_g = D_800F36A4++;
                            _g->w0 = 0xE200001C;
                            _g->w1 = 0x0C184B50;
                        } else {
                            Gfx555C *_g = D_800F36A4++;
                            _g->w0 = 0xE200001C;
                            _g->w1 = 0x0C184340;
                        }
                        {
                            Gfx555C *_g = D_800F36A4++;
                            _g->w0 = 0xD9FCFFFF;
                            _g->w1 = 0;
                        }
                    } else {
                        if (flags & 0x400) {
                            {
                                Gfx555C *_g = D_800F36A4++;
                                _g->w0 = 0xD9FDFFFF;
                                _g->w1 = 0;
                            }
                        } else {
                            {
                                Gfx555C *_g = D_800F36A4++;
                                _g->w0 = 0xD9FFFFFF;
                                _g->w1 = 0x20000;
                            }
                        }
                        {
                            Gfx555C *_g = D_800F36A4++;
                            _g->w0 = 0xFCFFFFFF;
                            _g->w1 = 0xFFFE7C38;
                        }
                        if (D_800F5628 == 0x170000) {
                            {
                                Gfx555C *_g = D_800F36A4++;
                                _g->w0 = 0xE200001C;
                                _g->w1 = 0x0C192078;
                            }
                            {
                                Gfx555C *_g = D_800F36A4++;
                                _g->w0 = 0xD9FFFFFF;
                                _g->w1 = 0x10000;
                            }
                            {
                                Gfx555C *_g = D_800F36A4++;
                                _g->w0 = 0xD9FDFFFF;
                                _g->w1 = 0;
                            }
                        }
                        if (D_800F5628 & 0x10000) {
                            Gfx555C *_g = D_800F36A4++;
                            _g->w0 = 0xE200001C;
                            _g->w1 = 0x0C192078;
                        } else {
                            Gfx555C *_g = D_800F36A4++;
                            _g->w0 = 0xE200001C;
                            _g->w1 = 0x0C192048;
                        }
                    }
                }
            }
            {
                Gfx555C *_g = D_800F36A4++;
                _g->w0 = 0xDE000000;
                _g->w1 = e->unk8;
            }
            i++;
        }
    }
}
