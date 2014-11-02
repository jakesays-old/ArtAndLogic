// Copyright (c) 2014 Art & Logic, Inc. All Rights Reserved.
// $Id$

#include "stdafx.h"

short Decode(unsigned char hiByte, unsigned char loByte)
{
	short result = 0;

	//Recombine high and low bytes and then tranlate to 14-bit range [-8192..+8191]
	result = ((hiByte << 7) | loByte) - 8192;

	return result;
}

unsigned short HexToDec(string hexVal)
{
	std::stringstream sstream;
	unsigned short val;

	//use std::hex to convert string value into 
	sstream << std::hex << hexVal;

	//stream decimal to val
	sstream >> val;

	return val;
}