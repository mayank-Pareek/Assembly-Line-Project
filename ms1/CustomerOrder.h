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
#ifndef CUSTOMER_ORDER_H_
#define CUSTOMER_ORDER_H_

#include "Station.h"
#include "Utilities.h"

namespace sdds {
	class CustomerOrder {
		struct Item {
			std::string m_itemName{};
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};
		std::string m_name;
		std::string m_product;
		size_t m_cntItem{ 0 };
		Item** m_lstItem{ nullptr };
		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);
		CustomerOrder(const CustomerOrder&);
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&& c) noexcept;
		CustomerOrder& operator=(CustomerOrder&& c) noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif // CUSTOMER_ORDER_H_
