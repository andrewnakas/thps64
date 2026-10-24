/* cflags: -O2 */
#include "common.h"

typedef struct Blk {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Blk;

typedef struct {
    Blk *unk0;
    Blk *unk4;
    Blk *unk8;
    u8 padC[4];
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Heap;

void func_8009E0F0(s32, s32);
s32 func_8009E358(s32, s32);
void func_80001EC0(s32, s32, s32);
void func_80005070(s32, s32, s32);
void func_80004ED0(s32, s32, s32);
void func_8009EFF8(Heap *, s32);

void func_8009E3A0(Heap *arg0, s32 base, s32 size) {
    struct {
        s32 mq;
        s32 unk4;
    } lk;
    s32 p;
    s32 q;
    s32 mq;
    Blk *b;

    func_8009E0F0(base, 0);
    p = (base + 3) & ~3;
    q = p + 0x1C;
    size -= q - base;
    arg0->unk14 = p;
    mq = func_8009E358(0x1C, p);
    func_80001EC0(mq, mq + 0x18, 1);
    lk.mq = arg0->unk14;
    func_80005070(lk.mq, 0, 1);
    b = (Blk *)((p + 0x1F) & ~3);
    size -= (s32)b - q;
    size &= ~3;
    b->unk4 = 0;
    b->unk0 = 0;
    b->unkC = 0;
    b->unk8 = 0;
    b->unk10 = 0x1C;
    b->unk14 = size - 0x1C;
    arg0->unk18 = 0;
    b->unk18 = 0;
    arg0->unk8 = b;
    if (b->unk14 != 0) {
        arg0->unk4 = b;
        arg0->unk0 = b;
    } else {
        arg0->unk4 = NULL;
        arg0->unk0 = NULL;
    }
    arg0->unk10 = -1;
    func_8009EFF8(arg0, 1);
    func_80004ED0(lk.mq, 0, 1);
}
