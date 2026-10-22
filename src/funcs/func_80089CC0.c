#include "common.h"

typedef struct {
    u8 pad_000[0x2C];
    void * field_02C;
    u8 pad_030[0x2];
    u8 field_032;
    u8 field_033;
    u8 pad_034[0x8];
    s32 field_03C;
    u8 pad_040[0x10];
    s32 field_050;
    u8 pad_054[0x10];
    s32 field_064;
    u8 pad_068[0x10];
    s32 field_078;
    u8 pad_07C[0x10];
    s32 field_08C;
    u8 pad_090[0x10];
    s32 field_0A0;
    u8 pad_0A4[0x10];
    s32 field_0B4;
    u8 pad_0B8[0x10];
    s32 field_0C8;
    u8 pad_0CC[0x10];
    s32 field_0DC;
    u8 pad_0E0[0xC];
    f32 field_0EC;
    s32 field_0F0;
    u16 field_0F4;
    u16 field_0F6;
    u16 field_0F8;
    u16 field_0FA;
    u16 field_0FC;
    u16 field_0FE;
    u16 field_100;
    u8 pad_102[0x112];
    u8 field_214;
} State80089CC0;
typedef struct { u8 pad_000[0xC]; s32 field_00C; u8 pad_010[0x68]; } Entry80089CC0;


void func_800242CC();                                  /* extern */
void *func_80039500(void *);                                  /* extern */
void func_8003A69C(void *);                               /* extern */
void func_8003A880(void *);                               /* extern */
void func_80089F54(void *);                            /* extern */
void func_8008A0E0(void *);                            /* extern */
void func_8008B490(void *, void *, s32);                    /* extern */
void func_8008BB2C(void *, s32);                            /* extern */
void *func_8008BB50(void *);                               /* extern */
void func_800A72C0(void *);                            /* extern */
void func_800A73EC(void *, s32);                         /* extern */
void func_800B198C(void *);                            /* extern */
void func_800B1A80(void *, u16);                       /* extern */
void func_800B231C(void *, s32, s32, s32, s32);              /* extern */
#define D_8001F670 (*(const f32 *) 0x8001F670)
extern u8 D_8001F988[];
extern s32 D_800C0E20;
extern u8 D_800D3F34[];
extern Entry80089CC0 D_800D5C1C[];
extern s32 D_800DE7A0;

void *func_80089CC0(void *arg0) {
    State80089CC0 *state = arg0;
    s32 sp18[2];
    s32 mode;
    void *context;
    s32 temp_s2;
    void *temp_s0;
    void *temp_s0_2;

    func_80039500(state);
    state->field_02C = &D_8001F988;
    func_800B198C((u8 *) state + 0x38);
    func_800B198C((u8 *) state + 0x4C);
    func_800B198C((u8 *) state + 0x60);
    func_800B198C((u8 *) state + 0x74);
    func_800B198C((u8 *) state + 0x88);
    func_800B198C((u8 *) state + 0x9C);
    func_800B198C((u8 *) state + 0xB0);
    func_800B198C((u8 *) state + 0xC4);
    func_800B198C((u8 *) state + 0xD8);
    func_800A72C0((u8 *) state + 0x204);
    context = D_800D3F34;
    __asm__("" : "+r" (context));
    func_8003A69C(context);
    func_8003A880(context);
    mode = D_800DE7A0;
    if (mode == 1) {
        func_8008A0E0(state);
    } else if (((u32) (mode - 2) < 3U) || (mode == 8) || (mode == 5) || (mode == 7)) {
        func_80089F54(state);
    }
    temp_s0 = (u8 *) state + 0x204;
    func_800242CC();
    func_8008BB50(sp18);
    func_800A73EC(temp_s0, 0x501);
    func_8008B490(sp18, temp_s0, 0x501);
    state->field_214 = 1;
    state->field_032 = 1;
    state->field_033 = 1;
    if (D_800D5C1C[D_800C0E20].field_00C == 0) {
        temp_s2 = D_800DE7A0;
        if (temp_s2 == 1) {
            func_800B1A80((u8 *) state + 0x38, state->field_0FE);
            func_800B1A80((u8 *) state + 0x4C, state->field_0F4);
            state->field_050 = temp_s2;
            func_800B1A80((u8 *) state + 0x60, state->field_0F8);
            state->field_064 = temp_s2;
            func_800B1A80((u8 *) state + 0x74, state->field_0FC);
            state->field_078 = temp_s2;
            func_800B1A80((u8 *) state + 0x88, state->field_100);
            state->field_08C = temp_s2;
            func_800B1A80((u8 *) state + 0xB0, state->field_0F6);
            state->field_0B4 = temp_s2;
            func_800B1A80((u8 *) state + 0x9C, state->field_0FA);
            state->field_0A0 = temp_s2;
            temp_s0_2 = (u8 *) state + 0xC4;
            func_800B1A80(temp_s0_2, 0xC5U);
            state->field_0C8 = temp_s2;
            func_800B231C(temp_s0_2, 0x96, 0x96, 0x96, 0xFF);
        } else {
            goto check_mode;
        }
    } else if (D_800DE7A0 != 1) {
check_mode:
        if (((u32) (D_800DE7A0 - 2) < 3U) || (D_800DE7A0 == 8) || (D_800DE7A0 == 5) || (D_800DE7A0 == 7)) {
            goto initialize_first;
        }
    } else {
initialize_first:
        func_800B1A80((u8 *) state + 0x38, state->field_0FE);
    }
    state->field_03C = 1;
    func_800B1A80((u8 *) state + 0xD8, 0xCEU);
    state->field_0DC = 1;
    state->field_0EC = (f32) D_8001F670;
    state->field_0F0 = 1;
    func_8008BB2C(sp18, 2);
    return state;
}
