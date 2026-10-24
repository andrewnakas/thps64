/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 id;
    f32 val;
    void *obj;
} Item800A6AB0;

typedef struct {
    Item800A6AB0 *items;
    u8 count;
    u8 pad5[0x1B];
    f32 unk20;
} Obj800A6AB0;

extern s32 func_8009E6B4(void *, s32, s32);
extern void func_800A6A0C(void);
extern void *func_800B477C(void *, s32);
extern u8 D_800EA110[];
extern u8 D_800ECFE0[];

void func_800A6AB0(Obj800A6AB0 *arg0, s32 arg1, s32 *arg2, f32 *arg3) {
    Item800A6AB0 *it;
    s32 i;
    f32 k;

    func_800A6A0C();
    arg0->count = arg1;
    arg0->items = (Item800A6AB0 *)func_8009E6B4(D_800EA110, arg1 * sizeof(Item800A6AB0), 4);
    i = 0;
    k = 100.0f;
    while (1) {
        if (i >= arg0->count) break;
        it = &arg0->items[i];
        if (arg2 != NULL) {
            it->id = arg2[i];
        } else {
            it->id = -1;
        }
        if (it->id != -1) {
            it->obj = func_800B477C(D_800ECFE0, it->id);
            arg0->unk20 = *(f32 *)((u8 *)it->obj + 0x20);
        } else {
            it->obj = NULL;
        }
        if (arg3 != NULL) {
            it->val = arg3[i];
        } else {
            it->val = (f32)((i + 1) * (i + 1)) * k;
        }
        it->val = it->val * it->val;
        i++;
    }
}
