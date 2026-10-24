/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 flags;
    s32 active;
    s32 unk8;
    u32 time;
    s32 cnt;
    u32 unk14;
    u32 unk18;
    u8 pad1C[0x14];
    f32 vol;
    s32 unk34;
    s32 unk38;
    u32 next;
    s32 unk40;
    u8 pad44[4];
    s32 unk48;
    u8 pad4C[0x48];
    u32 unk94;
    u8 pad98[2];
    u16 unk9A;
    u16 tempo;
    u8 pad9E[0xC];
    s16 unkAA;
    u8 padAC[0x17];
    u8 unkC3;
    u8 padC4[5];
    u8 unkC9;
    u8 padCA[4];
    u8 unkCE;
    u8 padCF[5];
    u8 unkD4;
    u8 unkD5;
    u8 padD6[0x5A];
} Track_800AC8BC;

s32 func_800AAA60(Track_800AC8BC *, s32);
void func_800AC5EC(void);
void func_800ACB5C(Track_800AC8BC *, s32);
void func_800ACF84(Track_800AC8BC *, s32);
void func_800AD000(Track_800AC8BC *, s32);
void func_800AD180(Track_800AC8BC *, s32, f32);
void func_800AD2F8(Track_800AC8BC *);
void func_800AD4FC(Track_800AC8BC *);
f32 func_800AD5A8(Track_800AC8BC *);
f32 func_800AD600(Track_800AC8BC *);
void func_800AD65C(Track_800AC8BC *);
void func_800AD718(Track_800AC8BC *);
void func_800AFD10(s32);
extern s32 D_800FC2F0;
extern s32 D_800FC2F4;
extern Track_800AC8BC *D_800FC2F8;
extern s32 D_800FC304;

s32 func_800AC8BC(void) {
    Track_800AC8BC *t;
    s32 i;
    f32 vol;

    func_800AC5EC();
    i = -4;
    t = D_800FC2F8;
    while (1) {
        if (i >= D_800FC2F0 - 4) break;
        if (t->active != 0 && !(t->flags & 1)) {
            if (t->unk8 != 0) {
                func_800ACF84(t, i);
            }
            t->time += t->tempo;
            if (t->unk9A != 0x7FFF) {
                while (t->next < t->time) {
                    if (t->active == 0) {
                        goto next;
                    }
                    func_800ACB5C(t, i);
                }
                if (t->active == 0) {
                    goto next;
                }
            }
            if (t->unk38 != 0 && t->unk14 < t->time) {
                func_800AD65C(t);
            }
            if (t->unk34 != 0 && t->unk18 < t->time) {
                func_800AD718(t);
            }
            if (t->cnt != -1 && --t->cnt == -1) {
                t->active = func_800AAA60(t, 0);
                if (t->unkC9 != 0) {
                    t->unkC9 = 0;
                    t->unk48 = -2;
                    func_800AFD10(D_800FC2F4 + i * 0x1C);
                }
            }
            if (t->unkC9 != 0) {
                if (t->unkC3 != 0) {
                    func_800AD2F8(t);
                }
                if (t->unkD4 != 0 && t->unk94 < t->time) {
                    func_800AD4FC(t);
                }
                vol = t->vol;
                if (t->unkD5 != 0) {
                    vol += func_800AD600(t);
                }
                if (t->unkCE != 0) {
                    vol += func_800AD5A8(t);
                }
                if (t->unk8 == 0) {
                    func_800AD180(t, i, vol);
                    func_800AD000(t, i);
                }
            }
            t->unkAA = (t->time - t->unk40) >> 8;
        }
    next:
        i++;
        t++;
    }
    return D_800FC304;
}
