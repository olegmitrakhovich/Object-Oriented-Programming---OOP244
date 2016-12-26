#ifndef STREAMBLE_H
#define STREAMBLE_H
#include <fstream>

namespace sict {

	class Streamble {
	public:
		virtual std::fstream& store(std::fstream& file, bool addNewLine = true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& display(std::ostream& os) const = 0;
		virtual std::istream& read(std::istream& is) = 0;

	};

}
#endif
