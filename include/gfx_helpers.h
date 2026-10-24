/* Display-list helpers: the Gfx packet type, the game's display-list write pointer D_800F36A4, and the packet
 * writer shapes that matched files use. Include after common.h.
 *
 * Evidence: 34 matched files declare D_800F36A4 as a pointer to an 8-byte {u32 w0; u32 w1;} packet and write it
 * with post-increment (func_80024A60, func_80025C54, func_8003E210, func_800BFDD4, func_8003E9FC, ...).
 * The opcodes are what the game writes (F3DEX2-family RSP opcodes 0xD9/0xE2/0xE3, RDP opcodes 0xE7-0xFF).
 *
 * Two write shapes match the game; pick the one the asm shows:
 *   GFX_PUSH(w0, w1)  - `{ Gfx *_g = D_800F36A4++; _g->w0 = ..; _g->w1 = ..; }` (pointer reloaded per packet)
 *   h = D_800F36A4; D_800F36A4 = h + 1; h[0].w0 = ..; h[0].w1 = ..; D_800F36A4 = h + 2; h[1]... (base kept in a
 *     register, D_800F36A4 stored before each packet: func_80024A60, func_8003E210)
 *
 * Opt-outs: #define GFX_NO_GLOBAL before including to skip the extern (when a file types D_800F36A4 itself).
 */
#ifndef GFX_HELPERS_H
#define GFX_HELPERS_H

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

#ifndef GFX_NO_GLOBAL
extern Gfx *D_800F36A4;   /* display-list write pointer */
#endif

/* exact form of GSET in func_800B233C / func_800BF6AC / func_800BFDD4 (type renamed) */
#define GFX_PUSH(a, b)                        \
    {                                         \
        Gfx *_g = D_800F36A4++;               \
        _g->w0 = (a);                         \
        _g->w1 = (b);                         \
    }

/* exact form of SCISSOR in func_80031804 / func_8003E9FC: gDPSetScissor with float coordinates (10.2 fixed) */
#define GFX_SCISSOR(ulx, uly, lrx, lry)                                                          \
    {                                                                                            \
        Gfx *_g = D_800F36A4++;                                                                  \
        _g->w0 = 0xED000000 | (((s32)((f32)(ulx) * 4.0f) & 0xFFF) << 12) |                       \
                 ((s32)((f32)(uly) * 4.0f) & 0xFFF);                                             \
        _g->w1 = (((s32)((f32)(lrx) * 4.0f) & 0xFFF) << 12) | ((s32)((f32)(lry) * 4.0f) & 0xFFF); \
    }

/* float -> 10.2 fixed screen coordinate: FX in func_800B233C / func_800BD740 / func_800BFDD4 */
#define GFX_FX(v) ((s32)((f32)(v) * 4.0f) & 0xFFF)

/* First words the game writes (command byte in bits 24-31). Use them or the plain constants, the code is the same. */
#define GFX_OP_GEOMETRYMODE   0xD9000000   /* F3DEX2 G_GEOMETRYMODE (0xD9FFFBFF / 0xD9FFFFFF in func_80025C54) */
#define GFX_OP_SETOTHERMODE_L 0xE2000000   /* F3DEX2 G_SETOTHERMODE_L (0xE200001C) */
#define GFX_OP_SETOTHERMODE_H 0xE3000000   /* F3DEX2 G_SETOTHERMODE_H (0xE3000A01, 0xE3001201, ...) */
#define GFX_OP_RDPPIPESYNC    0xE7000000
#define GFX_OP_SETSCISSOR     0xED000000
#define GFX_OP_SETPRIMCOLOR   0xFA000000
#define GFX_OP_SETENVCOLOR    0xFB000000
#define GFX_OP_SETCOMBINE     0xFC000000

#endif
