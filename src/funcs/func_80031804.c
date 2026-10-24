/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_800A8678(void *, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
extern char D_80019B08[];
extern char D_80019B10[];
extern s32 D_800F3294;
extern s32 D_800F3298;
extern f32 D_800F329C;
typedef struct {
    u32 w0;
    u32 w1;
} Gfx31804;

extern Gfx31804 *D_800F36A4;

#define SCISSOR(ulx, uly, lrx, lry)                                                              \
    {                                                                                            \
        Gfx31804 *_g = D_800F36A4++;                                                             \
        _g->w0 = 0xED000000 | (((s32)((f32)(ulx) * 4.0f) & 0xFFF) << 12) |                        \
                ((s32)((f32)(uly) * 4.0f) & 0xFFF);                                              \
        _g->w1 = (((s32)((f32)(lrx) * 4.0f) & 0xFFF) << 12) | ((s32)((f32)(lry) * 4.0f) & 0xFFF); \
    }

#define H(o) (*(s16 *)(arg0 + (o)))
#define SCALE (*(f32 *)(arg0 + 0x630))

void func_80031804(u8 *arg0) {
    f32 a;
    f32 b;

    switch (arg0[0x4B]) {
    case 0:
        func_800B1AC4(arg0 + 0x5E8, H(0x63A), H(0x658), 0.925f, 0.95f);
        func_800B1AC4(arg0 + 0x5C0, H(0x63E), 223.0f, SCALE, SCALE);
        func_800B1AC4(arg0 + 0x610, H(0x666), H(0x668), 0.925f, 0.95f);
        SCISSOR((s32)(H(0x666) * D_800F329C), 131, (s32)((H(0x666) + 0x37) * D_800F329C), 261);
        if (arg0[0x41] != arg0[0x3F]) {
            func_800B1AC4(arg0 + 0x598, H(0x64C), H(0x654), SCALE, 0.45f);
        }
        func_800B1AC4(arg0 + 0x570, H(0x636), H(0x652), SCALE, 0.45f);
        break;
    case 1:
        func_800B1AC4(arg0 + 0x5C0, H(0x63E), 223.0f, SCALE, SCALE);
        func_800B1AC4(arg0 + 0x570, H(0x636), 141.0f, SCALE, 0.45f);
        func_800B1AC4(arg0 + 0x610, H(0x670), H(0x672), 0.925f, 0.95f);
        func_800B1AC4(arg0 + 0x5E8, H(0x63A), H(0x658), 0.925f, 0.95f);
        break;
    case 2:
        func_800B1AC4(arg0 + 0x570, H(0x636), 141.0f, SCALE, 0.45f);
        func_800B1AC4(arg0 + 0x5E8, H(0x63A), H(0x658), 0.925f, 0.95f);
        func_800B1AC4(arg0 + 0x610, H(0x678), H(0x67A), 0.925f, 0.95f);
        SCISSOR((s32)(H(0x678) * D_800F329C), 216, (s32)((H(0x678) + 0x32) * D_800F329C), 260);
        if (arg0[0x43] != arg0[0x45]) {
            func_800B1AC4(arg0 + 0x598, H(0x65E), H(0x662), SCALE, SCALE);
        }
        func_800B1AC4(arg0 + 0x5C0, H(0x63E), H(0x65A), SCALE, SCALE);
        break;
    }
    SCISSOR(0, 0, D_800F3294 - 1, D_800F3298 - 1);
    if (*(s32 *)(arg0 + 0x38) != 0) {
        func_800A8678(arg0 + 0x298, D_80019B08, 500.0f, 305.0f, 2, 2, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
        func_800A8678(arg0 + 0x298, D_80019B10, 500.0f, 285.0f, 2, 2, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    }
}
