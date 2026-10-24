/* cflags: -O2 -Wa,-O0 */
#include "common.h"

typedef struct Player800B0000 {
    struct Player800B0000 *next;
    void *clientData;
    s32 (*handler)(struct Player800B0000 *);
    s32 callTime;
    s32 samplesLeft;
} Player800B0000;

typedef struct {
    void *head;
    u8 pad4[0x28 - 0x4];
    s64 paramSamples;
    s64 curSamples;
    u8 pad38[0x58 - 0x38];
    s32 maxOutSamples;
    s32 *outBuf;
} Synth800B0000;

typedef struct {
    u32 w0;
    u32 w1;
} Acmd800B0000;

extern void func_800B024C(void);
extern s32 func_800B02E4(s32);
extern s32 func_800B0354(Player800B0000 **);
extern Acmd800B0000 *func_800B1590(s32, Acmd800B0000 *);
extern Synth800B0000 *D_800ECC34;

Acmd800B0000 *func_800B0000(Acmd800B0000 *cmdList, s32 *cmdLen, s32 *outBuf, s32 outLen) {
    Player800B0000 *client;
    Acmd800B0000 *cmdlEnd = cmdList;
    s32 nOut;
    s32 *lOutBuf = outBuf;

    if (D_800ECC34->head == NULL) {
        *cmdLen = 0;
        return cmdlEnd;
    }
    for (D_800ECC34->paramSamples = func_800B0354(&client);
         D_800ECC34->paramSamples - D_800ECC34->curSamples < outLen && client != NULL;
         D_800ECC34->paramSamples = func_800B0354(&client)) {
        D_800ECC34->paramSamples &= ~0xF;
        client->samplesLeft += func_800B02E4(client->handler(client));
    }
    D_800ECC34->paramSamples &= ~0xF;
    while (outLen > 0) {
        nOut = (D_800ECC34->maxOutSamples < outLen) ? D_800ECC34->maxOutSamples : outLen;
        D_800ECC34->outBuf = lOutBuf;
        cmdlEnd = func_800B1590(D_800ECC34->curSamples, cmdlEnd);
        outLen -= nOut;
        lOutBuf += nOut;
        D_800ECC34->curSamples += nOut;
    }
    *cmdLen = cmdlEnd - cmdList;
    func_800B024C();
    return cmdlEnd;
}
