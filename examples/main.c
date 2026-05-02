//------------------------------------------------------------------------------
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 FUTEK Advanced Sensor Technology, Inc.
//
// This file provides example validation for the FUTEK checksum implementation.
//------------------------------------------------------------------------------

#include <stdint.h>
#include <stdio.h>

#include "checksum_futek.h"

#define _CHECKSUM_FUTEK_ASCII_CHECK_INPUT()           ("123456789")
#define _CHECKSUM_FUTEK_ASCII_CHECK_INPUT_LENGTH()    (9u)
#define _CHECKSUM_FUTEK_ASCII_EXPECTED_RESULT()       (0x8Du)

#define _CHECKSUM_FUTEK_HEX_CHECK_INPUT_LENGTH()      (5u)
#define _CHECKSUM_FUTEK_HEX_EXPECTED_RESULT()         (0x89u)

static const uint8_t checksumFutekHexCheckInput[] = {
    0x12u,
    0x34u,
    0x56u,
    0x78u,
    0x09u
};

//------------------------------------------------------------------------------
// Function Name: Main
// Description: This function validates the FUTEK checksum calculation method
//              using known check values.
// Parameters: None
// Returns: 0 if all checks pass, otherwise 1
//------------------------------------------------------------------------------
int main(void) {
    uint8_t asciiChecksumValue;
    uint8_t hexChecksumValue;
    uint8_t checkResult;

    asciiChecksumValue = calculateChecksumFutek(
        (const uint8_t *)_CHECKSUM_FUTEK_ASCII_CHECK_INPUT(),
        _CHECKSUM_FUTEK_ASCII_CHECK_INPUT_LENGTH()
    );

    hexChecksumValue = calculateChecksumFutek(
        checksumFutekHexCheckInput,
        _CHECKSUM_FUTEK_HEX_CHECK_INPUT_LENGTH()
    );

    if ((asciiChecksumValue == _CHECKSUM_FUTEK_ASCII_EXPECTED_RESULT())
        && (hexChecksumValue == _CHECKSUM_FUTEK_HEX_EXPECTED_RESULT())) {
        checkResult = 1u;
    } else {
        checkResult = 0u;
    }

    printf("Checksum/FUTEK ASCII Result: 0x%02X Expected: 0x%02X\n",
           asciiChecksumValue,
           _CHECKSUM_FUTEK_ASCII_EXPECTED_RESULT());

    printf("Checksum/FUTEK HEX Result:   0x%02X Expected: 0x%02X\n",
           hexChecksumValue,
           _CHECKSUM_FUTEK_HEX_EXPECTED_RESULT());

    printf("Checksum/FUTEK Status: %s\n",
           (checkResult == 1u) ? "PASS" : "FAIL");

    return (checkResult == 1u) ? 0 : 1;
}