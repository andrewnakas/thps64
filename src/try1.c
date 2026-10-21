extern int D_800F5664;
extern int D_800D3668;
extern void func_8009FD60(void *, int);

typedef struct { char pad[0x88]; int x; } Thing88;

void func_80024BA8(Thing88 *a) { a->x = D_800F5664 + 2; }

void func_8002C0C0(int a) { func_8009FD60(&D_800D3668, a); }
