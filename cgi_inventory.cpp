#include <iostream>
#include "UI.hpp"
#include "Inventory.hpp"

int		main()
{

	UI ui("Inventory");
	Inventory	inv;
	inv.readInventory(ui.param("Inventory"));
	std::cout	<<	"<body>" << std::endl
				<<	"<form action=\"http://localhost/cgi-bin/Pathfinder/Map.cgi\">" << std::endl
				<<	"<input type=\"hidden\" name=\"Inventory\" value=\"" << ui.param("Inventory") << "\">" << std::endl;
	inv.print_html_list();
	std::cout	<<	"<button type=\"submit\">add to cart</submit>" << std::endl
				<<	"</form>" << std::endl
				<<	"</body>" << std::endl;
}