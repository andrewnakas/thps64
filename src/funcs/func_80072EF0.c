typedef struct { char pad[0x2E4]; short v[1]; } S80072EF0;

void func_80072EF0(S80072EF0 *a0, unsigned char a1, short a2) {
    a0->v[a1] = a2;
}
