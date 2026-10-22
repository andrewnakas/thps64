#include "common.h"

void func_8008130C(void *);                                  /* extern */

void func_80079228(void *arg0) {
    *(s32 *) ((u8 *) arg0 + 0x654) = 0;
    *(s32 *) ((u8 *) arg0 + 0x5B0) = 0x17;
    func_8008130C(arg0);
}
