#include "Cart.hpp"
#include <fstream>
#include <string>
#include <cstdlib>

void	Cart::readList(std::string	filename)
{
	std::ifstream	in(filename);
	if(!in.is_open())
	{
		std::cerr << "Could not open file to read grocery list." << std::endl;
		exit(-1);
	}
	std::string		line;
	while (!in.eof())
	{
		std::getline(in, line);
		_list.push_back(line);
	}
	in.close();
}

std::string&	Cart::operator[](int i)
{
	return _list[i];
}

void			Cart::to_string() const
{
	for(auto item : _list)
		std::cout << item << std::endl;
}