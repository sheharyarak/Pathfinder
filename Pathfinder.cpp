#include "Pathfinder.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include "Strings.hpp"

Map			Pathfinder::map()	const
{
	return _map;
}
Path		Pathfinder::path()	const
{
	return _path;
}
Inventory	Pathfinder::inventory()	const
{
	return	_inv;
}
Path		Pathfinder::items()	const
{
	return	_items;
}
Cart		Pathfinder::cart()	const
{
	return _cart;
}
void	Pathfinder::readMap(std::string filename)
{
	_map.readMap(filename);
	_checked = new bool*[_map.height()];
	for(size_t i = 0; i < _map.height(); i++)
	{
		_checked[i] = new bool[_map.width()];
		for(size_t j = 0; j < _map.width(); j++)
			_checked[i][j] = false;
	}
}

bool	sort_by_size(Path left, Path right)
{
	return left.size() < right.size();
}

Path	Pathfinder::find_path(Coords pos, Coords end, bool** checked)//, size_t current_size/*, std::string dir*/)
{
	// creates path to be returned
	Path final;
	// we add the current position to the path
	final.push_back(pos);
	//	if the end point is reached return the path
	if(pos == end) 
	{
		// std::cout << "pos == end; "<< coord_to_string(pos) << "==" << coord_to_string(end) << std::endl;
		return final;
	}
	//	if path leads to out of bounds return an empty path
	if((checked != nullptr && out_of_bounds(pos, checked)))// || current_size >= shortest_path)
	{
		// std::cout << "out of bounds: " << coord_to_string(pos) << std::endl;
		return Path();
	}
	//	if default argument
	if(checked == nullptr)
	{
		// std::cout << "checked = _checked" << std::endl;
		//	if default argument given then set checked equal to
		//	2D array of bools of same dimensions as the map 
		//	that are set to false
		//	header has a better info
		checked = _checked;
	}
	std::vector<Path> paths;
	//	right
	paths.push_back(find_path(Coords(pos.first+1,pos.second), end, check(pos, checked)));//, current_size + 1/*, dir+"r"*/));
	//	left
	paths.push_back(find_path(Coords(pos.first-1,pos.second), end, check(pos, checked)));//, current_size + 1/*, dir+"l"*/));
	//	down
	paths.push_back(find_path(Coords(pos.first,pos.second+1), end, check(pos, checked)));//, current_size + 1/*, dir+"u"*/));
	//	up
	paths.push_back(find_path(Coords(pos.first,pos.second-1), end, check(pos, checked)));//, current_size + 1/*, dir+"d"*/));
	// std::string directions[] = {"up", "left", "down", "right"};
	// std::cout << "paths.size()=" << paths.size() << std::endl;
	// int j = 0;

	//	remove empty paths
	for(size_t i = 0; i < paths.size(); i++)
	{
		//**// //! NOT ENTERING THE LOOP
		// std::cout << i;

		if(paths[i].size() == 0) 
		{
			// std::cout << "found empty path at index " << directions[j] << std::endl;
			paths.erase(paths.begin()+i);
			i--;
		}
	}
	//	sort by size in ascending order
	std::sort(paths.begin(), paths.end(), sort_by_size);
	//	concatenate the shortest path to the final path
	if(paths.size() == 0)
	{
		// std::cerr << "Error: No valid paths found." << std::endl;
		return Path();
	}
	for(size_t i = 0; i < paths[0].size(); i++)
	{
		final.push_back(paths[0][i]);
	}
	//	if path leads to end, then return this path
	if(final[final.size()-1] == end)
	{
		// std::cout << "returning path: " << path_to_string(final) << std::endl;
		if(final.size() < shortest_path)
			shortest_path = final.size();
		return final;
	}
	//	else return empty path
	else
	{
		// std::cout << "hit a dead end at: " << path_to_string(final) << std::endl;
		return Path();
	}
	
}
bool	Pathfinder::out_of_bounds(Coords pos, bool** checked)
{
	//	make sure coords are within the map
	if(pos.first < 0 || pos.second < 0 || pos.first >= _map.width() || pos.second >= _map.height())
	{
		// std::cout << "outside map" << std::endl;
		return true;
	}
	//	make sure its a walking path
	if(_map.at_coord(pos.first, pos.second) != 0) return true;
	//	make sure the path hasn't been visited before
	// std::cout << "checked["<<pos.second<<"]["<<pos.first<<"]: "<<std::boolalpha << checked[pos.second][pos.first] << std::endl;
	if(checked[pos.second][pos.first])
	{
		return true;
	}
	return false;
}
bool**	Pathfinder::check(Coords pos, bool** checked)
{
	bool**	map = new bool*[_map.height()];
	for(size_t i = 0; i < _map.height(); i++)
	{
		map[i] = new bool[_map.width()];
	}
	for(size_t i = 0; i < _map.height(); i++)
	{
		for(size_t j = 0; j < _map.width(); j++)
		{
			map[i][j] = checked[i][j];
		}
	}

	map[pos.second][pos.first] = true;
	// std::cout << "marked as checked["<<pos.second<<"]["<<pos.first<<"]: "<<std::boolalpha << map[pos.second][pos.first] << std::endl;
	return map;
}
/*
 * /////TODO: Make a function that finds the shortest path
 * Approach: Recursion - Brute force
 ? Should I use an approach with loops or should I focus on a recursive approch and covert it to loops later on?
 @param 
 * What to look out for:
 	-	repition: don't search along the same path over and over again
	-	memory: probably going to have to convert this to a loop approach later on.
  	-	Check for in boundaries : make function
 	-	Keep track of steps taken : use a container of Coords
 	-	returns shortest distance.
 *	requirements: (Args)
 	-	Map to traverse through
	-	Current Coords to know where we are
	-	Final Coords to know when to stop
	-	Visited Coords to know not to repeat
*	return:
	-	Path
	? What defines a path?
	-	An ordered list of Coords that connect Point A to Point B
*	Algorithm:
	create new empty Path
	save current coord in Path

	Check if Point B was reached
		- if true: return the Path
	Check if current coord is a valid position on the map.
		- if false: return an empty Path

	Create a container of paths
	add the path returned by the recursive call of the function to the container
	remove all failed/empty paths from the container
	check if the container contains elements
		- if false: return an empty path; there is no way to get to Point B

	sort the container by size of each path
	add shortest path in the container to the end of the Path in the function
	return the Path
 */

std::string	path_to_string(Path path)
{
	std::string os = "";
	if(path.empty())
	{
		os += "empty path";
	}
	else
	{
		for(size_t i = 0; i < path.size() - 1; i++)
			os += coord_to_string(path[i]) + ", ";
		os += coord_to_string(path[path.size()-1]);
	}
	return os;
}

void	Pathfinder::readCart(std::string filename)
{
	_cart.readList(filename);
}
void	Pathfinder::readInventory(std::string filename)
{
	_inv.readInventory(filename);
}
Coords	Pathfinder::get_coords(std::string item)
{
	trim(item);
	// std::cout << item << " is " << item.length() << " characters long." << std::endl;
	size_t item_no = _inv[item];
	Coords coord = _map[item_no];
	// std::cout << item_no << " - " << item << " is at " <<coord_to_string(coord) << std::endl;
	return coord;
}
void	Pathfinder::fill_items()
{
	Path items;
	Coords coord;
	for(auto item : _cart.list())
	{
		coord = get_coords(item);
		items.push_back(coord);
		std::cout << item << " is at " << coord_to_string(coord) << "<br>" <<std::endl;
	}
	_items = items;
}

bool	sort_by_distance(std::pair<double, Coords> lhs, std::pair<double, Coords> rhs)
{
	return	lhs.first < rhs.first;
}

void	Pathfinder::sort_items_by_distance()
{
	Path	sorted;
	Coords	entrance = get_coords("Entrance");
	std::vector<std::pair<double, Coords>> tmp;
	for(Coords item: _items)
		tmp.push_back(std::pair<double, Coords>(distance(entrance, item), item));
	std::sort(tmp.begin(), tmp.end(), sort_by_distance);
	for(auto pair : tmp)
		sorted.push_back(pair.second);
	_items = sorted;
}

double	distance(Coords start, Coords end)
{
	return	std::sqrt(std::pow(end.first - start.first, 2) + std::pow(end.second - start.second, 2));
}

Path	Pathfinder::generate()
{
	Path path, tmp;
	Coords	start = get_coords("Entrance");
	fill_items();
	// std::cout << "items list: " << path_to_string(_items) << std::endl;
	sort_items_by_distance();
	// std::cout << "sorted items list: " << path_to_string(_items) << std::endl;
	for(Coords item : _items)
	{
		// std::cout << "Finding path from " << coord_to_string(start) << " to " << coord_to_string(item) << std::endl;
		tmp = find_path(start, item);
		// std::cout << "tmp = " << path_to_string(tmp) << std::endl;
		for(Coords coord: tmp)
			path.push_back(coord);
		start = path[path.size()-1];
	}
	_path = path;
	return path;
}

void	Pathfinder::mark_items()
{
	for(Coords item: _items)
		std::cout << "ctx.fillStyle = \"" << "#00FF04" << "\";" << std::endl
			<<	"ctx.fillRect(" 
			<< item.first * map().scale() << ", " << item.second * map().scale() 
			<< ", " << map().scale() << ", " << map().scale() << ");"
			<< std::endl;
}

void	Pathfinder::draw_path()
{
	std::cout << "ctx.beginPath();" << std::endl;
	std::cout << "ctx.lineWidth = " << _width << ";" << std::endl
	<<	"ctx.moveTo(" << _path[0].first*map().scale() << ", " << _path[0].second*map().scale() <<");" << std::endl;
	std::string color = "#FF63FF";
	for (size_t i = 1; i < _path.size(); i++)
	{
		/* code */
		std::cout << "ctx.lineTo(" << _path[i].first*map().scale() << ", " << _path[i].second*map().scale() << ");"
		<<	"ctx.strokeStyle = \"" << color << "\";" << std::endl
		<<	"ctx.stroke();" << std::endl;
		color = i % 2 ? "#FF63FF" : "339966";
	}
}

size_t	Pathfinder::width()	const
{
	return _width;
}
void	Pathfinder::width(size_t width)
{
	_width = width;
}
void	Pathfinder::add_to_cart(std::string item)
{
	_cart.add_to_cart(item);
}
