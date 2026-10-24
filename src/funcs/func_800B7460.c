/* cflags: -O2 -fno-schedule-insns */
#include "common.h"

typedef struct Chunk {
    void *data;
    s32 size;
    s32 align;
    s32 unkC;
    struct Chunk *next;
} Chunk;

typedef struct {
    Chunk *head;
    s32 unk4;
    s32 count;
} ChunkList;

typedef struct {
    s32 *hdr;
    void *base;
} Writer;

s32 func_800B7420(void);
s32 *func_8009E6B4(void *, s32, s32);
s32 *func_8009E8F0(void *, s32, s32);
void func_800B760C(Writer *, s32);
void func_80005720(void *, void *, s32);
extern u8 D_800EA110[];

s32 *func_800B7460(ChunkList *arg0, s32 arg1, s32 arg2) {
    Writer w;
    s32 *buf;
    s32 size;
    s32 i;
    s32 off;
    Chunk *c;
    s32 t;
    s32 a;
    Writer *pw;
    s32 sz;

    size = func_800B7420();
    if (arg1 != 0) {
        buf = func_8009E8F0(D_800EA110, size, arg2);
    } else {
        buf = func_8009E6B4(D_800EA110, size, arg2);
    }
    if (buf != NULL) {
        pw = &w;
        func_800B760C(pw, 0);
        pw->base = buf;
        w.hdr = buf;
        i = 0;
        *buf = arg0->count;
        w.hdr[1] = 8;
        c = arg0->head;
        off = arg0->count * 4 + 8;
        while (1) {
            if (c == NULL) {
                break;
            }
            t = i * 4;
            a = c->align;
            i++;
            off = (off + a - 1) & -a;
            sz = c->size;
            *(s32 *)(t + (s32)w.hdr + 4) = off;
            *(s32 *)(t + (s32)w.hdr + 8) = off + sz;
            func_80005720((u8 *)buf + off, c->data, c->size);
            off += c->size;
            c = c->next;
        }
    }
    return buf;
}
