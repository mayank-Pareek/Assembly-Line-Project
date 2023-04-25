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

#include <iomanip>
#include "Station.h"
#include "Utilities.h"
namespace sdds {
	size_t Station::m_widthField = 0;
	size_t Station::id_generator = 0;

	Station::Station(const std::string& str) {
		Utilities util;
		size_t next_pos = 0;
		bool more = true;
		m_id = ++id_generator;
		m_itemName = util.extractToken(str, next_pos, more);
		m_serialNumber = stoi(util.extractToken(str, next_pos, more));
		m_quantity = stoi(util.extractToken(str, next_pos, more));
		m_widthField = std::max(m_widthField, util.getFieldWidth());
		m_desc = util.extractToken(str, next_pos, more);
	}

	const std::string& Station::getItemName() const {
		return m_itemName;
	}

	size_t Station::getNextSerialNumber() {
		return m_serialNumber++;
	}

	size_t Station::getQuantity() const {
		return m_quantity;
	}

	void Station::updateQuantity() {
		if (m_quantity > 0) {
			m_quantity--;
		}
	}

	void Station::display(std::ostream& os, bool full) const {
		os << std::setfill('0') << std::right << std::setw(3) << m_id;
		os << " | " << std::setfill(' ') << std::left << std::setw(m_widthField + 1) << m_itemName;
		os << " | " << std::right << std::setfill('0') << std::setw(6) << m_serialNumber;
		os << " | ";
		if (full) {
			os << std::right << std::setw(4) << std::setfill(' ') << m_quantity;
			os << " | " << m_desc;
		}
		os << std::endl;
	}
}