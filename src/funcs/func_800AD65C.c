/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    u32 end;
    u8 pad10[0x4];
    u32 pos;
    u8 pad18[0x20];
    u8 *data;
    u8 pad3C[0x66];
    u16 wait;
    u8 padA4[0x18];
    u8 cmd;
} Seq800AD65C;

void func_800AD65C(Seq800AD65C *s) {
    u8 c;

    do {
        s->pos += 0x100;
        if (--s->wait == 0) {
            c = *s->data++;
            if ((s8)c < 0) {
                s->cmd = c & 0x7F;
                c = *s->data++;
                if ((s8)c < 0) {
                    s->wait = (c & 0x7F) << 8;
                    s->wait += *s->data++ + 2;
                } else {
                    s->wait = c + 2;
                }
            } else {
                s->cmd = c;
                s->wait = 1;
            }
        }
    } while (s->pos < s->end);
}
