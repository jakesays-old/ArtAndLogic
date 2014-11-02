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
	std::stringstream dec;
	unsigned short x;

	dec << std::hex << hexVal;
	dec >> x;

	return x;
}



//string s = "" << std::hex << hiByte << loByte;

//BitArray bits;
//bits.shortValue = result;
//
//cout << DecToHex(hiByte, loByte) << "(" << (_TUCHAR)hiByte << "," << (_TUCHAR)loByte << "): " << result;
//
//cout << "\r\n";
//
//cout << bits.bitValues.bit15 << bits.bitValues.bit14 << bits.bitValues.bit13 << bits.bitValues.bit12;
//cout << bits.bitValues.bit11 << bits.bitValues.bit10 << bits.bitValues.bit9 << bits.bitValues.bit8;
//
//cout << " ";
//
//cout << bits.bitValues.bit7 << bits.bitValues.bit6 << bits.bitValues.bit5 << bits.bitValues.bit4;
//cout << bits.bitValues.bit3 << bits.bitValues.bit2 << bits.bitValues.bit1 << bits.bitValues.bit0;
//
//cout << "\r\n";
//
////High Bits
//BitArray hiBits;
//hiBits.charValue = hiByte;
//cout << "\r\Hi Bits: ";
//cout << hiBits.bitValues.bit7 << hiBits.bitValues.bit6 << hiBits.bitValues.bit5 << hiBits.bitValues.bit4;
//cout << hiBits.bitValues.bit3 << hiBits.bitValues.bit2 << hiBits.bitValues.bit1 << hiBits.bitValues.bit0;
//
//cout << "\r\n";
//
////Low Bits
//BitArray loBits;
//loBits.charValue = loByte;
//cout << "\r\Lo Bits: ";
//cout << loBits.bitValues.bit7 << loBits.bitValues.bit6 << loBits.bitValues.bit5 << loBits.bitValues.bit4;
//cout << loBits.bitValues.bit3 << loBits.bitValues.bit2 << loBits.bitValues.bit1 << loBits.bitValues.bit0;
//
//cout << "\r\n";
//cout << "\r\n";