// Design by Joan Andrés.

#include <bitset>
#include <iostream>
#include <cstddef>
#include <climits>
#include "Cup/Properties/Readable.h"

using namespace Cup;

static_assert(CHAR_BIT == 8);

int main()
{
	try
	{
		std::vector datas = Properties::Readable::readBinary("../Test/Images/PNG-Transparency.png");

		for(auto data : datas)
		{
			std::cout << std::bitset<8>(std::to_integer<int>(data)) << " ";
		}
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what();
	}
}