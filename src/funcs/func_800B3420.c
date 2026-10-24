/* cflags: -O2 */
#include "common.h"

typedef struct { s32 pad0; u8 b[0x68]; s16 state; u8 pad[0x12]; } E800FC380;
void func_8000C618(void *);
extern E800FC380 D_800FC380[];

void func_800B3420(s32 arg0) {
    E800FC380 *e = &D_800FC380[arg0];
    if (e->state == 2) {
        func_8000C618(e->b);
    }
}
