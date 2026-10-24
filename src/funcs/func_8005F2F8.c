/* cflags: -fexpensive-optimizations */
#include "common.h"

s32 func_8004B514(s32);
void func_8004B13C(u8 *, void *);
u16 *func_800617B8(void *, s32);
u16 *func_80061904(s32);
u8 *func_80065BF4(s32, u8 *, s32);
u8 *func_800671C4(s32, void *, s32, s32, void *);
void func_80067290(u8 *, s32);
u8 *func_8006FBE0(s32, u8 *, s32, s32);
u8 *func_800721DC(s32, u8 *, s32);
extern u8 *D_800D6180;
extern s32 D_800D6188;
extern s16 **D_800DACB0;
extern u8 *D_800DC5A0;
extern u8 *D_800DDC60;
extern s32 D_800DE7A0;

static inline u8 has_code(u8 *p, u8 c) {
    while (*p != 0xFF) {
        if (*p++ == c) {
            return 1;
        }
    }
    return 0;
}

static inline s32 skip_list(u8 *p) {
    while (*p != 0xFF) {
        p++;
    }
    return (s32)(p + 4) & ~3;
}

u8 *func_8005F2F8(s32 arg0) {
    u8 buf[16];
    s16 *s;
    s32 type;
    s32 id;
    u16 flags;
    s32 has4;
    s32 has2;
    s32 is7;
    u8 *ent;
    u16 *r;
    s32 a2;
    s32 a3;
    void *list;

    flags = 0xFFFF;
    has4 = 0;
    is7 = has4;
    ent = (u8 *)has4;
    s = D_800DACB0[arg0];
    type = *s++;
    switch (type) {
    case 7:
        is7 = 1;
    case 1:
        id = *s++;
        flags = *s++;
        s += *s + 1;
        has2 = has_code((u8 *)s, 2);
        has4 = has_code((u8 *)s, 4);
        s = (s16 *)skip_list((u8 *)s);
        switch (id) {
        case 0xCB:
            ent = func_800721DC(func_8004B514(0x330), (u8 *)s, arg0);
            break;
        case 0x192:
            ent = func_80065BF4(func_8004B514(0x350), (u8 *)s, arg0);
            break;
        case 0xD5:
        case 0xD6:
        case 0xD7:
        case 0xD8:
            ent = func_8006FBE0(func_8004B514(0x31C), (u8 *)s, arg0, id);
            break;
        }
        break;
    case 5:
        id = *s;
        r = func_800617B8(buf, arg0);
        r++;
        a2 = (r[0] == 0) * 4;
        a3 = r[1];
        if (D_800DE7A0 != 7 || ((id < 4 || id > 6) && id != 15 && id != 10)) {
            ent = func_800671C4(id & 0xFFFF, buf, a2, a3, &D_800D6188);
            if (*func_80061904(arg0) != 0) {
                func_80067290(ent, arg0);
            }
            has2 = 1;
        }
        break;
    }
    if (ent != NULL) {
        *(s16 *)(ent + 0x15E) = arg0;
        *(u16 *)(ent + 0x114) = flags;
        if (has4) {
            *(u16 *)(ent + 0x52) &= 0xFFFD;
        }
        if (is7) {
            *(u16 *)(ent + 0x52) |= 4;
        }
        if (!has2) {
            list = NULL;
            if (ent == D_800DDC60) {
                list = &D_800DDC60;
            }
            if (ent == D_800D6180) {
                list = &D_800D6180;
            }
            if (ent == D_800DC5A0) {
                list = &D_800DC5A0;
            }
            func_8004B13C(ent, list);
        }
        return ent;
    }
    return NULL;
}
