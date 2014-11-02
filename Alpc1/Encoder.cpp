// Copyright (c) 2014 Art & Logic, Inc. All Rights Reserved.
// $Id$

#include "stdafx.h"

string Encode(short encodeVal)
{
	string result = "";
	unsigned short val = 0;
	unsigned char loByte = 0x00;
	unsigned char hiByte = 0x00;

	//Add 8192 to the raw value, so it's range is translated to [0..16383]
	val = encodeVal + 8192;

	//Pack the value into two bytes such that the most significant bit of each is cleared.
	loByte = (val & 0x7F);
	hiByte = val >> 7;

	//Format the two bytes as a single 4-character hexadecimal string and return it.
	result = DecToHex(hiByte, loByte);

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

