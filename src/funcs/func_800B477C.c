/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 refs;
    u8 *obj;
} Entry;

extern u8 *func_8009E30C(s32);
extern Entry *func_800B46EC(s32, s32);
extern void func_800B4718(s32, u8 *);
extern void func_800B5A44(u8 *);
extern void func_800B5CA0(u8 *, s32);

u8 *func_800B477C(s32 arg0, s32 arg1) {
    Entry *e;
    u8 *p;

    e = func_800B46EC(arg0, arg1);
    if (e != NULL) {
        e->refs++;
        return e->obj;
    }
    p = func_8009E30C(0x3C);
    func_800B5A44(p);
    if (p != NULL) {
        func_800B5CA0(p, arg1);
        *(s32 *)(p + 0x30) = arg1;
        *(s32 *)(p + 0x34) = 1;
        *(u8 **)(p + 0x38) = p;
        func_800B4718(arg0, p + 0x28);
    }
    return p;

}
