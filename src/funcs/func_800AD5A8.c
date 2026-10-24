/* cflags: -O2 -Wa,-O0 */
/* near-miss 19/21: target leaves jr delay slot empty (cvt.s.w before jr); -O2 puts cvt.s.w in the slot */
#include "common.h"

f32 func_800AD5A8(void *arg0) {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((u8 *)arg0 + 0xD0)) - 1;
    (*(u8 *)((u8 *)arg0 + 0xD0)) = temp_v0;
    if (!(temp_v0 & 0xFF)) {
        if ((*(s8 *)((u8 *)arg0 + 0xD1)) == 0) {
            (*(s8 *)((u8 *)arg0 + 0xD1)) = (s8) (*(u8 *)((u8 *)arg0 + 0xD8));
            (*(u8 *)((u8 *)arg0 + 0xD0)) = (u8) (*(u8 *)((u8 *)arg0 + 0xCE));
        } else {
            (*(s8 *)((u8 *)arg0 + 0xD1)) = 0;
            (*(u8 *)((u8 *)arg0 + 0xD0)) = (u8) (*(u8 *)((u8 *)arg0 + 0xCF));
        }
    }
    return (f32) (*(s8 *)((u8 *)arg0 + 0xD1));
}
