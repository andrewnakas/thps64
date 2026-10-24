#include "common.h"

void func_800AA8C8(void *arg0, void *arg1) {
    void *temp_a1;
    void *temp_a1_2;
    void *temp_v1;

    temp_v1 = (*(void **)((u8 *)arg1 + 0x40));
    if (temp_v1 != NULL) {
        (*(void **)((u8 *)temp_v1 + 0x3C)) = (void *) (*(void **)((u8 *)arg1 + 0x3C));
        temp_a1 = (*(void **)((u8 *)arg1 + 0x3C));
        if (temp_a1 == NULL) {
            (*(void **)((u8 *)arg0 + 0x2154)) = temp_v1;
            return;
        }
        (*(void **)((u8 *)temp_a1 + 0x40)) = temp_v1;
        return;
    }
    temp_a1_2 = (*(void **)((u8 *)arg1 + 0x3C));
    if (temp_a1_2 == NULL) {
        (*(void **)((u8 *)arg0 + 0x2154)) = NULL;
        return;
    }
    (*(void **)((u8 *)temp_a1_2 + 0x40)) = NULL;
}
