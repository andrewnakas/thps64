#include "common.h"

void func_80079614(void *arg0, u8 arg1) {
    arg0 = (u8 *) arg0 + arg1 * 2;
    *(u16 *) ((u8 *) arg0 + 0x638) = *(u16 *) ((u8 *) arg0 + 0x628);
}
