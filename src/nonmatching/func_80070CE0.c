/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: 12/824 insns agree (difflib ratio 0.527 against the game's 1002). Script-opcode interpreter.
 * The game dispatches its 45 case nodes (0x4101..0x42C0, 3 ranges) as a balanced compare tree rooted at 0x4281;
 * our cc1 emits a jump table (case range 447 is under 10x the case count, so GCC 2.8 expand_end_case picks a
 * table), so dispatch, block order and register allocation differ. Every case body was checked against the game
 * asm block by block. Cases are listed in the game's code-block order (not numeric) so bodies line up. */
#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i_80070CE0;

/* C++-style vtable entry: this-adjust + function pointer. */
typedef struct {
    s16 delta;
    s16 pad;
    void *fn;
} VEnt_80070CE0;

typedef struct {
    u16 flags;
    u8 pad2[2];
    Vec3i_80070CE0 pos;           /* 0x04 */
    u8 pad10[0x48 - 0x10];
    VEnt_80070CE0 *vtbl;          /* 0x48 */
    u8 pad4C[0x84 - 0x4C];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    u8 pad90[0x15E - 0x90];
    u16 unk15E;
    u8 pad160[0x294 - 0x160];
    u8 unk294;
    u8 pad295[0x29A - 0x295];
    s8 unk29A;
    u8 unk29B;
    u16 unk29C;
    u8 pad29E[0x2A4 - 0x29E];
    s32 condFlags;                /* 0x2A4 */
    u16 *pc;                      /* 0x2A8 */
    u16 *label[0x12];             /* 0x2AC */
    s16 unk2F4;
    u8 pad2F6[0x310 - 0x2F6];
    s32 unk310;
} Script_80070CE0;

typedef s32 (*GetFn_80070CE0)(void *, u16);
typedef void (*SetFn_80070CE0)(void *, u16);
typedef void (*VoidFn_80070CE0)(void *);

typedef struct {
    u8 pad0[0x60];
    s32 unk60;
    u8 pad64[0x78 - 0x64];
} Player_80070CE0;

extern void func_80039E60(s16, s32, s32);
extern void func_8003A0C4(s16, Vec3i_80070CE0 *, s32);
extern void func_8003A0DC(u16);
extern void func_8003A0E4(u16);
extern void func_800459B8(u16);
extern void func_8004A204(Script_80070CE0 *, u16, s32, s32, s32);
extern void func_8004AE2C(Script_80070CE0 *, u16, s8);
extern void func_8004B468(Script_80070CE0 *, u16 *);
extern void func_8005F634(u16);
extern u8 *func_800617B8(Vec3i_80070CE0 *, u16);
extern u16 *func_80061904(u16);
extern void func_80061ACC(u16 *);
extern void func_80061B94(s32, u16);
extern void func_80061BC8(u16 *);
extern s32 func_8006648C(s32);
extern void *func_800671C4(u16, Vec3i_80070CE0 *, u16, u16, void *);
extern void func_800672FC(void *, s32, s32);
extern void func_80072ACC(Script_80070CE0 *);
extern void func_80073D68(s32, Vec3i_80070CE0 *, s32);
extern void func_80079774(void);
extern void func_8007977C(s32);
extern void func_80079784(void);
extern void func_8007978C(u16);
extern void func_800797A4(Vec3i_80070CE0 *);
extern void func_800797AC(s32);
extern s32 D_800C0E20;
extern Player_80070CE0 D_800D5C1C[];
extern s32 D_800D6180;
extern u8 D_800D6188[];
extern s32 D_800D61A8;
extern s32 D_800DC618;
extern s32 D_800DDC60;
extern s32 D_800DE144;
extern s32 D_800DE7A0;
extern s32 D_800DE814;
extern s32 D_800DE818;
extern s32 D_800DE98C;
extern s32 D_800DE9A8;

#define VAR_FLAG 0x2000 /* operand names a script variable instead of a literal */

/* Virtual slot 10: read script variable `v` (may consume further operand words from c->pc). */
#define GET_VAR(c, v) ((GetFn_80070CE0)(c)->vtbl[10].fn)((u8 *)(c) + (c)->vtbl[10].delta, (v))
/* Virtual slot 9: write script variable `v` (value and index words are read from c->pc). */
#define SET_VAR(c, v) ((SetFn_80070CE0)(c)->vtbl[9].fn)((u8 *)(c) + (c)->vtbl[9].delta, (v))

/* Skip the body of a failed conditional: scan to the matching 0x4120 (end-if, consumed), counting nested
 * conditionals 0x4112..0x4116; stops after an 0x4100 (end of script) at any depth. */
static inline void skip_block_80070CE0(Script_80070CE0 *c) {
    s32 depth;
    u16 op;

    depth = 0;
    do {
        op = *c->pc++;
        if (op == 0x4120) {
            if (depth == 0) {
                return;
            }
            depth--;
        } else if ((u16)(op - 0x4112) < 5) {
            depth++;
        }
    } while (op != 0x4100);
}

/* Literal operands are zero-extended; variable values are truncated to s16 and sign-extended. */
static inline s32 read_arg_80070CE0(Script_80070CE0 *c) {
    s32 v;

    v = *c->pc++;
    if (v & VAR_FLAG) {
        v = (s16)GET_VAR(c, v);
    }
    return v;
}

/* Returns 0 to stop running the script this frame, 1 to continue. */
s32 func_80070CE0(Script_80070CE0 *c, u16 op) {
    Vec3i_80070CE0 tmp;
    s16 buf[8];
    s32 v;
    s32 a;
    s32 b;
    u16 id;
    u16 arg1;
    u16 arg2;
    u16 arg3;
    s32 n;
    u16 *save;
    u16 *s;
    s16 *d;
    u8 *p;
    u16 *list;
    s32 i;
    void *obj;
    s32 f;

    switch (op) {
    case 0x42A0: /* spawn */
        v = *c->pc++;
        if (v & VAR_FLAG) {
            v = GET_VAR(c, v);
        }
        arg1 = *c->pc++;
        arg2 = *c->pc++;
        arg3 = *c->pc++;
        obj = func_800671C4(v, &c->pos, arg1, arg2, D_800D6188);
        if (obj != NULL) {
            func_800672FC(obj, arg3 << 12, 5);
            return 1;
        }
        break;
    case 0x429E:
        if (c->unk310 != 0) {
            if (c->unk310 == D_800D61A8) {
                D_800DE814 = c->pos.y;
            } else {
                D_800DE818 = c->pos.y;
            }
        } else {
            D_800DE814 = c->pos.y;
            D_800DE818 = c->pos.y;
        }
        break;
    case 0x42A2:
        D_800DE98C = *c->pc++;
        break;
    case 0x429A: /* at another script's position */
    case 0x42A6: /* at our own position */
        if (op == 0x429A) {
            v = *c->pc++;
            if (v & VAR_FLAG) {
                v = GET_VAR(c, v);
            }
            func_800617B8(&tmp, v);
        } else {
            tmp = c->pos;
        }
        if (*c->pc++ == 2) {
            func_80072ACC(c);
            c->pc += 2;
        }
        break;
    case 0x4227:
        id = *c->pc++;
        if (id == 0) {
            c->condFlags &= ~2;
        } else {
            c->unk29A = id;
            c->unk29B = 0;
            c->condFlags |= 2;
        }
        break;
    case 0x4298:
        v = *c->pc++;
        if (v & VAR_FLAG) {
            v = GET_VAR(c, v);
        }
        if (D_800DE144 == 0) {
            break;
        }
        if ((u16)v == 0) {
            func_80073D68(D_800DE144, &c->pos, 2);
        } else if ((u16)v == 1) {
            func_80073D68(D_800DE144, &c->pos, 1);
        } else {
            func_80073D68(D_800DE144, &c->pos, 0);
        }
        return 1;
    case 0x4296:
        func_8003A0DC(*c->pc++);
        return 1;
    case 0x4297:
        func_8003A0E4(*c->pc++);
        return 1;
    case 0x4299:
        func_8007978C(*c->pc++);
        return 1;
    case 0x4293: /* 32-bit operand, word-aligned */
        p = (u8 *)(((s32)c->pc + 3) & ~3);
        func_800797AC(*(s32 *)p);
        c->pc = (u16 *)(p + 4);
        break;
    case 0x4294:
        func_800797A4(&c->pos);
        i = 0;
        list = func_80061904(c->unk15E);
        s = list;
        while (1) {
            if (i >= *list) {
                break;
            }
            func_800617B8(&tmp, s[1]);
            func_800797A4(&c->pos);
            s++;
            i++;
        }
        if (D_800DE7A0 == 7) {
            break;
        }
        f = 0;
        if (D_800DE9A8 == 1) {
            f = D_800D5C1C[D_800C0E20].unk60 != 0;
        }
        func_8007977C(f);
        return 1;
    case 0x429D:
        func_800797A4(&c->pos);
        func_80079784();
        return 1;
    case 0x4295:
        func_80079774();
        return 1;
    case 0x42B1:
    case 0x42B2:
        v = *c->pc++;
        if (v & VAR_FLAG) {
            v = GET_VAR(c, v);
        }
        list = func_80061904(v);
        if (op == 0x42B1) {
            func_80061ACC(list);
        } else {
            func_80061BC8(list);
        }
        return 1;
    case 0x42B3:
    case 0x42B4:
        v = *c->pc++;
        if (v & VAR_FLAG) {
            v = GET_VAR(c, v);
        }
        if (op == 0x42B3) {
            func_80061B94(D_800DDC60, v);
            func_80061B94(D_800D6180, v);
        } else {
            func_8005F634(v);
        }
        return 1;
    case 0x42C0:
        id = *c->pc++;
        if (D_800DE7A0 == 1 && func_8006648C(1) == 0 && D_800DC618 != 2) {
            func_800459B8(id);
        }
        return 1;
    case 0x42B0: /* skip an inline string */
        p = (u8 *)c->pc;
        while (*p != 0) {
            p++;
        }
        c->pc = (u16 *)(((s32)p & 1) ? p + 1 : p + 2);
        break;
    case 0x4226:
        c->unk8C = 0;
        c->unk88 = 0;
        c->unk84 = 0;
        break;
    case 0x4200: /* inline string: pass it on, then skip it (NUL included, re-aligned to u16) */
        func_8004B468(c, c->pc);
        p = (u8 *)c->pc;
        while (*p != 0) {
            p++;
        }
        c->pc = (u16 *)(((s32)p & 1) ? p + 1 : p + 2);
        break;
    case 0x4106: /* jump to another script */
        v = *c->pc++;
        if (v & VAR_FLAG) {
            v = GET_VAR(c, v);
        }
        c->pc = (u16 *)(func_800617B8(&tmp, v) + 6);
        break;
    case 0x4104: /* define label */
        id = *c->pc++;
        c->label[id] = c->pc;
        break;
    case 0x4105: /* pre-scan the script for label definitions */
        save = c->pc;
        while (*c->pc != 0x4100) {
            if (*c->pc++ == 0x4104) {
                id = *c->pc++;
                c->label[id] = c->pc;
            }
        }
        c->pc = save;
        break;
    case 0x4101: /* goto label */
        id = *c->pc++;
        c->pc = c->label[id];
        break;
    case 0x4102: /* goto label and yield */
        id = *c->pc++;
        c->pc = c->label[id];
        return 0;
    case 0x4116: /* if no flag set */
        id = *c->pc++;
        if (!(c->condFlags & id)) {
            break;
        }
        skip_block_80070CE0(c);
        return 1;
    case 0x4115: /* if all flags set */
        id = *c->pc++;
        if ((c->condFlags & id) == id) {
            break;
        }
        skip_block_80070CE0(c);
        return 1;
    case 0x4110: /* var += x */
    case 0x4111: /* var -= x */
        n = 0;
        id = *c->pc++;
        s = c->pc;
        a = (s16)GET_VAR(c, id);
        /* copy the index words the getter consumed, so the setter sees the same variable */
        d = buf;
        while (s != c->pc) {
            *d++ = *s++;
            n++;
        }
        b = *c->pc++;
        if (b & VAR_FLAG) {
            b = (s16)GET_VAR(c, b);
        }
        if (op == 0x4110) {
            buf[n] = a + b;
        } else {
            buf[n] = a - b;
        }
        save = c->pc;
        c->pc = (u16 *)buf;
        SET_VAR(c, id);
        c->pc = save;
        break;
    case 0x4112: /* if (a > b) */
        a = read_arg_80070CE0(c);
        b = read_arg_80070CE0(c);
        if (b < a) {
            return 1;
        }
        skip_block_80070CE0(c);
        return 1;
    case 0x4113: /* if (a < b) */
        a = read_arg_80070CE0(c);
        b = read_arg_80070CE0(c);
        if (a < b) {
            return 1;
        }
        skip_block_80070CE0(c);
        return 1;
    case 0x4114: /* if (a == b) */
        a = read_arg_80070CE0(c);
        b = read_arg_80070CE0(c);
        if (a == b) {
            break;
        }
        skip_block_80070CE0(c);
        return 1;
    case 0x4280: /* store a (possibly variable) value and yield */
        id = *c->pc++;
        c->unk2F4 = id;
        if (id & VAR_FLAG) {
            c->unk2F4 = GET_VAR(c, id);
        }
        return 0;
    case 0x4281: /* wait until bit 0 of unk29C is set: re-run this opcode next frame */
        if (c->unk29C & 1) {
            return 1;
        }
        c->pc--;
        return 0;
    case 0x4107: /* yield */
        return 0;
    case 0x4240:
        c->unk294 = 0;
        return 0;
    case 0x4201:
        id = *c->pc++;
        func_8004AE2C(c, id, *c->pc++);
        return 1;
    case 0x4202:
        func_8004A204(c, *c->pc++, 0, -1, -1);
        return 1;
    case 0x4203:
        c->flags &= 0xFFFE;
        break;
    case 0x4204:
        c->flags |= 1;
        break;
    case 0x4205: /* virtual slot 2 */
        ((VoidFn_80070CE0)c->vtbl[2].fn)((u8 *)c + c->vtbl[2].delta);
        return 1;
    case 0x4290:
        func_80039E60(*c->pc++, 10000, 0);
        return 1;
    case 0x4291:
        func_8003A0C4(*c->pc++, &c->pos, 0);
        return 1;
    case 0x4292:
        c->pc++;
        break;
    case 0x429C:
        c->pc += 5;
        break;
    case 0x42A3:
        break;
    default:
        return 1;
    }
    return 1;
}
