#include "Linked List.h"
#include <iostream>


int main() {
	int val = 0;
	LinkedList myList;

	while (val != -1) {
		std::cout << "Enter a positive value for the next node (-1 to stop): " << std::endl;
		std::cin >> val;

		if (val != -1) {
			myList.addNode(val);
		}
	}
	
	std::cout << std::endl << "=================" << std::endl;
	std::cout << "Nodes before sort: " << std::endl;

	myList.printNodes();

	std::cout << std::endl << "=================" << std::endl;
	std::cout << "Nodes after sort: " << std::endl;

	myList.bubbleSort();
	myList.printNodes();
}