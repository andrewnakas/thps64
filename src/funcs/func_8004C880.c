#include "common.h"

typedef struct { s32 v[8]; } S32x8;
typedef struct { s32 x, y, z; } Vec3i;
typedef struct { s16 x, y, z; } Vec3s;

void func_80022598(Vec3s *, void *);
void func_800226A0(void *, Vec3i *, Vec3i *);
void func_80022FCC(void *, void *);
void func_800230FC(void *, Vec3i *);

void func_8004C880(u8 *arg0) {
    s32 sp10[8];
    Vec3s sp30;
    Vec3i sp38;
    Vec3i sp48;
    Vec3i sp58;
    Vec3i sp68;
    void *s2;

    *(S32x8 *)(arg0 + 0x8A4) = *(S32x8 *)(arg0 + 0x884);
    *(Vec3i *)(arg0 + 0x8C4) = *(Vec3i *)(arg0 + 0x4);
    s2 = arg0 + 0x884;
    if (*(s32 *)(arg0 + 0x818) != 0) {
        sp38.z = 0;
        sp38.y = 0;
        sp38.x = 0;
        func_800230FC(s2, &sp38);
        func_800230FC(sp10, &sp38);
        sp48.x = 0;
        sp48.y = 0x46000;
        sp48.z = 0;
        func_800226A0(s2, &sp48, &sp58);
        sp30.z = 0;
        sp30.y = 0;
        sp30.x = *(u16 *)(arg0 + 0x81E) & 0xFFF;
        func_80022598(&sp30, sp10);
        func_80022FCC(s2, sp10);
        func_800226A0(s2, &sp48, &sp68);
        *(s32 *)(arg0 + 0x4) = *(s32 *)(arg0 + 0x4) + sp58.x - sp68.x;
        *(s32 *)(arg0 + 0x8) = *(s32 *)(arg0 + 0x8) + sp58.y - sp68.y;
        *(s32 *)(arg0 + 0xC) = *(s32 *)(arg0 + 0xC) + sp58.z - sp68.z;
    }
}
