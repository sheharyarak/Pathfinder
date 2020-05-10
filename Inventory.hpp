#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>

class Inventory
{
private:
	size_t	max_item_length = 0;
	std::map<std::string, size_t> inventory;
public:
	Inventory(){}
	size_t&	operator[](const std::string key);
	void			print_html_list();
	void			readInventory(std::string filename);
	void			to_string();
};

#endif