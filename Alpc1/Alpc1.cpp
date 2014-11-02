// Copyright (c) 2014 Art & Logic, Inc. All Rights Reserved.
// $Id$

#include "stdafx.h"

int _tmain(int argc, char* argv[])
{
	bool running = true;

	std::cout << "Art & Logic Programming Challenge 1 - Marissa du Bois";
	std::cout << endl;

	do
	{
		short decVal = 0;
		short hexVal = 0;
		std::string input = "";

		std::cout << endl << "E: Encode" << endl;
		std::cout << "D: Decode" << endl;
		std::cout << "Q: Quit" << endl << endl;
		std::cout << "Choose: ";

		std::cin >> input;
		
		switch (toupper(input[0]))
		{
			//Encode 14-bit int to hex string
			case 'E':
			while (true)
			{
				std::cout << "Enter a value to Encode: ";

				std::cin >> decVal;

				if (decVal > 8191 || decVal < -8192)
				{
					std::cout << "Please enter a value between -8192 and 8191.";
					std::cout << endl << endl;
				}
				else
				{
					break;
				}
			};

			std::cout << "\r\nEncoded value is: " << Encode(decVal) << endl;
			break;

			//Decode a hex value and show 14-bit int
			case 'D':
			while (true)
			{
				std::cout << "Enter a Hex Value to Decode: ";

				std::cin >> input;

				hexVal = HexToDec(input);

				if (hexVal > 0x7F7F || hexVal < 0x0000)
				{
					std::cout << "Please enter a value between 0x0000 and 0x7F7F.";
					std::cout << endl << endl;
				}
				else
				{
					break;
				}
			};

			std::cout << "\r\nDecoded value is: ";
			std::cout << Decode(hexVal >> 8,  hexVal & 0x00FF);
			std::cout << endl;
			break;

			//Exit program
			case 'Q':
			running = false;
			break;
		}
	} while (running);

	return 0;
}




