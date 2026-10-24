/* cflags: -O2 */
#include "common.h"

typedef struct { u8 pad[0x88]; s16 off; s16 pad2; void (*fn)(void *); } V800B3BC8;
void func_80004ED0(void *, s32 *, s32);
void func_800A011C(u8 *);

void func_800B3BC8(u8 *arg0) {
    s32 msg;
    V800B3BC8 *v;

    while (1) {
        func_80004ED0(arg0 + 0x1C8, &msg, 1);
        if (msg == 1) {
            v = *(V800B3BC8 **)(arg0 + 0x1C4);
            v->fn(arg0 + v->off);
        }
        func_800A011C(arg0);
    }
}
