/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
} Msg;

extern void func_800AED54(u8 *, s32, Msg *);
extern Msg *func_800B0208(void);
extern u8 *D_800ECC34;

void func_800AFA50(u8 *arg0, s32 arg1) {
    Msg *m;
    s32 t;

    if (*(u8 **)(arg0 + 8) != NULL) {
        m = func_800B0208();
        if (m != NULL) {
            t = *(s32 *)(D_800ECC34 + 0x2C) + *(s32 *)(*(u8 **)(arg0 + 8) + 0x88);
            m->unk8 = 0x10;
            m->unkC = arg1 & 0xFF;
            m->unk0 = 0;
            m->unk4 = t;
            func_800AED54(*(u8 **)(arg0 + 8), 3, m);
        }
    }

}
