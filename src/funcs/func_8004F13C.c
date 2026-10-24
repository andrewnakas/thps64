/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 key;
    s32 anim;
    s32 unk8;
    s32 padC;
    s32 len;
    s32 unk14;
    s32 pad18[2];
    s32 unk20;
    s32 unk24;
    s32 unk28;
} Move4F13C;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x154 - 0x10];
} Char4F13C;

typedef struct {
    u8 pad0[0x10];
    u8 b10;
    u8 pad11[0xF];
    u8 b20;
    u8 pad21[0x5F];
    u8 b80;
    u8 pad81[0xF];
    u8 b90;
    u8 pad91[0xF];
    u8 bA0;
    u8 padA1[0xF];
    u8 bB0;
} Pad4F13C;

typedef struct {
    u8 pad0[0x208];
    s32 unk208;
    u8 pad20C[0x21C - 0x20C];
    s16 h21C;
    u16 hu21E;
    u8 pad220;
    s8 b221;
    u8 pad222[4];
    u8 b226;
    u8 b227;
    s32 unk228;
    u8 pad22C[0x2E4 - 0x22C];
    s32 unk2E4;
    u8 pad2E8[0x2F8 - 0x2E8];
    s32 unk2F8;
    u8 pad2FC[0x34C - 0x2FC];
    s32 unk34C;
    u8 pad350[4];
    s32 unk354;
    s32 unk358;
    s32 unk35C;
    s32 unk360;
    s32 unk364;
    s32 unk368;
    s32 unk36C;
    s32 unk370;
    s32 unk374;
    s32 unk378;
    s32 unk37C;
    s32 unk380;
    u8 pad384[0x3E0 - 0x384];
    s32 unk3E0;
    u8 pad3E4[4];
    s32 unk3E8;
    s32 unk3EC;
    u8 pad3F0[0x41C - 0x3F0];
    s32 unk41C;
    u8 pad420[0x440 - 0x420];
    s32 unk440;
    u8 pad444[0x450 - 0x444];
    s32 unk450;
    s32 unk454;
    s32 unk458;
    s32 unk45C;
    s32 unk460;
    s32 unk464;
    s32 unk468;
    s32 unk46C;
    s32 btn[10];
    s32 mode[10];
    s32 btnTime[10];
    s32 modeTime[10];
    u8 pad510[0x51C - 0x510];
    s32 unk51C;
    u8 pad520[0x7D4 - 0x520];
    s32 unk7D4;
    u8 pad7D8[0x818 - 0x7D8];
    s32 unk818;
    s32 unk81C;
    s32 unk820;
    u8 pad824[0x82C - 0x824];
    s32 unk82C;
    u8 pad830[0x838 - 0x830];
    s32 unk838;
    u8 pad83C[0x964 - 0x83C];
    Pad4F13C *pad;
    u8 pad968[0x98C - 0x968];
    s8 stickX;
    s8 stickY;
} Sk4F13C;

s32 func_8004D2D4(Sk4F13C *);
void func_8004A204(Sk4F13C *, s32, s32, s32, s32);
void func_8004F030(Sk4F13C *);
void func_8004EF10(Sk4F13C *);
extern s32 D_800DE994;
extern Char4F13C D_800D4D80[];
extern Move4F13C D_800D63F8[];
extern Move4F13C D_800D6978[];

static inline void play4F13C(Sk4F13C *s, s32 anim, s32 a, s32 len) {
    func_8004D2D4(s);
    func_8004A204(s, anim, a, len, -1);
}

static inline void flags4F13C(Sk4F13C *s, Move4F13C *m) {
    u32 f;

    f = m->key & 0xFFF00000;
    s->unk37C = (f >> 20) & 1;
    s->unk380 = (f >> 21) & 1;
    s->unk2E4 = (f >> 26) & 1;
    if (s->unk37C != 0) {
        s->unk41C = 0;
    }
    if (f & 0x800000) {
        s->unk460 = (((s->unk460 & 0xFFFFFF) | 0x80000000) & ~0x4000) | 0x2000;
    }
    s->unk3E8 = (f >> 24) & 1;
    s->unk3EC = (f >> 22) & 1;
}

static inline void start4F13C(Sk4F13C *s) {
    s32 k;

    s->unk440 = D_800DE994;
    s->unk454 = 1;
    s->unk45C = 0;
    s->unk458 = 0;
    k = s->unk464;
    s->mode[k] = 0;
    s->btn[k] = 0;
    s->unk464++;
    if (s->unk464 == 10) {
        s->unk464 = 0;
    }
}

void func_8004F13C(Sk4F13C *s) {
    Pad4F13C *pad;
    s32 btn;
    s32 dir;
    s32 mode;
    s32 i;
    s32 j;
    s32 k;
    s32 key;
    s32 f;
    s32 id;
    s32 top;
    s32 len;
    Move4F13C *e;
    Move4F13C *e2;

    if (s->unk454 == 0 && s->unk838 == 0) {
        s->unk51C = 0;
    }
    if (s->unk2F8 != 0) {
        s->unk2F8--;
        return;
    }
    if (s->unk81C != 0) {
        return;
    }
    pad = s->pad;
    btn = pad->bA0 + pad->bB0 * 2 + pad->b80 * 4 + pad->b90 * 8;
    if (s->stickY < -40) {
        btn |= 1;
    }
    if (s->stickY > 40) {
        btn |= 2;
    }
    if (s->stickX < -40) {
        btn |= 4;
    }
    if (s->stickX > 40) {
        btn |= 8;
    }
    if (btn != 0) {
        if (s->unk378 != 0) {
            if (s->unk374 != 0) {
                s->unk354 = s->unk360;
                s->unk358 = s->unk364;
                s->unk35C = s->unk368;
                s->unk360 = s->unk370;
                s->unk364 = s->unk36C;
                s->unk368 = s->unk374;
                s->unk36C = 0;
                s->unk374 = 0;
            }
            if (s->unk36C == 0) {
                s->unk370 = btn;
                s->unk36C = D_800DE994;
                s->unk374 = 0;
            }
        }
        s->btn[s->unk468] = btn;
        s->btnTime[s->unk468] = D_800DE994;
        if (s->mode[s->unk468] != 0 && D_800DE994 - s->modeTime[s->unk468] >= 21) {
            s->mode[s->unk468] = 0;
        }
    } else if (s->unk36C != 0 && s->unk374 == 0) {
        s->unk374 = D_800DE994;
    } else {
        s->unk378 = 1;
    }
    if (s->unk450 != 0) {
        s->unk46C = 0;
        return;
    }
    if (s->unk838 == 0 || s->unk82C == 4 || s->unk82C == 5 || s->unk82C == 8) {
        s->unk46C = 0;
        return;
    }
    mode = s->pad->b20 + s->pad->b10 * 2;
    if (mode != 0) {
        s->mode[s->unk468] = mode;
        s->modeTime[s->unk468] = D_800DE994;
        if (s->btn[s->unk468] != 0 && D_800DE994 - s->btnTime[s->unk468] >= 21) {
            s->btn[s->unk468] = 0;
        }
    }
    if (mode == 0 && s->unk46C > 0) {
        k = s->unk468;
        s->btn[k] = 0;
        s->mode[k] = 0;
        s->unk46C--;
    }
    if (s->btn[s->unk468] != 0 && s->mode[s->unk468] != 0 && s->unk46C == 0) {
        if (s->unk368 != 0 && s->unk368 < (f = s->btnTime[s->unk468]) && s->unk368 - s->unk364 < 20 &&
            (top = f - s->unk368) < 30) {
            s->btn[s->unk468] |= s->unk360 << 4;
        }
        s->unk35C = 0;
        s->unk358 = 0;
        s->unk378 = 0;
        s->unk374 = 0;
        s->unk368 = 0;
        s->unk36C = 0;
        s->unk364 = 0;
        s->unk468++;
        if (s->unk468 == 10) {
            s->unk468 = 0;
        }
        k = s->unk468;
        s->mode[k] = 0;
        s->btn[k] = 0;
        s->unk46C = 3;
    }
    if (s->unk464 != s->unk468 && (s->unk454 == 0 || s->unk458 != 0)) {
        j = s->unk464;
        btn = s->btn[j] & 0xF;
        dir = s->btn[j] >> 4;
        mode = s->mode[j];
        if (s->unk34C == 0) {
            dir = 0;
        }
        if (dir != 0) {
            key = D_800D4D80[s->unk3E0].unkC + (dir << 8) + (btn << 4) + mode;
            e = D_800D6978;
            i = 0x20;
            while (1) {
                if (e->key <= 0) {
                    break;
                }
                if ((e->key & 0xFFFFF) == key) {
                    s->unk228 = e->unk8;
                    if (mode == 2) {
                        s->unk460 = i | 0x2000;
                    } else {
                        s->unk460 = i | 0x4000;
                    }
                    if (e->len != 0) {
                        play4F13C(s, e->anim, 0, e->len);
                        s->unk460 |= 0x40000000;
                    } else {
                        play4F13C(s, e->anim, 0, -1);
                        if (mode == 2) {
                            s->unk460 |= 0x80000000;
                        } else {
                            s->unk460 |= 0x20000000;
                        }
                    }
                    flags4F13C(s, e);
                    s->unk818 = e->unk20;
                    s->unk820 = e->unk24;
                    if (s->unk820 < 0) {
                        s->unk818++;
                    }
                    s->unk81C = 0;
                    if (s->unk208 & 2) {
                        s->unk41C -= e->unk28;
                    } else {
                        s->unk41C += e->unk28;
                    }
                    start4F13C(s);
                    break;
                }
                i++;
                e++;
            }
            if (e->key == -1) {
                dir = 0;
            }
        }
        if (dir != 0) {
        } else if ((mode & 1) && D_800D63F8[btn].anim != 0x4E) {
            btn += 0x10;
            e2 = &D_800D63F8[btn];
            s->unk228 = e2->unk8;
            s->unk460 = btn | 0x4000;
            if (e2->len != 0) {
                play4F13C(s, e2->anim, 0, e2->len);
                s->unk460 |= 0x40000000;
            } else {
                play4F13C(s, e2->anim, 0, -1);
                s->unk460 |= 0x20000000;
            }
            start4F13C(s);
            flags4F13C(s, &D_800D63F8[btn]);
        } else if (dir == 0 && (mode & 2) && D_800D63F8[btn].anim != 0x4E) {
            s->unk228 = D_800D63F8[btn].unk8;
            s->unk460 = btn | 0x2000;
            if (D_800D63F8[btn].len != 0) {
                play4F13C(s, D_800D63F8[btn].anim, 0, D_800D63F8[btn].len);
                s->unk460 |= 0x40000000;
            } else {
                play4F13C(s, D_800D63F8[btn].anim, 0, -1);
                s->unk460 |= 0x80000000;
            }
            start4F13C(s);
            flags4F13C(s, &D_800D63F8[btn]);
        }
    }
    if (s->unk454 == 0) {
        return;
    }
    id = s->unk460 & 0xFF;
    top = s->unk460 & 0xFF000000;
    if (top == 0x20000000 && s->b227 != 0) {
        s->unk458 = 1;
    }
    if (top == 0x40000000 && s->b227 != 0) {
        s->unk458 = 1;
    }
    if (s->b221 == -1) {
        s->unk458 = 1;
    } else {
        if ((s->unk460 & 0x4000) && D_800D63F8[id].len != 0 && s->h21C >= s->b226 - D_800D63F8[id].unk14 - 1) {
            s->unk458 = 1;
        }
        if ((s->unk460 & 0x2000) && s->h21C >= s->b226 - D_800D63F8[id].unk14 - 1) {
            s->unk458 = 1;
        }
    }
    if (s->unk458 != 0) {
        func_8004F030(s);
        s->unk45C = 1;
    }
    if (s->unk2E4 == 0) {
        func_8004EF10(s);
    }
    if (s->b227 == 0) {
        return;
    }
    f = s->unk460;
    id = f & 0xFF;
    top = f & 0xFF000000;
    switch (top) {
    case 0x40000000:
        if (f & 0x4000) {
            if (s->pad->b20 != 0) {
                s->unk460 = f | 0x800;
            }
            if (s->pad->b20 == 0) {
                s->unk460 &= ~0x800;
            }
            if (s->unk460 & 0x800) {
                return;
            }
            if (s->h21C <= (len = D_800D63F8[id].len)) {
                goto call;
            }
            goto end;
        } else {
            if (s->pad->b10 != 0) {
                s->unk460 = f | 0x800;
            }
            if (s->pad->b10 == 0) {
                s->unk460 &= ~0x800;
            }
            if (s->unk460 & 0x800) {
                return;
            }
            if (s->h21C > (len = D_800D63F8[id].len)) {
                goto end;
            }
        }
    call:
        play4F13C(s, s->hu21E, len, -1);
        return;
    case 0x20000000:
        if (s->pad->b20 != 0) {
            s->unk460 = f | 0x800;
        }
        if (s->pad->b20 == 0) {
            s->unk460 &= ~0x800;
        }
        if (s->unk460 & 0x800) {
            return;
        }
        if (!(s->unk460 & 0x400)) {
            play4F13C(s, s->hu21E, s->h21C, 0);
            s->unk460 |= 0x400;
            return;
        }
    case 0x80000000:
    end:
        if (s->unk7D4 != 0) {
            return;
        }
        s->unk228 = 0x10000;
        play4F13C(s, 0xE, 0, -1);
        s->unk454 = 0;
        return;
    }
}
