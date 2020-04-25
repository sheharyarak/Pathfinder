#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>

class Inventory
{
private:
	std::map<int, std::string> inventory;
public:
	Inventory(){}
	std::string&	operator[](int i);
	void			readInventory(std::string filename);
	void			to_string();
};



#endif