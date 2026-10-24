/* cflags: -O2 */
#include "common.h"

typedef struct Node800BBB50 {
    struct Node800BBB50 *prev;
    struct Node800BBB50 *next;
    s32 unk8;
    s32 id;
    void *buf;
} Node800BBB50;

extern void func_80001EC0(void *, void *, s32);
extern s32 func_80004850(void);
extern s32 func_80010B40(void);
extern void func_8009E0F0(void *, s32, s32);
extern void *func_800B1850(s32);
extern void func_800B18A4(void *, s32, s32);
extern s32 D_800FC850;
extern Node800BBB50 *D_800FC854;
extern Node800BBB50 *D_800FC858;
extern void *D_800FC85C;
extern void *D_800FC860;
extern s32 D_800FC864;
extern s32 D_800FC868;
extern u8 D_800FC870[];
extern s32 D_800FC888;
extern s32 D_800FC88C;
extern void func_800BBDD4(void);

void *func_800BBB50(s32 arg0, s32 arg1) {
    s32 i;

    D_800FC888 = func_80004850();
    D_800FC88C = func_80010B40();
    D_800FC85C = func_800B1850(arg0 * 0x30);
    D_800FC860 = func_800B1850(arg0 * 8);
    D_800FC858 = func_800B1850(arg0 * sizeof(Node800BBB50));
    func_800B18A4(D_800FC858, 0, arg0 * sizeof(Node800BBB50));
    for (i = 0; i < arg0 - 1; i++) {
        D_800FC858[i].next = &D_800FC858[i] + 1;
        D_800FC858[i].next->prev = &D_800FC858[i];
        D_800FC858[i].buf = func_800B1850(arg1);
        D_800FC858[i].id = -1;
    }
    D_800FC858[i].buf = func_800B1850(arg1);
    D_800FC858[i].id = -1;
    func_8009E0F0(D_800FC858[0].buf, 0, arg1);
    func_8009E0F0(D_800FC858[1].buf, 0, arg1);
    D_800FC864 = arg1;
    D_800FC868 = 0;
    D_800FC850 = 0;
    D_800FC854 = D_800FC858;
    func_80001EC0(D_800FC870, D_800FC860, arg0 * 2);
    return func_800BBDD4;
}
