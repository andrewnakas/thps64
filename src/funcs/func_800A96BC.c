/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 handle;
    s32 voice;
    s32 pad8;
    s32 time;
    s32 unk10;
    u8 unk14;
    u8 vol;
    u8 unk16;
    u8 pad17;
    u8 pad18[4];
    f32 pitch;
    u8 pad20[4];
} Chn;

typedef struct {
    s32 unk0;
    s32 now;
    u8 pad8[0x40];
    s32 n;
    s32 next;
    u8 pad50[0x533 - 0x50];
    u8 mute;
    Chn ch[1];
} Snd;

s32 func_800A9D64(Snd *, s32);
s32 func_800A95F0(Snd *, s32);
void func_800A9588(Snd *, s32);
s32 func_800ABA60(s32, s32, s32, s32, s32);
s32 func_800AB9E0(s32);
void func_800ABFC4(s32, s32);
void func_800AC0CC(s32, f32);
void func_800AC1B8(s32, s32);

s32 func_800A96BC(Snd *o, s32 i) {
    s32 t;

    if (i == -1) {
        t = o->next % o->n;
        o->next++;
        i = t;
    }
    func_800A9D64(o, i);
    if (o->unk0 == 0) {
        goto fail;
    }
    if (func_800A9D64(o, i) == 0 || o->mute != 0) {
        return 0;
    }
    if (o->ch[i].vol != 0 && func_800A95F0(o, i) == 0) {
        goto body;
    }
fail:
    return 0;
body:
    func_800A9588(o, i);
    if (o->ch[i].unk10 != -1) {
        o->ch[i].voice = func_800ABA60(o->ch[i].handle, 0x7F, 0x7F, 0, o->ch[i].unk10);
    } else {
        o->ch[i].voice = func_800AB9E0(o->ch[i].handle);
    }
    if (o->ch[i].vol != 0x7F) {
        func_800ABFC4(o->ch[i].voice, o->ch[i].vol % 256);
    }
    if (o->ch[i].pitch != 0.0f) {
        func_800AC0CC(o->ch[i].voice, o->ch[i].pitch);
    }
    if (o->ch[i].unk16 != 0) {
        func_800AC1B8(o->ch[i].voice, o->ch[i].unk16);
    }
    o->ch[i].time = o->now;
    return 1;
}
