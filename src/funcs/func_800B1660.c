/* cflags: -O2 */
#include "common.h"

typedef struct { u8 pad[0x24]; s32 arr[1]; } S1660;
extern void func_800B06A0(void *);
extern u8 *D_800ECC34;

s32 func_800B1660(s16 i) {
    func_800B06A0(&(*(S1660 **)(D_800ECC34 + 0x48))->arr[i]);
    return (*(S1660 **)(D_800ECC34 + 0x48))->arr[i];
}
