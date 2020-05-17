#include "Cart.hpp"
#include <fstream>
#include <string>
#include <cstdlib>

// Reads and parses the text file
void	Cart::readList(std::string	filename)
{
	// create input stream object
	std::ifstream	in(filename);
	// check if the file was opened
	if(!in.is_open())
	{
		std::cerr << "Could not open file to read grocery list." << std::endl;
		// exit the program 
		exit(-1);
	}
	// create string to read in each line
	std::string		line;
	while (!in.eof())
	{
		std::getline(in, line);
		// add line to list
		_list.push_back(line);
	}
	in.close();
}

// returns element at index i of list
std::string&	Cart::operator[](int i)
{
	return _list[i];
}

// prints list; used for debugging
void			Cart::to_string() const
{
	std::cout << "printing cart:" << std::endl;
	for(auto item : _list)
		std::cout << item << std::endl;
}
// prints list; used for debugging
void			Cart::to_stringHTML() const
{
	std::cout << "----------------start cart.to_stringHTML-----------------<br>" << std::endl;
	for(auto item : _list)
		std::cout << item << "<br>" << std::endl;
	std::cout << "---------------- end cart.to_stringHTML-----------------<br>" << std::endl;
}

// adds item to list
void	Cart::add_to_cart(std::string item)
{
	_list.push_back(item);
}

// removes item from list
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

// returns list
std::vector<std::string>	Cart::list() const
{
	return _list;
}
