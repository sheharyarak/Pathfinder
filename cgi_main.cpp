#include <iostream>
#include <fstream>
#include "UI.hpp"
#include "Pathfinder.hpp"

int		main()
{

	UI ui("Pathfinder");
	std::string inv = ui.param("Inv");
	std::string cart = ui.param("Cart");
	std::string map = ui.param("Map");

	Pathfinder p;
	p.readMap(map);
	p.readInventory(inv);
	p.readCart(cart);
	p.generate();

	std::cout	<<	"<script>" << std::endl
	<<	"window.onload = draw;" << std::endl
	<<	"function draw(){" << std::endl
	<<	"var canvas = document.getElementById(\"canvas1\");" << std::endl
	<<	"var ctx = canvas.getContext(\"2d\");" << std::endl;
	p.map().draw_map();
	p.mark_items();
	p.draw_path();
	std::cout << "}" << std::endl
	<<	"</script>" << std::endl;
	std::cout	<<	"<body>" << std::endl;
	std::cout	<<	"<canvas id=\"canvas1\" width=\"" << p.map().width() * p.map().scale() 
	<< "\" heigth=\"" << p.map().height() * p.map().scale() <<"\"></canvas>" << std::endl;
	std::cout 	<<	"</body>" << std::endl
				<<	"</html>" << std::endl;
}