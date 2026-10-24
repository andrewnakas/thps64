/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec34C44;

typedef struct {
    u8 pad0[0x3A];
    s16 unk3A;
} Hit34C44;

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[0x58 - 8];
} Obj34C44;

Hit34C44 *func_80038F9C(Obj34C44 *, s32);
void func_8009CC10(f32 *, f32);
void func_8009D624(f32 *, f32);
void func_8009D8B4(f32 *, Vec34C44 *);
void func_800A4DD0(void *);
void func_800B4A08(void *, s32, s32, s32, s32, s32, s32);
s32 func_800C000C(f32 *);
extern s32 D_800D36D0;
extern s32 D_800ECFE0;
extern s32 D_800F5628;
extern s32 D_800F65E0;
extern Obj34C44 D_800FA140[];
extern f32 D_800FA590;

void func_80034C44(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 m[12];
    Vec34C44 pos;
    Vec34C44 t;
    Vec34C44 sc;
    Obj34C44 *found;
    Hit34C44 *hit;
    Obj34C44 **pf;
    Hit34C44 **ph;
    Obj34C44 *p;
    s32 i;
    s32 ok;
    s32 *d;
    s32 r;
    f32 z;

    func_800A4DD0(&D_800F65E0);
    D_800F5628 = 0;
    func_8009CC10(m, arg5 + arg4 * (D_800FA590 * 6.2831855f));
    func_8009D624(m, 3.1415927f);
    z = 40.0f;
    t.x = arg1;
    t.y = arg2;
    t.z = z;
    pos = t;
    sc.x = arg3;
    sc.y = arg3;
    sc.z = arg3;
    func_8009D8B4(m, &sc);
    pf = &found;
    ph = &hit;
    i = 0;
    if (i < D_800D36D0) {
        do {
            *pf = &D_800FA140[i];
            ok = 1;
            if ((*ph = func_80038F9C(&D_800FA140[i], arg0)) != NULL) {
                goto done;
            }
            i++;
        } while (i < D_800D36D0);
    }
    ok = 0;
done:
    if (ok) {
        r = func_800C000C(m);
        d = &D_800ECFE0;
        func_800B4A08(d, found->unk4, hit->unk3A, r, -1, 0, 0);
    }
}
