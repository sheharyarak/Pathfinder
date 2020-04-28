#include "Pathfinder.hpp"

int main(int argc, char* argv[])
{
	Pathfinder p;
	p.readMap("map.txt");
	Coords start(1,1), end(4, 3);
	std::cout << "Starting find path." << std::endl;
	Path path = p.find_path(start, end);
	std::cout << "Starting output." << std::endl;
	std::cout << "Map width: " << p.map().width() << std::endl;
	std::cout << "Map height: " << p.map().height() << std::endl;
	std::cout << "Path size: " << path.size() << std::endl;
	std::cout << "Path: " << path_to_string(path) << std::endl;
}