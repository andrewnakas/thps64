#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_800494F0;

typedef struct Node800494F0 {
    u8 pad0[4];
    V3_800494F0 pos;
    u8 pad10[0x1C - 0x10];
    struct Node800494F0 *next;
    u8 pad20[0x52 - 0x20];
    u16 flags;
    u8 pad54[0x15C - 0x54];
    u16 radius;
} Node800494F0;

void func_80046FBC(void *, s32, V3_800494F0 *);
s32 func_800474C8(void *);

Node800494F0 *func_800494F0(s32 arg0, s32 arg1, V3_800494F0 *arg2, Node800494F0 *arg3, Node800494F0 *arg4) {
    V3_800494F0 d;

    Node800494F0 *found;


    found = NULL;
    while (1) {
        if (arg3 == NULL || found != NULL) break;
        if (arg3 == arg4 || (arg3->flags & 0x40)) {
            arg3 = arg3->next;
            continue;
        }
        {
            func_80046FBC(&d, arg1, &arg3->pos);
            if (func_800474C8(&d) < arg3->radius) {
                found = arg3;
                *arg2 = arg3->pos;
            }
        }
        arg3 = arg3->next;
    }
    return found;
}
