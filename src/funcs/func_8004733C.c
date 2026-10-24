/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

s32 func_800233B8(s32);
void func_80043264(s32 *);
void func_80043288(void);
void func_800433E4(s32 *);

void func_8004733C(s32 *arg0) {
    s32 v[3];
    s32 len;
    s32 r;

    v[0] = arg0[0] >> 12;
    v[1] = arg0[1] >> 12;
    v[2] = arg0[2] >> 12;
    func_800433E4(v);
    func_80043288();
    func_80043264(v);
    r = func_800233B8(v[0] + v[1] + v[2]);
    len = r;
    if (r == 0) {
        arg0[2] = 0;
        arg0[1] = 0;
        arg0[0] = 0;
        return;
    }
    arg0[0] = arg0[0] / len;
    arg0[1] = arg0[1] / len;
    arg0[2] = arg0[1] / len;
}
