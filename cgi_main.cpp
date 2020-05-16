#include <iostream>
#include <fstream>
#include "UI.hpp"
#include "Pathfinder.hpp"

int		main()
{

	UI ui("Pathfinder");
	std::string inv = ui.param("Inventory");
	std::string map = ui.param("Map");
	Pathfinder p;
	p.readMap(map);
	p.readInventory(inv);
	for(size_t i = 0; i < ui.queries().size(); i++)
	{
		//~ std::cerr << "here" << std::endl;
		if(ui.queries().at(i) == "item")
		{
			p.add_to_cart(ui.params().at(i));
		}		
		//~ std::cout << ui.queries().at(i) << " --> " << ui.params().at(i) << "<br>" <<std::endl;
	}
	//~ p.map().printMapHTML();
	//~ p.inventory().to_stringHTML();
	//~ p.cart().to_stringHTML();

	p.generate();
	p.map().scale(100);

	std::cout	<<	"<script>" << std::endl
	<<	"window.onload = draw;" << std::endl
	<<	"function draw(){" << std::endl
	<<	"var canvas = document.getElementById(\"canvas1\");" << std::endl
	<<	"console.log(canvas.width); console.log(canvas.height);" << std::endl 
	<<	"var ctx = canvas.getContext(\"2d\");" << std::endl;
	p.map().draw_map();
	p.mark_items();
	p.draw_path();
	p.map().scale(50);
	p.width(p.map().scale()/10);
	std::cout << "}" << std::endl
	<<	"</script>" << std::endl;
	std::cout	<<	"<body>" << std::endl;
	ui.color_body();
	//~ std::cout	<<	"<p>Scale: " << p.map().scale() << " Path: " << path_to_string(p.path()) << "</p><br><br>" << std::endl;
	std::cout	<<	"<canvas id=\"canvas1\" width=\"" << p.map().width() * p.map().scale() 
	<< "\" height=\"" << p.map().height() * p.map().scale() <<"\"></canvas>" << std::endl;
	std::cout 	<<	"</body>" << std::endl;
}
