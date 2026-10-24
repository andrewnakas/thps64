/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0x3EC - 0x1C];
    u8 unk3EC[0x408 - 0x3EC];
    s32 unk408[6];
    s32 unk420;
    u8 pad424[0x434 - 0x424];
    s32 unk434;
    u8 pad438[0x43C - 0x438];
    s32 *unk43C;
    u8 pad440[0x45C - 0x440];
    s32 unk45C;
    u8 pad460[0x4B8 - 0x460];
    s32 unk4B8;
    u8 pad4BC[0x4D8 - 0x4BC];
    s32 unk4D8;
    u8 pad4DC[0x4E8 - 0x4DC];
    s32 *unk4E8;
} Obj800A21E8;

extern s32 func_8000A5AC(void *, s32, s32, s32, s32, s32);
extern s32 func_8000B470(void *, void *, s32);
extern s32 func_8009E6B4(void *, s32, s32);
extern void func_8009ECF8(void *, s32);
extern void func_800A0870(Obj800A21E8 *, s32, s32);
extern void func_800A3194(Obj800A21E8 *);
extern u8 D_800EA110[];
extern s32 D_800EA550;

void func_800A21E8(Obj800A21E8 *arg0) {
    u8 buf[0x68];
    s32 r;

    if (arg0->unk18 != -1) {
        *arg0->unk4E8 = func_8009E6B4(D_800EA110, arg0->unk4B8, 4);
        if (*arg0->unk4E8 != 0) {
            *arg0->unk43C = arg0->unk4B8;
            r = func_8000B470(arg0->unk3EC, buf, arg0->unk434);
            if (r == 0) {
                r = func_8000B470(arg0->unk3EC, buf, arg0->unk434);
                if (r != 0) {
                    func_800A0870(arg0, r, 0);
                    return;
                }
                r = func_8000A5AC(buf, arg0->unk4D8, 0, 0, arg0->unk4B8, *arg0->unk4E8);
                if (r != 0) {
                    func_800A0870(arg0, r, arg0->unk420);
                    func_8009ECF8(D_800EA110, *arg0->unk4E8);
                    *arg0->unk4E8 = 0;
                } else {
                    D_800EA550 = arg0->unk420;
                    if (arg0->unk45C != 0) {
                        arg0->unk408[arg0->unk434] = arg0->unk4D8;
                    }
                }
            } else {
                func_8009ECF8(D_800EA110, *arg0->unk4E8);
                *arg0->unk4E8 = 0;
                func_800A0870(arg0, r, arg0->unk420);
            }
            goto end;
        }
    }
    D_800EA550 = arg0->unk420;
end:
    func_800A3194(arg0);
}
