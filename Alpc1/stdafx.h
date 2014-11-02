// Copyright (c) 2014 Art & Logic, Inc. All Rights Reserved.
// $Id$

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "Encoder.h"
#include "Decoder.h"
#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <sstream>
using namespace std;

union BitArray
{
	unsigned char charValue;
	short shortValue;
	struct bitArray
	{
		unsigned int bit0 : 1;
		unsigned int  bit1 : 1;
		unsigned int  bit2 : 1;
		unsigned int  bit3 : 1;
		unsigned int  bit4 : 1;
		unsigned int  bit5 : 1;
		unsigned int  bit6 : 1;
		unsigned int  bit7 : 1;
		unsigned int  bit8 : 1;
		unsigned int  bit9 : 1;
		unsigned int  bit10 : 1;
		unsigned int  bit11 : 1;
		unsigned int  bit12 : 1;
		unsigned int  bit13 : 1;
		unsigned int  bit14 : 1;
		unsigned int  bit15 : 1;

	} bitValues;
};


