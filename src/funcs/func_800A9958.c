/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk534;
    s32 unk538;
    s32 pad53C;
    s32 unk540;
    s32 unk544;
    u8 pad548;
    u8 unk549;
    u8 pad54A[2];
    s32 pad54C;
    s32 pad550;
    s32 pad554;
} Voice_800A9958;

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x40];
    s32 count;
    s32 next;
    u8 pad50[0x533 - 0x50];
    u8 unk533;
    Voice_800A9958 v[1];
} Snd_800A9958;

s32 func_800A9588(Snd_800A9958 *, s32);
s32 func_800A95F0(Snd_800A9958 *, s32);
s32 func_800A9D64();
s32 func_800AB9E0(s32);
s32 func_800ABA60(s32, s32, s32, s32, s32);
void func_800ABFC4(s32, s32);
void func_800AC01C(s32, s32);
void func_800AC0CC(s32, s32);
void func_800AC1B8(s32, s32);
void func_800AC130(s32, s32);

static inline s32 next_voice_(Snd_800A9958 *s) {
    return s->next++ % s->count;
}

s32 func_800A9958(Snd_800A9958 *s, s32 arg1, u8 vol, u8 pan, s32 pitch, u8 fx, u8 arg6) {
    s32 id = arg1;

    if (s->unk0 == 0) {
        goto fail;
    }
    if (func_800A9D64() == 0) {
        return 0;
    }
    if (s->unk533 != 0) {
        return 0;
    }
    do {
        if (id == -1) {
            id = next_voice_(s);
        }
    } while (0);
    if (s->v[id].unk549 == 0 || func_800A95F0(s, id) != 0) {
    fail:
        return 0;
    }
    func_800A9588(s, id);
    if (s->v[id].unk544 != -1) {
        s->v[id].unk538 = func_800ABA60(s->v[id].unk534, 0x7F, pan, 0, s->v[id].unk544);
    } else {
        s->v[id].unk538 = func_800AB9E0(s->v[id].unk534);
    }
    func_800ABFC4(s->v[id].unk538, (s32)vol % 256);
    func_800AC01C(s->v[id].unk538, (s32)pan % 256);
    func_800AC0CC(s->v[id].unk538, pitch);
    func_800AC1B8(s->v[id].unk538, fx & 0x7F);
    func_800AC130(s->v[id].unk538, (s32)arg6 % 256);
    s->v[id].unk540 = s->unk4;
    return 1;
}
