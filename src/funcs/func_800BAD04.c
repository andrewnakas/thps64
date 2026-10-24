/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 used;
    void *obj;
} Entry;

typedef struct {
    Entry *entries;
    s32 count;
} Table;

void func_800BA8A4(void *, s32);

void func_800BAD04(Table *arg0, s32 arg1) {
    s32 i = 0;

    while (1) {
        Entry *e;
        if (i >= arg0->count) {
            break;
        }
        e = &arg0->entries[i];
        if (e->used != 0) {
            func_800BA8A4(e->obj, arg1);
        }
        i++;
    }
}
