/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x20];
} Unk_800A9D64_Entry;

typedef struct {
    u8 pad0[0x534];
    Unk_800A9D64_Entry entries[200];
} Unk_800A9D64;

s32 func_800A9D64(Unk_800A9D64 *arg0, u32 arg1) {
    if (arg1 < 200 && arg0->entries[arg1].unk0 != -1) {
        return 1;
    }
    return 0;
}
