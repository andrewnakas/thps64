/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 x, y, z;
} Ref_80078778;

typedef struct {
    s32 unk0;
    Ref_80078778 *ref;
    s32 x, y, z;
    u8 pad14[0x14];
    s32 vx, vy, vz;
    s16 ang;
} Obj_80078778;

void func_8006F280(u16, u16, s32, u8, u8, u8, s32);
void func_8006F9F8(u16, u16, char *, u8, u8, u8, s32);
extern char D_8001DF0C[];
extern char D_8001DF14[];
extern char D_8001DF1C[];

void func_80078778(o, x, y, c0, c1, c2)
    Obj_80078778 *o; u16 x; u16 y; u8 c0; u8 c1; u8 c2;
{
    if (o->unk0 != 0) {
        func_8006F9F8(x, y, D_8001DF0C, c0, c1, c2, 0);
        func_8006F280(x, y + 8, o->ref->x >> 12, c0, c1, c2, 0);
        func_8006F280(x, y + 16, o->ref->y >> 12, c0, c1, c2, 0);
        func_8006F280(x, y + 24, o->ref->z >> 12, c0, c1, c2, 0);
    } else {
        func_8006F9F8(x, y, D_8001DF14, c0, c1, c2, 0);
        func_8006F280(x, y + 8, o->x >> 12, c0, c1, c2, 0);
        func_8006F280(x, y + 16, o->y >> 12, c0, c1, c2, 0);
        func_8006F280(x, y + 24, o->z >> 12, c0, c1, c2, 0);
    }
    func_8006F9F8(x, y + 40, D_8001DF1C, c0, c1, c2, 0);
    func_8006F280(x, y + 48, o->ang, c0, c1, c2, 0);
    func_8006F280(x, y + 64, o->vx >> 12, c0, c1, c2, 0);
    func_8006F280(x, y + 72, o->vy >> 12, c0, c1, c2, 0);
    func_8006F280(x, y + 80, o->vz >> 12, c0, c1, c2, 0);
}
