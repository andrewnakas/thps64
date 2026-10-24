#include "common.h"

typedef struct { u8 pad[0x60]; u16 a; u16 b; u16 c; u16 d; } S7E6BC;

void func_8007E6BC(S7E6BC *s) {
    u16 v;
    s->a = (s->a + s->b) & 0xFFF;
    v = s->b + s->c;
    s->b = v;
    s->b = v - ((s16)v >> s->d);
}
