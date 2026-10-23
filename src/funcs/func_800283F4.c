#include "common.h"
typedef struct { s32 x, y, z; } Vec3i_F2;
typedef struct { u8 pad[0x30]; Vec3i_F2 v; } Big_F2;
void func_80028348(void *, Big_F2 *, s32); void func_800283F4(void *arg0, Vec3i_F2 *arg1, s32 arg2) { Big_F2 b; func_80028348(arg0, &b, arg2); *arg1 = b.v; }
