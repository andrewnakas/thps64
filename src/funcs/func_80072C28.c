#include "common.h"

typedef struct ShortVec80072C28 { s16 x, y, z; } ShortVec80072C28;
typedef struct State80072C28 {
    u8 pad0[0x100];
    ShortVec80072C28 unk100;
    u8 pad106[0x5A];
    u16 unk160;
} State80072C28;

void func_80046A30(void *, void *);
void func_80046C1C(void *, void *);
void func_80046CB0(void *);
void func_80046D00(void *);
void func_800470E0(void *, void *);
void func_800472C0(void *, void *);
void func_800472F8(void *);
extern ShortVec80072C28 D_800D6194;

void func_80072C28(State80072C28 *arg0) {
    void *block84;
    void *blockB8;
    void *block10;

    arg0->unk100 = D_800D6194;
    arg0->unk160 = 0;
    block84 = (u8 *)arg0 + 0x84;
    func_800472C0(block84, (u8 *)arg0 + 0x9C);
    func_800470E0(block84, (u8 *)arg0 + 0xB5);
    func_800472F8(block84);
    func_800472C0((u8 *)arg0 + 4, block84);
    block10 = (u8 *)arg0 + 0x10;
    blockB8 = (u8 *)arg0 + 0xB8;
    func_80046C1C(block10, blockB8);
    func_80046D00(block10);
    func_80046C1C(blockB8, (u8 *)arg0 + 0xCC);
    func_80046A30(blockB8, (u8 *)arg0 + 0xE0);
    func_80046CB0(blockB8);
}
