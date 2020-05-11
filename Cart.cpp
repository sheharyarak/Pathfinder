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
	std::cout << "printing cart:" << std::endl;
	for(auto item : _list)
		std::cout << item << std::endl;
}
void			Cart::to_stringHTML() const
{
	std::cout << "----------------start cart.to_stringHTML-----------------<br>" << std::endl;
	for(auto item : _list)
		std::cout << item << "<br>" << std::endl;
	std::cout << "---------------- end cart.to_stringHTML-----------------<br>" << std::endl;
}

void	Cart::add_to_cart(std::string item)
{
	_list.push_back(item);
}
void	Cart::remove_item(std::string item)
{
	for(size_t i = 0; i < _list.size(); i++)
	{
		if(_list[i] == item)
		{
			_list.erase(_list.begin()+i);
			return;
		}
	}
}

std::vector<std::string>	Cart::list() const
{
	return _list;
}
