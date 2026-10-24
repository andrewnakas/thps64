/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 a;
    s32 b;
} Dim_800AF5A4;

typedef struct {
    s32 x, y, z;
    u8 rest[1];
} Pos_800AF5A4;

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 type;
    u8 pad9[3];
    Pos_800AF5A4 *pos;
    Dim_800AF5A4 *dim;
} Data_800AF5A4;

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    s32 x, y, z;
    Data_800AF5A4 *data;
    s32 unk24;
    u8 pad28[8];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
} Obj_800AF5A4;

void func_800104E0(void *, s32, s32, void *);

void func_800AF5A4(Obj_800AF5A4 *o, s32 msg, Data_800AF5A4 *d) {
    switch (msg) {
    case 5:
        o->data = d;
        o->unk3C = d->unk0;
        o->unk30 = 0;
        switch (o->data->type) {
        case 0:
            o->data->unk4 = o->data->unk4 / 9 * 9;
            o->unk24 = o->data->dim->a * (o->data->dim->b + o->data->dim->b) * 8;
            if (o->data->pos != NULL) {
                o->x = o->data->pos->x;
                o->y = o->data->pos->y;
                o->z = o->data->pos->z;
                func_800104E0(o->data->pos->rest, o->unk10, 0x20, o);
            } else {
                o->z = 0;
                o->y = 0;
                o->x = 0;
            }
            break;
        case 1:
            if (o->data->pos != NULL) {
                o->x = o->data->pos->x;
                o->y = o->data->pos->y;
                o->z = o->data->pos->z;
            } else {
                o->z = 0;
                o->y = 0;
                o->x = 0;
            }
            break;
        }
        break;
    case 4:
        o->unk34 = 0;
        o->unk38 = 1;
        o->unk30 = 0;
        if (o->data != NULL) {
            o->unk3C = o->data->unk0;
            switch (o->data->type) {
            case 0:
                if (o->data->pos != NULL) {
                    o->z = o->data->pos->z;
                }
                break;
            case 1:
                if (o->data->pos != NULL) {
                    o->z = o->data->pos->z;
                }
                break;
            }
        }
        break;
    }
}
