// Copyright (c) 2014 Art & Logic, Inc. All Rights Reserved.
// $Id$

#ifndef h_Encoder
#define h_Encoder

#include <iostream>
using namespace std;

/**
* Encodes a 14-bit integer into a 4-character hexadecimal string
* \param A 16-bit integer value to encode
*/
std::string Encode(short encodeVal);


/**
* Converts a byte into a 2 character Hexidecimal string
* \param The value to convert to Hexidecimal
*/
std::string DecToHex(short byte);

/**
* Converts High Byte and Low Byte into a 4 character Hexidecimal string
* \param The value to convert to Hexidecimal
*/
std::string DecToHex(unsigned char hiByte, unsigned char loByte);

#endif