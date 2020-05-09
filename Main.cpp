#include "Pathfinder.hpp"

int main(int argc, char* argv[])
{
	Pathfinder p;
	p.readMap("map.txt");
	std::cout << "Map:" << std::endl;
	p.map().printMap();
	p.readInventory("Inventory.txt");
	std::cout << "Inventory:" << std::endl;
	p.inventory().to_string();
	p.readCart("list.txt");
	std::cout << "List:" << std::endl;
	p.cart().to_string();
	std::cout << "Final Path:" << std::endl;
	std::cout << path_to_string(p.generate()) << std::endl;
}