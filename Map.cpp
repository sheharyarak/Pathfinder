#include "Map.hpp"
#include <fstream>
#include <iomanip>
#include <string> 

void	Map::generateArray()
{
	_map = new size_t*[_height];
	for(size_t	i = 0; i < _height; i++)
	{
		_map[i] = new size_t[_width];
	}
}

void	Map::generateColorMap()
{
	colors[0] = "#FFFBD7";
	colors[1] = "#808080";
	colors[2] = "#58F658";
	colors[3] = "#FF0000";
	colors[4] = "#12B1FF";
	colors[5] = "#000000";
}

std::string	Map::color(size_t c)
{
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

size_t		Map::height() const
{
	return _height;
}
size_t		Map::width() const
{
	return	_width;
}
void	Map::readMap(std::string filename)
{	
	std::ifstream	in;
	size_t data;
	Coords coord;
	in.open(filename);
	if(!in.is_open())
	{
		// std::cout << "Could not open file to read map." << std::endl;
		exit(-2);
	}
	in >> _width >> _height;
	// std::cout << "generating array." << std::endl;
	generateArray();
	// std::cout << "finished generating array." << std::endl;
	for(size_t i = 0; i < _height; i++)
	{
		for(size_t j = 0; j < _width; j++)
		{
			if(in.eof())
			{
				std::cout << "file ended before array was completed." <<std::endl;
				return;
			}
			else
			{
				in >> data;
				// std::cout << "read value: " << data << std::endl;
				_map[i][j] = data;
				coord = Coords(j,i);
				// std::cout << "mapping value " << data << " to " << coord_to_string(coord) << std::endl;
				_also_a_map_lol.emplace(data, coord);
				// std::cout << "mapped value" << data << " to " << coord_to_string(coord) << std::endl;
			}
		}
	}
	in.close();
	// std::cout << "finished reading map" << std::endl;
}
void	Map::printMap()
{
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
void	Map::printMapHTML()
{
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
size_t	Map::at_coord(size_t x, size_t y) const
{

	return _map[y][x];
}
Coords&	Map::operator[](size_t key)
{
	return _also_a_map_lol[key];
}

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

size_t	Map::scale() const
{
	// std::cout <<  "returning _scale: " << _scale << std::endl;
	return _scale;
}
void	Map::scale(size_t sc)
{
	//~ std::cout <<  "setting _scale: " << _scale << std::endl;
	_scale = sc;
	//~ std::cout <<  "setting _scale: " << _scale << std::endl;
}

void	Map::draw_map()
{
	for(size_t i = 0; i < _height; i++)
	{
		for(size_t j = 0; j < _width; j++)
		{
			std::cout << "ctx.fillStyle = \"" << color(_map[i][j]) << "\";" << std::endl
			<<	"ctx.fillRect(" 
			<< j * _scale << ", " << i * _scale << ", " << _scale << ", " << _scale << ");"
			<< std::endl;
		}
	}
}
