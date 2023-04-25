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
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds {
	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation : public Station {
	private:
		std::deque<CustomerOrder> m_orders{};
		Workstation* m_pNextStation{ nullptr };
	public:
		Workstation() = default;
		Workstation(const std::string& str);
		Workstation(const Workstation&) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&&) = delete;
		void fill(std::ostream& os = std::cout);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station = nullptr);
		Workstation* getNextStation() const;
		void display(std::ostream& os = std::cout) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}

#endif