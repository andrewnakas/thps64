/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 id;
    u8 pad8[2];
    u8 kind;
    u8 padB[0x20 - 0xB];
    s32 index;
    s32 flag;
} Ent800A2FE0;

typedef struct {
    u8 pad0[0x14];
    s32 count;
    u8 pad18[0x3EC - 0x18];
    u8 unk3EC[0x434 - 0x3EC];
    s32 unk434;
    u8 pad438[0x440 - 0x438];
    s32 unk440;
    u8 pad444[0x4B4 - 0x444];
    Ent800A2FE0 *ents;
    u8 pad4B8[0x4E4 - 0x4B8];
    s32 unk4E4;
} Obj800A2FE0;

extern s32 func_8000A9B0(s32, s32, Ent800A2FE0 *);
extern s32 func_8000B1D0(s32, s32 *);
extern s32 func_8000B320(s32, s32 *, s32 *);
extern s32 func_8000B470(void *, s32, s32);
extern void *func_8009E6B4(void *, s32, s32);
extern void func_800A0870(Obj800A2FE0 *, s32, s32);
extern void func_800A3194(Obj800A2FE0 *);
extern u8 D_800EA110[];

void func_800A2FE0(Obj800A2FE0 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4) {
    s32 total;
    s32 sel;
    s32 val;
    s32 r;
    s32 n;
    s32 i;
    Ent800A2FE0 *e;

    func_800A3194(arg0);
    r = func_8000B470(arg0->unk3EC, arg1, arg0->unk434);
    if (r != 0) {
        func_800A0870(arg0, r, 0);
        return;
    }
    r = func_8000B320(arg1, &total, &sel);
    if (arg4 != 0) {
        n = total;
        arg0->count = 0;
    } else {
        n = sel;
        arg0->count = 0;
    }
    if (r == 0) {
        arg0->ents = func_8009E6B4(D_800EA110, n * sizeof(Ent800A2FE0), 4);
        if (sel != 0) {
            i = 0;
            while (1) {
                if (i >= total) break;
                e = &arg0->ents[arg0->count];
                if (func_8000A9B0(arg1, i, e) == 0 && (arg2 != 0 || e->id == arg0->unk4E4) &&
                    (arg3 == NULL || e->kind == *arg3)) {
                    e->index = i;
                    e->flag = 1;
                    arg0->count++;
                } else if (arg4 != 0) {
                    e->index = i;
                    e->flag = 0;
                    arg0->count++;
                }
                i++;
            }
        }
    }
    if (func_8000B1D0(arg1, &val) == 0) {
        arg0->unk440 = val;
    } else {
        arg0->unk440 = 0;
    }
}
