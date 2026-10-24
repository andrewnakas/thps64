/* cflags: -fexpensive-optimizations */
/* NON_MATCHING: a/c1 reg swap + k=0 placement; best 45/54. Equivalent C; only register allocation / scheduling / delay-slot choice differ. */
/* nearly 45/54 with -fexpensive-optimizations (CFH/B1 draft): a/c1 registers a1<->a3 swapped and k = 0 placed before
 * the c1/c2 loads (game: after). Z1: moving k = 0 after the loads loses (38-42); the compare as a static inline helper
 * (strncasecmp-like, structured for/return) loses badly (14-35) under every flag set. */
#include "common.h"

typedef struct Node626B4 {
    u32 *table;
    struct Node626B4 *next;
} Node626B4;

extern Node626B4 *D_800DAD9C;

void *func_800626B4(u8 *name) {
    void *result;
    Node626B4 *node;
    s32 found;
    u32 i;
    u32 n;
    u8 *entry;
    u32 *tbl;
    u8 *a;
    u8 *b;
    u8 c1;
    u8 c2;
    s32 k;

    result = NULL;
    node = D_800DAD9C;
    while (1) {
        found = 0;
        if (node == NULL) {
            break;
        }
        tbl = node->table;
        n = *tbl;
        entry = (u8 *)(tbl + 1);
        i = 0;
        while (1) {
            a = name;
            if (i >= n) {
                break;
            }
            b = entry;
            k = 0;
            c1 = *a & 0xDF;
            c2 = *b & 0xDF;
            while (1) {
                if (!((u8)c1 == c2 && (u8)c1 != 0 && k < 8)) {
                    break;
                }
                a++;
                b++;
                c1 = *a & 0xDF;
                c2 = *b & 0xDF;
                k++;
            }
            if ((c1 == 0 && c2 == 0) || k == 8) {
                found = 1;
                break;
            }
            entry += *(s32 *)(entry + 8) * 8 + 0xC;
            i++;
        }
        if (found) {
            result = entry + 0xC;
            break;
        }
        node = node->next;
    }
    return result;
}
