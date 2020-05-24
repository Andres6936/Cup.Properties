#ifndef CUP_READABLE_H
#define CUP_READABLE_H

#include <vector>
#include <string>
#include <string_view>

namespace Cup::Properties
{
	class Readable
	{

	private:

	public:

		static std::string readSimple(std::string_view filename);

		static std::vector<char> readBinary(std::string_view filename);

	};
}

#endif //CUP_READABLE_H
