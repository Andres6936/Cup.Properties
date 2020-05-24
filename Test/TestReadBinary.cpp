// Design by Joan Andrés.

#include <cstddef>
#include <cassert>
#include <iostream>
#include "Cup/Properties/Readable.h"

using namespace Cup;

int main()
{
	// Test Number One, Verify the number magic of png file
	// Assumptions: The filename point to file of type .png
	// 		and it is a .png file valid (aka: not corrupted).
	try
	{
		std::vector dataBinary = Properties::Readable::readBinary("../Test/Images/Format.png");

		// Wikipedia say: A PNG file starts with an 8-byte signature
		// So, that we only needed the first eight bytes of information
		std::vector numberMagic(dataBinary.cbegin(), dataBinary.cbegin() + 8);

		// The values in hexadecimal are: 89 50 4E 47 0D 0A 1A 0A

		// In binary 89 is 10001001
		assert(numberMagic[0] == std::byte(0b10001001));
		// In binary 50 is 01010000
		assert(numberMagic[1] == std::byte(0b01010000));
		// In binary 4E is 01001110
		assert(numberMagic[2] == std::byte(0b01001110));
		// In binary 47 is 01000111
		assert(numberMagic[3] == std::byte(0b01000111));
		// In binary 0D is 00001101
		assert(numberMagic[4] == std::byte(0b00001101));
		// In binary 0A is 00001010
		assert(numberMagic[5] == std::byte(0b00001010));
		// In binary 1A is 00011010
		assert(numberMagic[6] == std::byte(0b00011010));
		// In binary 0A is 00001010
		assert(numberMagic[7] == std::byte(0b00001010));

		std::cout << "Test Success, PNG Verify.\n";
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what();
	}

	// Test Number Two, Verify the number magic of gif file
	// Assumptions: The filename point to file of type .gif
	// 		and it is a .gif file valid (aka: not corrupted).
	try
	{
		std::vector dataBinary = Properties::Readable::readBinary("../Test/Images/Format.gif");

		// Wikipedia say: A GIF file starts with an signature as GIF89a GIF87a
		std::vector numberMagic(dataBinary.cbegin(), dataBinary.cbegin() + 6);

		// The values in hexadecimal are: 47 49 46 38 39 61 for the signature GIF89a

		// In binary 47 is 01000111
		assert(numberMagic[0] == std::byte(0b01000111));
		// In binary 49 is 01001001
		assert(numberMagic[1] == std::byte(0b01001001));
		// In binary 46 is 01000110
		assert(numberMagic[2] == std::byte(0b01000110));
		// In binary 38 is 00111000
		assert(numberMagic[3] == std::byte(0b00111000));
		// In binary 39 is 00111001
		assert(numberMagic[4] == std::byte(0b00111001));
		// In binary 61 is 01100001
		assert(numberMagic[5] == std::byte(0b01100001));

		std::cout << "Test Success, GIF89a Verify.\n";
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what();
	}

	// Test Number Three, Verify the number magic of psd/psb file
	// Assumptions: The filename point to file of type .psd/.psb
	// 		and it is a .psd/psb file valid (aka: not corrupted).
	try
	{
		// Change the extension of filename (here) to .psd or .psb
		std::vector dataBinary = Properties::Readable::readBinary("../Test/Images/Format.psd");

		// Wikipedia say that signature of .psd/.psb is 8BPS
		std::vector numberMagic(dataBinary.cbegin(), dataBinary.cbegin() + 4);

		// The values in hexadecimal are: 38 42 50 53 for the signature 8BPS

		assert(numberMagic[0] == std::byte(0x38));
		assert(numberMagic[1] == std::byte(0x42));
		assert(numberMagic[2] == std::byte(0x50));
		assert(numberMagic[3] == std::byte(0x53));

		std::cout << "Test Success, PSD/PSB Verify.\n";
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what();
	}
}