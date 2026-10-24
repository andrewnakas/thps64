/* cflags: -O2 */
#include "common.h"

typedef struct { u8 *head; s32 pad4[2]; u8 *tail; u8 pad10[0x24]; s32 unk34; } L800AE49C;
s32 func_80002B20(s32);
extern L800AE49C *D_800ECC34;

void func_800AE49C(u8 *arg0) {
    s32 m;
    L800AE49C *l;

    m = func_80002B20(1);
    l = D_800ECC34;
    *(s32 *)(arg0 + 0x10) = l->unk34;
    *(u8 **)arg0 = l->head;
    l->head = arg0;
    if (l->tail == NULL) {
        l->tail = arg0;
    }
    func_80002B20(m);
}
