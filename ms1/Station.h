#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>
namespace sdds {
	class Station
	{
        int m_id;                           // The id of the station
        std::string m_itemName;             // The name of the item handled by the station
        std::string m_desc;                 // The description of the station
        size_t m_serialNumber;              // The next serial number to be assigned to an item at this station
        size_t m_quantity;                  // The number of items currently in stock
        static size_t m_widthField;         // The maximum number of characters required to print to the screen the item name for any object of type Station
        static size_t id_generator;         // A variable used to generate IDs for new instances of type Station
    public:
        Station(const std::string&);        // Custom 1-argument constructor
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream&, bool) const;
	};
}
#endif // !SDDS_STATION_H