# Assembly-Line-Project

This project was developed as a part of my coursework for OOP345 - Object-Oriented Software Development Using C++. I utilized advanced C++ concepts such as Smart Pointers, Algorithms, File Stream Objects, Standard Library, Containers, and Iterators, Error Handling, and Class Templates.

## Description

The Assembly Line Simulator project is a C++ application that simulates an assembly line. The assembly line consists of a set of workstations, each holding specific stock items. A line manager moves customer orders along the line, filling the orders at each station as requested.
Each customer order comprises a list of items that need to be filled. The stations process a queue of orders by filling the next order in the queue if it requests the station's item and the item is in stock. The line manager keeps moving the customer orders from station to station until all orders have been processed. Any station that has used all the items in stock cannot fill any more orders.
At the end of the line, the simulator lists the completed orders and any incomplete orders due to a lack of inventory at one or more stations.

##Included Files

Utilities.cpp and Utilities.h: Support the parsing of input files used to set up and configure the assembly line.
Station.cpp and Station.h: Manage information about a station on the assembly line, including the specific item it holds and filling customer orders.
CustomerOrder.cpp and CustomerOrder.h: Provide functionality for processing customer orders as they move along the assembly line.
LineManager.cpp and LineManager.h: Configure the assembly line and move customer orders along it.
Workstation.cpp and Workstation.h: Represent a station that the line manager activates and use queues to hold orders at either end of the assembly line.
main_tester.cpp: Test the functionality of the assembly line simulator with input files and expected output.

#Usage
To run the Assembly Line Simulator:

Clone the repository to your local machine.
Compile the source code files using a C++ compiler.
Execute the compiled program.
Review the output to see the completed and incomplete orders.

Note: This project was developed as a part of my coursework for OOP345 and belongs to Seneca College.

Feel free to explore the code and modify it for your own use or educational purposes.
