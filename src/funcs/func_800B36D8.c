/* cflags: -O2 */
#include "common.h"
#define HELPERS_MQLOCK
#include "helpers.h"

typedef struct {
    u8 pad0[0x6C];
    s16 state;
    s16 pad6E;
    f32 vol;
    f32 pan;
    u8 pad78[0x8];
} Chan800B36D8;

extern u8 D_800FC350[];
extern Chan800B36D8 D_800FC380[];

void func_800B36D8(s32 arg0, f32 pan, f32 vol) {
    MqLock l;
    Chan800B36D8 *c;

    mq_lock(&l, (s32)D_800FC350);
    c = &D_800FC380[arg0];
    if (c->state != 2) {
        mq_unlock(&l);
        return;
    }
    if (vol < 0.0f) {
        vol = 0.0f;
    } else if (vol > 1.0f) {
        vol = 1.0f;
    }
    c->pan = pan;
    c->vol = vol;
    mq_unlock(&l);
}
