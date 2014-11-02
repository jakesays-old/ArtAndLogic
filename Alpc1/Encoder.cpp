// Copyright (c) 2014 Art & Logic, Inc. All Rights Reserved.
// $Id$

#include "stdafx.h"

string Encode(short encodeVal)
{
	unsigned short val = 0;
	unsigned char loByte = 0x00;
	unsigned char hiByte = 0x00;
	string result;

	//Make sure the value is in the 14-bit range [-8192..+8191]
	if (encodeVal < -8192 || encodeVal > 8191)
		return "";

	//Add 8192 to the raw value, so it's range is translated to [0..16383]
	val = encodeVal + 8192;

	//Pack the value into two bytes such that the most significant bit of each is cleared.
	loByte = (val & 0xFF) >> 1;
	hiByte = val >> 7;

	//Format the two bytes as a single 4-character hexadecimal string and return it.
	result = DecToHex(hiByte, loByte);

	//Debug info
	BitArray bits;
	bits.shortValue = val;

	cout << encodeVal << ": " << val << "(" << (_TUCHAR)hiByte << "," << (_TUCHAR)loByte << ") " << DecToHex(hiByte, loByte);

	cout << "\r\n";

	cout << bits.bitValues.bit15 << bits.bitValues.bit14 << bits.bitValues.bit13 << bits.bitValues.bit12;
	cout << bits.bitValues.bit11 << bits.bitValues.bit10 << bits.bitValues.bit9 << bits.bitValues.bit8 ;
	
	cout << " ";

	cout << bits.bitValues.bit7 << bits.bitValues.bit6 << bits.bitValues.bit5 << bits.bitValues.bit4;
	cout << bits.bitValues.bit3 << bits.bitValues.bit2 << bits.bitValues.bit1 << bits.bitValues.bit0;

	cout << "\r\n";

	//High Bits
	BitArray hiBits;
	hiBits.charValue = hiByte;
	cout << "\r\Hi Bits: ";
	cout << hiBits.bitValues.bit7 << hiBits.bitValues.bit6 << hiBits.bitValues.bit5 << hiBits.bitValues.bit4;
	cout << hiBits.bitValues.bit3 << hiBits.bitValues.bit2 << hiBits.bitValues.bit1 << hiBits.bitValues.bit0;

	cout << "\r\n";

	//Low Bits
	BitArray loBits;
	loBits.charValue = loByte;
	cout << "\r\Lo Bits: ";
	cout << loBits.bitValues.bit7 << loBits.bitValues.bit6 << loBits.bitValues.bit5 << loBits.bitValues.bit4;
	cout << loBits.bitValues.bit3 << loBits.bitValues.bit2 << loBits.bitValues.bit1 << loBits.bitValues.bit0;

	cout << "\r\n";
	cout << "\r\n";

	return result;
}

string DecToHex(unsigned char hiByte, unsigned char loByte)
{
	//Concatinate 2-character hexidecimal strings into single 4-character hexidecimal string.
	return DecToHex(hiByte) + DecToHex(loByte);
}

string DecToHex(short byte)
{
	short i = 1;
	short hex[2] = { 0, 0 };
	stringstream stream;

	//split the decimal value and convert to numeric hex value.
	do
	{
		hex[i] = byte % 16;

		byte = byte / 16;

		i--;
	} while (byte > 0);

	//Convert calculated values into string representation by streaming
	for (i = 0; i < 2; i++)
	{
		byte = hex[i];

		//Concatinate values less than 10 and convert 10 and higher into A-F
		if(byte < 10)
			stream << byte;
		else if (byte == 10)
			stream << 'A';
		else if (byte == 11)
			stream << 'B';
		else if (byte == 12)
			stream << 'C';
		else if (byte == 13)
			stream << 'D';
		else if (byte == 14)
			stream << 'E';
		else if (byte == 15)
			stream << 'F';
	}

	//Return stream as string
	return stream.str();
}

