/* cflags: -fcse-follow-jumps -fcse-skip-blocks */
#include "common.h"

typedef struct Blk_5E7A0 {
    struct Blk_5E7A0 *next;
    u32 info;
} Blk_5E7A0;

extern Blk_5E7A0 *D_800DA6C8[];

void func_8005E7A0(Blk_5E7A0 *b, s32 idx) {
    Blk_5E7A0 *cur = D_800DA6C8[idx];
    Blk_5E7A0 *prev = NULL;
    u32 info;
    u32 sz;
    u32 bs;
    u32 t;
    u32 tb;

    while (cur < b) {
        if (cur == NULL) break;
        prev = cur;
        cur = cur->next;
    }
    if (prev != NULL) {
        info = prev->info;
        tb = info & 0x0FFFFFFF;
        sz = tb + 8;
        if ((Blk_5E7A0 *)((u32)prev + sz) == b) {
            bs = b->info & 0x0FFFFFFF;
            tb = bs + 8;
            if ((Blk_5E7A0 *)((u32)b + tb) == cur) {
                prev->next = cur->next;
                t = (info & 0x0FFFFFFF) + 16;
                t += (b->info & 0x0FFFFFFF) + (cur->info & 0x0FFFFFFF);
                t &= 0x0FFFFFFF;
                info = (info & 0xF0000000) | t;
                prev->info = info;
                return;
            }
            sz = (sz + bs) & 0x0FFFFFFF;
            prev->info = (info & 0xF0000000) | sz;
            return;
        }
        prev->next = b;
    } else {
        D_800DA6C8[idx] = b;
    }
    tb = (b->info & 0x0FFFFFFF) + 8;
    if ((Blk_5E7A0 *)((u32)b + tb) == cur) {
        b->next = cur->next;
        {
            u32 x = b->info;
            u32 y = (x & 0x0FFFFFFF) + 8;
            y += cur->info & 0x0FFFFFFF;
            y &= 0x0FFFFFFF;
            b->info = (x & 0xF0000000) | y;
        }
        return;
    }
    b->next = cur;
}
