#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <iostream>
#include <vector>
#include <utility>

#include "Map.hpp"
#include "Inventory.hpp"
#include "Cart.hpp"

typedef	std::vector<Coords> Path;

class Pathfinder
{
private:
	/* data */
	// shortest path lenghth. Will be used to make code more efficient
	// doesn't work right now
	size_t		shortest_path = 100000000;
	// shortest path
	Path		_path;
	// map of the store through which we're navigating
	Map			_map;
	// cart with the list of items to generate a path for
	Cart		_cart;
	// inventory of the store with item codes
	Inventory	_inv;
	// NOT A PATH; list of cordinates at which each item in the cart is located
	Path		_items;
	// width of the path when drawing
	size_t		_width = 10;
	/*
		Map	_map:
			j	0	1	2	3	4
		i	
		0		1	1	1	1	1
		1		1	0	0	0	1
		2		1	0	1	0	1
		3		1	0	0	0	1
		4		1	1	1	1	1
	 */
	// map of checked nodes
	bool** _checked;
	/*
		bool**	_checked:
		*	No node visited	*
			j	0	1	2	3	4
		i	
		0		F	F	F	F	F
		1		F	F	F	F	F
		2		F	F	F	F	F
		3		F	F	F	F	F
		4		F	F	F	F	F
		*	(1, 1) visited	*
			j	0	1	2	3	4
		i	
		0		F	F	F	F	F
		1		F	T	F	F	F
		2		F	F	F	F	F
		3		F	F	F	F	F
		4		F	F	F	F	F
		
	 */
	
public:
	// number of paths generated.
	// used to make graph shown in presentation
	// size_t		path_count = 0;
	//	getters
	Cart		cart()		const;
	Map			map()		const;
	Map*		map_view()		const;
	Path		path()		const;
	Inventory	inventory()	const;
	Path		items()		const;
	//	reading
	void	readMap(std::string filename);
	void	readInventory(std::string filename);
	void	readCart(std::string filename);
	//	path finding
	Path	find_path(Coords pos, Coords end, bool **checked = nullptr);//, size_t current_size = 1/*, std::string dir=""*/);
	bool	out_of_bounds(Coords pos, bool**checked);
	bool	**check(Coords pos, bool **checked);
	//	utility
	// generates the path
	Path	generate();
	// gets the coordinats of the item
	Coords	get_coords(std::string item);
	// fills the items list with coordinates
	void	fill_items();
	// sorts the item list by distance
	void	sort_items_by_distance(Coords pos);
	// marks the items on the map;  html
	void	mark_items();
	// draws the path on the map; html
	void	draw_path();
	// returns the width of the path
	size_t	width()	const;
	// sets te width of the path
	void	width(size_t width);
	// adds item to the cart
	void	add_to_cart(std::string item);
};

// returns the path as a string of coordinates
std::string	path_to_string(Path path);
// returns the distance between two coordinates using the distance formula
double		distance(Coords start, Coords end);
#endif
