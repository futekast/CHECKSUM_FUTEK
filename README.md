# CHECKSUM_FUTEK

Reusable C implementation of the FUTEK weighted additive 8-bit checksum.

## Files

- `include/checksum_futek.h`
- `src/checksum_futek.c`
- `examples/main.c`

## Checksum Parameters

| Parameter | Value |
|---|---:|
| Name | Checksum/FUTEK |
| Type | Weighted additive checksum |
| Output Width | 8-bit |
| Final Mask | 0xFF |
| Input Length | Variable |
| Weighting | Byte index + 1 |

## Checksum Formula

```text
Checksum = Σ(byte[index] × (index + 1)) & 0xFF