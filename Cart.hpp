#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>

class Cart
{
private:
	std::vector<std::string>	_list;
public:
	void						readList(std::string	filename);
	void						add_to_cart(std::string item);
	void						remove_item(std::string item);
	std::string&				operator[](int i);
	std::vector<std::string>	list() const;
	void						to_string() const;
	void						to_stringHTML() const;
};

#endif
