#include "Map.hpp"
#include <fstream>
#include <iomanip>
#include <string> 

// creates 2D array of height and width and of data type unsigned long
void	Map::generateArray()
{
	_map = new size_t*[_height];
	for(size_t	i = 0; i < _height; i++)
	{
		_map[i] = new size_t[_width];
	}
}

// creates color map
void	Map::generateColorMap()
{
	colors[0] = "#FFFBD7";
	colors[1] = "#808080";
	colors[2] = "#58F658";
	colors[3] = "#FF0000";
	colors[4] = "#12B1FF";
	colors[5] = "#000000";
}

// gets color of coord based on item number
std::string	Map::color(size_t c)
{
	// ternary operation
	// limits item number to be a value between 0 and 5
	c = c > 4 ? 5 : c;
	return colors[c];
}
// Map::~Map()
// {
// 	for(size_t i = 0; i < _height; i++)
// 	{
// 		delete [] _map[i];
// 	}
// 	delete [] _map;
// 	delete this;
// }
// getters for height, width, and scale. Also, the setter for scale.
size_t		Map::height() const
{
	return _height;
}
size_t		Map::width() const
{
	return	_width;
}
size_t	Map::scale() const
{
	// std::cout <<  "returning _scale: " << _scale << std::endl;
	return _scale;
}
void	Map::scale(size_t sc)
{
	// ! Setter for scale doesn't work for some reason
	//~ std::cout <<  "setting _scale: " << _scale << std::endl;
	_scale = sc;
	//~ std::cout <<  "setting _scale: " << _scale << std::endl;
}

// reads the map from tsv file
void	Map::readMap(std::string filename)
{	
	// create input file stream
	std::ifstream	in;
	// create data
	size_t data;
	// create coord
	Coords coord;
	// open file
	in.open(filename);
	// check if file was opened.
	if(!in.is_open())
	{
		std::cout << "Could not open file to read map." << std::endl;
		// leave program if fale wasn't opened
		exit(-2);
	}
	// read in width and height
	in >> _width >> _height;
	// std::cout << "generating array." << std::endl;
	// create 2D array
	generateArray();
	// std::cout << "finished generating array." << std::endl;
	// fill array with values from text file
	for(size_t i = 0; i < _height; i++)
	{
		for(size_t j = 0; j < _width; j++)
		{
			if(in.eof())
			{
				// leave function if file ends before array finishes
				std::cout << "file ended before array was completed." <<std::endl;
				return;
			}
			else
			{
				// read in data
				in >> data;
				//// std::cout << "read value: " << data << std::endl;
				// map data
				_map[i][j] = data;
				// create coord
				coord = Coords(j,i);
				//// std::cout << "mapping value " << data << " to " << coord_to_string(coord) << std::endl;
				// map data to coord
				_also_a_map_lol.emplace(data, coord);
				//// std::cout << "mapped value" << data << " to " << coord_to_string(coord) << std::endl;
			}
		}
	}
	in.close();
	// std::cout << "finished reading map" << std::endl;
}

// prints map for debugging
void	Map::printMap()
{
	// prints map exatly as it was read
	std::cout << _width << "\t" << _height << std::endl;
	for(size_t i = 0; i < _height; i++)
	{
		for(size_t j = 0; j < _width; j++)
		{
			std::cout << _map[i][j];
			if(j == _width - 1)
				std::cout << std::endl;
			else
				std::cout << "\t";
		}
	}
}

// prints map for debugging in html
void	Map::printMapHTML()
{
	// same as above but with some html elements
	std::cout << "----------------start Map.to_stringHTML-----------------<br>" << std::endl;
	std::cout << _width << "\t" << _height << "<br>" << std::endl;
	for(size_t i = 0; i < _height; i++)
	{
		for(size_t j = 0; j < _width; j++)
		{
			std::cout << _map[i][j];
			if(j == _width - 1)
				std::cout << "<br>" << std::endl;
			else
				std::cout << "\t";
		}
	}
	std::cout << "----------------end Map.to_stringHTML-----------------<br>" << std::endl;
}
// get item umebr at coord (x, y)
size_t	Map::at_coord(size_t x, size_t y) const
{

	return _map[y][x];
}
// access item number --> coord map
// using item numebr key
Coords&	Map::operator[](size_t key)
{
	return _also_a_map_lol[key];
}

// returns a coordinate as a string
std::string		coord_to_string(Coords coord)
{
	std::string str = "";
	if(coord == Coords())
		str = "empty coord";
	else
	{
		str += "(";
		str += std::to_string(coord.first);
		str += ", ";
		str += std::to_string(coord.second);
		str += ")";
	}
	return str;
}

// draws the map for html
void	Map::draw_map()
{
	for(size_t i = 0; i < _height; i++)
	{
		for(size_t j = 0; j < _width; j++)
		{
			// some javascript to draw a 
			// square of size scale x scale and color from color map
			std::cout << "ctx.fillStyle = \"" << color(_map[i][j]) << "\";" << std::endl
			<<	"ctx.fillRect(" 
			<< j * _scale << ", " << i * _scale << ", " << _scale << ", " << _scale << ");"
			<< std::endl;
		}
	}
}
