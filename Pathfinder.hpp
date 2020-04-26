#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <iostream>
#include <deque>
#include <utility>
#include "Map.hpp"
#include "Inventory.hpp"
#include "Cart.hpp"

typedef std::pair<std::deque<std::pair<unsigned int, unsigned int>>, bool> FoundPath;
typedef std::pair<unsigned int, unsigned int> Coords;
typedef std::deque<std::pair<unsigned int, unsigned int>> Path;

class Pathfinder
{
private:
	/* data */
	Path _path;
	Map		_map;
	Cart	_cart;
	Inventory _inv;
	
public:
	Cart	cart()	const;
	Map		map()	const;
	Path	path()	const;
	FoundPath	find_path(Coords start, Coords end, FoundPath path = FoundPath())	const;
};

#endif