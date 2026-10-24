/* NON_MATCHING: 16/193 insns agree (difflib ratio 0.559). Returns the address of the script command after `cmd`
 * (command word + operands); NULL for the 0xFFFF end marker. The game's compare tree over the same case node
 * set (incl. the explicit no-op cases 3-5, A-C, 66-67, 79-7A, 81, AD, AF) is rooted at 0x8B; our cc1's
 * balance_case_nodes roots it at 0x8C, so the whole tree shape and block order differ. Each case value's size
 * and path was checked against the game's tree. */
#include "common.h"

/* Skip a NUL-terminated string (NUL included) and re-align to u16. */
#define SKIP_STRING(p)               \
    do {                             \
        while (*(p)++ != 0) {        \
        }                            \
        (p) += (u32)(p) & 1;         \
    } while (0)

#define ALIGN4(p) ((u8 *)(((u32)(p) + 3) & ~3))

u16 *func_8005FE98(u16 *cmd) {
    u8 *p;
    s32 op;

    op = *cmd;
    p = (u8 *)(cmd + 1);
    switch (op) {
    case 2: /* list of strings terminated by an empty string, then one word */
        while (*p != 0) {
            p++;
            SKIP_STRING(p);
        }
        p += 2;
        break;
    case 3 ... 5:
        break;
    case 0xA ... 0xC:
        break;
    case 0xD:
        p += 2;
        break;
    case 0x66 ... 0x67:
        break;
    case 0x68:
        return (u16 *)(p + 6);
    case 0x69 ... 0x6A:
        p += 2;
        break;
    case 0x73: /* one string operand */
    case 0x77:
    case 0x7E ... 0x80:
    case 0x8C:
    case 0x8E:
    case 0xB0:
    case 0xB2:
        SKIP_STRING(p);
        break;
    case 0x79 ... 0x7A:
        break;
    case 0x81:
        break;
    case 0x82: /* two words */
    case 0x87:
    case 0x8B:
    case 0x8F ... 0x92:
    case 0xA7:
    case 0xC8:
    case 0xCA:
        p += 4;
        break;
    case 0x83 ... 0x84: /* one word */
    case 0x86:
    case 0x93 ... 0x94:
    case 0x99 ... 0x9C:
    case 0xA0:
    case 0xB1:
        p += 2;
        break;
    case 0x8A:
    case 0xA3 ... 0xA6:
    case 0xA8 ... 0xAA:
    case 0xAC:
        p += 2;
        break;
    case 0xAE:
        p += 4;
        break;
    case 0xAD:
    case 0xAF:
        break;
    case 0xAB: /* word-aligned 10-byte operand */
        p = ALIGN4(p) + 10;
        break;
    case 0xC9: /* word-aligned 6-byte operand */
        p = ALIGN4(p) + 6;
        break;
    case 0x8D: /* two words, then the 0x85 record list */
        p += 4;
    case 0x85: /* word-aligned 0x18-byte records up to a 0xFF word */
        while (*(u16 *)p != 0xFF) {
            p = ALIGN4(p) + 0x18;
        }
        p += 2;
        break;
    case 0xFFFF:
        return NULL;
    }
    return (u16 *)p;
}
