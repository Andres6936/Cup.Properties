#include "Cup/Properties/Readable.h"
#include <memory>
#include <fstream>
#include <filesystem>

using namespace Cup;

namespace fs = std::filesystem;

std::string Properties::Readable::readSimple(std::string_view filename)
{
	return std::string();
}

std::vector<char> Properties::Readable::readBinary(std::string_view filename)
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

			std::unique_ptr<char[]> buffer = std::make_unique<char[]>(sizeFile);

			inputStream.read(buffer.get(), sizeFile);

			// Automatic template deduction to char <C++17>
			// Note that the second argument is an "end pointer",
			// very common in C++. Importantly, it is a pointer
			// to the character after the end of the buffer, not
			// the last character in the buffer.
			// In other words, the start is inclusive but the
			// end is exclusive.
			// Ref: https://stackoverflow.com/a/4272524
			return std::vector(buffer.get(), buffer.get() + sizeFile);
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
				+ pathAbsolute + "> not exist, not is a regular file"
				+ " or the path is wrong.\nPlease assure that path is"
				+ " valid and the file not is a directory."s;

		throw std::runtime_error(message);
	}

	throw std::runtime_error("An unexpected error has occurred,"
						  " this exception should not be thrown");
}
