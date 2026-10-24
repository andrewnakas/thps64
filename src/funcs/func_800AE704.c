/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x16];
    s16 prio;
} Snd800AE704;

typedef struct Node800AE704 {
    struct Node800AE704 *next;
    u8 pad4[0x4];
    Snd800AE704 *snd;
    u8 padC[0x7C];
    s32 busy;
} Node800AE704;

void func_8000CB00(Node800AE704 *);
void func_8000CB30(Node800AE704 *, u8 *);
extern u8 *D_800ECC34;

s32 func_800AE704(Node800AE704 **arg0, s16 prio) {
    Node800AE704 *n;
    s32 found;

    n = *(Node800AE704 **)(D_800ECC34 + 0x20);
    found = 0;
    if (n != NULL || (n = *(Node800AE704 **)(D_800ECC34 + 0x10)) != NULL) {
        *arg0 = n;
        func_8000CB00(n);
        do {
            func_8000CB30(n, D_800ECC34 + 0x18);
        } while (0);
    } else {
        for (n = *(Node800AE704 **)(D_800ECC34 + 0x18); n != NULL; n = n->next) {
            if (prio >= n->snd->prio && n->busy == 0) {
                *arg0 = n;
                found = 1;
                prio = n->snd->prio;
            }
        }
    }
    return found;
}
