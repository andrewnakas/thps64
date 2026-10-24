/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x44];
    s32 owner;
    u8 pad48[0x34];
    s32 unk7C;
    u8 pad80[0xB0];
} Voice800AB2EC;

s32 func_800ADF98(s32, s32, s32, s32, s32);
extern s32 D_800FC2F0;
extern Voice800AB2EC *D_800FC2F8;

u8 *func_800AB2EC(u8 *arg0, u8 *p) {
    s32 note;
    s32 id;
    s32 i;
    Voice800AB2EC *v;

    note = *p++;
    if (note >= 0x80) {
        note = ((note & 0x7F) << 8) + *p++;
    }
    (*(s32 *)(arg0 + 0x48))++;
    id = func_800ADF98(*(s32 *)(arg0 + 0x78), note, *(s16 *)(arg0 + 0x9E), *(s16 *)(arg0 + 0xB0),
                       *(s32 *)(arg0 + 0x48));
    (*(s32 *)(arg0 + 0x48))--;
    if (id != 0) {
        v = D_800FC2F8;
        for (i = 0; i < D_800FC2F0; i++, v++) {
            if (v->owner == id) {
                v->owner = *(s32 *)(arg0 + 0x44);
                v->unk7C = *(s32 *)(arg0 + 0x7C);
            }
        }
    }
    return p;
}
