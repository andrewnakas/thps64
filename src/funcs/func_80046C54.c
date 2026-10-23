#include "common.h"

extern void func_800433E4(s32 *);
extern void func_80043288(void);
extern void func_80043264(s32 *);
extern void func_800233B8(s32);

void func_80046C54(s16 *a) {
    s32 v[3];

    v[0] = a[0];
    v[1] = a[1];
    v[2] = a[2];
    func_800433E4(v);
    func_80043288();
    func_80043264(v);
    func_800233B8(v[0] + v[1] + v[2]);
}
