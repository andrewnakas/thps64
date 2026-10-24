/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 type;
    s32 flags;
    void *ucode_boot;
    s32 ucode_boot_size;
    s32 ucode;
    s32 ucode_size;
    s32 ucode_data;
    s32 ucode_data_size;
    s32 dram_stack;
    s32 dram_stack_size;
    s32 output_buff;
    s32 output_buff_size;
    s32 data_ptr;
    s32 data_size;
    s32 yield_data_ptr;
    s32 yield_data_size;
    s64 unk40;
    u8 pad48[0x18];
    s64 unk60;
    s64 unk68;
    s64 unk70;
    s64 unk78;
    u8 pad80[0x38];
} AudTask;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} AudInfo;

typedef struct {
    u8 pad0[0x2314];
    s32 unk2314;
} Sched;

void func_80004ED0(s32, s32, s32);
void func_800BC6AC(Sched *, AudTask *, s32, AudInfo *);
extern u8 D_800988A0[];
extern u8 D_80098970[];
extern Sched D_800F0DD0;
extern s32 D_800FC674;

void func_800BB6B8(AudInfo *arg0) {
    AudTask t;
    AudTask *p;

    p = &t;
    if (D_800F0DD0.unk2314 == 0) {
        p->unk78 = 0;
        p->unk60 = 0;
        p->unk70 = 0;
        p->unk40 = 0;
        p->unk68 = 0;
        t.type = 2;
        t.flags = 0;
        t.ucode_boot = D_800988A0;
        t.ucode_boot_size = D_80098970 - D_800988A0;
        t.ucode = arg0->unk8;
        t.ucode_size = 0x1000;
        t.ucode_data = arg0->unkC;
        t.ucode_data_size = 0x800;
        t.dram_stack = 0;
        t.dram_stack_size = 0;
        t.output_buff = 0;
        t.output_buff_size = 0;
        t.data_ptr = arg0->unk0;
        t.data_size = arg0->unk4;
        t.yield_data_ptr = 0;
        t.yield_data_size = 0;
        func_800BC6AC(&D_800F0DD0, p, D_800FC674 + 0x30, arg0);
        func_80004ED0(D_800FC674 + 0x30, 0, 1);
    }
}
