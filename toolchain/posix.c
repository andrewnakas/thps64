/* POSIX bits old binutils expects; only what gas/ld link against */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
static char ***real_env(void) { return &_environ; }
#undef environ
char **environ;
__attribute__((constructor)) static void init_environ(void) { environ = *real_env(); }
void *sbrk(long n) { static char dummy[16]; return n == 0 ? (void *)dummy : (void *)-1; }
int getuid(void) { return 0; }
int getgid(void) { return 0; }
int fsync(int fd) { return _commit(fd); }
int mkstemps(char *tmpl, int suffixlen)
{
    int len = (int)strlen(tmpl), i, tries;
    char *x = tmpl + len - suffixlen - 6;
    static const char cs[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    for (tries = 0; tries < 1000; tries++) {
        for (i = 0; i < 6; i++) x[i] = cs[rand() % 36];
        int fd = _open(tmpl, _O_RDWR | _O_CREAT | _O_EXCL | _O_BINARY, _S_IREAD | _S_IWRITE);
        if (fd >= 0) return fd;
    }
    return -1;
}

#include <fcntl.h>
#include <stdlib.h>
/* all files binary, as on the Unix hosts these tools were written for */
__attribute__((constructor)) static void binary_files(void) { _fmode = _O_BINARY; }
