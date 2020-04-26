#include "Pathfinder.hpp"

Cart	Pathfinder::cart()	const
{
	return _cart;
}
Map		Pathfinder::map()	const
{
	return _map;
}
Path	Pathfinder::path()	const
{
	return _path;
}
void	Pathfinder::readMap(std::string filename)
{
	_map.readMap(filename);
	_checked = new bool*[_map.height()];
	for(unsigned int i = 0; i < _map.height(); i++)
	{
		_checked[i] = new bool[_map.width()];
	}
}
Path	Pathfinder::find_path(Coords pos, Coords end)
{
	
}
bool	Pathfinder::out_of_bounds(Coords pos);
bool**	Pathfinder::check(Coords pos);
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