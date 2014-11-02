// Copyright (c) 2014 Art & Logic, Inc. All Rights Reserved.
// $Id$

#ifndef h_Decoder
#define h_Decoder

#include <iostream>
using namespace std;

/**
* Decodes a 14-bit integer from a 4-character hexadecimal string
* \param A 4-character hexadecimal string to decode
*/
short Decode(unsigned char hiByte, unsigned char loByte);

unsigned short HexToDec(string hexVal);

#endif