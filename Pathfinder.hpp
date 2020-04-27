#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <iostream>
#include <vector>
#include <utility>
#include "Map.hpp"
#include "Inventory.hpp"
#include "Cart.hpp"


typedef std::pair<unsigned int, unsigned int> Coords;
typedef	std::vector<Coords> Path;

class Pathfinder
{
private:
	/* data */
	Path _path;
	Map		*_map;
	bool** _checked;
	
public:
	Cart	cart()	const;
	Map		map()	const;
	Path	path()	const;
	void	readMap(std::string filename);
	void	readInventory(std::string filename);
	void	readList(std::string	filename);
	Path	find_path(Coords pos, Coords end, bool **checked = nullptr);
	bool	out_of_bounds(Coords pos, bool**checked);
	bool	**check(Coords pos, bool **checked);
};

std::string	coord_to_string(Coords coord);
std::string	path_to_string(Path path);
#endif