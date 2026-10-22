#include "common.h"

s32 func_80034390(s32, s32);                /* extern */
s32 func_800349D4();                            /* extern */
s32 func_80037300(s32, void *);                   /* extern */
s32 func_80037540(s32);                         /* extern */
s32 func_800A4DD0(s32);                         /* extern */
s32 func_800A6E74(s32, s32, s32, s32, s32); /* extern */
s32 func_800BE3D8();                            /* extern */
s32 func_800BE5A4();                            /* extern */
s32 func_800BEF70(s32, s32, s32);   /* extern */
extern s32 D_800FA670;

s32 func_800377BC(s32 arg0) {
    func_80037300(arg0, &D_800FA670);
    func_800349D4();
    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    func_800A4DD0(arg0 + 0x30);
    func_80034390(arg0 + 0x30, 0);
    func_80037540(arg0);
    func_800A6E74(arg0 + 0x710, arg0 + 0x30, -1, 0, -1);
    func_800BE5A4();
    return 0;
}
