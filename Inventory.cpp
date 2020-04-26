#include "Inventory.hpp"
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

unsigned int&	Inventory::operator[](std::string key)
{
	return inventory[key];
}
void			Inventory::readInventory(std::string filename)
{
	std::stringstream	ss;
	std::ifstream	in(filename);
	std::string		line, item_name;
	unsigned int	item_num;
	if(!in.is_open())
	{
		std::cerr << "Could not open file to read inventory." << std::endl;
		exit(-3);
	}
	while(!in.eof())
	{
		item_name = "";
		std::getline(in, line);
		std::cout << "read line: " << line << std::endl;
		ss.str(line);
		ss.seekg(0, ss.beg);
		ss >> item_num;
		
		while(!ss.eof())
		{
			ss >> line;
			std::cout << "read word: " << line << std::endl;
			if(line[0] == '#')
				break;
			item_name += line;
		}
		inventory[item_name] = item_num;
		ss.clear();
	}
	in.close();
}
void			Inventory::to_string()
{
	for(auto iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		std::cout << std::setw(10) << iter->first << "\t";
		std::cout << iter->second << std::endl;
	}
}