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
	size_t		shortest_path = 100000000;
	Path		_path;
	Map			_map;
	Cart		_cart;
	Inventory	_inv;
	Path		_items;
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
	//	getters
	Cart		cart()		const;
	Map			map()		const;
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
	Path	generate();
	Coords	get_coords(std::string item);
	void	fill_items();
	void	sort_items_by_distance();
	void	mark_items();
	void	draw_path();
	size_t	width()	const;
	void	width(size_t width);
	void	add_to_cart(std::string item);
};

std::string	path_to_string(Path path);
double		distance(Coords start, Coords end);
#endif
