/* cflags: -O2 */
/* MATCHES only with a redundant 'if (buf) {...} else return 0;' after the goto-fail check (permuter, runs/func_8009B898_c); plain forms keep a1=size copy order wrong. */

/* -O2: 4 diffs; size computed into s1 directly vs target a1 then copied to s1 */
#include "common.h"

s32 func_8009B988();                                /* extern */
s32 func_8009B9A0(s32 **, s32, s32);            /* extern */
s32 func_8009E8F0(s32 *, s32, s32);         /* extern */
s32 func_8009ECF8(s32 *, s32);              /* extern */
s32 func_800B2CF0(void *, s32, s32, s32);       /* extern */
extern s32 D_800EA110;

s32 func_8009B898(void *arg0, s32 arg1, s32 arg2)
{
  int new_var3;
  s32 new_var;
  s32 *sp10;
  s32 base;
  s32 *new_var2;
  s32 size;
  s32 buf;
  base = (*((s32 *) (((u8 *) arg0) + 4))) + func_8009B988();
  if (arg2 == (-1))
  {
 do { buf = func_8009E8F0(&D_800EA110, 4, 8); if (buf == 0) { goto fail; } } while (0);
    if (buf)
    {
      func_800B2CF0(((u8 *) arg0) + 0xC, base, 4, buf);
      func_8009B9A0(&sp10, buf, base);
      new_var = *sp10;
      arg2 = new_var;
      func_8009ECF8(&D_800EA110, buf);
    }
    else
    {
      return 0;
    }
  }
  new_var2 = &D_800EA110;
  new_var3 = (2 * (2 * arg2)) + 8;
  size = new_var3;
  buf = func_8009E8F0(new_var2, size, 8);
  if (buf == 0)
  {
    fail:
    return 0;

  }
  func_800B2CF0(((u8 *) arg0) + 0xC, base, size, buf);
  return buf;
}
