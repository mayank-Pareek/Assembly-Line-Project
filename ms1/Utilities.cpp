#include<stdexcept>
#include "Utilities.h"

namespace sdds {
    /*Utilities::Utilities() {
        m_delimiter = ',';
    }*/
    char Utilities::m_delimiter = ',';

    void Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        std::string token;
        size_t delimiter_pos = str.find(m_delimiter, next_pos);
        if (delimiter_pos != std::string::npos) {
            token = str.substr(next_pos, delimiter_pos - next_pos);
            if (token.empty()) {
                throw std::runtime_error("no token found");
            }
            if (token.back() == ' ') {
                token.erase(token.find_last_not_of(' ') + 1);
            }
            if (token.front() == ' ') {
                token.erase(0, token.find_first_not_of(' '));
            }
            next_pos = delimiter_pos + 1;
            m_widthField = std::max(m_widthField, token.length());
            more = true;
        }
        else {
            token = str.substr(next_pos);
            if (token.back() == ' ') {
                token.erase(token.find_last_not_of(' ') + 1);
            }
            if (token.front() == ' ') {
                token.erase(0, token.find_first_not_of(' '));
            }
            next_pos = str.length();
            more = false;
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
