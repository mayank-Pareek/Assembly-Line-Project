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