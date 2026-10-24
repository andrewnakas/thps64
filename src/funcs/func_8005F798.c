/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* D3: apply written in both cases (cross-jumped; set/mask refs give set s1, i s2), func_800352A4 takes one arg, idx = *p++. */
#include "common.h"

typedef struct O5 {
    u8 pad[0x1C];
    struct O5 *next;
    u8 pad20[0x13E];
    u16 id;
} O5;

typedef struct L {
    s32 pad;
    struct L *next;
} L;

extern s32 D_800D61A0;
extern s16 **D_800DACB0;
extern O5 *D_800DC5A0;
extern L *D_800DE5AC;
extern s32 D_800DE7A8;
extern s32 D_800DE7AC;
extern s32 D_800DE9A8;
u16 *func_80061904(s32);
u16 *func_800352A4(s32);

void func_8005F798(s32 arg0, s32 arg1) {
    s32 set;
    s32 mask;
    s32 i;
    u16 *p;
    s32 cnt;
    s32 id;

    id = D_800D61A0;
    if (id == 0 || D_800DE9A8 == 1) {
        set = 0x41;
    } else if (id == D_800DE7A8) {
        set = 1;
    } else if (id == D_800DE7AC) {
        set = 0x40;
    }
    mask = ~set;
    if (arg1 != 0) {
        set = 0;
    } else {
        mask = -1;
    }
    i = 0;
    p = func_80061904(arg0);
    cnt = *p++;
    for (;; i++) {
        u16 idx;
        s16 *e;
        u16 *obj;
        if (i >= cnt) {
            break;
        }
        idx = *p++;
        e = D_800DACB0[idx];
        switch (*e) {
        case 5: {
            O5 *o;
            for (o = D_800DC5A0; o != NULL; o = o->next) {
                if (o->id == idx) {
                    obj = (u16 *)o;
                    *obj = (*obj & mask) | set;
                    break;
                }
            }
            break;
        }
        case 0x1F5: {
            L *l;
            for (l = D_800DE5AC; l != NULL; l = l->next) {
            }
            break;
        }
        case 2:
        case 9:
        case 0xC:
        case 0xE:
            e++;
            e = (s16 *)((u8 *)e + (*e * 2 + 2));
            if ((s32)e & 2) {
                e++;
            }
            obj = func_800352A4(*(s32 *)e);
            if (obj != NULL) {
                *obj = (*obj & mask) | set;
            }
            break;
        }
    }
}
