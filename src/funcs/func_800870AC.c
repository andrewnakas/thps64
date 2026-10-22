#include "common.h"

void func_800870AC(s32 arg0, u8 *arg1, u8 *arg2, u8 *arg3) {

    s32 temp_v1;

    s32 temp_v1_2;

    s32 temp_v1_3;

    temp_v1 = (*arg1 * 0xBE) / 100;

    if (temp_v1 < 0x100) {

        *arg1 = (u8) temp_v1;

    } else {

        *arg1 = 0xFF;

    }

    temp_v1_2 = (*arg2 * 0xBE) / 100;

    if (temp_v1_2 < 0x100) {

        *arg2 = (u8) temp_v1_2;

    } else {

        *arg2 = 0xFF;

    }

    temp_v1_3 = (*arg3 * 0xBE) / 100;

    if (temp_v1_3 < 0x100) {

        *arg3 = (u8) temp_v1_3;

        return;

    }

    *arg3 = 0xFF;

}
