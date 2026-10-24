/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x64];
    s32 unk68;
} Obj800A8FBC;

extern void func_800AB734(s32, s32);

void func_800A8FBC(Obj800A8FBC *arg0, f32 arg1) {
    if (arg0->unk0 != 0) {
        arg0->unk68 = arg1 * 32767.0f;
        if (arg0->unk68 > 0x7FFF) {
            arg0->unk68 = 0x7FFF;
        }
        if (arg0->unk68 < 0) {
            arg0->unk68 = 0;
        }
        func_800AB734(1, arg0->unk68);
    }
}
