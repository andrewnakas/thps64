/* cflags: -O2 */
/* NON_MATCHING: aln 0.680. Equivalent C (the goto into the else arm only fixes block layout); register choices for it/it->addr and the addr mask temp, and the scheduling of the request tail differ. */
/* D6 near-miss (80/102 paired, from P2 72): `goto found` with the found block placed between the if/else arms gives the game's block layout; addr+len <= ... order gives the preheader order; do-while(0) around the addr remap gives addr a2/prev a3. Left: it (game a0) vs it->addr temp (game v1) swap (greg priority 2.44 vs 2.4), addr&mask temp in v1 (game in a2), and sched1 of the request tail (game keeps the D_800FC864 load after the r->data store but hoists the n->addr load above the r->size store: alias classes differ). */
#include "common.h"

typedef struct Node_800BBE4C {
    struct Node_800BBE4C *prev;
    struct Node_800BBE4C *next;
    s32 state;
    u32 addr;
    s32 data;
} Node_800BBE4C;

typedef struct {
    u8 pad0[2];
    u8 unk2;
    u8 pad3;
    s32 *unk4;
    s32 data;
    u32 addr;
    s32 size;
    s32 pad14;
} Req_800BBE4C;

void func_800BB0D8(s32 *, u32, s32, s32, s32 *, s32, s32);
extern s32 D_800ECC10;
extern s32 D_800EED10;
extern Node_800BBE4C *D_800FC850;
extern Node_800BBE4C *D_800FC854;
extern Req_800BBE4C *D_800FC85C;
extern s32 D_800FC864;
extern s32 D_800FC868;
extern s32 D_800FC870;

Node_800BBE4C *func_800BBE4C(u32 addr, s32 len) {
    Node_800BBE4C *it;
    Node_800BBE4C *n;
    Node_800BBE4C *prev;
    Node_800BBE4C *nx;
    Req_800BBE4C *r;

    if ((addr & 0xFF000000) == 0xFF000000) {
        do { addr = (addr & 0xFFFFFF) + 0x140000; } while (0);
    } else if (D_800ECC10 & 1) {
        goto fail;
    }
    prev = NULL;
    for (it = D_800FC850; it != NULL; it = it->next) {
        if (addr < it->addr) {
            break;
        }
        prev = it;
        if (addr + len <= it->addr + D_800FC864) {
            goto found;
        }
    }
    n = D_800FC854;
    if (n == NULL) {
        return D_800FC850;
    }
    D_800FC854 = n->next;
    if (prev != NULL) {
        nx = prev->next;
        n->next = nx;
        if (nx != NULL) {
            nx->prev = n;
        }
        n->prev = prev;
        prev->next = n;
    } else {
        goto head;
    found:
        return it;
    head:
        n->prev = NULL;
        n->next = D_800FC850;
        if (D_800FC850 != NULL) {
            D_800FC850->prev = n;
        }
        D_800FC850 = n;
    }
    n->addr = addr & ~1;
    n->state = 2;
    r = &D_800FC85C[D_800FC868++];
    r->unk2 = 0;
    r->unk4 = &D_800FC870;
    r->data = n->data;
    r->size = D_800FC864;
    r->addr = n->addr;
    func_800BB0D8(&D_800EED10, r->addr, r->size, r->data, &D_800FC870, 0, 1);
    return n;
fail:
    return NULL;
}
