/* cflags: -fexpensive-optimizations -frerun-cse-after-loop */
#include "common.h"

extern char D_8001C734[];
extern u8 D_800E8CE0[];
extern void *D_800DACA8;
extern s32 D_800DACB4;
extern s16 **D_800DACB0;
extern s32 D_800DAC50;
extern u8 *D_800DAC00[];
extern s32 D_800DACA4;
extern u8 *D_800DAC54[];
extern s32 D_800DACAC;
extern s32 D_800DE9A8;
u8 *func_80084B2C(void *, char *);
u8 *func_800617B8(void *, s32);
void func_800601A0(s16 *, s32, s32);
void func_8006140C(void);

void func_8005F02C(u8 *name) {
    char buf[0x20];
    u8 tmp[0x10];
    u8 *s;
    u8 *d;
    s32 *p;
    s32 i;
    s32 found;
    u8 ch;

    s = (u8 *)D_8001C734;
    d = (u8 *)buf;
    while ((ch = *name) != 0) {
        *d++ = ch;
        name++;
    }
    for (; (ch = *s) != 0; s++, d++) {
        *d = ch;
    }
    *d = 0;
    {
        s32 j;

        p = D_800DACA8 = func_80084B2C(D_800E8CE0, buf);
        D_800DACB4 = *(u16 *)((u8 *)p + 0xA);
        p = (s32 *)((u8 *)p + 0xC);
        D_800DACB0 = (s16 **)p;
        for (j = 0; j < D_800DACB4; j++) {
            *p += (s32)D_800DACA8;
            p++;
        }
    }
    D_800DAC50 = 0;
    i = 0;
    while (1) {
        if (i >= D_800DACB4) {
            break;
        }
        if (*D_800DACB0[i] == 8) {
            u8 *entry = func_800617B8(tmp, i) + 6;
            D_800DAC00[D_800DAC50++] = entry;
        }
        i++;
    }
    D_800DACA4 = 0;
    i = 0;
    while (1) {
        if (i >= D_800DACB4) {
            break;
        }
        if (*D_800DACB0[i] == 8) {
            u8 *entry = func_800617B8(tmp, i);
            entry += 6;
            ch = *entry;
            if (ch == 0x48) {
                D_800DAC54[D_800DACA4++] = entry;
            }
        }
        i++;
    }
    D_800DACAC = 0xFFFF;
    found = 0;
    if (D_800DE9A8 == 2) {
        i = 0;
        while (1) {
            if (i >= D_800DACB4) {
                break;
            }
            if (*D_800DACB0[i] == 0xF) {
                found = 1;
                func_800601A0(D_800DACB0[i] + 1, i, found);
            }
            i++;
        }
    }
    if (!found) {
        i = 0;
        while (1) {
            if (i >= D_800DACB4) {
                break;
            }
            if (*D_800DACB0[i] == 4) {
                func_800601A0(D_800DACB0[i] + 1, i, 1);
            }
            i++;
        }
    }
    func_8006140C();
}
