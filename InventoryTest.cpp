#include "Inventory.hpp"

int		main()
{
	Inventory inv;
	inv.readInventory("inventory.txt");
	inv.to_string();
}