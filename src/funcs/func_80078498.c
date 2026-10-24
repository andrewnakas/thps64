/* cflags: -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_80078498;

typedef struct {
    s32 x, y, z, w;
} Q_80078498;

typedef struct {
    s32 unk0;
    V3_80078498 pos;
} Par_80078498;

typedef struct {
    s32 unk0;
    u8 *parent;
    V3_80078498 pos;
    s32 unk14;
    Q_80078498 rot;
    u8 pad28[0xC];
    s16 len;
    u8 pad36[0x26];
    u8 *unk5C;
    u8 pad60[0xC];
    Q_80078498 rot2;
    V3_80078498 tip;
} Bone_80078498;

void func_800226A0(void *, V3_80078498 *, V3_80078498 *);
s32 func_800233EC(s32);
void func_800673B0(Q_80078498 *, Q_80078498 *, Q_80078498 *);
void func_80067A48(Q_80078498 *, void *);
void func_80067B44(void *, Q_80078498 *);

void func_80078498(Bone_80078498 *b) {
    V3_80078498 v;
    V3_80078498 r;
    s32 m[8];
    Q_80078498 q;
    Q_80078498 t;
    s32 n;

    {
        s32 x = 0, y = 0, z = -(b->len << 12);
        v.x = x;
        v.y = y;
        v.z = z;
    }
    {
        s32 x = 0, y = 0, z = 0, w = 0x1000;
        q.x = x;
        q.y = y;
        q.z = z;
        q.w = w;
    }
    if (b->unk14 != 0) {
        func_80067B44(b->parent + 0x884, &q);
        func_800673B0(&t, &b->rot, &q);
        q = t;
    } else {
        q = b->rot;
    }
    n = func_800233EC(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
    if (n == 0) {
        n = 1;
    }
    q.x = (q.x << 12) / n;
    q.y = (q.y << 12) / n;
    q.z = (q.z << 12) / n;
    q.w = (q.w << 12) / n;
    func_80067A48(&q, m);
    func_800226A0(m, &v, &r);
    if (b->unk0 != 0) {
        b->pos = ((Par_80078498 *)b->parent)->pos;
    }
    b->tip.x = (b->pos.x + r.x) >> 12;
    b->tip.y = (b->pos.y + r.y) >> 12;
    b->tip.z = (b->pos.z + r.z) >> 12;
    {
        s32 x = 0, y = 0, z = 0, w = 0x1000;
        t.x = x;
        t.y = y;
        t.z = z;
        t.w = w;
    }
    b->rot2 = t;
    if (b->unk5C == b->parent) {
        b->rot2 = q;
    }
}
