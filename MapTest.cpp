#include "Map.hpp"

int		main(int argc, char	*argv[])
{
	std::string 	path;
	if(argc < 2)
	{
		path = "test.tsv";
	}
	else
	{
		path = argv[1];
	}
	Map	map;
	map.readMap(path);
	map.printMap();
}