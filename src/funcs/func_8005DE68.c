#include "common.h"
void func_8005EA48(void *);
void func_8005DE68(u8 *arg0) {
    *(s32 *)(arg0 + 0x284) = 0;
    if (*(void **)(arg0 + 0x27C) != NULL) {
        func_8005EA48(*(void **)(arg0 + 0x27C));
        *(void **)(arg0 + 0x27C) = NULL;
    }
    if (*(void **)(arg0 + 0x280) != NULL) {
        func_8005EA48(*(void **)(arg0 + 0x280));
        *(void **)(arg0 + 0x280) = NULL;
    }
}
