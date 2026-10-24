/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: compiler register rotation, induction/setup, reload and store
 * scheduling differ: 47/460 positional instructions; target 448.
 * Claude K19 draft; Codex reviewed every asm block, table case and call.
 * 73340..73584: predicted position, best/previous-best selection, unsigned
 * distance rejection. 73584..73768: cooldown, flag update and board setup.
 * 73768..73A10: kind switch and distance pitch; kind/type/IDs are signed s16,
 * sound +0xC stores are s16, the flag byte at +3 is unsigned (big endian).
 * Preserve the post-49D60 reload at 73620 before updating the two flag words.
 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec_73340;

typedef struct {
    s16 type;
    s16 kind;
} CamInfo_73340;

typedef struct {
    u8 pad0[0x24];
    s32 cur;
    Vec_73340 pos;
    u8 pad34[4];
    u32 time;
    s32 skip;
    s32 count;
    s32 prev;
    u32 kind;
} Cam_73340;

typedef struct {
    u8 pad0[0x4B4];
    void *unk4B4;
    u8 pad4B8[4];
    s32 unk4BC;
    u8 pad4C0[0xC];
    s32 unk4CC;
    Vec_73340 unk4D0;
    u8 pad4DC[0x10];
    void *unk4EC;
    s32 unk4F0;
    u8 pad4F4[0xBC];
    s32 unk5B0;
    u8 pad5B4[0xB4];
    s32 unk668;
} Board_73340;

typedef struct {
    u8 pad0[4];
    Vec_73340 pos;
    u8 pad10[0x2D0 - 0x10];
    Board_73340 *unk2D0;
    u8 pad2D4[0x8E8 - 0x2D4];
    s32 unk8E8;
    s32 unk8EC;
    s32 unk8F0;
} Skater_73340;

typedef struct {
    u8 pad0[0xC];
    s16 unkC;
} Snd_73340;

u32 func_80047C34(Vec_73340 *, Vec_73340 *);
s32 func_80048E68(Vec_73340 *, Vec_73340 *);
s32 func_80049BA0(Vec_73340 *, Vec_73340 *);
s32 func_80049D60(s32);
CamInfo_73340 *func_800617B8(Vec_73340 *, s16);

extern s32 D_800C0E2C;
extern s32 D_800C0E30;
extern u32 D_800D613C;
extern Skater_73340 *D_800D61A8;
extern Snd_73340 *D_800D8434;
extern s32 D_800D9D54;
extern s32 D_800D9D58;
extern Cam_73340 D_800DC618;
extern Cam_73340 D_800DC6D8;
extern s32 D_800DDF10;
extern s32 D_800DDF14[];
extern s16 D_800DE02C[];
extern s32 D_800DE0C0;
extern s32 D_800DE0C4;
extern s32 D_800DE0C8;

void func_80073340(Skater_73340 *sk) {
    Skater_73340 *arg0 = sk;
    Vec_73340 tmp;
    Vec_73340 p1;
    Vec_73340 p2;
    Vec_73340 pos;
    Vec_73340 tmp2;
    Cam_73340 *cam;
    CamInfo_73340 *info;
    s32 *e;
    u32 best;
    u32 second;
    u32 d;
    s32 bestIdx;
    s32 secIdx;
    s32 i;
    s16 kind;
    s32 f;
    s32 v;
    s32 dist;
    s32 c;
    s32 none;

    best = 0x7FFFFFFF;
    pos = arg0->pos;
    {
        s32 t = arg0->unk8E8 * 110;
        s32 b = pos.x;
        pos.x = b + t;
    }
    {
        s32 t = arg0->unk8EC * 110;
        s32 b = pos.y;
        pos.y = b + t;
    }
    {
        s32 t = arg0->unk8F0 * 110;
        s32 b = pos.z;
        pos.z = b + t;
    }
    bestIdx = -1;
    if (arg0 == D_800D61A8) {
        cam = &D_800DC618;
    } else {
        cam = &D_800DC6D8;
    }
    if (func_80048E68(&pos, (Vec_73340 *)((u8 *)arg0->unk2D0 + 4)) != 0) {
        cam->count = 0;
    } else {
        cam->count++;
        if (cam->count > 10) {
            cam->skip = cam->cur;
        }
    }
    for (i = 0; i < D_800DDF10; i++) {
        if (i != cam->skip) {
            func_800617B8(&tmp, D_800DE02C[i]);
            d = func_80047C34(&arg0->pos, &tmp);
            if (d < best) {
                second = best;
                /* The first old position is never consumed (secIdx == -1). */
                if (bestIdx != -1) {
                    p2 = p1;
                }
                secIdx = bestIdx;
                best = d;
                p1 = tmp;
                bestIdx = i;
            }
        }
    }
    none = -1;
    if (bestIdx != cam->cur && bestIdx != none && func_80048E68(&pos, &p1) == 0) {
        if (secIdx == cam->cur) {
            bestIdx = -1;
        } else if (secIdx == none) {
            bestIdx = -1;
        } else if (func_80048E68(&pos, &p2) != 0) {
            bestIdx = secIdx;
            p1 = p2;
            best = second;
        } else {
            bestIdx = none;
        }
    }
    if (!(best < 9001)) {
        bestIdx = -1;
    }
    if (bestIdx != -1 && bestIdx != cam->cur && (bestIdx != cam->prev || !(D_800D613C < cam->time + 60))) {
        info = func_800617B8(&tmp2, D_800DE02C[bestIdx]);
        v = info->type;
        kind = info->kind;
        D_800DDF14[0] &= ~0xC00;
        if (v == 1) {
            D_800DDF14[0] |= 0x400;
        } else {
            D_800DDF14[0] |= 0x800;
        }
        v = func_80049D60(5);
        D_800DDF14[0] = (D_800DDF14[0] & ~0xFF) + (v + 5) * 10;
        D_800DDF14[bestIdx] = D_800DDF14[0];
        if (best > 4000) {
            v = 10000 - best;
            if (v < 0) {
                v = 0;
            }
            D_800DDF14[0] = (D_800DDF14[0] & ~0xFF) + (v / 200 + 10);
        }
        cam->time = D_800D613C;
        cam->prev = cam->cur;
        cam->cur = bestIdx;
        cam->pos = p1;
        f = D_800DDF14[bestIdx];
        if (f & 0x800) {
            arg0->unk2D0->unk5B0 = 1;
            arg0->unk2D0->unk4F0 = 1;
            arg0->unk2D0->unk4EC = arg0;
            arg0->unk2D0->unk4CC = 1;
            arg0->unk2D0->unk4BC = 1;
            arg0->unk2D0->unk4B4 = arg0;
            cam->kind = kind;
        } else if (f & 0x400) {
            arg0->unk2D0->unk5B0 = 2;
            arg0->unk2D0->unk4F0 = 1;
            arg0->unk2D0->unk4EC = arg0;
            arg0->unk2D0->unk4CC = 1;
            arg0->unk2D0->unk4BC = 0;
            arg0->unk2D0->unk4D0 = p1;
            arg0->unk2D0->unk4CC = 1;
            arg0->unk2D0->unk4B4 = NULL;
        }
    }
    e = &D_800DDF14[cam->cur];
    f = *e;
    if (f & 0x800) {
        arg0->unk2D0->unk668 = 0;
        switch (cam->kind) {
        case 0:
            D_800D8434->unkC = 0x96A;
            D_800DE0C0 = 0xF5;
            D_800DE0C4 = 0xD7;
            D_800DE0C8 = -0x46;
            arg0->unk2D0->unk668 = 0;
            break;
        case 1:
            D_800D8434->unkC = 0xB72;
            D_800DE0C0 = 0xAF;
            D_800DE0C4 = 0x32;
            D_800DE0C8 = -0x11;
            arg0->unk2D0->unk668 = 0;
            break;
        case 2:
            D_800D8434->unkC = 0xD52;
            D_800DE0C0 = 0x122;
            D_800DE0C4 = 0x96;
            D_800DE0C8 = -0x6C;
            arg0->unk2D0->unk668 = 0;
            break;
        case 4:
            D_800D8434->unkC = 0x96A;
            D_800DE0C0 = 0xF5;
            D_800DE0C4 = 0xD7;
            D_800DE0C8 = -0x46;
            arg0->unk2D0->unk668 = 0x800;
            break;
        case 5:
            D_800D8434->unkC = 0xB72;
            D_800DE0C0 = 0xC3;
            D_800DE0C4 = 0x32;
            D_800DE0C8 = -0x11;
            arg0->unk2D0->unk668 = 0x800;
            break;
        case 6:
            D_800D8434->unkC = 0xD52;
            D_800DE0C0 = 0x122;
            D_800DE0C4 = 0x96;
            D_800DE0C8 = -0x6C;
            arg0->unk2D0->unk668 = 0x800;
            break;
        }
    } else if (f & 0x400) {
        if (f & 0x200) {
            D_800D8434->unkC = (0x100 - (f & 0xFF)) * 10 + 300;
        } else if (f & 0x100) {
            dist = func_80049BA0(&arg0->pos, &cam->pos);
            c = dist;
            if (c > 2400) {
                c = 2400;
            }
            if (c < 450) {
                c = 450;
            }
            D_800D8434->unkC = (((u8 *)e)[3] * 34130) / c;
            D_800D9D58 = dist + D_800C0E30;
            D_800D9D54 = D_800D9D58 + (D_800C0E2C - D_800C0E30);
        }
    }
}
