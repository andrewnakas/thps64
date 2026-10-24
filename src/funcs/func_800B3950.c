/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad[0x1C4];
    void *vt;
} S800B3950;

S800B3950 *func_8009FF00(S800B3950 *);
extern u8 D_80021F60[];
extern S800B3950 *D_800F5660;

S800B3950 *func_800B3950(S800B3950 *arg0) {
    func_8009FF00(arg0);
    arg0->vt = D_80021F60;
    D_800F5660 = arg0;
    return arg0;
}
