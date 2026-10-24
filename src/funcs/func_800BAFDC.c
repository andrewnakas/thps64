/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 data[0x18];
} MesgQueue;

typedef struct {
    s32 src;
    s32 dst;
    u32 size;
    MesgQueue *mq;
    s32 pad10[2];
} DmaReq;

void func_80001EC0(MesgQueue *, void *, s32);
void func_80004ED0(MesgQueue *, s32, s32);
void func_80005070(void *, DmaReq *, s32);
void func_800108F0(void *, DmaReq *, s32);

static __inline__ void mqinit_(MesgQueue *q, s32 *msg) {
    func_80001EC0(q, msg, 1);
}

void func_800BAFDC(u8 *arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    DmaReq req;
    MesgQueue mq;
    s32 msg[2];
    u32 n;
    MesgQueue *pmq;

    mqinit_(&mq, msg);
    pmq = &mq;
    req.mq = pmq;
    if (arg4 != 0) {
        req.src = arg1;
        req.size = arg2;
        req.dst = arg3;
        func_800108F0(arg0 + 0x1DC8, &req, 1);
        func_80004ED0(pmq, 0, 1);
        return;
    }
loop:
    if (arg2 != 0) {
        n = 0x800;
        if (arg2 <= 0x800) {
            n = arg2;
        }
        req.src = arg1;
        arg1 += n;
        req.dst = arg3;
        arg3 += n;
        arg2 -= n;
        req.size = n;
        func_80005070(arg0 + 0x1DC8, &req, 1);
        func_80004ED0(&mq, 0, 1);
        goto loop;
    }
}
