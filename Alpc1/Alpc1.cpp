// Copyright (c) 2014 Art & Logic, Inc. All Rights Reserved.
// $Id$

#include "stdafx.h"

int _tmain(int argc, char* argv[])
{
	bool running = true;
	
	cout << "Art & Logic Programming Challenge 1 - Marissa du Bois\r\n";
	string input = "";

	do
	{
		int decVal = 0;
		short hexVal = 0;

		
		input = "";

		cout << "\r\nE: Encode\r\n";
		cout << "D: Decode\r\n";
		cout << "Q: Quit\r\n\r\n";
		cout << "Choose: ";

		cin >> input;
		
		switch (input[0])
		{
		case 'e':
		case 'E':
			while (true)
			{
				input = "";

				cout << "Enter a value to Encode: ";

				cin >> decVal;

				if (decVal > 8191 || decVal < -8192)
					cout << "Please enter a value between -8192 and 8191.\r\n\r\n"; 
				else
					break;
			};

			cout << "\r\nEncoded value is: " << Encode(decVal) << "\r\n";
			break;
		case 'd':
		case 'D':
			while (true)
			{
				input = "";

				cout << "Enter a Hex Value to Decode: ";

				cin >> input;

				hexVal = HexToDec(input);

				if (hexVal > 0x7F7F || hexVal < 0x0000)
					cout << "Please enter a value between 0x0000 and 0x7F7F.\r\n\r\n";
				else
					break;
			};

			cout << "\r\nDecoded value is: " << Decode(hexVal >> 8, hexVal & 0x00FF) << "\r\n";
			break;
		case 'q':
		case 'Q':
			running = false;
			break;
		}
	} while (running);

	cout << Encode(0) << "\r\n";
	cout << Encode(1) << "\r\n";
	cout << Encode(2) << "\r\n";
	cout << Encode(3) << "\r\n";

	cin >> input;
	//cout << "Encode     0: " << Encode(0) << "\r\n";

	//cout << "Encode -8192: " << Encode(-8192) << "\r\n";

	//cout << "Encode  8191: " << Encode(8191) << "\r\n";

	//cout << "Encode  2048: " << Encode(2048) << "\r\n";

	//cout << "Encode -4096: " << Encode(-4096) << "\r\n";

	//cout << "\r\n";

	//Test values
	//cout << "Encode  6111: " << Encode(6111) << "\r\n";

	//cout << "Encode   340: " << Encode(340) << "\r\n";

	//cout << "Encode -2628: " << Encode(-2628) << "\r\n";

	//cout << "Encode  -255: " << Encode(-255) << "\r\n";

	//cout << "Encode  7550: " << Encode(7550) << "\r\n";

	//Decode(0x40, 0x00);
	//Decode(0x00, 0x00);
	//Decode(0x7F, 0x7F);
	//Decode(0x50, 0x00);
	//Decode(0x0A, 0x05);
	//Decode(0x55, 0x00);

	//int s;

	//cin >> s;

	return 0;
}




