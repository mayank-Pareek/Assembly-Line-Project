#include<stdexcept>
#include "Utilities.h"

namespace sdds {
	char Utilities::m_delimiter = ',';

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		size_t delim_pos = str.find(m_delimiter, next_pos + 1);

		if (delim_pos == std::string::npos) {
			more = false;
		}

		if (str[next_pos] == m_delimiter) {
			more = false;
			throw std::string("No token found");
		}

		size_t first = str.find_first_not_of(' ', next_pos);
		size_t last = str.find_last_not_of(' ', delim_pos - 1);
		std::string token = str.substr(first, last - first + 1);

		next_pos = delim_pos + 1;

		if (token.length() > m_widthField) {
			m_widthField = token.length();
		}

		return token;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}