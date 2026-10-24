/* cflags: -O2 */
#include "common.h"

typedef struct Node {
    u8 pad0[0xC];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8 pad18[4];
    struct Node *unk1C;
    struct Node *unk20;
} Node;

typedef struct {
    Node *unk0;
    Node *unk4;
    u8 pad8[0x504];
    f32 unk50C;
} Obj;

extern f32 D_800F5668;

void func_8009B28C(Obj *arg0) {
    Node *n;
    f32 dt = D_800F5668;
    f32 t;

    arg0->unk50C -= dt;
    for (n = arg0->unk0; n != NULL; n = n->unk1C) {
        t = n->unk14 - dt;
        n->unk14 = t;
        n->unkC += n->unk10 * dt;
        if (t <= 0.0f) {
            n->unk14 = 0.0f;
            if (n->unk1C != NULL) {
                n->unk1C->unk20 = n->unk20;
            } else {
                arg0->unk4 = n->unk20;
            }
            if (n->unk20 != NULL) {
                n->unk20->unk1C = n->unk1C;
            } else {
                arg0->unk0 = n->unk1C;
            }
        }
    }
}
