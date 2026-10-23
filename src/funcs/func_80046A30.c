#include "common.h"

u16 *func_80046A30(u16 *arg0, u8 *arg1) {
    arg0[0] = arg0[0] - ((s16)arg0[0] >> arg1[0]);
    arg0[1] = arg0[1] - ((s16)arg0[1] >> arg1[1]);
    arg0[2] = arg0[2] - ((s16)arg0[2] >> arg1[2]);
    return arg0;
}
