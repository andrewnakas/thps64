#include "common.h"

typedef struct {
    s32 val;
    u8 pad[0x3C];
} Elem8003C6B4;

typedef struct {
    u8 pad[0x240];
    s8 idx;
    u8 pad241[3];
    union {
        s32 w;
        u8 b[4];
    } u244;
    s32 w248;
    s32 w24C;
    u8 pad250[0x50];
    Elem8003C6B4 elems[1];
} Obj8003C6B4;

s32 func_8003C354(void);

s32 func_8003C6B4(Obj8003C6B4 *arg0) {
    s32 r;
    s32 i;

    r = func_8003C354();
    if (arg0->u244.b[1] == 6) {
        if (arg0->u244.b[2] != 0) {
            return arg0->w248;
        }
        return arg0->elems[arg0->idx].val;
    }
    if ((arg0->u244.w & 0xFFFF00) == 0x50100) {
        arg0->u244.b[2] = 0;
        i = arg0->idx;
        if (i == -1) {
            return arg0->w24C;
        }
        r = arg0->elems[i].val;
    }
    return r;
}
