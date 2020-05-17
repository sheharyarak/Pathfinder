#include "Inventory.hpp"

// test file to debug inventory
int		main()
{
	Inventory inv;
	inv.readInventory("inventory.txt");
	inv.to_string();
}