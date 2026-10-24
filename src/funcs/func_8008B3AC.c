#include "common.h"

void func_80043B24(void);
void func_80049DC4(s32);
void func_8005C8CC(s32 *);
void func_8005DEF0(void);
void func_800619B8(void);
void func_80061C7C(void);
void func_80061EAC(void);
void func_80061F10(void);
void func_8006305C(void);
void func_80063160(void);
void func_80068F14(void);
void func_8006A2F0(void);
void func_80073A90(void);
void func_8008AF70(s32);
extern s32 D_800D619C;
extern s32 D_800DE808;
extern s32 D_800DE814;
extern s32 D_800DE818;
extern s32 D_800DE98C;

void func_8008B3AC(s32 arg0) {
    s32 v[3];
    s32 t;

    func_8008AF70(arg0);
    func_80061EAC();
    func_80073A90();
    if (arg0 == 0) {
        func_80063160();
        func_800619B8();
        func_80061C7C();
    } else {
        func_8006305C();
    }
    func_80049DC4(0x12A6CC58);
    func_80061F10();
    func_8005DEF0();
    func_8006A2F0();
    func_80068F14();
    t = 0x8000;
    v[0] = 0;
    v[1] = t;
    v[2] = 0;
    func_8005C8CC(v);
    D_800DE808 = 0;
    func_80043B24();
    D_800D619C = 0x32C8;
    D_800DE98C = 0;
    D_800DE814 = 0x7FFFFFFF;
    D_800DE818 = 0x7FFFFFFF;
}
