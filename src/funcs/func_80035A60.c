#include "common.h"

void func_80087620(char *, char *);
void func_800BAD04(void *, char *);
void func_800B4930(void *, char *);
extern char D_800D3DA4[];
extern char D_800D3DB4[];
extern char D_800D3DC4[];
extern char D_800D3DD4[];
extern char D_800D3DE4[];
extern char D_800D3DF4[];
extern char D_800D3E04[];
extern char D_800D3E14[];
extern char D_800D3E24[];
extern char D_800D3E34[];
extern char D_800D3E44[];
extern char D_800D3E54[];
extern char D_800D3E64[];
extern char D_800D3E74[];
extern char D_800D3E84[];
extern u8 D_800EECF0[];
extern u8 D_800ECFE0[];

void func_80035A60(u8 *arg0) {
    char buf[0x100];
    char *a;
    char *b;

    switch (*(u32 *)(arg0 + 0x40)) {
    case 19:
    case 20:
        a = D_800D3DA4;
        b = D_800D3DB4;
        break;
    case 62:
    case 63:
        a = D_800D3DC4;
        b = D_800D3DD4;
        break;
    case 14:
    case 15:
        a = D_800D3DA4;
        b = D_800D3DE4;
        break;
    case 55:
    case 56:
        a = D_800D3DF4;
        b = D_800D3E04;
        break;
    case 0:
    case 1:
        a = D_800D3DA4;
        b = D_800D3E14;
        break;
    case 4:
    case 5:
        a = D_800D3E24;
        b = D_800D3E34;
        break;
    case 49:
    case 50:
        a = D_800D3E44;
        b = D_800D3E54;
        break;
    case 10:
    case 11:
        a = D_800D3E64;
        b = D_800D3E74;
        break;
    case 25:
    case 26:
        a = D_800D3DA4;
        b = D_800D3E84;
        break;
    default:
        return;
    }
    func_80087620(a, buf);
    func_800BAD04(D_800EECF0, buf);
    func_80087620(b, buf);
    func_800B4930(D_800ECFE0, buf);
}
