#ifndef CUP_READABLE_H
#define CUP_READABLE_H

#include <vector>
#include <string_view>

namespace Cup::Properties
{
	class Readable
	{

	public:

		static std::vector<std::byte> readBinary(std::string_view filename);

	};
}

#endif //CUP_READABLE_H
