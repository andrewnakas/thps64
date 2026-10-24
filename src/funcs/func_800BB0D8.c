/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 src;
    s32 dst;
    u32 size;
    void *mq;
    s32 msg;
} DmaReq;

DmaReq *func_800BAF94(u8 *);
void func_80005070(void *, DmaReq *, s32);
void func_800108F0(void *, DmaReq *, s32);
extern s32 D_800F30E4;

void func_800BB0D8(u8 *arg0, s32 arg1, u32 arg2, s32 arg3, void *arg4, s32 arg5, s32 arg6) {
    DmaReq *req;
    u32 n;

    if (D_800F30E4 != 0) {
        while (1) {
        }
    }
    if (arg6 != 0) {
        req = func_800BAF94(arg0);
        req->src = arg1;
        req->size = arg2;
        req->dst = arg3;
        req->mq = arg4;
        req->msg = arg5;
        func_800108F0(arg0 + 0x1DC8, req, 1);
        return;
    }
    do {
        n = 0x800;
        if (arg2 <= 0x800) {
            n = arg2;
        }
        req = func_800BAF94(arg0);
        req->src = arg1;
        arg1 += n;
        req->dst = arg3;
        arg3 += n;
        arg2 -= n;
        req->size = n;
        if (arg2 != 0) {
            req->mq = NULL;
            req->msg = 0;
        } else {
            req->mq = arg4;
            req->msg = arg5;
        }
        func_80005070(arg0 + 0x1DC8, req, 1);
    } while (arg2 != 0);
}
