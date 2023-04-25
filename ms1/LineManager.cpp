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
#include <iostream>
#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
		std::ifstream infile(file);
		if (!infile) {
			throw "ERROR: Unable to open file";
		}
		Utilities utils{};
		std::string str{};
		size_t next_pos{ 0 };
		size_t next_copy = next_pos;
		bool more{ true };

		std::vector<std::string> leftStations;
		std::vector<std::string> rightStations;

		while (std::getline(infile, str)) {
			next_pos = next_copy;
			std::string tempCurrStation{}, tempNextStation{};
			tempCurrStation = utils.extractToken(str, next_pos, more);
			if (!(next_pos == next_copy)) {
				tempNextStation = utils.extractToken(str, next_pos, more);
				leftStations.push_back(tempCurrStation);
				rightStations.push_back(tempNextStation);
			}
			auto currStation = std::find_if(stations.begin(), stations.end(), [&](Workstation* station) {
				return station->getItemName() == tempCurrStation;
				});
			m_activeLine.push_back(*currStation);

			if (tempNextStation.length() > 0) {
				auto nextStation = std::find_if(stations.begin(), stations.end(), [&](Workstation* station) {
					return station->getItemName() == tempNextStation;
					});
				(*currStation)->setNextStation(*nextStation);
			}
		}

		size_t count{};
		std::string fStn{};
		for (const auto& leftStation : leftStations) {
			count = 0;
			for (const auto& rightStation : rightStations) {
				if (leftStation == rightStation) {
					count++;
				}
			}
			if (count == 0) {
				fStn = leftStation;
				break;
			}
		}

		auto firstStation = std::find_if(stations.begin(), stations.end(), [&](Workstation* station) {
			return station->getItemName() == fStn;
			});
		m_firstStation = *firstStation;

		m_cntCustomer = g_pending.size();
	}

	void LineManager::reorderStations() {
		std::vector<Workstation*> reorderedStations;
		Workstation* currentStation = m_firstStation;
		while (currentStation != nullptr) {
			reorderedStations.push_back(currentStation);
			currentStation = currentStation->getNextStation();
		}
		m_activeLine = reorderedStations;
	}

	bool LineManager::run(std::ostream& os) {
		static size_t iterationCount = 1;
		os << "Line Manager Iteration: " << iterationCount << std::endl;
		++iterationCount;

		if (!g_pending.empty()) {
			*m_firstStation += std::move(g_pending.front());
			g_pending.pop_front();
		}

		std::for_each(m_activeLine.begin(), m_activeLine.end(),
			[&](auto& i) {
				i->fill(os);
			});

		std::for_each(m_activeLine.begin(), m_activeLine.end(),
			[&](auto& i) {
				i->attemptToMoveOrder();
			});

		return g_completed.
			size() + g_incomplete.size() == m_cntCustomer;
	}

	void LineManager::display(std::ostream& os) const {
		std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](auto station) {
			station->display(os);
			});
	}
}