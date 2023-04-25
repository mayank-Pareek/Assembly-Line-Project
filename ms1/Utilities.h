/*
*****************************************************************************
						Project - Milestone 3
Full Name  : Mayank Kumar
Student ID#: 145998217
Email      : mkumar87@myseneca.ca
Date       : 08 April 2023

Authenticity Declaration:
I confirm that I am the only author of this file and
the content was created entirely by me.
*****************************************************************************
*/
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>
namespace sdds {
	class Utilities
	{
		size_t m_widthField = 1;
		static char m_delimiter;
	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}
#endif // !SDDS_UTILITIES_H