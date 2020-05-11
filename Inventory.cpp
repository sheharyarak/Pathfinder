#include "Inventory.hpp"
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Strings.hpp"

size_t&	Inventory::operator[](std::string key)
{
	return inventory[key];
}
void			Inventory::readInventory(std::string filename)
{
	std::stringstream	ss;
	std::ifstream	in(filename);
	std::string		line, item_name;
	size_t	item_num;
	if(!in.is_open())
	{
		std::cerr << "Could not open file [" << filename <<"] to read inventory." << std::endl;
		exit(-3);
	}
	while(!in.eof())
	{
		item_name = "";
		std::getline(in, line);
		// std::cout << "read line: " << line << std::endl;
		ss.str(line);
		ss.seekg(0, ss.beg);
		ss >> item_num;
		
		while(ss >> line)
		{
			// std::cout << "read word: " << line << std::endl;
			if(line[0] == '#')
				break;
			item_name += line + " ";
		}
		// std::cout << "read item: " << item_name << std::endl;
		trim(item_name);
		// std::cout  << item_num << " - " << item_name << " is " << item_name.length() << " characters long." << std::endl;
		if(max_item_length < item_name.length())
			max_item_length = item_name.length();
		inventory[item_name] = item_num;
		ss.clear();
	}
	in.close();
}
void	Inventory::to_string()
{
	for(auto iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		std::cout << std::setw(max_item_length+3) << iter->first << "\t";
		std::cout << iter->second << std::endl;
	}
}

void	Inventory::print_html_list()
{
	for(auto iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		if(iter->second > 4)
		std::cout << "<input type=\"checkbox\" id=\"" << iter->second << "\" name=\"" << iter->second << "\" value=\"" << iter->first << "\">" << std::endl
  		<< "<label for=\"" << iter->second << "\">"<< iter->first <<"</label><br>" << std::endl;
		//   std::cout<<"<input type=\"checkbox\"><p>item</p><br>"<<std::endl;
	}

}