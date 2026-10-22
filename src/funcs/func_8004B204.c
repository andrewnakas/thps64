#include "common.h"

typedef struct {
    u8 pad[0x10];
    u16 a;
    u16 b;
    u16 c;
} Struct8004B204;

u16 *func_8004B204(Struct8004B204 *arg0, u16 *arg1) {
    arg0->a = *arg1;
    arg1++;
    arg0->b = *arg1;
    arg1++;
    arg0->c = *arg1;
    arg1++;
    return arg1;
}
