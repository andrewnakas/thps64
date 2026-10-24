/* cflags: -O2 */
#include "common.h"

typedef char *va_list;
#define va_start(ap, last) (ap = (char *)&last + sizeof(last))
#define va_arg(ap, T) (((T *)(ap = (char *)((((s32)ap + 4 - 1) & -4) + 4)))[-1])
#define va_end(ap)

typedef struct {
    u8 pad0[0x39C];
    s32 unk39C;
    s16 buf[200];
    u8 cnt;
    u8 idx;
    u8 unk532;
} Obj;

s32 func_800A9D64(Obj *, s32);
f32 func_8009F274(void);

void func_800AA354(Obj *obj, s32 arg1, s32 n, ...) {
    va_list ap;
    s32 i;
    s32 v;
    u8 c;

    va_start(ap, n);
    obj->unk39C = arg1;
    if ((u32)(n - 1) < 200) {
        for (i = 0; i < n; i++) {
            v = va_arg(ap, s32);
            if (func_800A9D64(obj, v) == 0) {
                return;
            }
            obj->buf[obj->idx] = v;
            obj->idx = (u8)(obj->idx + 1) % 200;
            obj->cnt++;
            obj->cnt = (obj->cnt > 200) ? 200 : obj->cnt;
        }
        obj->unk532 = (s32)(n * func_8009F274());
        c = obj->cnt;
        if (c < obj->unk532) {
            obj->unk532 = c;
        }
    }
}
