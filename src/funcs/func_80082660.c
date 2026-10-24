/* cflags: -fexpensive-optimizations */
#include "common.h"

typedef struct {
    u8 pad0[0x2E8];
    s32 score;
    u8 pad2EC[0x428 - 0x2EC];
    s32 unk428;
    u8 pad42C[0x82C - 0x42C];
    s32 unk82C;
    u8 pad830[0x930 - 0x830];
    s32 unk930;
} Sk;

void func_8003A69C(void *);
void func_8003A3E4(void *);
extern Sk *D_800DE7A8;
extern Sk *D_800DE7AC;
extern s32 D_800DE994;
extern u8 D_800D0FE3;
extern s32 D_800DE7A0;
extern u8 D_800D3F34[];
extern s32 D_800DE7C4;
extern s32 D_800D71E4;
extern s32 D_800D71D8;
extern s32 D_800D71EC;
extern s32 D_800D71DC;
extern s32 D_800D71D4;
extern s32 D_800D71E8;
extern s32 D_800D71E0;
extern s32 D_800D71F0;
extern s32 D_800DE9AC;
extern s32 D_800DE9B0;
extern s32 D_800DE9B4;

void func_80082660(void) {
    s32 d;

    d = D_800DE7A8->unk428 - D_800DE994;
    if (D_800D0FE3 != 8 && (D_800DE7A0 == 2 || D_800DE7A0 == 7 || d > 0)) {
        func_8003A69C(D_800D3F34);
        func_8003A3E4(D_800D3F34);
        if (D_800DE7A0 == 7) {
            D_800DE7C4 = 1;
        }
    } else if (D_800DE7A8->unk82C == 0 && D_800DE7AC != NULL && D_800DE7AC->unk82C == 0) {
        func_8003A69C(D_800D3F34);
        func_8003A3E4(D_800D3F34);
    }
    if (D_800DE7A0 == 8) {
        if (D_800DE7AC->score != D_800DE7A8->score) {
            if (D_800DE7A8->score < D_800DE7AC->score) {
                D_800D71E4++;
                D_800D71D8++;
                if (D_800D71EC < 0) {
                    D_800D71EC = 1;
                } else {
                    D_800D71EC++;
                }
                D_800D71DC = -D_800D71EC;
            } else {
                D_800D71D4++;
                D_800D71E8++;
                if (D_800D71DC < 0) {
                    D_800D71DC = 1;
                } else {
                    D_800D71DC++;
                }
                D_800D71EC = -D_800D71DC;
            }
            if (D_800DE7A8->score > D_800D71E0) {
                D_800D71E0 = D_800DE7A8->score;
            }
            if (D_800DE7AC->score > D_800D71F0) {
                D_800D71F0 = D_800DE7AC->score;
            }
        }
    }
    if (D_800DE9AC == 0) {
        D_800DE9AC = 1;
        D_800DE9B0 = 0x50;
        D_800DE9B4 = 0x40;
        if (D_800DE7AC != NULL) {
            D_800DE7AC->unk930 = 0;
        }
    }
}
