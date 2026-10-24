/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void *unkC;
    s32 unk10;
} DmaReq;

typedef struct {
    u8 pad0[0x2314];
    s32 unk2314;
} Sched;

void func_80001EC0(void *, void *, s32);
void func_80002C40(s32, s32);
void func_80002E00(s32, void *, s32);
void func_80004770(s32, s32, s32, s32);
void func_80004ED0(void *, void *, s32);
void func_80005070(void *, s32, s32);
void func_80007650(s32, s32);
void func_800A011C(u8 *);
void func_800BAFBC(u8 *, DmaReq *);
extern Sched D_800F0DD0;

void func_800BAE84(u8 *arg0) {
    u8 mq[0x18];
    s32 msgbuf;
    DmaReq *req;
    s32 msg;
    void *q;

    q = mq;
    func_80001EC0(q, &msgbuf, 1);
    func_80002E00(8, q, 0x7CF);
    while (1) {
        func_80004ED0(arg0 + 0x1DC8, &req, 1);
        if (D_800F0DD0.unk2314 == 0) {
            if (req->unk8 != 0) {
                func_80002C40(req->unk4, req->unk8);
                func_80004770(0, req->unk0, req->unk4, req->unk8);
                func_80004ED0(mq, &msg, 1);
                func_80007650(req->unk4, req->unk8);
            }
            if (req->unkC != NULL) {
                func_80005070(req->unkC, req->unk10, 1);
            }
            if ((u32)req >= (u32)(arg0 + 0x1C8) && (u32)(arg0 + 0x15B4) >= (u32)req) {
                func_800BAFBC(arg0, req);
            }
        }
        func_800A011C(arg0);
    }
}
