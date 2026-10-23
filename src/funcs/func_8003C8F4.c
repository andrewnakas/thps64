/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x260];
    s32 unk260;
    f32 unk264;
    f32 unk268;
} Obj3C8F4;

void func_8003C8F4(Obj3C8F4 *arg0, s32 arg1) {
    f32 f;
    u32 v;

    if (arg1 == 1) {
        arg0->unk264 = 1.3f;
        arg0->unk268 = 1.3f;
    }
    if (arg1 == 2) {
        arg0->unk264 = 0.9f;
        arg0->unk268 = 0.9f;
    }
    f = arg0->unk264 * 210.0f;
    if (f >= 2147483648.0f) {
        goto big;
    }
    v = (s32) f;
    goto end;
big:
    v = (s32) (f - 2147483648.0f);
    v |= 0x80000000;
end:
    arg0->unk260 = v & 0xFFFF;
}
