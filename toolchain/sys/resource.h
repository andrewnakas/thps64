/* stub for building old GCC on Windows */
#ifndef COMPAT_RESOURCE_H
#define COMPAT_RESOURCE_H
#define RLIMIT_STACK 3
#define RUSAGE_SELF 0
struct rlimit { long rlim_cur, rlim_max; };
struct timeval_c { long tv_sec, tv_usec; };
struct rusage { struct timeval_c ru_utime, ru_stime; };
static int getrlimit(int r, struct rlimit *l) { l->rlim_cur = l->rlim_max = 64L << 20; return 0; }
static int setrlimit(int r, const struct rlimit *l) { return 0; }
static int getrusage(int w, struct rusage *u) { u->ru_utime.tv_sec = u->ru_utime.tv_usec = u->ru_stime.tv_sec = u->ru_stime.tv_usec = 0; return 0; }
#endif
