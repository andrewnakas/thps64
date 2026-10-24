/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"
#include "vecmath.h"

typedef struct Node601A0 {
    u8 *unk0;
    u8 pad4[2];
    u8 unk6;
    u8 unk7;
    u16 unk8;
    u16 unkA;
    s32 unkC;
    u8 pad10[4];
    struct Node601A0 *next;
} Node601A0;

typedef struct {
    Vec3s rot;
    u8 name[1];
} Rec601A0;

typedef struct {
    s16 id;
    s16 unk2;
    s32 unk4;
} Ev601A0;

typedef struct {
    u8 pad0[4];
    Vec3i pos;
    Vec3s rot;
    u8 pad16[0x84 - 0x16];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    u8 pad90[0x9C - 0x90];
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    u8 padA8[0x16C - 0xA8];
    Vec3i unk16C;
    u8 pad178[0x2B4 - 0x178];
    Vec3i unk2B4;
    u8 pad2C0[0x2D0 - 0x2C0];
    void *unk2D0;
    Vec3i unk2D4;
    u8 pad2E0[0x384 - 0x2E0];
    s32 unk384[10];
    s32 unk3AC[10];
    s32 unk3D4;
    Ev601A0 *unk3D8;
    u8 pad3DC[0x450 - 0x3DC];
    s32 unk450;
    s32 unk454;
    u8 pad458[0x7D8 - 0x458];
    s32 unk7D8;
    u8 pad7DC[0x83C - 0x7DC];
    s32 unk83C;
    s32 unk840;
    u8 pad844[0xA1C - 0x844];
    u8 unkA1C[4];
} Sk601A0;

typedef struct {
    u8 pad0[0x97C];
    s32 unk97C;
    s32 unk980;
    u8 pad984[0x99C - 0x984];
    s32 unk99C;
    s32 unk9A0;
} Sk61A8;

typedef struct {
    u8 pad0[0x4B4];
    s32 unk4B4;
    u8 pad4B8[0x4EC - 0x4B8];
    s32 unk4EC;
    u8 pad4F0[0x544 - 0x4F0];
    u16 unk544;
    u16 unk546;
    u8 pad548[0x5B0 - 0x548];
    s32 unk5B0;
} ObjE144;

typedef struct Obj601A0 {
    u8 pad0[0x1C];
    struct Obj601A0 *next;
    u8 pad20[0x50 - 0x20];
    u16 unk50;
    u8 pad52[0x15E - 0x52];
    u16 unk15E;
} Obj601A0;

void func_80023414();
void func_8002341C();
void func_80035384(s32);
void func_80035420(f32);
void func_8003552C(s32, f32, f32, f32);
void func_800356C0(s32);
void func_800356CC(s32, s32, s32);
void func_800356E4(s32, s32, s32);
s32 func_80039E60(s32, s32, s32);
void func_80039F88(s32);
void func_8003A0D4();
void func_8003A0DC();
void func_8003A0E4();
void func_8003A0EC();
void func_8003A0F4();
void func_80046034(void *);
void func_80046FBC(Vec3i *, Vec3i *, Vec3i *);
s32 func_800474C8(Vec3i *);
void func_800480B4(Vec3i *, Vec3i *);
void func_80048438(Vec3i *, Vec3i *, s32, s32);
s32 func_80049034(u8 *, u8 *, s32);
void func_8004A204(void *, s32, s32, s32, s32);
void func_8004CACC(void *, s32, s32, s32, s32);
void func_8004CED0(void *);
void func_8005C444(void *);
void func_8005E5CC(s32, s32, s32);
void func_8005EA48(s32);
void func_8005EB20(void *);
void func_8005F634(s32);
void func_8005F798(s32, s32);
void func_8005F974(s32, s32);
void func_8005FD44(u16 *, s32);
u16 *func_8005FE98(u16 *);
Rec601A0 *func_800617B8(Vec3i *, s32);
u16 *func_80061904(s32);
void func_8006278C(u16 *, s32, s32);
void func_80062EBC();
void func_800631CC(u16 *);
s32 func_80063294(void *);
void func_8006EEF0();
void func_800740F8(void *);
void func_800792A0(void *, s32, s32);
void func_800792FC(void *, s32, s32);
void func_80079304(void *, s32, s32);
void func_8007930C(void *, s32, s32);
void func_80079314(void *, s32, s32);
void func_8007931C(void *, s32, s32);
void func_80079324(void *, s32, s32);
void func_80079414(void *, s32);
void func_8007941C(void *, s32);
void func_80079424(void *, s32);
void func_8007942C(void *, s32);
void func_80079434(void *, s32);
void func_80082660(void);
void func_80082CA8(void);
s32 func_800847E8(void *, u8 *);
void func_8008C274(void);
void func_80094FA8(void);
void func_8009FD60(void *, u8 *);

extern u32 D_800C0E3C;
extern s32 D_800C0E40;
extern u8 D_800D1E72[];
extern Obj601A0 *D_800D6180;
extern s32 D_800D619C;
extern Sk601A0 *D_800D61A0;
extern Sk61A8 *D_800D61A8;
extern u16 D_800D8438;
extern u16 D_800D843A;
extern u32 D_800D9D60;
extern Ev601A0 D_800DA6D0[];
extern u16 *D_800DAC00[];
extern s32 D_800DAC50;
extern u8 *D_800DAC54[];
extern s32 D_800DACA4;
extern s32 D_800DACAC;
extern s16 **D_800DACB0;
extern s32 D_800DACB4;
extern u8 *D_800DACB8;
extern Node601A0 *D_800DACC0;
extern s32 D_800DACC4;
extern s8 D_800DACCC;
extern s32 D_800DC618;
extern Obj601A0 *D_800DDC60;
extern ObjE144 *D_800DE144;
extern s32 D_800DE7A0;
extern s32 D_800DE988;
extern s32 D_800DE9A8;
extern s32 D_800DE9D4;
extern u8 D_800E8A20[];

/* func_800619F8 */
static inline u8 *skip_str(u8 *s) {
    while (*s != 0) {
        s++;
    }
    s++;
    return s + ((s32)s & 1);
}

#define FIND_NAMED(nm)                                                                     \
    {                                                                                      \
        s32 i_;                                                                            \
                                                                                           \
        D_800DACAC = 0xFFFF;                                                               \
        i_ = 0;                                                                            \
        while (1) {                                                                        \
            if (i_ >= D_800DACB4) {                                                        \
                break;                                                                     \
            }                                                                              \
            if (*D_800DACB0[i_] == 8 && func_80049034(func_800617B8(&a, i_)->name, nm, -1) != 0) {   \
                D_800DACAC = i_;                                                           \
                break;                                                                     \
            }                                                                              \
            i_++;                                                                          \
        }                                                                                  \
    }

void func_800601A0(u16 *s, s32 arg1, s32 arg2) {
    Vec3i a;
    Vec3i b;
    Vec3i c;
    Vec3i d;
    s32 pending;
    s32 p0;
    s32 p1;
    u32 p2;
    Rec601A0 *best_rec;
    Node601A0 *node;
    u16 op;

    pending = 0;
    if (arg1 != 0xFFFF) {
        Node601A0 *p;

        node = NULL;
        if (*D_800DACB0[arg1] != 6) {
            goto found;
        }
        for (p = D_800DACC0; p != NULL; p = p->next) {
            if (p->unkA == arg1) {
                node = p;
                goto found;
            }
        }
    }
    node = NULL;
found:
    while (1) {
        u16 t = *s;

        if (t == 0xFFFF) {
            break;
        }
        op = t;
        s++;
        switch (op) {
        case 0x2:
            D_800DAC50 = 0;
            while (1) {
                if (*(u8 *)s == 0) {
                    break;
                }
                D_800DAC00[D_800DAC50++] = s;
                s = (u16 *)skip_str((u8 *)s);
            }
            s++;
            break;
        case 0x97:
            if (D_800DACC4 != 0) {
                func_8005EA48(D_800DACC4);
            }
            D_800DACC4 = 0;
            s++;
            break;
        case 0x8A:
            s++;
            break;
        case 0x8C:
        case 0xB0: {
            s32 prev = D_800DACAC;

            if (D_800DE7A0 == 7) {
                u8 *name = D_800DAC54[D_800DE9D4];

                FIND_NAMED(name);
            } else {
                FIND_NAMED((u8 *)s);
            }
            s = (u16 *)skip_str((u8 *)s);
            if (prev != 0xFFFF && D_800DACAC != prev) {
                if (op != 0xB0) {
                    func_8006EEF0();
                }
                func_80094FA8();
            }
            break;
        }
        case 0xB2:
            if (D_800DE9A8 == 2) {
                if (D_800DE7A0 == 7) {
                    u8 *name = D_800DAC54[D_800DE9D4];

                FIND_NAMED(name);
                } else {
                    FIND_NAMED((u8 *)s);
                }
            }
            s = (u16 *)skip_str((u8 *)s);
            break;
        case 0xA2:
            s = (u16 *)skip_str((u8 *)s);
            break;
        case 0x7E:
            func_8006278C(s, 0, 0);
            if (arg2 != 0) {
                func_80062EBC();
            }
            s = (u16 *)skip_str((u8 *)s);
            break;
        case 0x7F:
            func_800631CC(s);
            s = (u16 *)skip_str((u8 *)s);
            break;
        case 0x80:
            func_8006278C(s, 1, 0);
            if (arg2 != 0) {
                func_80062EBC();
            }
            s = (u16 *)skip_str((u8 *)s);
            break;
        case 0x81:
            func_80062EBC();
            break;
        case 0x9F:
            func_8003A0F4(s);
            s = (u16 *)skip_str((u8 *)s);
            break;
        case 0x8E:
            D_800DACB8 = (u8 *)s;
            s = (u16 *)skip_str((u8 *)s);
            D_800DACCC = func_80063294(D_800DACB8);
            func_8009FD60(D_800D1E72, D_800DACB8);
            func_80035384(func_800847E8(D_800E8A20, D_800DACB8));
            break;
        case 0x85:
            while (1) {
                s32 *p;

                if (*s == 0xFF) {
                    break;
                }
                p = (s32 *)(((u32)s + 3) & ~3);

                a.x = *p++ << 12;
                a.y = *p++ << 12;
                a.z = *p++ << 12;
                b.x = *p++ << 12;
                b.y = *p++ << 12;
                b.z = *p++ << 12;
                func_800480B4(&a, &b);
                s = (u16 *)p;
            }
            s++;
            break;
        case 0x8D: {
            u16 clear = *s++;
            u16 inside = *s++;

            while (1) {
                s32 *p;

                if (*s == 0xFF) {
                    break;
                }
                p = (s32 *)(((u32)s + 3) & ~3);

                a.x = *p++ << 12;
                a.y = *p++ << 12;
                a.z = *p++ << 12;
                b.x = *p++ << 12;
                b.y = *p++ << 12;
                b.z = *p++ << 12;
                func_80048438(&a, &b, clear, inside);
                s = (u16 *)p;
            }
            s++;
            break;
        }
        case 0x66:
            D_800C0E40 = 1;
            break;
        case 0x67:
            D_800C0E40 = 0;
            break;
        case 0xAB: {
            s32 *p = (s32 *)(((u32)s + 3) & ~3);
            s32 id = *p++;

            s = (u16 *)p;
            ((Vec3s *)&a)->x = *s++;
            ((Vec3s *)&a)->y = *s++;
            ((Vec3s *)&a)->z = *s++;
            func_8003552C(id, ((Vec3s *)&a)->x * 0.001533980831f, ((Vec3s *)&a)->y * 0.001533980831f,
                          ((Vec3s *)&a)->z * 0.001533980831f);
            break;
        }
        case 0x83:
            func_8002341C(*s++);
            func_800356C0(1);
            break;
        case 0x84:
            func_80023414(*s++);
            func_800356C0(0);
            break;
        case 0x68:
            p0 = *s++;
            p1 = *s++;
            p2 = *s++;
            pending = 1;
            {
                f64 d = (s32)p2;

                if ((s32)p2 < 0) {
                    d += 4294967296.0;
                }
                func_80035420((f32)d * 0.000244140625f);
            }
            break;
        case 0xC8: {
            u32 hi = *s++;
            u32 col = (hi << 16) + *s++;
            D_800D9D60 = col;
            func_800356CC((col >> 16) & 0xFF, (col >> 8) & 0xFF, col & 0xFF);
            break;
        }
        case 0xCA: {
            u32 hi = *s++;
            u32 col = (hi << 16) + *s++;
            D_800C0E3C = col;
            func_80082CA8();
            func_800356E4((col >> 16) & 0xFF, (col >> 8) & 0xFF, col & 0xFF);
            break;
        }
        case 0xC9: {
            s32 *p = (s32 *)(((u32)s + 3) & ~3);
            s32 key = *p++;
            s32 ev;
            s32 i;

            s = (u16 *)p;
            ev = *s++;
            if (D_800DC618 != 2) {
                i = 0;
                while (1) {
                    Sk601A0 *o = D_800D61A0;

                    if (i >= o->unk3D4) {
                        break;
                    }
                    if (o->unk384[i] != 0 && o->unk384[i] == node->unkC) {
                        o->unk384[i] = 0;
                        if (o->unk450 == 0) {
                            Ev601A0 *e = D_800DA6D0;

                            while (e->id != -1) {
                                if (e->id == o->unk3AC[i]) {
                                    break;
                                }
                                e++;
                            }
                            if (e->id != -1) {
                                if (e->id < 20000) {
                                    func_8004CACC(o, 0x4D, e->unk4, -e->unk2, 0);
                                    func_80039E60(0xA1, 10000, 0);
                                } else {
                                    o->unk3D8 = e;
                                }
                            }
                        }
                    }
                    i++;
                }
                if (key != 0) {
                    Sk601A0 *o = D_800D61A0;

                    if (o->unk3D4 < 10) {
                        o->unk384[o->unk3D4] = key;
                        o->unk3AC[o->unk3D4] = ev;
                        o->unk3D4++;
                    }
                }
            }
            break;
        }
        case 0x69:
            func_80039E60((s16)*s++, 10000, 0);
            break;
        case 0x6A:
            func_80039F88((s16)*s++);
            break;
        case 0x96:
            func_8003A0EC(*s++);
            break;
        case 0x9B:
            func_8003A0DC(*s++);
            break;
        case 0x9C:
            func_8003A0E4(*s++);
            break;
        case 0x9D:
            func_8003A0D4(((u8 *)s++)[1]);
            break;
        case 0x9E:
            func_80082660();
            break;
        case 0xA3:
            if (D_800D61A8 != NULL) {
                u16 v = *s++;

                D_800D61A8->unk97C = v;
            }
            break;
        case 0xB1:
            if (D_800D61A8 != NULL) {
                u16 v = *s++;

                D_800D61A8->unk980 = v;
            }
            break;
        case 0x98: {
            s32 dist = 10000000;
            u16 *ids = func_80061904(arg1);

            if (*ids++ != 0) {
                best_rec = func_800617B8(&b, *ids);
                dist = 1;
            } else {
                s32 j;

                j = 0;
                while (1) {
                    s32 i;

                    if (j >= D_800DACA4) {
                        break;
                    }
                    i = 0;
                    while (1) {
                        if (i >= D_800DACB4) {
                            break;
                        }
                        if (*D_800DACB0[i] == 8 && func_80049034(func_800617B8(&c, i)->name, D_800DAC54[j], -1) != 0) {
                            Rec601A0 *r = func_800617B8(&a, i);
                            s32 len;

                            func_80046FBC(&d, &a, &D_800D61A0->unk2D4);
                            len = func_800474C8(&d);
                            if (len < dist) {
                                dist = len;
                                b = a;
                                best_rec = r;
                            }
                        }
                        i++;
                    }
                    j++;
                }
            }
            if (dist != 10000000) {
                Sk601A0 *o = D_800D61A0;

                o->pos = b;
                o->unk84 = 0;
                o->unk88 = -0x4000;
                o->unk8C = 0;
                o->unk9C = 0;
                o->unkA0 = 0;
                o->unkA4 = 0;
                o->pos.y += -0x19000;
                func_8004CED0(o);
                o->unk454 = 0;
                o->unk83C = 0;
                o->unk840 = 0;
                func_8005C444(o);
                o->unk7D8 = 0;
                o->rot = best_rec->rot;
                func_8005EB20(o);
                o->unk16C = o->pos;
                o->unk2B4 = o->pos;
                o->unk450 = 0;
                func_800740F8(o->unk2D0);
                func_8004A204(o, 0, 0, -1, -1);
                if (D_800DE7A0 != 7) {
                    func_80046034(o->unkA1C);
                }
            } else {
                func_8008C274();
            }
            break;
        }
        case 0x94:
            if (node->unk7 != *s++) {
                while (*s != 0x95) {
                    s = func_8005FE98(s);
                }
                s++;
            }
            break;
        case 0x86:
            if (node->unk6 == 0) {
                node->unk8 = *s;
                node->unk6 = 1;
            }
            s++;
            break;
        case 0x3:
            if (node != NULL) {
                if (node->unk8 != 0) {
                    s32 i;
                    u16 *ids = func_80061904(arg1);
                    u16 *p = ids + 1;
                    u16 n = ids[0];

                    for (i = 0; i < n; i++, p++) {
                        func_8005F634(*p);
                    }
                    if (node->unk8 != 0xFFFF) {
                        node->unk8--;
                    }
                }
            } else {
                s32 i;
                u16 *ids = func_80061904(arg1);
                u16 *p = ids + 1;
                u16 n = ids[0];

                for (i = 0; i < n; i++, p++) {
                    func_8005F634(*p);
                }
            }
            break;
        case 0x4:
        case 0x5:
            func_8005FD44(func_80061904(arg1), op);
            break;
        case 0xA: {
            u16 *ids = func_80061904(arg1);
            u16 *pid = ids + 1;
            s32 i = 0;
            u16 n = *ids;

            while (1) {
                s32 id;
                s16 type;

                if (i >= n) {
                    break;
                }
                id = *pid;
                type = *D_800DACB0[id];
                if (type == 1 || type == 7) {
                    Obj601A0 *q;

                    for (q = D_800DDC60; q != NULL; q = q->next) {
                        if (q->unk15E == id) {
                            q->unk50 |= 1;
                        }
                    }
                    for (q = D_800D6180; q != NULL; q = q->next) {
                        if (q->unk15E == id) {
                            q->unk50 |= 1;
                        }
                    }
                }
                i++;
                pid++;
            }
            break;
        }
        case 0xD:
            func_8005F798(arg1, s[0]);
            s++;
            break;
        case 0xB:
            func_8005F974(arg1, 0);
            break;
        case 0xC:
            func_8005F974(arg1, 1);
            break;
        case 0x77:
            s = (u16 *)skip_str((u8 *)s);
            break;
        case 0xAA:
            D_800D619C = *s;
            s++;
            break;
        case 0xA6:
            D_800D8438 = *s;
            s++;
            break;
        case 0xA9:
            D_800D843A = *s;
            s++;
            break;
        case 0xAD:
            if (D_800DE144 != NULL) {
                D_800DE144->unk4EC = D_800DE144->unk4B4;
            }
            break;
        case 0xA7:
            if (D_800DE144 != NULL) {
                func_800792A0(D_800DE144, s[0], s[1]);
            }
            s += 2;
            break;
        case 0xA8:
            if (D_800DE144 != NULL) {
                D_800DE144->unk544 = *s;
            }
            s++;
            break;
        case 0xAC:
            if (D_800DE144 != NULL) {
                D_800DE144->unk546 = *s;
            }
            s++;
            break;
        case 0x82:
            if (D_800DE144 != NULL) {
                func_80079324(D_800DE144, (s16)s[0], s[1]);
            }
            s += 2;
            break;
        case 0x87:
            if (D_800DE144 != NULL) {
                func_8007931C(D_800DE144, s[0], s[1]);
            }
            s += 2;
            break;
        case 0x8F:
            if (D_800DE144 != NULL) {
                func_80079314(D_800DE144, (s16)s[0], s[1]);
            }
            s += 2;
            break;
        case 0x90:
            if (D_800DE144 != NULL) {
                func_8007930C(D_800DE144, (s16)s[0], s[1]);
            }
            s += 2;
            break;
        case 0x91:
            if (D_800DE144 != NULL) {
                func_80079304(D_800DE144, (s16)s[0], s[1]);
            }
            s += 2;
            break;
        case 0x92:
            if (D_800DE144 != NULL) {
                func_800792FC(D_800DE144, (s16)s[0], s[1]);
            }
            s += 2;
            break;
        case 0x99:
            if (D_800DE144 != NULL) {
                func_80079434(D_800DE144, (s16)s[0]);
            }
            s++;
            break;
        case 0x9A:
            if (D_800DE144 != NULL) {
                func_8007942C(D_800DE144, (s16)s[0]);
            }
            s++;
            break;
        case 0xA4:
            if (D_800DE144 != NULL) {
                func_80079424(D_800DE144, (s16)s[0]);
            }
            s++;
            break;
        case 0xA5:
            if (D_800DE144 != NULL) {
                func_8007941C(D_800DE144, (s16)s[0]);
            }
            s++;
            break;
        case 0xA0:
            if (D_800DE144 != NULL) {
                D_800DE144->unk5B0 = *s;
            }
            s++;
            break;
        case 0xA1:
            if (D_800DE144 != NULL) {
                func_80079414(D_800DE144, s[0]);
            }
            s++;
            break;
        case 0x93:
            D_800DE988 = *s;
            s++;
            break;
        case 0xAE:
            {
                Sk61A8 *o = D_800D61A8;

                if (o != NULL) {
                    s32 x = s[0];
                    s32 y = s[1];

                    o->unk99C = x;
                    o->unk9A0 = y;
                }
            }
            s += 2;
            break;
        case 0x8B:
            s += 2;
            break;
        case 0xAF:
            if (D_800D61A8 != NULL) {
                D_800D61A8->unk99C = 0;
            }
            break;
        }
    }
    if (pending != 0) {
        func_8005E5CC(p0, p1, p2);
    }
}
