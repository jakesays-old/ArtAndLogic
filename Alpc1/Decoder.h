// Copyright (c) 2014 Art & Logic, Inc. All Rights Reserved.
// $Id$

#ifndef h_Decoder
#define h_Decoder

#include <iostream>
using namespace std;

/**
* Decodes a 14-bit integer from two hexidecimal bytes
* \param high order bits to decode
* \param low order bits to decode
*/
short Decode(unsigned char hiByte, unsigned char loByte);

/**
* Converts Hexadecimal string into a Decimal value
* \param A 4-character hexadecimal string to convert
*/
unsigned short HexToDec(std::string hexVal);

#endif