#include <iostream>
#include <fstream>
#include "UI.hpp"

int		main()
{

	UI ui("Map");
	// std::cerr << "here" << std::endl;
	std::ofstream cart("cart.txt");
	// std::cerr << "here" << std::endl;
	for(auto iter = ui.queries().begin(); iter != ui.queries().end(); iter++)
	{
		// std::cerr << "here" << std::endl;
		if(iter->first != "Inventory")
			cart << iter->second << std::endl;
		// std::cout << iter->first << " --> " << iter->second << std::endl;
	}
	// std::string inv = ui.param("Inventory");
	std::cout << "here" << std::endl;
	std::cout	<<	"<body>" << std::endl;
	std::cout	<<	"<p>" << ui.get_query_string() << "</p>";
	std::cout	<<	"	<form action=\"http://localhost/cgi-bin/Pathfinder/Pathfinder.cgi\">" << std::endl;
	std::cout	<<	"		<input type=\"hidden\" name=\"Inventory\" value=\"" << ui.param("Inventory") << "\">" << std::endl;
	std::cout	<<	"		<input type=\"hidden\" name=\"Cart\" value=\"" << "cart.txt" << "\">"  << std::endl;
	std::cout	<<	"		<input type=\"radio\" name=\"Map\" value=\"" << "Map.tsv" << "\" id=\"" << "Map.tsv" << "\"" << ">" << std::endl;
	std::cout	<<	"		<button type=\"submit\">Find Shortest Route</submit>" << std::endl;
	std::cout	<<	"	</form>" << std::endl;
	std::cout	<<	"</body>" << std::endl;
}