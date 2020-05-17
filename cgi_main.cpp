#include <iostream>
#include <fstream>
#include "UI.hpp"
#include "Pathfinder.hpp"

int		main()
{
	// create a web page
	UI ui("Pathfinder");
	std::string inv = ui.param("Inventory");
	std::string map = ui.param("Map");
	// create Pathfinder object
	Pathfinder p;
	// read map and inventory
	p.readMap(map);
	p.readInventory(inv);
	// add items to cart
	for(size_t i = 0; i < ui.queries().size(); i++)
	{
		////~ std::cerr << "here" << std::endl;
		if(ui.queries().at(i) == "item")
		{
			p.add_to_cart(ui.params().at(i));
		}		
		////~ std::cout << ui.queries().at(i) << " --> " << ui.params().at(i) << "<br>" <<std::endl;
	}
	////~ p.map().printMapHTML();
	////~ p.inventory().to_stringHTML();
	////~ p.cart().to_stringHTML();
	// generate shortest route
	p.generate();
	// set map scale to 100 pixels
	p.map().scale(100);
	// javascript
	std::cout	<<	"<script>" << std::endl
	<<	"window.onload = draw;" << std::endl
	<<	"function draw(){" << std::endl
	<<	"var canvas = document.getElementById(\"canvas1\");" << std::endl
	<<	"console.log(canvas.width); console.log(canvas.height);" << std::endl 
	<<	"var ctx = canvas.getContext(\"2d\");" << std::endl;
	// draw map
	p.map().draw_map();
	//mark items
	p.mark_items();
	// draw path
	p.width(p.map().scale()/10);
	// set path width
	p.draw_path();
	std::cout << "}" << std::endl
	<<	"</script>" << std::endl;
	// html
	std::cout	<<	"<body>" << std::endl;
	ui.color_body();
	////~ std::cout	<<	"<p>Scale: " << p.map().scale() << " Path: " << path_to_string(p.path()) << "</p><br><br>" << std::endl;
	std::cout	<<	"<canvas id=\"canvas1\" width=\"" << p.map().width() * p.map().scale() 
	<< "\" height=\"" << p.map().height() * p.map().scale() <<"\"></canvas>" << std::endl;
	std::cout 	<<	"</body>" << std::endl;
}
