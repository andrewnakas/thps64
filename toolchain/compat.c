#include <string.h>
char *index(const char *s, int c) { return strchr(s, c); }
char *rindex(const char *s, int c) { return strrchr(s, c); }

#include <fcntl.h>
#include <stdlib.h>
/* all files binary, as on the Unix hosts these tools were written for */
__attribute__((constructor)) static void binary_files(void) { _fmode = _O_BINARY; }
