/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} IVec5EDD0;

typedef struct {
    s16 x, y, z;
} SVec5EDD0;

typedef struct Obj5EDD0 {
    u8 pad0[4];
    IVec5EDD0 pos;
    SVec5EDD0 rot;
    u8 pad16[6];
    struct Obj5EDD0 *next;
    u8 pad20[0x16C - 0x20];
    IVec5EDD0 pos2;
    u8 pad178[0x2B4 - 0x178];
    IVec5EDD0 pos3;
    u8 pad2C0[0x8D0 - 0x2C0];
    u8 unk8D0[1];
} Obj5EDD0;

SVec5EDD0 *func_800617B8(IVec5EDD0 *, s32);
void func_8005EC14(IVec5EDD0 *);
void func_8005EB20(Obj5EDD0 *);
void func_800601A0(char *, s32, s32);
void func_80046F58(IVec5EDD0 *, void *, s32 *);
void func_800472C0(IVec5EDD0 *, IVec5EDD0 *);
s32 func_80049034(char *, char *, s32);
extern s32 D_800DACAC;
extern Obj5EDD0 *D_800D61A8;
extern s32 D_800DE7A0;
extern s32 D_800C0E20;
extern s32 D_800DE9A8;
extern s32 D_800DACB4;
extern s16 **D_800DACB0;
extern char D_8001C72C[];

void func_8005EDD0(void) {
    IVec5EDD0 pos;
    IVec5EDD0 pos2;
    IVec5EDD0 pos3;
    s32 tmp;
    SVec5EDD0 *r;
    Obj5EDD0 *o;
    Obj5EDD0 *p;
    u8 *s;
    s32 i;
    IVec5EDD0 *pp;

    r = func_800617B8(&pos, D_800DACAC);
    {
        Obj5EDD0 *cur;
        cur = D_800D61A8;
        while (1) {
            p = cur;
            if (cur == NULL) {
                break;
            }
            cur->pos = pos;
            cur->pos2 = pos;
            cur->pos3 = pos;
            cur->rot = *r;
            if (D_800DE7A0 == 7 || D_800C0E20 == 8) {
                func_8005EC14(&cur->pos);
            }
            func_8005EB20(p);
            cur = cur->next;
        }
    }
    s = (u8 *)r + 6;
    while (*s != 0) {
        s++;
    }
    s++;
    func_800601A0((char *)(s + ((s32)s & 1)), D_800DACAC, 1);
    if (D_800DE9A8 == 2 && D_800DE7A0 != 7) {
        o = D_800D61A8;
        pp = &pos2;
        tmp = 100;
        func_80046F58(pp, o->unk8D0, &tmp);
        func_800472C0(&o->pos, pp);
        i = 0;
        while (1) {
            if (i >= D_800DACB4) {
                break;
            }
            if (*D_800DACB0[i] == 8) {
                if (func_80049034((char *)func_800617B8(&pos2, i) + 6, D_8001C72C, -1) != 0) {
                    SVec5EDD0 *rot = func_800617B8(&pos3, i);
                    o->pos = pos3;
                    o->pos2 = pos3;
                    o->rot = *rot;
                    func_8005EB20(o);
                }
            }
            i++;
        }
    }
}
