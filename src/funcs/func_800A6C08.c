/* cflags: -O2 */
#include "common.h"
typedef struct {
    f32 x, y, z;
} Vec800A6C08;

void func_800A6C08(void *arg0, void *arg1) {
    s32 temp_f6;
    s32 temp_f6_2;
    s32 temp_f6_3;
    void *temp_a0;
    void *temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x80)) != 0) {
        temp_a0 = (*(void **)((u8 *)arg0 + 0x6C));
        temp_f6 = (s32) (((*(f32 *)((u8 *)arg1 + 0)) * 65536.0f) + 0.5f);
        (*(s16 *)((u8 *)temp_a0 + 0x18)) = (s16) (temp_f6 >> 0x10);
        (*(s16 *)((u8 *)temp_a0 + 0x38)) = (s16) temp_f6;
        temp_f6_2 = (s32) (((*(f32 *)((u8 *)arg1 + 4)) * 65536.0f) + 0.5f);
        (*(s16 *)((u8 *)temp_a0 + 0x1A)) = (s16) (temp_f6_2 >> 0x10);
        (*(s16 *)((u8 *)temp_a0 + 0x3A)) = (s16) temp_f6_2;
        temp_f6_3 = (s32) (((*(f32 *)((u8 *)arg1 + 8)) * 65536.0f) + 0.5f);
        (*(s16 *)((u8 *)temp_a0 + 0x1C)) = (s16) (temp_f6_3 >> 0x10);
        (*(s16 *)((u8 *)temp_a0 + 0x3C)) = (s16) temp_f6_3;
    } else {
        temp_v0 = (*(void **)((u8 *)arg0 + 0x68));
        *(Vec800A6C08 *)((u8 *)temp_v0 + 0x30) = *(Vec800A6C08 *)arg1;
    }
    *(Vec800A6C08 *)((u8 *)arg0 + 0x70) = *(Vec800A6C08 *)arg1;
}
