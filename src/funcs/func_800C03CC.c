/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x68];
    s16 delta;
    s16 pad6A;
    void (*fn)(u8 *);
} VT;

extern void func_8009E3A0(void *, s32, s32);
extern void func_800C0710(s32, s32);
extern void func_800A011C(s32);
extern void func_80004540(s32, s32);
extern s32 D_80000300;
extern s32 D_80000318;
extern s32 D_800F56BC;
extern s32 D_800F56C0;
extern u8 D_800EA110[];
extern u8 D_800FC970[];
extern u8 D_80000870[];
extern u8 D_80000870_end[];
extern u8 D_800222C0[];
extern u8 D_80022360[];
extern u8 *D_800F5660;
extern s32 D_800F6260;

void func_800C03CC(s32 arg0) {
    u8 *o;
    VT *vt;
    s32 size;

    D_800F56BC = D_80000300;
    size = D_80000318;
    D_800F56C0 = size;
    func_8009E3A0(D_800EA110, (s32)D_800FC970, size - ((s32)D_800FC970 - 0x80000000));
    func_800C0710((s32)D_80000870, (s32)D_80000870_end);
    func_800C0710((s32)D_800222C0, (s32)D_80022360);
    func_800A011C(arg0);
    o = D_800F5660;
    vt = *(VT **)(o + 0x1C4);
    vt->fn(o + vt->delta);
    func_80004540(D_800F6260, 0);
    while (1) {
    }
}
