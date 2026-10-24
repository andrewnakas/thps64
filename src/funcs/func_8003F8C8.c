/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    u16 u14;
    u8 pad16[6];
    u8 b1C;
    u8 pad1D[3];
} Sub3F8C8;

typedef struct {
    u8 pad0[0x40];
    Sub3F8C8 sub[8];
    u8 pad140[0x14];
} Ent3F8C8;

typedef struct {
    u8 pad0[8];
    u8 f8;
    u8 pad9[0xB];
} Ent14_3F8C8;

typedef struct {
    u8 pad0[0x34];
    s16 x34;
    s16 x36;
    s16 x38;
    u8 pad3A[2];
    s32 dir;
    u8 pad40[0x20];
    u8 b60;
    u8 b61;
    u8 b62;
    u8 b63;
    u8 b64;
    u8 b65;
    u8 b66;
    u8 b67;
    s32 w68;
    s32 w6C;
    u8 pad70[2];
    u8 b72;
} Menu3F8C8;

void func_80039E60(s32, s32, s32);
void func_800B1A80(void *, s32);
extern u8 D_800D4770[];
extern u8 D_800D4774[];
extern u8 D_800D4778[];
extern Ent3F8C8 D_800D4D80[];
extern Ent14_3F8C8 D_800DE9F4[];

void func_8003F8C8(Menu3F8C8 *m) {
    switch (m->b67) {
    case 0:
        m->b62 = m->b61;
        if (m->dir == -1) {
            if (m->b61 != 0) {
                m->x34 = 0x8B;
                m->x36 = -0x79;
                m->b61--;
            } else {
                m->x34 = 0x8B;
                m->x36 = -0x79;
                m->b61 = 7;
            }
        } else if (m->dir == 1) {
            if (m->b61 != 7) {
                m->x34 = 0x8B;
                m->x36 = 0x18F;
                m->b61++;
            } else {
                m->x34 = 0x8B;
                m->x36 = 0x18F;
                m->b61 = 0;
            }
        }
        m->w68 = D_800DE9F4[m->b60].f8 >= D_800D4D80[m->b60].sub[m->b61].b1C;
        m->b72 = 1;
        func_80039E60(0x94, 10000, 0);
        func_800B1A80((u8 *)m + 0x340, m->w6C);
        if (m->w68 != 0) {
            m->w6C = D_800D4D80[m->b60].sub[m->b61].u14;
        } else {
            m->w6C = 0x40;
        }
        func_800B1A80((u8 *)m + 0x32C, m->w6C);
        break;
    case 1:
        if (m->dir == -1) {
            if (m->b65 != 0) {
                m->b65--;
            } else {
                m->b65 = 2;
            }
        } else if (m->dir == 1) {
            if (m->b65 != 2) {
                m->b65++;
            } else {
                m->b65 = 0;
            }
        }
        func_80039E60(0x96, 10000, 0);
        m->b66 = D_800D4770[m->b65];
        func_800B1A80((u8 *)m + 0x37C, D_800D4774[m->b65]);
        break;
    case 2:
        m->b63 = m->b64;
        if (m->dir == -1) {
            if (m->b64 != 0) {
                m->x34 = 0x127;
                m->x38 = 0xC3;
                m->b64--;
            } else {
                m->x34 = 0x127;
                m->x38 = 0xC3;
                m->b64 = 14;
            }
        } else if (m->dir == 1) {
            if (m->b64 != 14) {
                m->x34 = 0x127;
                m->x38 = 0x18B;
                m->b64++;
            } else {
                m->x34 = 0x127;
                m->x38 = 0x18B;
                m->b64 = 0;
            }
        }
        func_80039E60(0x97, 10000, 0);
        func_800B1A80((u8 *)m + 0x354, D_800D4778[m->b63]);
        func_800B1A80((u8 *)m + 0x368, D_800D4778[m->b64]);
        break;
    }
}
