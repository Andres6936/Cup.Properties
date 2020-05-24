#include "Cup/Properties/Readable.h"

#include <vector>
#include <memory>
#include <fstream>
#include <filesystem>

using namespace Cup;

namespace fs = std::filesystem;

std::vector<std::byte> Properties::Readable::readBinary(std::string_view filename)
{
	// Get the absolute path to file, is more simple
	// inform of error with the absolute path.
	const fs::path path(fs::absolute(filename));
	// Verify that the file exist and that it is regular file
	const fs::directory_entry file(path);

	if (file.exists() and file.is_regular_file())
	{
		// Open the file in mode only read and read of binary
		std::ifstream inputStream(path, std::ios::binary);

		// Checks if the stream has an associated file
		if (inputStream.is_open())
		{
			// You can imagine ifstream as a position,
			// and that position has the ability to
			// move through the file, you can move
			// anywhere within the file and read content
			// from that position.
			// What we want to do is determine the
			// size of the file to read it completely
			// in a single iteration, so our position
			// needs to move to the end of the file,
			// and then ask him where he is.
			inputStream.seekg(0, std::ifstream::end);
			// This is how we ask our position where it is
			const std::size_t sizeFile = inputStream.tellg();
			// To read the entire contents of the file,
			// it is necessary to move back to the beginning
			// of the file
			inputStream.seekg(0, std::ifstream::beg);

			// std::byte was introduced in C++17, allowing
			// interpret unsigned char and char as a byte

			// See the motivations of use std::byte instead
			// of unsigned char and char

			// 		Many programs require byte-oriented access
			// 		to memory. Today, such programs must use
			// 		either the char, signed char, or unsigned
			// 		char types for this purpose. However, these
			// 		types perform a “triple duty”. Not only are
			// 		they used for byte addressing, but also as
			// 		arithmetic types, and as character types.
			// 		This multiplicity of roles opens the door
			// 		for programmer error – such as accidentally
			// 		performing arithmetic on memory that should
			// 		be treated as a byte value – and confusion
			// 		for both programmers and tools.
			// Ref: http://open-std.org/JTC1/SC22/WG21/docs/papers/2016/p0298r0.pdf
			std::vector<std::byte> buffer(sizeFile);

			// The "reinterpret_cast<char*>" is necessary,
			// yet that the method read not support to read
			// of std::byte type, only of pointers (aka: arrays)
			// of type char
			inputStream.read(reinterpret_cast<char*>(buffer.data()), sizeFile);

			return buffer;
		}
	}
	else
	{
		// For create std::string in compilation
		// time is necessary say to compile that the
		// string literal [aka: const char*] will
		// be convert to std::string; note the 's'
		// added to end of string literals.
		using namespace std::string_literals;

		const std::string pathAbsolute = path;
		const std::string message = "The file with path <"s
				+ pathAbsolute + "> not exist, not is a regular file"s
				+ " or the path is wrong.\nPlease assure that path is"s
				+ " valid and the file not is a directory."s;

		throw std::runtime_error(message);
	}

	throw std::runtime_error("An unexpected error has occurred,"
						  " this exception should not be thrown");
}
