/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[4];
    s32 unk8;
} Buf;

typedef struct {
    u8 pad0[0x80];
    s32 unk80;
} Task;

typedef struct {
    u8 pad0[0x1D4];
    u8 unk1D4[0x88];
    s32 unk25C;
    s32 unk260;
    Task *unk264;
    s32 *unk268;
    u8 pad26C[0x2040];
    Buf *unk22AC;
    Buf *unk22B0;
    s32 unk22B4;
    u8 pad22B8[0x28];
    s32 unk22E0;
    u8 pad22E4[0x30];
    s32 unk2314;
} Sched;

void func_80010C10(s32);
void func_8000CAD0(void);
s32 func_800110C0(void);
void func_800BCC48(Sched *);
void func_800BCDEC(Sched *);
void func_800BCA1C(Sched *, void *, s32);
void func_800BD05C(Sched *);

void func_800BCB0C(Sched *arg0) {
    Buf *b;
    s32 *p;

    if (arg0->unk2314 != 0 && arg0->unk260 == 0 && arg0->unk25C == 0) {
        func_80010C10(0);
        func_8000CAD0();
    }
    if (arg0->unk22AC != NULL && func_800110C0() == arg0->unk22AC->unk0) {
        arg0->unk22AC->unk8 = 4;
        if (arg0->unk22B0 != NULL) {
            arg0->unk22B0->unk8 = 0;
        }
        b = arg0->unk22AC;
        arg0->unk22AC = NULL;
        arg0->unk22B4 = 0;
        arg0->unk22B0 = b;
    }
    arg0->unk22B4++;
    if (arg0->unk22E0 != 0) {
        if (arg0->unk22B4 == 0x1A4) {
            if (arg0->unk264 != NULL) {
                if (arg0->unk264->unk80 == 0 && arg0->unk268 != NULL) {
                    func_800BCC48(arg0);
                    func_800BCDEC(arg0);
                } else {
                    func_800BCC48(arg0);
                }
            } else {
                p = arg0->unk268;
                if (p != NULL) {
                    func_800BCDEC(arg0);
                } else {
                    *p = 0;
                }
            }
        } else if (arg0->unk22B4 == 0x1E0) {
            *(s32 *)NULL = 0;
        }
    }
    func_800BCA1C(arg0, arg0->unk1D4, 3);
    func_800BD05C(arg0);
}
