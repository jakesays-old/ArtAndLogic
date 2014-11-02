// Copyright (c) 2014 Art & Logic, Inc. All Rights Reserved.
// $Id$

#include "stdafx.h"

int _tmain(int argc, char* argv[])
{
	bool running = true;

	cout << "Art & Logic Programming Challenge 1 - Marissa du Bois" << endl;

	do
	{
		short decVal = 0;
		short hexVal = 0;
		string input = "";
		
		cout << endl << "E: Encode" << endl;
		cout << "D: Decode" << endl;
		cout << "Q: Quit" << endl << endl;
		cout << "Choose: ";

		cin >> input;
		
		switch (toupper(input[0]))
		{
		case 'E':
			while (true)
			{
				cout << "Enter a value to Encode: ";

				cin >> decVal;

				if (decVal > 8191 || decVal < -8192)
					cout << "Please enter a value between -8192 and 8191." << endl << endl;
				else
					break;
			};

			cout << "\r\nEncoded value is: " << Encode(decVal) << endl;
			break;
		case 'D':
			while (true)
			{
				cout << "Enter a Hex Value to Decode: ";

				cin >> input;

				hexVal = HexToDec(input);

				if (hexVal > 0x7F7F || hexVal < 0x0000)
					cout << "Please enter a value between 0x0000 and 0x7F7F." << endl << endl;
				else
					break;
			};

			cout << "\r\nDecoded value is: " << Decode(hexVal >> 8, hexVal & 0x00FF) << endl;
			break;
		case 'Q':
			running = false;
			break;
		}
	} while (running);

	return 0;
}




