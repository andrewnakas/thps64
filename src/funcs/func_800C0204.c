/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 off;
    s16 pad;
    s32 (*fn)(void *);
} VEntry;

typedef struct {
    u8 pad[0x28];
    VEntry e5;
    VEntry e6;
} VTbl;

typedef struct {
    u8 pad[0x1C4];
    VTbl *vt;
} Obj;

typedef struct {
    s32 *hdr;
    s32 base;
} Chunk;

void func_8009B650(void *, s32);
void func_8009F538(void);
void func_800A59E0(void *, s32);
void func_800A66D0(void);
void func_800B294C(s32, s32);
void func_800B32EC(void);
void func_800B3D14(void);
void func_800B4684(void *);
s32 func_800B8150(void);
void func_800BAA78(void *, s32);
void func_800BAE54(void *, s32, s32);
void func_800BB29C(void *, s32, s32);
void func_800BC378(void *, s32, s32, s32, s32, s32, s32);
void func_800BDA40(void);
s32 func_800C05A8(Chunk *, s32);
void func_800C0608(void *, s32, s32);
extern s32 D_80011C2C;
extern u8 D_800ECFE0[];
extern u8 D_800EECF0[];
extern u8 D_800EED10[];
extern u8 D_800F0B10[];
extern u8 D_800F0DD0[];
extern Obj *D_800F5660;
extern Chunk D_800F566C;
extern u8 D_800F5678[];
extern u8 D_800F5684[];
extern s32 D_800F56BC;
extern u8 D_800F6270[];

void func_800C0204(void) {
    s32 m;
    VTbl *vt;

    func_800C0608(D_800F6270, 7, 7);
    if (D_800F56BC == 0) {
        m = 0x10;
    } else if (D_800F56BC == 1) {
        m = 2;
    } else {
        m = 0x1E;
    }
    func_800BC378(D_800F0DD0, 3, 2, 6, 6, 6, m);
    func_800BDA40();
    func_800BAE54(D_800EED10, 4, 4);
    func_800B294C(6, 1);
    func_800A59E0(&D_800F566C, D_80011C2C);
    vt = D_800F5660->vt;
    func_800A59E0(D_800F5678, D_800F566C.base + func_800C05A8(&D_800F566C, vt->e5.fn((u8 *)D_800F5660 + vt->e5.off)));
    vt = D_800F5660->vt;
    func_8009B650(D_800F5684, D_800F566C.base + func_800C05A8(&D_800F566C, vt->e6.fn((u8 *)D_800F5660 + vt->e6.off)));
    func_800B4684(D_800ECFE0);
    func_800B3D14();
    func_800B32EC();
    func_800BB29C(D_800F0B10, 5, 5);
    func_800BAA78(D_800EECF0, func_800B8150());
    func_800A66D0();
    func_8009F538();
}
