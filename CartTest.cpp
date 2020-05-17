#include "Cart.hpp"

// tester file for cart object
int main(void)
{
	Cart c;
	c.readList("list.txt");
	c.to_string();
}