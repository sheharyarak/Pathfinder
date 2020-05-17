#include "Pathfinder.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Strings.hpp"

// Getters
Map			Pathfinder::map()	const
{
	return _map;
}
Map*		Pathfinder::map_view()	const
{
	return (Map*)(&_map);
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
// Reads the map from text file and creates map of checked locations
void	Pathfinder::readMap(std::string filename)
{
	_map.readMap(filename);
	_checked = new bool*[_map.height()];
	// initializes all checked locations to false
	for(size_t i = 0; i < _map.height(); i++)
	{
		_checked[i] = new bool[_map.width()];
		for(size_t j = 0; j < _map.width(); j++)
			_checked[i][j] = false;
	}
}
// sorts by size
bool	sort_by_size(Path left, Path right)
{
	return left.size() < right.size();
}

// Plan for Pathfinding Algorithm
/*
 * /////TODO: Make a function that finds the shortest path
 * Approach: Recursion - Brute force
 ? Should I use an approach with loops or should I focus on a recursive approch and covert it to loops later on?
 @param 
 * What to look out for:
 	-	repition: don't search along the same path over and over again
TODO:	-	memory: probably going to have to convert this to a loop approach later on.
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
		- if false: return an empty path; there is no way to get to Point B from here
	sort the container by size of each path
	add shortest path in the container to the end of the Path in the function
	return the Path
 */

// pathfinding algorithm
Path	Pathfinder::find_path(Coords pos, Coords end, bool** checked)//, size_t current_size/*, std::string dir*/)
{
	// creates path to be returned
	Path final;
	// we add the current position to the path
	final.push_back(pos);
	//	if the end point is reached return the path
	if(pos == end) 
	{
		return final;
	}
	//	if path leads to out of bounds return an empty path
	if((checked != nullptr && out_of_bounds(pos, checked)))// || current_size >= shortest_path)
	{
		// path_count++;
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
	// list paths which will contain the path checked in each direction
	std::vector<Path> paths;
	//	right
	paths.push_back(find_path(Coords(pos.first+1,pos.second), end, check(pos, checked)));//, current_size + 1/*, dir+"r"*/));
	//	left
	paths.push_back(find_path(Coords(pos.first-1,pos.second), end, check(pos, checked)));//, current_size + 1/*, dir+"l"*/));
	//	down
	paths.push_back(find_path(Coords(pos.first,pos.second+1), end, check(pos, checked)));//, current_size + 1/*, dir+"u"*/));
	//	up
	paths.push_back(find_path(Coords(pos.first,pos.second-1), end, check(pos, checked)));//, current_size + 1/*, dir+"d"*/));

	//	remove empty paths
	for(size_t i = 0; i < paths.size(); i++)
	{
		if(paths[i].size() == 0) 
		{
			// erasing decrements size
			// and places another element at current index
			// so the index should stay the same for next iteration
			paths.erase(paths.begin()+i);
			i--; // decrements i
			// so when the loop increments the index doesnt change
		}
	}
	// sort by size in ascending order
	// smallest size first
	std::sort(paths.begin(), paths.end(), sort_by_size);
	//	all empty paths returned
	if(paths.size() == 0)
	{
		return Path();
	}
	//	concatenate the shortest path to the final path
	for(size_t i = 0; i < paths[0].size(); i++)
	{
		final.push_back(paths[0][i]);
	}
	//	if path leads to end, then return this path
	if(final[final.size()-1] == end)
	{
		// path_count++;
		if(final.size() < shortest_path)
			shortest_path = final.size();
		return final;
	}
	//	else return empty path
	else
	{
		return Path();
	}
	
}

// Check if current position is out of bounds
bool	Pathfinder::out_of_bounds(Coords pos, bool** checked)
{
	//	make sure coords are within the map
	if(pos.first < 0 || pos.second < 0 || pos.first >= _map.width() || pos.second >= _map.height())
	{
		return true;
	}
	//	make sure its a walking path
	if(_map.at_coord(pos.first, pos.second) != 0) return true;
	//	make sure the path hasn't been visited before
	if(checked[pos.second][pos.first])
	{
		return true;
	}
	//current position is within bounds
	return false;
}
// Mark location as visited
bool**	Pathfinder::check(Coords pos, bool** checked)
{
	// create new visit map to prevent paths from interfering
	bool**	map = new bool*[_map.height()];
	for(size_t i = 0; i < _map.height(); i++)
	{
		map[i] = new bool[_map.width()];
	}
	// copy visited nodes
	for(size_t i = 0; i < _map.height(); i++)
	{
		for(size_t j = 0; j < _map.width(); j++)
		{
			map[i][j] = checked[i][j];
		}
	}
	// add current node as visited
	map[pos.second][pos.first] = true;
	// return map of visiited  nodes
	return map;
}

// prints path as string
std::string	path_to_string(Path path)
{
	// create empty string
	std::string os = "";
	// if the path is empty return empty path
	if(path.empty())
	{
		os += "empty path";
	}
	// add coords to string
	else
	{
		// iterate through each coord in string
		for(size_t i = 0; i < path.size() - 1; i++)
			// add cord to string followed by a comma
			os += coord_to_string(path[i]) + ", ";
		// add last coord to string
		os += coord_to_string(path[path.size()-1]);
	}
	// return string
	return os;
}

// reads the cart
void	Pathfinder::readCart(std::string filename)
{
	_cart.readList(filename);
}
// reads the inventory
void	Pathfinder::readInventory(std::string filename)
{
	_inv.readInventory(filename);
}

// gets the coord of the item
Coords	Pathfinder::get_coords(std::string item)
{
	// removes spaces from string
	// wass getting this issue for some reason
	// used previously developed trim function
	// to remove all white spaces
	trim(item);
	// each item in the set of item names
	// maps to an item number in the set of item numbers
	size_t item_no = _inv[item];
	// each item number in the set of item numbers 
	// maps to a coordinate in the set of coords
	Coords coord = _map[item_no];
	// return the coordinate at which the item is located
	return coord;
}

// fill the item list with coordinates of each item
void	Pathfinder::fill_items()
{
	// create items path
	Path items;
	// create coords
	Coords coord;
	// iterate through each item in the cart
	for(auto item : _cart.list())
	{
		// get the coordinate of the item
		coord = get_coords(item);
		// add the coordinate to the items list
		items.push_back(coord);
	}
	// update items
	_items = items;
}

// return true if the distance of the first coord
// is less than the distance of the second coord
bool	sort_by_distance(std::pair<double, Coords> lhs, std::pair<double, Coords> rhs)
{
	return	lhs.first < rhs.first;
}

// sorts the items by distance to pos
void	Pathfinder::sort_items_by_distance(Coords pos)
{
	// create sorted path
	Path	sorted;
	// create vector of distance coordinate pair
	std::vector<std::pair<double, Coords>> tmp;
	// add distance and coord to tmp vector
	for(Coords item: _items)
		tmp.push_back(std::pair<double, Coords>(distance(pos, item), item));
	// sort tmp vector
	std::sort(tmp.begin(), tmp.end(), sort_by_distance);
	// add cord in order to sorted list of coords
	for(auto pair : tmp)
		sorted.push_back(pair.second);
	// update items
	_items = sorted;
}

// distance between to lines
// uses the distance formula
double	distance(Coords start, Coords end)
{
	return	std::sqrt(std::pow(end.first - start.first, 2) + std::pow(end.second - start.second, 2));
}

// geneerates the route to take
Path	Pathfinder::generate()
{
	// creates a path and a tmp path
	Path path, tmp;
	// gets coordinates to entrance
	// TODO: update for multiple entry points
	Coords	start = get_coords("Entrance");
	// fill items with coords
	fill_items();
	// create a backup items 
	Path	items = _items;
	// print list of items for debugging
	// std::cout << "items list: " << path_to_string(items) << "<br>" << std::endl;
	// iterate through each item in the list
	// until the ist is empty
	while(_items.size() > 0)
	{
		// sort items by distance from entrance
		sort_items_by_distance(start);
		// find path to nearest item
		tmp = find_path(start, _items[0]);
		// add path to final path
		for(Coords coord: tmp)
			path.push_back(coord);
		// set path equal to point directly before item was reached
		start = path[path.size()-2];
		// delete item from list
		_items.erase(_items.begin());
	}
	// find exit path
	tmp = find_path(start, get_coords("Exit"));
	// add path to exit to final path
	for(Coords coord: tmp)
			path.push_back(coord);
	// update path
	_path = path;
	// restore item backup
	_items = items;
	// return path
	return path;
}

// colors each item cart on map <HTML>
void	Pathfinder::mark_items()
{
	// iterate through each item
	for(Coords item: _items)
		// color it
		std::cout << "ctx.fillStyle = \"" << "#00FF04" << "\";" << std::endl
			<<	"ctx.fillRect(" 
			<< item.first * map().scale() << ", " << item.second * map().scale() 
			<< ", " << map().scale() << ", " << map().scale() << ");"
			<< std::endl;
}

// draws the path to each item <HTML>
void	Pathfinder::draw_path()
{
	// used to d=set random color; looked ugy so removed
	// std::srand(std::time(nullptr));
	// print out a buch of javascript to set up drawing lines
	std::cout << std::endl
	<<"var R = 0; var G = 0; var B = 0; var color = \'rgba(0,0,0,1)\';" << std::endl
	<< "ctx.beginPath();" << std::endl;
	std::cout << "ctx.lineWidth = " << _width << ";" << std::endl
	<<	"ctx.moveTo(" << _path[0].first*map().scale() << ", " << _path[0].second*map().scale() <<");" << std::endl;
	std::string color = "#FF63FF";
	// more javascript to draw lines
	for (size_t i = 1; i < _path.size(); i++)
	{
		std::cout << "ctx.lineTo(" << _path[i].first*map().scale() + map().scale()/2.0 << ", " << _path[i].second*map().scale() + map().scale()/2.0 << ");" << std::endl
		<< "R = " << (255 - i*map().scale()) % 256 <<";" << std::endl
		<< "G = " << 0<<";" << std::endl
		<< "B = " << 255<<";" << std::endl
		
		<<	"color = \'rgba(\' + R + \', \' + G + \', \' + B + \', 1)\';" << std::endl
		<<	"ctx.strokeStyle = " << "color" << ";" << std::endl
		<<	"ctx.stroke(); ctx.closePath(); " << std::endl;
		std::cout <<	"ctx.beginPath(); ctx.moveTo(" << _path[i].first*map().scale() + map().scale()/2.0 << ", " << _path[i].second*map().scale() + map().scale()/2.0 <<");" << std::endl;
	}
}

// getter and setter for width
size_t	Pathfinder::width()	const
{
	return _width;
}

void	Pathfinder::width(size_t width)
{
	_width = width;
}

// add item to cart
void	Pathfinder::add_to_cart(std::string item)
{
	_cart.add_to_cart(item);
}
