#include "common.h"

void *func_8005E950(void *arg0) {
    void *p;

    p = *(void **)arg0;
    if (p == NULL) {
        return NULL;
    }
    if (*(s32 *)((u8 *)p - 8) == *(s32 *)((u8 *)arg0 + 4)) {
        return p;
    }
    *(void **)arg0 = NULL;
    return NULL;
}
