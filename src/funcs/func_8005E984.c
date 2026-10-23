#include "common.h"

typedef struct {
    void *ptr;
    s32 val;
} Handle_5E984;

typedef struct {
    s32 a;
    s32 b;
} Hdr_5E984;

Handle_5E984 func_8005E984(void *arg1) {
    Handle_5E984 h;
    Hdr_5E984 *hdr;

    h.ptr = NULL;
    if (arg1 != NULL) {
        hdr = (Hdr_5E984 *)arg1 - 1;
        if (hdr->a >= 0) {
            switch (((s32 *)arg1)[-1] >> 28) {
                case -2:
                case 0:
                case 1:
                    if ((u32)((hdr->b & 0x0FFFFFFF) - 4) <= 0x1FFFFC) {
                        h.ptr = arg1;
                        h.val = hdr->a;
                    }
                    break;
            }
        }
    }
    return h;
}
