#include <iostream>
#include "UI.hpp"
#include "Inventory.hpp"

// driver function for Inventory page
int		main()
{
	// create UI object
	UI ui("Inventory");
	Inventory	inv;
	// read inventory
	inv.readInventory(ui.param("Inventory"));
	std::cout	<<	"<body>" << std::endl;
	// color body
	ui.color_body();
	std::cout	<<	"<form action=\"http://pathfinder.johnwack.com/cgi-bin/Pathfinder/Map.cgi\">" << std::endl
				<<	"<input type=\"hidden\" name=\"Inventory\" value=\"" << ui.param("Inventory") << "\">" << std::endl;
	// checkbox list
	ui.print_check_box_from_list(inv.get_inventory());
	// create add to cart button
	std::cout	<<	"<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-sm-5\"></div>\n    <div class=\"col-sm-2\"><button type=\"submit\" class=\"button\">Add to Cart</button></div>\n    <div class=\"col-sm-5\"></div>\n  </div>\n</div>" << std::endl
				<<	"</form>" << std::endl
				<<	"</body>" << std::endl;
}
