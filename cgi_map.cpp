#include <iostream>
#include <fstream>
#include "UI.hpp"

int		main()
{

	UI ui("Map");
	// std::cerr << "here" << std::endl;
	std::ofstream cart("cart.txt");
	if(!cart.is_open())
		std::cout << "unable to open file." << std::endl;
	else
		std::cout << "file cart.txt opened." << std::endl;
	
	// std::string inv = ui.param("Inventory");
	// std::cout << "here" << std::endl;
	std::cout	<<	"<body>" << std::endl;
	ui.color_body();
	// std::cout	<<	"<p>" << ui.get_query_string() << "</p>";
	std::cout	<<	"	<form action=\"http://localhost:8080/cgi-bin/Pathfinder/Pathfinder.cgi\">" << std::endl;
	std::cout	<<	"		<input type=\"hidden\" name=\"Inventory\" value=\"" << ui.param("Inventory") << "\">" << std::endl;
	// std::cout	<<	"		<input type=\"hidden\" name=\"Cart\" value=\"" << "cart.txt" << "\">"  << std::endl;
	std::cout	<<	"		<label><input type=\"radio\" name=\"Map\" value=\"" << "Map.tsv" << "\" id=\"" << "Map.tsv" << "\"" << ">Map.tsv</label>" << std::endl;
	for(size_t i = 0; i < ui.queries().size(); i++)
	{
		//~ std::cerr << "here" << std::endl;
		if(ui.queries().at(i) == "item")
		{
			std::cout << "<input type=\"hidden\" name=\"item\" value=\"" << ui.params().at(i) << "\">"  << std::endl;
		}		
		// std::cout << ui.queries().at(i) << " --> " << ui.params().at(i) << std::endl;
	}
	std::cout	<<	"<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-sm-5\"></div>\n    <div class=\"col-sm-2\"><button type=\"submit\" class=\"button\">Find shortest route</button></div>\n    <div class=\"col-sm-5\"></div>\n  </div>\n</div>" << std::endl;
	std::cout	<<	"	</form>" << std::endl;
	std::cout	<<	"</body>" << std::endl;
}
