#include "Pathfinder.hpp"
#include <algorithm>
#include <iostream>

Map		Pathfinder::map()	const
{
	return *_map;
}
Path	Pathfinder::path()	const
{
	return _path;
}
void	Pathfinder::readMap(std::string filename)
{
	_map->readMap(filename);
	_checked = new bool*[_map->height()];
	for(unsigned int i = 0; i < _map->height(); i++)
	{
		_checked[i] = new bool[_map->width()];
	}
}

bool	sort_by_size(Path left, Path right)
{
	return left.size() < right.size();
}

Path	Pathfinder::find_path(Coords pos, Coords end, bool** checked)
{
	//	if default argument
	if(checked == nullptr)
		checked = _checked;
	Path final = Path();
	final.push_back(pos);
	//	if the end point is reached return the path
	if(pos == end) return final;
	//	if path leads to out of bounds return an empty path
	if(out_of_bounds(pos, checked)) return Path();
	std::vector<Path> paths;
	//	right
	paths.push_back(find_path(Coords(pos.first+1,pos.second), end, check(Coords(pos.first+1,pos.second), checked)));
	//	up
	paths.push_back(find_path(Coords(pos.first+1,pos.second), end, check(Coords(pos.first,pos.second+1), checked)));
	//	left
	paths.push_back(find_path(Coords(pos.first+1,pos.second), end, check(Coords(pos.first-1,pos.second), checked)));
	//	down
	paths.push_back(find_path(Coords(pos.first+1,pos.second), end, check(Coords(pos.first,pos.second-1), checked)));
	//	remove empty paths
	std::string directions[] = {"up", "left", "down", "right"};
	for(int i = 0; i < paths.size(); i++)
	{
		//! NOT ENTERING THE LOOP
		std::cout << i;
		if(paths[i].size() == 0) 
		{
			std::cout << "found empty path at index " << directions[i] << std::endl;
			paths.erase(paths.begin()+i);
		}
	}
	//	sort by size in ascending order
	std::sort(paths.begin(), paths.end(), sort_by_size);
	//	add all elements of the shortest path to the final path
	for(int i = 0; i < paths[0].size(); i++)
	{
		final.push_back(paths[0][i]);
	}
	return final;
}
bool	Pathfinder::out_of_bounds(Coords pos, bool** checked)
{
	//	make sure coords are within the map
	if(!(pos.first < 0 || pos.second < 0 || pos.first >= _map->width() || pos.second >= _map->height())) return true;
	//	make sure its a walking path
	//if(_map->at_coord(pos.first, pos.second) != 0) return true;
	//	make sure the path hasn't been visited before
	if(checked[pos.second][pos.first])	return true;
	return false;
}
bool**	Pathfinder::check(Coords pos, bool** checked)
{
	bool**	map = new bool*[_map->height()];
	for(unsigned int i = 0; i < _map->height(); i++)
	{
		map[i] = new bool[_map->width()];
	}
	for(unsigned int i = 0; i < _map->height(); i++)
	{
		for(unsigned int j = 0; j < _map->width(); j++)
		{
			map[i][j] = checked[i][j];
		}
	}
	map[pos.second][pos.first] = true;
	return map;
}
/*
 * //TODO: Make a function that finds the shortest path
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

std::string		coord_to_string(Coords coord)
{
	std::string str = "";
	str += "(";
	str += coord.first;
	str += ", ";
	str += coord.second;
	str += ")";
	return str;
}

std::string	path_to_string(Path path)
{
	std::string os = "";
	if(path.empty())
	{
		os += "empty path";
	}
	else
	{
		for(int i = 0; i < path.size() - 1; i++)
			os += coord_to_string(path[i]) + ", ";
		os += coord_to_string(path[path.size()-1]);
	}
	return os;
}