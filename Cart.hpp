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
	std::string&				operator[](int i);
	std::vector<std::string>&	list() const;
	void						to_string() const;
};

#endif