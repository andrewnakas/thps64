/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x66];
    u16 unk66;
} Inner;

typedef struct {
    Inner *unk0;
    u8 pad4[0xC];
    s32 unk10;
} Obj;

void func_8009E334(void *);
void func_8009ECF8(void *, s32);
void func_800BAC04(void *, s32);
extern u8 D_800EA110[];
extern u8 D_800EECF0[];

void func_8009BAD4(Obj *arg0, s32 arg1) {
    func_8009ECF8(D_800EA110, arg0->unk10);
    if (arg0->unk0 != NULL) {
        func_800BAC04(D_800EECF0, arg0->unk0->unk66);
    }
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
