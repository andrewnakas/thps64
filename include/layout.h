/* Compile-time layout checks for the shared type headers (C89 / GCC 2.8: no _Static_assert).
 *   LAYOUT_ASSERT(name, cond)  -> a typedef'd array of size -1 when cond is false: a compile error, no code/data.
 *   OFFSETOF(T, f)             -> byte offset of field f in T.
 * Nothing here emits code; including it changes no object file. */
#ifndef LAYOUT_H
#define LAYOUT_H

#define OFFSETOF(T, f) ((u32) & (((T *)0)->f))
#define LAYOUT_ASSERT(name, cond) typedef char layout_assert_##name[(cond) ? 1 : -1]
#define ASSERT_OFFSET(T, f, off) LAYOUT_ASSERT(T##_##f, OFFSETOF(T, f) == (off))
#define ASSERT_SIZE(T, size) LAYOUT_ASSERT(T##_size, sizeof(T) == (size))

#endif
