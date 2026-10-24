/* cflags: -fcse-follow-jumps */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    u8 unk14;
    u8 pad15[0x2F];
} Chan;

extern f32 D_800D0FEC;

static __inline__ void setvol(u8 *p) {
    f32 f = D_800D0FEC * 127.0f;
    u32 v;
    u32 m;
    f32 g;
    if (f >= 2147483648.0f) {
        goto big;
    }
    v = (s32)f;
    goto end;
big:
    g = f - 2147483648.0f;
    m = 0x80000000;
    v = (s32)g;
    v |= m;
end:
    *p = v;
}

void func_8003A598(Chan *arg0) {
    setvol(&arg0[0].unk14);
    setvol(&arg0[1].unk14);
    setvol(&arg0[2].unk14);
}
