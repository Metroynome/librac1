# librac1

## Compact address tables

`GetAddress` and `GetAddressImmediate` accept both the original `VariableAddress_t` and `rac1VariableAddressCompact_t`. Existing full tables keep their layout. A compact table occupies 44 bytes instead of 80, saving 36 bytes per table before linker alignment and the shared decoder cost.

```c
rac1VariableAddressCompact_t vaExample = {
	.MainMenu = RAC1_VA_COMPACT_MENU(0),
	.Veldin1 = 0x00400000,
	.Novalis = RAC1_VA_COMPACT_OFFSET(0x00400000, 0x00400100),
};
```

These are illustrative values, not game addresses. Always tag MainMenu, even when it has no address. Veldin1 remains a 32-bit base; later fields encode a signed word delta biased by 0x8000. Zero means unavailable; a field equal to the base encodes 0x8000. Nonzero entries must differ from the base by a multiple of four within +/-32767 words. The macro rejects constant offsets outside that range at compile time. Use a full table when it cannot fit.

The website's Address Table (Compact) formatter emits this layout, and falls back to a full table when its base is missing/ambiguous or a delta cannot fit. Recompile consumers against the updated headers and library. Do not index compact fields as an array of 32-bit addresses.

Validation: all existing regional Makefile variants build, and compiled MIPS tests match the original resolver for full and compact tables, including menu/loading states and offset boundaries. No new PCSX2 gameplay test was performed.
