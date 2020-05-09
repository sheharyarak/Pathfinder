#include <map>
#include <utility>
#include <iostream>

typedef std::pair<size_t, size_t> Coords;

int main()
{
	std::map<size_t, Coords> map;
	std::cout << "placing 32 and (1,1) into the map." <<std::endl;
	map.emplace(32, Coords(1,1));
	std::cout << "placed." <<std::endl;
}