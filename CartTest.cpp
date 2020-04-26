#include "Cart.hpp"

int main(void)
{
	Cart c;
	c.readList("list.txt");
	c.to_string();
}