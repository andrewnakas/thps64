/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} VecL800648AC;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} VecS800648AC;

typedef struct {
    u8 pad0[4];
    VecL800648AC pos;
    VecS800648AC rot;
    u8 pad16[0x84 - 0x16];
    VecL800648AC vel;
    u8 pad90[0x9C - 0x90];
    VecL800648AC acc;
    u8 padA8[0xB5 - 0xA8];
    u8 drag;
    u8 padB6[2];
    VecS800648AC avel;
    u8 padBE[0xCC - 0xBE];
    VecS800648AC aacc;
    u8 padD2[0xE0 - 0xD2];
    u8 adrag[0x100 - 0xE0];
    s16 f100;
    s16 f102;
    s16 f104;
    u8 pad106[0x2D0 - 0x106];
    u16 mode;
} Obj800648AC;

void func_80046A30(void *, void *);
void func_80046C1C(void *, void *);
void func_80046CB0(void *);
void func_80046D00(void *);
void func_800470E0(void *, void *);
void func_800472C0(void *, void *);
void func_800472F8(void *);

void func_800648AC(Obj800648AC *arg0) {
    s32 vx;
    s32 vy;
    s32 vz;
    s16 ax;
    s16 ay;
    s16 az;
    s16 tx;
    s16 ty;
    s16 tz;

    arg0->f104 = 0;
    arg0->f102 = 0;
    arg0->f100 = 0;
    if (arg0->mode == 0) {
        vx = arg0->vel.x + arg0->acc.x;
        vy = arg0->vel.y + arg0->acc.y;
        vz = arg0->vel.z + arg0->acc.z;
        if (vx >= -0x800 && vx <= 0x800) {
            vx = 0;
        }
        if (vy >= -0x800 && vy <= 0x800) {
            vy = 0;
        }
        if (vz >= -0x800 && vz <= 0x800) {
            vz = 0;
        }
        arg0->vel.x = vx;
        arg0->vel.y = vy;
        arg0->vel.z = vz;
        arg0->pos.x += vx;
        arg0->pos.y += vy;
        arg0->pos.z += vz;
        ax = arg0->avel.x;
        ay = arg0->avel.y;
        az = arg0->avel.z;
        arg0->rot.x = (arg0->rot.x + ax) & 0xFFF;
        arg0->rot.y = (arg0->rot.y + ay) & 0xFFF;
        arg0->rot.z = (arg0->rot.z + az) & 0xFFF;
        tx = ax + arg0->aacc.x;
        ax = tx;
        ty = ay + arg0->aacc.y;
        ay = ty;
        tz = az + arg0->aacc.z;
        az = tz;
        if (tx >= -1 && tx <= 1) {
            ax = 0;
        }
        if (ty >= -1 && ty <= 1) {
            ay = 0;
        }
        if (tz >= -1 && tz <= 1) {
            az = 0;
        }
        arg0->avel.x = ax;
        arg0->avel.y = ay;
        arg0->avel.z = az;
    } else if (arg0->mode == 1 || arg0->mode == 2) {
        func_800472C0(&arg0->vel, &arg0->acc);
        func_800470E0(&arg0->vel, &arg0->drag);
        func_800472F8(&arg0->vel);
        func_800472C0(&arg0->pos, &arg0->vel);
        func_80046C1C(&arg0->rot, &arg0->avel);
        func_80046D00(&arg0->rot);
        func_80046C1C(&arg0->avel, &arg0->aacc);
        func_80046A30(&arg0->avel, arg0->adrag);
        func_80046CB0(&arg0->avel);
    }
}
