/* cflags: -O2 */
#include "common.h"

typedef char *va_list;
#define va_start(ap, last) (ap = (char *)&last + sizeof(last))
#define va_arg(ap, T) (((T *)(ap = (char *)((((s32)ap + 4 - 1) & -4) + 4)))[-1])
#define va_end(ap)

typedef struct {
    u8 pad0[0x6C];
    s32 unk6C;
    u8 pad70[0x8];
    s32 buf[200];
    u8 pad398_[0x398 - 0x78 - 800];
    u8 idx;
} Obj_800AA1E8;

s32 func_800A9D64(Obj_800AA1E8 *, s32);
void func_800AA0F4(Obj_800AA1E8 *);

void func_800AA1E8(Obj_800AA1E8 *obj, s32 n, ...) {
    va_list ap;
    s32 i;

    va_start(ap, n);
    if ((u32)(n - 1) < 10) {
        if (obj->unk6C != 0) {
            obj->buf[obj->idx] = -2;
            obj->idx = (u8)(obj->idx + 1) % 200;
        }
        for (i = 0; i < n; i++) {
            s32 v = va_arg(ap, s32);
            obj->buf[obj->idx] = v;
            if (func_800A9D64(obj, v) == 0) {
                obj->buf[obj->idx] = -2;
            }
            obj->idx = (u8)(obj->idx + 1) % 200;
        }
        func_800AA0F4(obj);
    }
    va_end(ap);
}
