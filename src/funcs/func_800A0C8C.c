/* cflags: -O2 */
#include "common.h"
#include "types/object.h"

void func_800A0C8C(Menu *arg0) {
    s32 id;
    s32 i;

    arg0->unk18 = -1;
    if (arg0->unk434 == -1) {
        return;
    }
    id = arg0->unk408[arg0->unk434];
    if (id == -1) {
        return;
    }
    for (i = 0; i < arg0->unk14; i++) {
        if (arg0->unk4B4[i].unk20 == id) {
            arg0->unk18 = i;
            return;
        }
    }
}
