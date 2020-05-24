#include <iostream>
#include <fstream>
#include "UI.hpp"

// map webpage
int		main()
{
	// create UI object
	UI ui("Map");
	//// std::cerr << "here" << std::endl;
	// ! initially the plan was to read a text file
	// ! but we decided to just use the query string
	//std::ofstream cart("cart.txt");
	//if(!cart.is_open())
	//	std::cout << "unable to open file." << std::endl;
	//else
		//std::cout << "file cart.txt opened." << std::endl;
	
	//// std::string inv = ui.param("Inventory");
	//// std::cout << "here" << std::endl;
	// 
	std::cout	<<	"<body>" << std::endl;
	// set body to random color
	ui.color_body();
	//// std::cout	<<	"<p>" << ui.get_query_string() << "</p>";
	std::cout	<<	"	<form action=\"http://pathfinder.johnwack.com/cgi-bin/Pathfinder/Pathfinder.cgi\">" << std::endl;
	std::cout	<<	"		<input type=\"hidden\" name=\"Inventory\" value=\"" << ui.param("Inventory") << "\">" << std::endl;
	//// std::cout	<<	"		<input type=\"hidden\" name=\"Cart\" value=\"" << "cart.txt" << "\">"  << std::endl;
	std::cout	<<	"		<label><input type=\"radio\" name=\"Map\" value=\"" << "Map.tsv" << "\" id=\"" << "Map.tsv" << "\"" << ">Map.tsv</label>" << std::endl;
	// add queries as hidden input so they get passed on to the next page
	// replacement for reading the cart text file
	for(size_t i = 0; i < ui.queries().size(); i++)
	{
		////~ std::cerr << "here" << std::endl;
		if(ui.queries().at(i) == "item")
		{
			std::cout << "<input type=\"hidden\" name=\"item\" value=\"" << ui.params().at(i) << "\">"  << std::endl;
		}		
		//// std::cout << ui.queries().at(i) << " --> " << ui.params().at(i) << std::endl;
	}
	// find shortest route button
	std::cout	<<	"<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-sm-5\"></div>\n    <div class=\"col-sm-2\"><button type=\"submit\" class=\"button\">Find shortest route</button></div>\n    <div class=\"col-sm-5\"></div>\n  </div>\n</div>" << std::endl;
	std::cout	<<	"	</form>" << std::endl;
	std::cout	<<	"</body>" << std::endl;
}
