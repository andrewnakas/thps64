/* cflags: -O2 */
#include "common.h"

typedef struct {
    void *data;
    s32 size;
    s32 unk8;
    s32 owned;
    s32 unk10;
} Buf;

typedef struct {
    u8 pad0[8];
    s32 unk8;
    u8 padC[8];
    s32 unk14;
} BufList;

void *func_8009E8F0(void *, s32, s32);
void func_8009ECF8(void *, void *);
void func_80005720(void *, void *, s32);
void func_800B72A4(BufList *, Buf *);
extern u8 D_800EA110[];

s32 func_800B72C8(BufList *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *p;
    Buf *b;
    s32 id;

    if (arg2 == 0) {
        arg3 = 0;
    }
    if (arg3 != 0) {
        p = func_8009E8F0(D_800EA110, arg2, 4);
        if (p != NULL) {
            func_80005720(p, arg1, arg2);
        }
    } else {
        p = arg1;
    }
    if (p == NULL && arg2 != 0) {
        return -1;
    }
    b = func_8009E8F0(D_800EA110, sizeof(Buf), 4);
    if (b != NULL) {
        b->data = p;
        b->size = arg2;
        b->unk8 = arg4;
        b->owned = arg3;
        func_800B72A4(arg0, b);
        arg0->unk14 = 1;
        return arg0->unk8++;
    }
    if (arg3 != 0) {
        func_8009ECF8(D_800EA110, p);
    }
    return -1;
}
