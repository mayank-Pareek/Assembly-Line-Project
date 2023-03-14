#include <iomanip>
#include "Station.h"
#include "Utilities.h"
namespace sdds {
    // Initialize static members
    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;

    // Custom constructor
    Station::Station(const std::string& str) {
        Utilities util;
        size_t next_pos = 0;
        bool more = true;
        m_id = ++id_generator;
        m_itemName = util.extractToken(str, next_pos, more);
        m_serialNumber = stoi(util.extractToken(str, next_pos, more));
        m_quantity = stoi(util.extractToken(str, next_pos, more));
        m_desc = util.extractToken(str, next_pos, more);
        m_widthField = std::max(m_widthField, util.getFieldWidth());
    }

    // Returns the name of the current Station object
    const std::string& Station::getItemName() const {
        return m_itemName;
    }

    // Returns the next serial number to be used on the assembly line and increments m_serialNumber
    size_t Station::getNextSerialNumber() {
        return m_serialNumber++;
    }

    // Returns the remaining quantity of items in the Station object
    size_t Station::getQuantity() const {
        return m_quantity;
    }

    // Subtracts 1 from the available quantity; should not drop below 0
    void Station::updateQuantity() {
        if (m_quantity > 0) {
            m_quantity--;
        }
    }

    // Inserts information about the current object into stream os
    void Station::display(std::ostream& os, bool full) const {
        os << "[" << std::setw(3) << std::setfill('0') << m_id << "] Item: ";
        os << std::setw(m_widthField) << std::left << m_itemName;
        os << " [" << std::setw(6) << std::setfill('0') << m_serialNumber << "]";
        if (full) {
            os << " Quantity: " << std::setw(4) << std::left << m_quantity;
            os << " Description: " << m_desc;
        }
        os << std::endl;
    }
}