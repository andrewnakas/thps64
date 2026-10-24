/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Base;

typedef struct {
    Base base;
    u8 sub[0x28];
} Big;

void func_800B2860(void *);
void func_800C05C0(Base *, s32);
extern Base D_800F566C;
extern Base D_800F5678;
extern Big D_800F5684;

void func_800C0534(void) {
    func_800C05C0(&D_800F566C, 0);
    D_800F566C.unk8 = 0;
    func_800C05C0(&D_800F5678, 0);
    D_800F5678.unk8 = 0;
    func_800C05C0(&D_800F5684.base, 0);
    func_800B2860(D_800F5684.sub);
    D_800F5684.base.unk8 = 0;
}
