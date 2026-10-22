#include "common.h"

s32 func_80039328(s32 **arg0, s32 arg1) {
    return ((volatile s32 *)(*arg0 + arg1))[1];
}
