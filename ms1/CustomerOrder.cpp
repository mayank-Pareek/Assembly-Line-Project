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
#include "CustomerOrder.h"
#include <iomanip>

namespace sdds {
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder() {
		m_cntItem = 0;
		m_lstItem = nullptr;
	}

	CustomerOrder::CustomerOrder(const std::string& str) {
		Utilities u{};
		m_cntItem = 0;
		size_t next = 0;
		bool more = true;
		m_lstItem = nullptr;
		m_name = u.extractToken(str, next, more);
		m_product = u.extractToken(str, next, more);
		Item** arr = new Item * [10];
		int i = 0;
		while (more) {
			arr[i] = new Item{ u.extractToken(str, next, more) };
			i++;
		}
		m_cntItem = i;
		m_lstItem = new Item * [m_cntItem];
		for (int j = 0; j < i; j++) {
			m_lstItem[j] = arr[j];
		}
		delete[] arr;

		if (CustomerOrder::m_widthField < u.getFieldWidth()) {
			CustomerOrder::m_widthField = u.getFieldWidth() + 2;
		}
	}
	CustomerOrder::CustomerOrder(const CustomerOrder& other) {
		throw std::string("Error: Copy constructor is not allowed.");
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& c) noexcept {
		m_name = std::move(c.m_name);
		m_product = std::move(c.m_product);
		m_cntItem = c.m_cntItem;
		m_lstItem = c.m_lstItem;
		c.m_lstItem = nullptr;
		c.m_cntItem = 0;
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& c) noexcept {
		if (this == &c) {
			return *this;
		}
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
		m_name = std::move(c.m_name);
		m_product = std::move(c.m_product);
		m_cntItem = c.m_cntItem;
		m_lstItem = c.m_lstItem;
		c.m_cntItem = 0;
		c.m_lstItem = nullptr;
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		if (m_lstItem != nullptr) {
			for (size_t i = 0; i < m_cntItem; i++)
			{
				if (m_lstItem[i] != nullptr) {
					delete m_lstItem[i];
				}
			}
			delete[] m_lstItem;
		}
	}

	bool CustomerOrder::isOrderFilled() const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_isFilled == false) {
				return false;
			}
		}
		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		bool flag = true;
		for (size_t i = 0; i < m_cntItem && flag; i++) {
			if (m_lstItem[i]->m_itemName == itemName) {
				if (!m_lstItem[i]->m_isFilled) {
					flag = false;
				}
			}
		}
		return flag;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		bool filled = false;
		for (size_t i = 0; i < m_cntItem && !filled; i++) {
			if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled) {
				if (station.getQuantity() > 0) {
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
					filled = true;
				}
				else {
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << "\n";
		for (size_t i = 0; i < m_cntItem; i++) {
			os << "[" << std::setfill('0') << std::right << std::setw(6) << m_lstItem[i]->m_serialNumber << "] ";
			os << std::setfill(' ') << std::left << std::setw(m_widthField) << m_lstItem[i]->m_itemName;
			os << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << "\n";
		}
	}
}