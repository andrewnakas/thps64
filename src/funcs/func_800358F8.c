/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct { s16 delta; s16 idx; void (*fn)(void *, s32); } VEnt;
typedef struct { u8 pad[8]; VEnt e; } VTbl;
typedef struct { u8 pad[0x48]; VTbl *vt; } VObj;

extern char D_80019DF0[];
typedef struct { u8 pad[0x1AC]; u8 x[4]; } S3130;
extern S3130 D_800D3130;
extern VObj *D_800DE7A8;
extern VObj *D_800DE7AC;
extern s32 D_800E929C;
extern u8 *D_800DE96C;
extern u8 *D_800DE970;
extern u8 *D_800DE974;
extern u8 *D_800DE978;
extern u8 *D_800DE97C;
void func_8008BB50(void *);
void func_800A73EC(void *, s32);
void func_8008B490(void *, void *, s32);
void func_80033A58(void);
void func_8008BB2C(void *, s32);
void func_8002C0E4(void *, s32);
void func_800394A8(void *, s32);

void func_800358F8(u8 *arg0, s32 arg1) {
    s32 buf[2];
    u8 *p;

    *(char **)(arg0 + 0x2C) = D_80019DF0;
    func_8008BB50(buf);
    {
        S3130 *q = &D_800D3130;
        p = q->x;
    }
    func_800A73EC(p, 0x501);
    func_8008B490(buf, p, 0x501);
    if (D_800DE7A8 != 0) {
        D_800DE7A8->vt->e.fn((u8 *)D_800DE7A8 + D_800DE7A8->vt->e.delta, 3);
    }
    if (D_800DE7AC != 0) {
        D_800DE7AC->vt->e.fn((u8 *)D_800DE7AC + D_800DE7AC->vt->e.delta, 3);
    }
    D_800DE7A8 = 0;
    D_800DE7AC = 0;
    D_800E929C = 0;
    if (D_800DE96C != 0) *(s16 *)(D_800DE96C + 0x230) = 1;
    if (D_800DE970 != 0) *(s16 *)(D_800DE970 + 0x230) = 1;
    if (D_800DE974 != 0) *(s16 *)(D_800DE974 + 0x230) = 1;
    if (D_800DE978 != 0) *(s16 *)(D_800DE978 + 0x230) = 1;
    if (D_800DE97C != 0) *(s16 *)(D_800DE97C + 0x230) = 1;
    func_80033A58();
    func_8008BB2C(buf, 2);
    func_8002C0E4(arg0 + 0x58, 2);
    func_800394A8(arg0, arg1);
}
