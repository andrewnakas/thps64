/* Shared types for THPS64 decomp files (one per function in src/funcs). KMC GCC 2.7.2 is a C89 compiler. */
#ifndef COMMON_H
#define COMMON_H

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;

#ifndef NULL
#define NULL ((void *)0)
#endif

#endif
