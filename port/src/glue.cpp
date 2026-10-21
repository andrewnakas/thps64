// Small pieces the Pilotwings-derived glue expects, specialised for THPS.
#include <cstdint>

#include "recomp.h"
#include "librecomp/rsp.hpp"
#include "thps/callbacks.h"
#include "thps/glue.h"

// The audio microcode is not recompiled yet: tasks are reported complete (callbacks.cpp never matches this
// because kAspMainTextStart is unset), so the game runs silent.
RspExitReason aspMain_run(uint8_t* rdram, uint32_t ucode_addr) {
    (void)rdram; (void)ucode_addr;
    return RspExitReason::Broke;
}

namespace thps {

namespace { uint8_t* g_rdram = nullptr; }

void input_script_state(uint16_t* buttons, float* x, float* y) { *buttons = 0; *x = 0.0f; *y = 0.0f; }
void input_script_state(int, uint16_t* buttons, float* x, float* y) { *buttons = 0; *x = 0.0f; *y = 0.0f; }
void set_rdram_base(uint8_t* rdram) { g_rdram = rdram; }
void poll_game_state() {}

// No base-recomp patches yet (boot main is replaced by an `ignored` function in src/boot.cpp instead).
void register_patches() {}
void register_patched_addresses() {}

}  // namespace thps
