/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 unk0[7];
    s32 unk1C;
    s32 unk20[3];
} Entry;

typedef struct {
    u8 pad0[0x460];
    s32 unk460;
    u8 pad464[0x520 - 0x464];
    s32 unk520[1];
} Obj;

void func_8004638C(Obj *, s32, s32, s32);
extern Entry D_800D63F8[];

void func_8004EF10(Obj *arg0) {
    s32 flags;
    s32 id;
    s32 v;

    flags = arg0->unk460;
    v = 0;
    if (flags & 0x800) {
        id = flags & 0xFF;
        if (flags & 0x6000) {
            v = D_800D63F8[id].unk1C;
            switch (arg0->unk520[id]) {
            case 0:
            case 1:
                break;
            case 2:
                v = v * 75 / 100;
                break;
            case 3:
                v /= 2;
                break;
            case 4:
                v /= 4;
                break;
            default:
                v /= 10;
                break;
            }
            v /= 20;
        }
        if (v != 0) {
            func_8004638C(arg0, v, flags, id);
        }
    }
}
