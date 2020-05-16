#include <iostream>
#include "UI.hpp"
#include "Inventory.hpp"

int		main()
{

	UI ui("Inventory");
	Inventory	inv;
	inv.readInventory(ui.param("Inventory"));
	std::cout	<<	"<body>" << std::endl;
	ui.color_body();
	std::cout	<<	"<form action=\"http://localhost:8080/cgi-bin/Pathfinder/Map.cgi\">" << std::endl
				<<	"<input type=\"hidden\" name=\"Inventory\" value=\"" << ui.param("Inventory") << "\">" << std::endl;
	ui.print_check_box_from_list(inv.get_inventory());
	std::cout	<<	"<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-sm-5\"></div>\n    <div class=\"col-sm-2\"><button type=\"submit\" class=\"button\">Add to Cart</button></div>\n    <div class=\"col-sm-5\"></div>\n  </div>\n</div>" << std::endl
				<<	"</form>" << std::endl
				<<	"</body>" << std::endl;
}
