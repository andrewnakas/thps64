/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* cflags: -fexpensive-optimizations */
#include "common.h"

typedef struct {
    s32 x, y, z, w;
} Q6168;

typedef struct {
    u8 pad0[0x18];
    Q6168 q;
    u8 pad28[0x34 - 0x28];
    u16 unk34;
} Cam6168;

void func_800673B0(Q6168 *, Q6168 *, Q6168 *);
void func_800676D0(Q6168 *, s32);
void func_800677F8(Q6168 *, s32);
void func_80067920(Q6168 *, s32);
void func_8006F9F8(s32, s32, char *, s32, s32, s32, s32);
void func_80078778(void *, s32, s32, s32, s32, s32);
void func_80078A1C(s32, s32, s32, s32, s32);
extern char D_8001DE54[];
extern char D_8001DE5C[];
extern u8 D_800D4B6C;
extern u8 D_800D4B7C;
extern u8 D_800D4B8C;
extern u8 D_800D4B9C;
extern u8 D_800D4BCC;
extern u8 D_800D4BDC;
extern u8 D_800D4BED;
extern u8 D_800D4BFD;
extern u8 D_800D4C0D;
extern u8 D_800D4C1D;
extern u16 D_800DE180;
extern u16 D_800DE182;

#define ROTATE(cam, fn, ang)                \
    {                                       \
        Q6168 *_q = &(cam)->q;              \
        Q6168 *_r = &r;                     \
        fn(_r, ang);                        \
        func_800673B0(&t, _q, _r);          \
        (cam)->q = t;                       \
    }

void func_80076168(u8 *arg0) {
    Q6168 t;
    Q6168 r;
    Cam6168 *cam;

    func_80078A1C(0x64, 0x32, 0xC8, 0xC8, 0xC8);
    func_8006F9F8(0xC8, 0x28, D_8001DE54, 0xC8, 0xC8, 0xC8, 0);
    func_80078778(arg0 + 0x20C, 0xC8, 0x32, 0x50, 0, 0);
    func_8006F9F8(0x12C, 0x28, D_8001DE5C, 0xC8, 0xC8, 0xC8, 0);
    func_80078778(arg0 + 0x404, 0x12C, 0x32, 0x50, 0, 0);
    if (D_800D4BFD != 0) {
        switch (D_800DE182) {
        case 0:
            D_800DE182 = 1;
            break;
        case 1:
            D_800DE182 = 1;
            break;
        }
        D_800D4BFD = 0;
    }
    if (D_800D4BED != 0) {
        switch (D_800DE182) {
        case 0:
            D_800DE182 = 0;
            break;
        case 1:
            D_800DE182 = 0;
            break;
        }
        D_800D4BED = 0;
    }
    if (D_800D4C1D != 0) {
        switch (D_800DE180) {
        case 0:
            D_800DE180 = 1;
            break;
        case 1:
            D_800DE180 = 2;
            break;
        case 2:
            D_800DE180 = 3;
            break;
        case 3:
            D_800DE180 = 5;
            break;
        case 5:
            D_800DE180 = 6;
            break;
        case 6:
            D_800DE180 = 8;
            break;
        case 8:
            D_800DE180 = 9;
            break;
        case 9:
            D_800DE180 = 10;
            break;
        case 10:
            D_800DE180 = 0;
            break;
        }
        D_800D4C1D = 0;
    }
    if (D_800D4C0D != 0) {
        switch (D_800DE180) {
        case 0:
            D_800DE180 = 10;
            break;
        case 1:
            D_800DE180 = 0;
            break;
        case 2:
            D_800DE180 = 1;
            break;
        case 3:
            D_800DE180 = 2;
            break;
        case 5:
            D_800DE180 = 3;
            break;
        case 6:
            D_800DE180 = 5;
            break;
        case 8:
            D_800DE180 = 6;
            break;
        case 9:
            D_800DE180 = 8;
            break;
        case 10:
            D_800DE180 = 9;
            break;
        }
        D_800D4C0D = 0;
    }
    switch (D_800DE182) {
    case 0:
        cam = (Cam6168 *)(arg0 + 0x20C);
        break;
    case 1:
        cam = (Cam6168 *)(arg0 + 0x404);
        break;
    }
    if (D_800D4B6C != 0) {
        switch (D_800DE180) {
        case 5:
            ROTATE(cam, func_800676D0, 10);
            break;
        case 6:
            cam->unk34 -= 10;
            break;
        }
    }
    if (D_800D4B9C != 0) {
        switch (D_800DE180) {
        case 5:
            ROTATE(cam, func_800676D0, -10);
            break;
        case 6:
            cam->unk34 += 10;
            break;
        }
    }
    if (D_800D4B7C != 0 && D_800DE180 == 5) {
        ROTATE(cam, func_800677F8, -10);
    }
    if (D_800D4B8C != 0 && D_800DE180 == 5) {
        ROTATE(cam, func_800677F8, 10);
    }
    if (D_800D4BCC != 0 && D_800DE180 == 5) {
        ROTATE(cam, func_80067920, 10);
    }
    if (D_800D4BDC != 0 && D_800DE180 == 5) {
        ROTATE(cam, func_80067920, -10);
    }
}
