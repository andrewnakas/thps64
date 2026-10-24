/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Node;

s32 func_8009E6B4(s32 *, s32, s32);
void func_800A02AC(s32, Node *);
extern s32 D_800EA110;
extern s32 D_800ECF7C;
extern s32 D_800F32A8;

s32 func_800B2BF4(s32 arg0, s32 arg1, s32 *arg2, s32 arg3) {
    s32 i;
    s32 base;
    s32 p;
    Node *node;

    if (arg3 != 0) {
        p = D_800F32A8;
        *arg2 = p;
        D_800ECF7C = p + 0x4000;
    } else {
        *arg2 = func_8009E6B4(&D_800EA110, (arg0 + 1) * 0x4000 + arg0 * sizeof(Node), 0x10);
    }
    if (*arg2 == 0) {
        return 0;
    }
    base = 1;
    if (arg3 != 0) {
        base = 2;
    }
    i = 0;
    node = (Node *)(*arg2 + (arg0 + base) * 0x4000);
    while (1) {
        if (i >= arg0) {
            break;
        }
        node->unk0 = 0;
        node->unk4 = *arg2 + (i + base) * 0x4000;
        func_800A02AC(arg1, node);
        i++;
        node++;
    }
    return 1;
}
