/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -ffast-math */
#include "common.h"

typedef struct {
    s8 b0;
    s8 b1;
    u8 pad2[2];
    s32 v4;
    s32 v8;
    s32 vC;
} Btn437E8;

typedef struct {
    u16 key;
    u8 pad2[0xE];
    Btn437E8 *btn[2];
} Map437E8;

typedef struct {
    u8 pad0[0x168];
    s8 x;
    s8 y;
    u8 pad16A[2];
    s32 v16C;
    u8 pad170[0x18C - 0x170];
} Pad437E8;

typedef struct {
    u8 n;
    u8 pad1;
    u8 port[2];
} Ctl437E8;

s32 func_800B3CF0(u8);
f32 func_800B4200(s32, s32);
s32 func_800B4240(s32, u16);
s32 func_800B4264(s32, u16);
s32 func_800B42A8(s32, u16);
extern Ctl437E8 D_800D0FC0;
extern s32 D_800D49C4;
extern Pad437E8 D_800D49E0[];
extern Map437E8 D_800FA6B0[];

static inline void upd_(Btn437E8 *b, s32 pressed, s32 held, s32 released) {
    b->vC++;
    b->v8++;
    b->b0 = 0;
    b->b1 = 0;
    if (pressed) {
        D_800D49C4 = 0;
        b->b0 = 1;
        b->b1 = 1;
        b->vC = 0;
        b->v4 = 1;
    } else if (held) {
        D_800D49C4 = 0;
        b->b0 = 1;
        b->v8 = 0;
        b->v4++;
    } else if (released) {
        b->v4 = 0;
        b->v8 = 0;
    }
}

s32 func_800437E8(void) {
    s32 i;
    s32 j;
    s32 held;
    s32 pressed;
    s32 released;
    f32 fx;
    f32 fy;
    s32 ix;
    s32 iy;
    s32 a;

    D_800D49E0[0].v16C = 0x41;
    D_800D49E0[1].v16C = 0x41;
    if (func_800B3CF0(D_800D0FC0.port[0]) == 0) {
        D_800D49E0[0].v16C = 0;
    }
    if (func_800B3CF0(D_800D0FC0.port[1]) == 0) {
        D_800D49E0[1].v16C = 0;
    }
    i = 0;
    while (1) {
        if (i >= D_800D0FC0.n) {
            break;
        }
        j = 0;
        while (1) {
            if (j >= 14) {
                break;
            }
            held = func_800B4240(i, D_800FA6B0[j].key);
            pressed = func_800B4264(i, D_800FA6B0[j].key);
            released = func_800B42A8(i, D_800FA6B0[j].key);
            upd_(D_800FA6B0[j].btn[i], (u16)pressed, (u16)held, (u16)released);
            j++;
        }
        fx = func_800B4200(i, 0x78);
        fy = -func_800B4200(i, 0x79);
        fx = fx * (fx >= 0.0f ? fx : -fx);
        fy = fy * (fy >= 0.0f ? fy : -fy);
        ix = fx * (fx > 0.0 ? 127.0f : 128.0f);
        iy = fy * (fy > 0.0 ? 127.0f : 128.0f);
        a = (s8)iy;
        if (a < 0) {
            a = -a;
        }
        if (a >= 0x21) {
            D_800D49E0[i].x = iy;
        } else {
            D_800D49E0[i].x = 0;
        }
        a = (s8)ix;
        if (a < 0) {
            a = -a;
        }
        if (a >= 0x21) {
            D_800D49E0[i].y = ix;
        } else {
            D_800D49E0[i].y = 0;
        }
        if ((s8)ix != 0 || (s8)iy != 0) {
            if (D_800D49E0[i].x < 0) {
                D_800FA6B0[10].btn[i]->b1 = 1;
                D_800FA6B0[10].btn[i]->b0 = 1;
            }
            if (D_800D49E0[i].x > 0) {
                D_800FA6B0[11].btn[i]->b1 = 1;
                D_800FA6B0[11].btn[i]->b0 = 1;
            }
            if (D_800D49E0[i].y < 0) {
                D_800FA6B0[8].btn[i]->b1 = 1;
                D_800FA6B0[8].btn[i]->b0 = 1;
            }
            if (D_800D49E0[i].y > 0) {
                D_800FA6B0[9].btn[i]->b1 = 1;
                D_800FA6B0[9].btn[i]->b0 = 1;
            }
        }
        i++;
    }
    return 0;
}
