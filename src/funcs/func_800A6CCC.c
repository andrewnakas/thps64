/* cflags: -O2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3;

extern void func_80001A30(u8 *, s32);
extern void func_8009C8EC(s32, u8 *);

void func_800A6CCC(u8 *arg0, u8 *arg1) {
    if (*(u8 *)(arg0 + 0x80) != 0) {
        func_80001A30(arg1, *(s32 *)(arg0 + 0x6C));
    } else {
        func_8009C8EC(*(s32 *)(arg0 + 0x68), arg1);
    }
    *(Vec3 *)(arg0 + 0x70) = *(Vec3 *)(arg1 + 0x30);

}
