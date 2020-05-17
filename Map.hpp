#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <map>
#include <utility>

typedef std::pair<size_t, size_t> Coords;

// Conatins map of store
// Each Coord maps to an Item Number which Maps to and Item Name
class Map
{
private:
	// map that maps item numer to color key
	std::map<size_t, std::string>	colors;
	// horizontal width of map
	size_t							_width = 0;
	// vertical height of map
	size_t							_height = 0;
	// height and width of each coord in pixels
	size_t							_scale = 100;
	// maps item number to a coordinate to allow finding items with ease
	std::map<size_t, Coords>		_also_a_map_lol;
	// 2D array of item numbers making up the map of the store
	size_t							**_map = nullptr;
	// creates the 2D array
	void							generateArray();
	// creates the color map
	void							generateColorMap();
public:
	// default constructor
	Map(){	generateColorMap();	}
	// reads the map
	void	readMap(std::string filename);
	// prints the map; for debugging
	void	printMap();
	// prints the map for HTML; for debugging
	void	printMapHTML();
	// draws the map for html
	void	draw_map();
	// getters for height and width
	size_t	height()	const;
	size_t	width()		const;
	// returns item number at position in 2D array
	size_t	at_coord(size_t, size_t) const;
	// accessor for _also_a_map; sorry for confusing names,
	//  I couldn't think of anything else
	Coords&	operator[](size_t key);
	// getter for scale
	size_t	scale()	const;
	// setter for scale
	void	scale(size_t sc);
	// returns color based on item number
	std::string	color(size_t c);
};
// converts coord to string
std::string	coord_to_string(Coords coord);

#endif /* MAP_H */
