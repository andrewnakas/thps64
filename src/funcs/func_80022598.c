#include "common.h"

typedef struct {
    s16 m[3][3];
} SMtx;

typedef struct {
    s16 m[3][3];
    s16 pad[7];
} SMtxP;

void func_80041EC0(SMtxP *, f32 *);
void func_8009CAD0(f32 *);
void func_8009D1BC(f32 *, f32);
void func_8009D3F0(f32 *, f32);
void func_8009D624(f32 *, f32);

SMtx *func_80022598(s16 *arg0, SMtx *arg1) {
    f32 mf[16];
    SMtxP sm;
    f32 scale;

    scale = 0.00153396f;
    func_8009CAD0(mf);
    if (arg0[1] != 0) {
        func_8009D3F0(mf, arg0[1] * scale);
    }
    if (arg0[0] != 0) {
        func_8009D1BC(mf, arg0[0] * scale);
    }
    if (arg0[2] != 0) {
        func_8009D624(mf, arg0[2] * scale);
    }
    func_80041EC0(&sm, mf);
    arg1->m[0][0] = sm.m[0][0];
    arg1->m[0][1] = sm.m[1][0];
    arg1->m[0][2] = sm.m[2][0];
    arg1->m[1][0] = sm.m[0][1];
    arg1->m[1][1] = sm.m[1][1];
    arg1->m[1][2] = sm.m[2][1];
    arg1->m[2][0] = sm.m[0][2];
    arg1->m[2][1] = sm.m[1][2];
    arg1->m[2][2] = sm.m[2][2];
    return arg1;
}
