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
	Map		_map;
	bool** _checked;
	Cart	_cart;
	Inventory _inv;
	
public:
	Cart	cart()	const;
	Map		map()	const;
	Path	path()	const;
	void	readMap(std::string filename);
	Path	find_path(Coords pos, Coords end)
	bool	out_of_bounds(Coords pos);
	bool	**check(Coords pos);
};

#endif