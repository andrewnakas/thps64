/* cflags: -O2 */
#include "common.h"

typedef char *va_list;
#define va_start(ap, last) (ap = (char *)&last + sizeof(last))
#define va_arg(ap, T) (((T *)(ap = (char *)((((s32)ap + 4 - 1) & -4) + 4)))[-1])
#define va_end(ap)

typedef struct {
    u8 unk0;
    u8 pad1[0x23];
} SndChan;

typedef struct {
    u8 pad0[0x548];
    SndChan chans[1];
} SndMgr;

f32 func_8009F228(void);
s32 func_800A9D64(SndMgr *, s32);
void func_800A96BC(SndMgr *, s32);
s32 func_800AA1C4(SndMgr *);
void func_800AA1E8(SndMgr *, s32, ...);

void func_800AA4A0(SndMgr *arg0, f32 prob, s32 n, ...) {
    va_list ap;
    s32 i;
    s32 v;
    s32 pick;
    f32 r;
    u8 c;

    v = 0;
    va_start(ap, n);
    if (prob <= 0.0f || prob > 1.0f) {
        return;
    }
    r = func_8009F228();
    if (!(r <= prob)) {
        return;
    }
    pick = r / prob * n;
    for (i = 0; i < n; i++) {
        v = va_arg(ap, s32);
        if (i == pick) {
            break;
        }
    }
    va_end(ap);
    if (func_800A9D64(arg0, v) == 0) {
        return;
    }
    c = arg0->chans[v].unk0;
    if (c == 0) {
        func_800A96BC(arg0, v);
    } else if (c == 2) {
        if (func_800AA1C4(arg0) == 0) {
            func_800AA1E8(arg0, 1, v);
        }
    }
}
