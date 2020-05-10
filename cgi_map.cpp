#include <iostream>
#include <fstream>
#include "UI.hpp"

int		main()
{

	UI ui("Map");
	std::ofstream cart("cart.txt");
	for(auto iter = ui.queries().begin(); iter != ui.queries().end(); iter++)
	{
		if(iter != ui.queries().begin())
			cart << iter->second << std::endl;
	}
	std::string inv = ui.param("inventory");
	
	std::cout	<<	"<body>" << std::endl
				<<	"	<form action=\"/Pathfinder.cgi\">" << std::endl
				<<	"		<input type=\"hidden\" name=\"Inv\" value=\"" << ui.param("inventory") << "\">" << std::endl
				<<	"		<input type=\"hidden\" name=\"Cart\" value=\"" << ui.param("cart") << "\">"  << std::endl
				<<	"		<input type=\"radio\" name=\"Map\" value=\"" << "Map.tsv" << "\" id=\"" << "Map.tsv" << "\"" << ">" << std::endl;
	std::cout	<<	"		<button type=\"submit\">add to cart</submit>" << std::endl
				<<	"	</form>" << std::endl
				<<	"</body>" << std::endl
				<<	"</html>" << std::endl;
}