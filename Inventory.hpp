#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>

// contains key map to inventory of store
// contains map of item name to item number
class Inventory
{
private:
	// length of string for printing
	size_t	max_item_length = 0;
	// map of item name to number
	std::map<std::string, size_t> inventory;
public:
	// constructor
	Inventory(){}
	// returns item number based on name
	size_t&	operator[](const std::string key);
	// reads key value pairs from text file
	void			readInventory(std::string filename);
	// prints map; used for debugging
	void			to_string();
	// prints map in html; used for debugging
	void			to_stringHTML();
	// returns ptr to inventory object; deprecated; replaced by reference
	std::map<std::string, size_t>* inventory_ptr();
	// returns reference to inventory
	std::map<std::string, size_t>& get_inventory();
};

#endif
