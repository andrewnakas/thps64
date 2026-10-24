/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

u32 func_8000574C(char *);
void func_8009FD60(char *, char *);
extern char D_800D3668[];
extern char D_800F65D0[];
extern char *D_800E8D70;

s32 func_8002BD0C(void) {
    u8 buf[16];
    u8 out[12];
    u32 len;
    u32 i;
    u8 *p;
    u8 *q;
    u8 *w;
    u32 ch;
    u8 c;
    u8 v;
    u32 sum;
    u32 key;
    u32 r;
    u32 m;
    u32 k;
    u32 prod;
    u32 bias;
    u32 lo;
    u32 blank;
    u32 rem;
    u8 space;
    char *name;
    char *dst;

    name = D_800D3668;
    len = func_8000574C(name);
    func_8009FD60((char *)buf, name);
    i = 0;
    while (1) {
        if (i >= 13) {
            break;
        }
        if (i < len) {
            c = buf[i];
            v = c - 'a';
            if (v >= 26) {
                v = c - 'A';
                if (v >= 26) {
                    buf[i] = 26;
                } else {
                    buf[i] = v;
                }
            } else {
                buf[i] = v;
            }
        } else {
            buf[i] = 26;
        }
        i++;
    }
    out[11] = 0;
    sum = 0;
    key = 0x98534637;
    bias = 0x10014;
    i = 0;
    while (1) {
        if (i >= 11) {
            break;
        }
        r = buf[i];
        lo = key & 0xFFFF;
        k = r + bias;
        k -= lo;
        m = k % 27;
        out[i] = m;
        prod = sum * 0x75344393;
        r += 0x92438937;
        sum += prod + r;
        key = key + m;
        key = key * 0x34985343 + 0x64358931;
        i++;
    }
    i = 0;
    while (1) {
        if (i >= 2) {
            break;
        }
        rem = sum % 27;
        sum /= 27;
        if (buf[i + 11] != (u8)rem) {
            return 0;
        }
        i++;
    }
    blank = 26;
    space = ' ';
    w = out;
    while (1) {
        if (w >= out + 11) {
            break;
        }
        ch = *w;
        if ((u8)ch == blank) {
            *w = space;
        } else if ((u8)ch < 27) {
            *w = ch + 'a';
        } else {
            return 0;
        }
        w++;
    }
    i = 10;
    p = out;
    while (1) {
        q = &p[i];
        if (*q != ' ') {
            break;
        }
        i--;
        *q = 0;
    }
    dst = D_800F65D0;
    func_8009FD60(dst, (char *)p);
    D_800E8D70 = dst;
    return 1;
}
