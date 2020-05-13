#include "Pathfinder.hpp"
#include "Timer.h"

int main(int argc, char* argv[])
{
	Pathfinder p;
	std::string file = "";
	if(argc == 2)
	{
		file = file + argv[1] +"x"+argv[1]+".tsv";
		p.readMap(file);
	}
	else if(argc == 3)
	{
		file = file + argv[1] +"x"+argv[2]+".tsv";
		p.readMap(file);
	} 
	else
		p.readMap("map.txt");
	Coords start(0, 0), end(p.map_view()->width()-1, p.map_view()->height()-1);
	std::cout << "Map width: " << p.map().width() << std::endl;
	std::cout << "Map height: " << p.map().height() << std::endl;
	std::cout << "Starting output." << std::endl;
	Timer t("find_path");
	Path path = p.find_path(start, end);
	std::cout << "paths:" << p.path_count << std::endl;
	// std::cout << "Path size: " << path.size() << std::endl;
	// std::cout << "Path: " << path_to_string(path) << std::endl;
}