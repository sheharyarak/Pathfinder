#include "Pathfinder.hpp"

// Driver function for Pathfinder.exe, used for testing
int main(int argc, char* argv[])
{
	// Creates Pathfinder object
	Pathfinder p;
	// read map
	p.readMap("Map.tsv");
	// debug statements
	std::cout << "Map:" << std::endl;
	p.map().printMap();
	// Read inventory
	p.readInventory("Inventory.txt");
	// debug statements
	std::cout << "Inventory:" << std::endl;
	p.inventory().to_string();
	// Read Cart 
	p.readCart("list.txt");
	// debug statements
	std::cout << "List:" << std::endl;
	p.cart().to_string();
	// Generate and print path
	std::cout << "Final Path:" << std::endl;
	std::cout << path_to_string(p.generate()) << std::endl;
}