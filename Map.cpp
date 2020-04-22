#include "Map.hpp"
#include <fstream>
#include <iomanip>

void	Map::generateArray()
{
	_map = new unsigned int*[_height];
	for(int	i = 0; i < _height; i++)
	{
		_map[i] = new unsigned int[_width];
	}
}

Map::~Map()
{
	for(int i = 0; i < _height; i++)
	{
		delete [] _map[i];
	}
	delete [] _map;
	delete this;
}

int		Map::height() const
{
	return _height;
}
int		Map::width() const
{
	return	_width;
}
void	Map::readMap(std::string filename)
{
	std::ifstream	in;
	unsigned int data;
	in.open(filename);
	if(!in.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}
	in >> _width >> _height;
	generateArray();
	for(int i = 0; i < _height; i++)
	{
		for(int j = 0; j < _width; j++)
		{
			if(in.eof())
			{
				std::cerr << "file ended before array was completed." <<std::endl;
				return;
			}
			else
			{
				in >> data;
				// std::cout << "read value: " << data << std::endl;
				_map[i][j] = data;
			}
		}
	}
}
void	Map::printMap()
{
	std::cout << _width << "\t" << _height << std::endl;
	for(int i = 0; i < _height; i++)
	{
		for(int j = 0; j < _width; j++)
		{
			std::cout << _map[i][j];
			if(j == _width - 1)
				std::cout << std::endl;
			else
				std::cout << "\t";
		}
	}
}