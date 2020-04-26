#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>

class Inventory
{
private:
	std::map<std::string, unsigned int> inventory;
public:
	Inventory(){}
	unsigned int&	operator[](const std::string key);
	void			readInventory(std::string filename);
	void			to_string();
};



#endif