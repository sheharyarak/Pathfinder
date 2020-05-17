#include "Inventory.hpp"
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include "Strings.hpp"

// accessor
size_t&	Inventory::operator[](std::string key)
{
	return inventory[key];
}

// reads inventory from text file
void			Inventory::readInventory(std::string filename)
{
	// creates string stream object
	std::stringstream	ss;
	// crates input filestream
	std::ifstream	in(filename);
	// create line and item name object
	std::string		line, item_name;
	// create item num object
	size_t	item_num;
	// check if file is open
	if(!in.is_open())
	{
		std::cerr << "Could not open file [" << filename <<"] to read inventory." << std::endl;
		exit(-3);
	}
	// while end of file is not reached
	while(!in.eof())
	{
		// reset item name to empty string
		item_name = "";
		// read line
		std::getline(in, line);
		//// std::cout << "read line: " << line << std::endl;
		// convert line to string stream
		ss.str(line);
		// move buffer to start of stream
		ss.seekg(0, ss.beg);
		// read item number
		ss >> item_num;
		// start reading item name
		while(ss >> line)
		{
			//// std::cout << "read word: " << line << std::endl;
			// if the first char of the word is a # the leave the loop
			// allows for commenting inventory file as shon in text file
			if(line[0] == '#')
				break;
			// concatonate line to itme name
			// allowing spaces between words in item names
			item_name += line + " ";
		}
		//// std::cout << "read item: " << item_name << std::endl;
		// remove spaces from start and end of item name
		trim(item_name);
		//// std::cout  << item_num << " - " << item_name << " is " << item_name.length() << " characters long." << std::endl;
		// update max length of item name
		if(max_item_length < item_name.length())
			max_item_length = item_name.length();
		// add item to inventory
		inventory[item_name] = item_num;
		// clear error state of string stream 
		ss.clear();
	}
	// close file
	in.close();
}

// prints inventory; for debugging
void	Inventory::to_string()
{
	// loop through map; print key and value; endl
	for(auto iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		std::cout << std::setw(max_item_length+3) << iter->first << "\t";
		std::cout << iter->second << std::endl;
	}
}

// same as above but formatted for html;
void	Inventory::to_stringHTML()
{
	std::cout << "----------------start Inventory.to_stringHTML-----------------<br>" << std::endl;
	for(auto iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		std::cout << std::setw(max_item_length+3) << iter->first << "\t";
		std::cout << iter->second << "<br>" << std::endl;
	}
	std::cout << "----------------end Inventory.to_stringHTML-----------------<br>" << std::endl;
}

// returns pointer to inventory; deprecated
std::map<std::string, size_t>*	Inventory::inventory_ptr()
{
	std::map<std::string, size_t>* ptr = &inventory;
	return ptr;
}

// returns reference to inventory
std::map<std::string, size_t>& Inventory::get_inventory()
{
	return inventory;
}