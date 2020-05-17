#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>

/*
 * Cart
 * This object stores the list of item that you want to buy
 */

class Cart
{
private:
	//	list of items
	std::vector<std::string>	_list;
public:
	//	reads list form text file;  Planned to read input from txt file
	// ended up just using QUERY_STRING and add to cart functions
	void						readList(std::string	filename);
	//	adds item to list
	void						add_to_cart(std::string item);
	//	removes item from lise
	void						remove_item(std::string item);
	//	accesses list
	std::string&				operator[](int i);
	//	returns list
	std::vector<std::string>	list() const;
	//	prints list
	void						to_string() const;
	//	prints list as html
	void						to_stringHTML() const;
};

#endif
