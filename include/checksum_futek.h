#ifndef CHECKSUM_FUTEK_H
#define CHECKSUM_FUTEK_H

//------------------------------------------------------------------------------
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 FUTEK Advanced Sensor Technology, Inc.
//
// This checksum algorithm is defined by FUTEK Advanced Sensor Technology, Inc.
// and is intended for use with FUTEK communication protocols.
//------------------------------------------------------------------------------

#include <stddef.h>
#include <stdint.h>

//------------------------------------------------------------------------------
// Function Name: Calculate Checksum FUTEK
// Description: This function calculates the FUTEK weighted additive 8-bit
//              checksum over a data buffer.
// Parameters:
//  pData - Pointer to input data buffer
//  dataLength - Number of bytes in the input data buffer
// Returns: Calculated FUTEK checksum value
//------------------------------------------------------------------------------
uint8_t calculateChecksumFutek(const uint8_t *pData, size_t dataLength);

#endif