/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx2040;

typedef struct {
    u8 unk0;
    u8 bits;
    u8 kind;
} Hdr2040;

extern Gfx2040 *D_800F36A4;

#define SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define MAXI(a, b) ((a) > (b) ? (a) : (b))
#define MINI(a, b) ((a) < (b) ? (a) : (b))
static inline s32 txl_bytes(s32 txls, s32 b_txl) {
    return txls * b_txl;
}

#define TXL2WORDS(txls, b_txl) MAXI(1, (txl_bytes(txls, b_txl) / 8))
#define CALC_DXT(width, b_txl) (((1 << 11) + TXL2WORDS(width, b_txl) - 1) / TXL2WORDS(width, b_txl))

#define gDPSetTextureImage(pkt, f, s, w, i) \
    { Gfx2040 *_g = (Gfx2040 *)(pkt); \
      _g->w0 = SHIFTL(0xFD, 24, 8) | SHIFTL(f, 21, 3) | SHIFTL(s, 19, 2) | SHIFTL((w) - 1, 0, 12); \
      _g->w1 = (u32)(i); }
#define gDPSetTile(pkt, fmt, siz, line, tmem, tile, palette, cmt, maskt, shiftt, cms, masks, shifts) \
    { Gfx2040 *_g = (Gfx2040 *)(pkt); \
      _g->w0 = SHIFTL(0xF5, 24, 8) | SHIFTL(fmt, 21, 3) | SHIFTL(siz, 19, 2) | SHIFTL(line, 9, 9) | SHIFTL(tmem, 0, 9); \
      _g->w1 = SHIFTL(tile, 24, 3) | SHIFTL(palette, 20, 4) | SHIFTL(cmt, 18, 2) | SHIFTL(maskt, 14, 4) | \
               SHIFTL(shiftt, 10, 4) | SHIFTL(cms, 8, 2) | SHIFTL(masks, 4, 4) | SHIFTL(shifts, 0, 4); }
#define gDPNoParam(pkt, cmd) \
    { Gfx2040 *_g = (Gfx2040 *)(pkt); _g->w0 = SHIFTL(cmd, 24, 8); _g->w1 = 0; }
#define gDPLoadBlock(pkt, tile, uls, ult, lrs, dxt) \
    { Gfx2040 *_g = (Gfx2040 *)(pkt); \
      _g->w0 = SHIFTL(0xF3, 24, 8) | SHIFTL(uls, 12, 12) | SHIFTL(ult, 0, 12); \
      _g->w1 = SHIFTL(tile, 24, 3) | SHIFTL(MINI(lrs, 0x7FF), 12, 12) | SHIFTL(dxt, 0, 12); }
#define gDPSetTileSize(pkt, t, uls, ult, lrs, lrt) \
    { Gfx2040 *_g = (Gfx2040 *)(pkt); \
      _g->w0 = SHIFTL(0xF2, 24, 8) | SHIFTL(uls, 12, 12) | SHIFTL(ult, 0, 12); \
      _g->w1 = SHIFTL(t, 24, 3) | SHIFTL(lrs, 12, 12) | SHIFTL(lrt, 0, 12); }
#define gDPLoadTextureBlock8(pkt, timg, fmt, width, height) \
    { gDPSetTextureImage(pkt, fmt, 2, 1, timg); \
      gDPSetTile(pkt, fmt, 2, 0, 0, 7, 0, 2, 0, 0, 2, 0, 0); \
      gDPNoParam(pkt, 0xE6); \
      gDPLoadBlock(pkt, 7, 0, 0, ((((width) * (height)) + 1) >> 1) - 1, CALC_DXT(width, 1)); \
      gDPNoParam(pkt, 0xE7); \
      gDPSetTile(pkt, fmt, 1, ((txl_bytes(width, 1) + 7) >> 3), 0, 0, 0, 2, 0, 0, 2, 0, 0); \
      gDPSetTileSize(pkt, 0, 0, 0, ((width) - 1) << 2, ((height) - 1) << 2); }

void func_800B2040(s32 arg0, Hdr2040 *t, void *img, s32 w, s32 h) {
    switch (t->kind) {
    case 4:
        if (t->bits == 8) {
            gDPLoadTextureBlock8(D_800F36A4++, img, 2, w, h);
        }
        break;
    case 0:
        if (t->bits == 8) {
            gDPLoadTextureBlock8(D_800F36A4++, img, 4, w, h);
        }
        break;
    }
}
