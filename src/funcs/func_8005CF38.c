/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 data[0x18];
} Elem;

typedef struct {
    u8 pad0[8];
} Node;

typedef struct {
    u8 pad0[0x20];
    Node *unk20;
    u8 pad24[0x14];
    u16 unk38;
    u8 pad3A[0xE];
} Slot;

void func_80023270(void *, Elem *, void *);
void func_80043264(s32 *);
void func_8005D0B0(s32, s32, Node *, u8 *, s32, s32);
Elem *func_8007EBE4(u8 *); /* takes only the object (src/funcs/func_8007EBE4.c) */
extern Elem D_800D7450[];
extern Slot D_800DAF98[];

void func_8005CF38(s32 *arg0, u8 *arg1, u8 *arg2) {
    s32 idx;
    Slot *slots;
    Node *nodes;
    s32 k;
    s32 cnt;
    Elem *e;

    idx = *(u16 *)(arg2 + 6);
    slots = D_800DAF98;
    nodes = slots[arg1[0x1B]].unk20;
    k = *(u16 *)(arg1 + 0x21E);
    if (*(u16 *)arg1 & 4) {
        e = &(*(Elem **)(arg1 + 0x27C))[idx];
    } else {
        cnt = *(u16 *)((u8 *)&nodes[k] + 8);
        if (cnt != 0) {
            func_8005D0B0(4, cnt + 1, nodes, arg1, idx, slots[arg1[0x1B]].unk38);
            {
                Elem *base = D_800D7450;
                e = &base[idx];
            }
        } else {
            e = &func_8007EBE4(arg1)[idx];
        }
    }
    func_80023270(arg2, e, arg1 + 0x23C);
    func_80043264(arg0);
    arg0[0] <<= 12;
    arg0[1] <<= 12;
    arg0[2] <<= 12;
    arg0[0] = *(s32 *)(arg1 + 4) + ((arg0[0] - *(s32 *)(arg1 + 4)) >> 4);
    arg0[1] = *(s32 *)(arg1 + 8) + ((arg0[1] - *(s32 *)(arg1 + 8)) >> 4);
    arg0[2] = *(s32 *)(arg1 + 0xC) + ((arg0[2] - *(s32 *)(arg1 + 0xC)) >> 4);
}
