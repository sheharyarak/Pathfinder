#include <iostream>
#include "UI.hpp"
#include "Inventory.hpp"

int		main()
{

	UI ui("Inventory");
	Inventory	inv;
	inv.readInventory(ui.param("inventory"));
	std::cout	<<	"<body>" << std::endl
				<<	"	<form action=\"/Map.cgi\">" << std::endl
				<<	"		<input type=\"hidden\" name=\"InvFile\" value=\"" << ui.param("inventory") << "\"" << std::endl;
	inv.print_html_list();
	std::cout	<<	"		<button type=\"submit\">add to cart</submit>" << std::endl
				<<	"	</form>" << std::endl
				<<	"</body>" << std::endl
				<<	"</html>" << std::endl;
}