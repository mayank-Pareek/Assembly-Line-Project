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
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <iostream>
#include <vector>
#include "Workstation.h"

namespace sdds {
	class LineManager {
		std::vector<Workstation*> m_activeLine{};
		size_t m_cntCustomer{ 0 };
		Workstation* m_firstStation{ nullptr };
	public:
		LineManager() = default;
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void reorderStations();
		bool run(std::ostream& os = std::cout);
		void display(std::ostream& os = std::cout) const;
	};
}

#endif