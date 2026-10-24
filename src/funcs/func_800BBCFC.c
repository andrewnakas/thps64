/* cflags: -O2 */
#include "common.h"

typedef struct Node800BBCFC {
    struct Node800BBCFC *a;
    struct Node800BBCFC *b;
    s32 count;
} Node800BBCFC;

void func_80004ED0(void *, void *, s32);
extern Node800BBCFC *D_800FC850;
extern Node800BBCFC *D_800FC854;
extern s32 D_800FC868;
extern u8 D_800FC870[];

void func_800BBCFC(void) {
    s32 msg[2];
    Node800BBCFC *n;
    Node800BBCFC *nx;
    Node800BBCFC *t;

    if (D_800FC868 != 0) {
        do {
            func_80004ED0(D_800FC870, msg, 0);
        } while (--D_800FC868 != 0);
    }
    n = D_800FC850;
    while (1) {
        if (n == NULL) {
            break;
        }
        if (--n->count == 0) {
            nx = n->b;
            if (nx != NULL) {
                nx->a = n->a;
            }
            if (n->a != NULL) {
                n->a->b = n->b;
            } else {
                D_800FC850 = n->b;
            }
            t = D_800FC854;
            n->a = NULL;
            D_800FC854 = n;
            n->b = t;
            n = nx;
        } else {
            n = n->b;
        }
    }
}
