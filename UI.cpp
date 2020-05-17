#include "UI.hpp"
#include <exception>

// destructor closes html tag
UI::~UI()
{
	std::cout << "</html>" << std::endl;
}

// constructor
UI::UI(std::string title)
{
	// initializes argc and pos
	size_t ac = 0,pos = -1;
	_title = title;
	// prints the header for html
	print_html_header();
	// count number of arguments
	do{
		pos = _query_string.find("=", pos+1);
		if(pos != std::string::npos)
			ac++;
		//// std::cout <<"pos: " << pos << " ac: " << ac << std::endl;
	}
	while (pos != std::string::npos);
	_argc = ac;
	// parse query string 
	parse();
}

// color body to random color
void		UI::color_body()
{
	// javascript
	std::cout << "<script>\n";
	std::cout << "   function random_bg_color() {\n      var x = Math.floor(Math.random() * 256);\n      var y = Math.floor(Math.random() * 256);\n      var z = Math.floor(Math.random() * 256);\n      var bgColor = \"rgb(\" + x + \",\" + y + \",\" + z + \")\";\n      console.log(bgColor);\n      document.body.style.background = bgColor;\n    }\n    document.onload = random_bg_color();\n\tdocument.body.addEventListener('click', function(e){\n    \trandom_bg_color();\n\t});\n";
	// std::cout << "$(\":checkbox\").on(\"change\", function() {\n    var that = this;\n    $(this).parent().css(\"background-color\", function() {\n        return that.checked ? \"#ff0000\" : \"\";\n    });\n});\n​";
	std::cout << "\n</script>";

}

// print header for html
void		UI::print_html_header()
{
	// little bit of html
	// a whole lot of css
	std::cout << "Content-type: text/html\n\n" << std::endl
	<< "<html>" << std::endl
	<< "<head>" << std::endl
	<< "<title>" << _title << "</title>" << std::endl
	// <<	"<meta charset=\"utf-8\">\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n  <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css\">\n  <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js\"></script>\n  <script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js\"></script><link rel = \"icon\" href = \"icon.png\" type=\"image/png\" sizes=\"16x16\">\n  <title>Pathfinder</title>\n<style class=\"cp-pen-styles\">\n.logo {\n  width: 8em;\n  position: absolute;\n  left: 1em;\n  top: 1em;\n}\n\nspan {\n  display: block;\n  position: absolute;\n  top: calc(50% - 10em);\n  left: calc(50% - 10em);\n  width: 20em;\n  height: 20em;\n}\n\nspan.spin {\n  -webkit-animation: spin 10s linear infinite;\n          animation: spin 10s linear infinite;\n}\n\nspan.spin-reverse {\n  -webkit-animation: spin 30s linear infinite;\n          animation: spin 30s linear infinite;\n}\n\nspan.pulse {\n  -webkit-animation: spin-pulse 20s linear infinite;\n          animation: spin-pulse 20s linear infinite;\n}\n\n@-webkit-keyframes spin {\n  0% {\n    -webkit-transform: rotateZ(0);\n            transform: rotateZ(0);\n  }\n  100% {\n    -webkit-transform: rotateZ(360deg);\n            transform: rotateZ(360deg);\n  }\n}\n\n@keyframes spin {\n  0% {\n    -webkit-transform: rotateZ(0);\n            transform: rotateZ(0);\n  }\n  100% {\n    -webkit-transform: rotateZ(360deg);\n            transform: rotateZ(360deg);\n  }\n}\n@-webkit-keyframes spin-pulse {\n  0% {\n    -webkit-transform: scale(1) rotateZ(0);\n            transform: scale(1) rotateZ(0);\n  }\n  50% {\n    -webkit-transform: scale(0.9) rotateZ(180deg);\n            transform: scale(0.9) rotateZ(180deg);\n  }\n  100% {\n    -webkit-transform: scale(1) rotateZ(360deg);\n            transform: scale(1) rotateZ(360deg);\n  }\n}\n@keyframes spin-pulse {\n  0% {\n    -webkit-transform: scale(1) rotateZ(0);\n            transform: scale(1) rotateZ(0);\n  }\n  50% {\n    -webkit-transform: scale(0.9) rotateZ(180deg);\n            transform: scale(0.9) rotateZ(180deg);\n  }\n  100% {\n    -webkit-transform: scale(1) rotateZ(360deg);\n            transform: scale(1) rotateZ(360deg);\n  }\n}\nbody {\n  background: rgb(0, 0, 0);\n  font-family: 'HelveticaNeue-Light', 'Helvetica Neue Light', 'Helvetica Neue', Helvetica, Arial, sans-serif;\n  color: #fff;\n  font-size: 24px;\n}\n.body-font {\n  font-family: 'HelveticaNeue-Light', 'Helvetica Neue Light', 'Helvetica Neue', Helvetica, Arial, sans-serif;\n  color: #fff;\n  font-size: 24px;\n}\n.circle {\n  border-radius: 50%;\n  left: calc(50% - 6.25em);\n  top: calc(50% - 12.5em);\n  -webkit-transform-origin: 50% 12.5em;\n          transform-origin: 50% 12.5em;\n}\n\n.squircle {\n  border-radius: 25%;\n}\n\n.circle, .squircle {\n  width: 12.5em;\n  height: 12.5em;\n  position: absolute;\n  border-top: 0.1em solid rgba(255, 255, 255, 0.4);\n}\n\n.large.circle {\n  box-shadow: 0 1em 2em rgba(0, 0, 0, 0.5);\n}\n\n.small {\n  width: 4em;\n  height: 4em;\n  left: calc(50% - 2em);\n  top: calc(50% - 15em);\n  -webkit-transform-origin: 50% 15em;\n          transform-origin: 50% 15em;\n  box-shadow: 0 0.25em 0.5em rgba(0, 0, 0, 0.2);\n}\n\n.one {\n  background: rgba(16, 63, 236, 0.75);\n  -webkit-transform: rotateZ(225deg);\n          transform: rotateZ(225deg);\n}\n\n.two {\n  background: rgba(37, 172, 162, 0.75);\n  -webkit-transform: rotateZ(180deg);\n          transform: rotateZ(180deg);\n}\n\n.three {\n  background: rgba(233, 124, 32, 0.75);\n  -webkit-transform: rotateZ(135deg);\n          transform: rotateZ(135deg);\n}\n\n.four {\n  background: rgba(235, 67, 35, 0.75);\n  -webkit-transform: rotateZ(90deg);\n          transform: rotateZ(90deg);\n}\n\n.five {\n  background: rgba(190, 28, 65, 0.75);\n  -webkit-transform: rotateZ(45deg);\n          transform: rotateZ(45deg);\n}\n\n.six {\n  background: rgba(208, 57, 159, 0.75);\n  -webkit-transform: rotateZ(0);\n          transform: rotateZ(0);\n}\n\n.seven {\n  background: rgba(150, 32, 198, 0.75);\n  -webkit-transform: rotateZ(-45deg);\n          transform: rotateZ(-45deg);\n}\n\n.eight {\n  background: rgba(95, 33, 203, 0.75);\n  -webkit-transform: rotateZ(-90deg);\n          transform: rotateZ(-90deg);\n}\n\n.small.squircle {\n  background: none;\n  box-shadow: none;\n}\n.small.squircle::after {\n  content: \"\";\n  border-radius: 25%;\n  width: 100%;\n  height: 100%;\n  position: absolute;\n  background: red;\n  -webkit-transform: rotateZ(-45deg);\n          transform: rotateZ(-45deg);\n  box-shadow: -0.25em 0.25em 0.5em rgba(0, 0, 0, 0.2);\n}\n.small.squircle.two::after {\n  background: rgba(37, 172, 162, 0.75);\n}\n.small.squircle.four::after {\n  background: rgba(235, 67, 35, 0.75);\n}\n.small.squircle.six::after {\n  background: rgba(208, 57, 159, 0.75);\n}\n.small.squircle.eight::after {\n  background: rgba(95, 33, 203, 0.75);\n}\n\n.large.squircle {\n  position: absolute;\n  background: rgba(30, 7, 66, 0.65);\n  border: none;\n  left: calc(50% - 7.5em);\n  top: calc(50% - 7.5em);\n  width: 15em;\n  height: 15em;\n  -webkit-transform: none;\n          transform: none;\n}\n.large.squircle.one {\n  -webkit-transform: rotateZ(45deg);\n          transform: rotateZ(45deg);\n}\n\n.content {\n  text-align: center;\n}\n.content svg {\n  fill: #fff;\n  width: 3em;\n  margin: 1.25em auto 1em;\n}\n.content h1 {\n  font-weight: lighter;\n  font-size: 1.75em;\n  margin: 0.25em auto 1em;\n  max-width: 6em;\n}\n\n.message {\n  position: absolute;\n  left: 1em;\n  bottom: 1em;\n  right: 0;\n  color: #222;\n  text-align: left;\n}\n.message a {\n  text-decoration: none;\n  font-weight: bold;\n  color: #999;\n}\n</style>\n"
	<< "<meta charset=\"utf-8\">\n"
	<< "  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
	<< "  <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css\">\n"
	<< "  <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js\"></script>\n"
	<< "  <script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js\"></script><link rel = \"icon\" href = \"icon.png\" type=\"image/png\" sizes=\"16x16\">\n"
	<< "  <title>Pathfinder</title>\n"
	<< "<style class=\"cp-pen-styles\">\n"
	<< ".logo {\n"
	<< "  width: 8em;\n"
	<< "  position: absolute;\n"
	<< "  left: 1em;\n"
	<< "  top: 1em;\n"
	<< "}\n"
	<< "\n"
	<< "span {\n"
	<< "  display: block;\n"
	<< "  position: absolute;\n"
	<< "  top: calc(50% - 10em);\n"
	<< "  left: calc(50% - 10em);\n"
	<< "  width: 20em;\n"
	<< "  height: 20em;\n"
	<< "}\n"
	<< "\n"
	<< "span.spin {\n"
	<< "  -webkit-animation: spin 10s linear infinite;\n"
	<< "          animation: spin 10s linear infinite;\n"
	<< "}\n"
	<< "\n"
	<< "span.spin-reverse {\n"
	<< "  -webkit-animation: spin 30s linear infinite;\n"
	<< "          animation: spin 30s linear infinite;\n"
	<< "}\n"
	<< "\n"
	<< "span.pulse {\n"
	<< "  -webkit-animation: spin-pulse 20s linear infinite;\n"
	<< "          animation: spin-pulse 20s linear infinite;\n"
	<< "}\n"
	<< "\n"
	<< "@-webkit-keyframes spin {\n"
	<< "  0% {\n"
	<< "    -webkit-transform: rotateZ(0);\n"
	<< "            transform: rotateZ(0);\n"
	<< "  }\n"
	<< "  100% {\n"
	<< "    -webkit-transform: rotateZ(360deg);\n"
	<< "            transform: rotateZ(360deg);\n"
	<< "  }\n"
	<< "}\n"
	<< "\n"
	<< "@keyframes spin {\n"
	<< "  0% {\n"
	<< "    -webkit-transform: rotateZ(0);\n"
	<< "            transform: rotateZ(0);\n"
	<< "  }\n"
	<< "  100% {\n"
	<< "    -webkit-transform: rotateZ(360deg);\n"
	<< "            transform: rotateZ(360deg);\n"
	<< "  }\n"
	<< "}\n"
	<< "@-webkit-keyframes spin-pulse {\n"
	<< "  0% {\n"
	<< "    -webkit-transform: scale(1) rotateZ(0);\n"
	<< "            transform: scale(1) rotateZ(0);\n"
	<< "  }\n"
	<< "  50% {\n"
	<< "    -webkit-transform: scale(0.9) rotateZ(180deg);\n"
	<< "            transform: scale(0.9) rotateZ(180deg);\n"
	<< "  }\n"
	<< "  100% {\n"
	<< "    -webkit-transform: scale(1) rotateZ(360deg);\n"
	<< "            transform: scale(1) rotateZ(360deg);\n"
	<< "  }\n"
	<< "}\n"
	<< "@keyframes spin-pulse {\n"
	<< "  0% {\n"
	<< "    -webkit-transform: scale(1) rotateZ(0);\n"
	<< "            transform: scale(1) rotateZ(0);\n"
	<< "  }\n"
	<< "  50% {\n"
	<< "    -webkit-transform: scale(0.9) rotateZ(180deg);\n"
	<< "            transform: scale(0.9) rotateZ(180deg);\n"
	<< "  }\n"
	<< "  100% {\n"
	<< "    -webkit-transform: scale(1) rotateZ(360deg);\n"
	<< "            transform: scale(1) rotateZ(360deg);\n"
	<< "  }\n"
	<< "}\n"
	<< "body {\n"
	<< "  background: rgb(0, 0, 0);\n"
	<< "  font-family: 'HelveticaNeue-Light', 'Helvetica Neue Light', 'Helvetica Neue', Helvetica, Arial, sans-serif;\n"
	<< "  color: #fff;\n"
	<< "  font-size: 24px;\n"
	<< "}\n"
	<< ".body-font {\n"
	<< "  font-family: 'HelveticaNeue-Light', 'Helvetica Neue Light', 'Helvetica Neue', Helvetica, Arial, sans-serif;\n"
	<< "  color: #fff;\n"
	<< "  font-size: 24px;\n"
	<< "}\n"
	<< ".circle {\n"
	<< "  border-radius: 50%;\n"
	<< "  left: calc(50% - 6.25em);\n"
	<< "  top: calc(50% - 12.5em);\n"
	<< "  -webkit-transform-origin: 50% 12.5em;\n"
	<< "          transform-origin: 50% 12.5em;\n"
	<< "}\n"
	<< "\n"
	<< ".squircle {\n"
	<< "  border-radius: 25%;\n"
	<< "}\n"
	<< "\n"
	<< ".circle, .squircle {\n"
	<< "  width: 12.5em;\n"
	<< "  height: 12.5em;\n"
	<< "  position: absolute;\n"
	<< "  border-top: 0.1em solid rgba(255, 255, 255, 0.4);\n"
	<< "}\n"
	<< "\n"
	<< ".large.circle {\n"
	<< "  box-shadow: 0 1em 2em rgba(0, 0, 0, 0.5);\n"
	<< "}\n"
	<< "\n"
	<< ".small {\n"
	<< "  width: 4em;\n"
	<< "  height: 4em;\n"
	<< "  left: calc(50% - 2em);\n"
	<< "  top: calc(50% - 15em);\n"
	<< "  -webkit-transform-origin: 50% 15em;\n"
	<< "          transform-origin: 50% 15em;\n"
	<< "  box-shadow: 0 0.25em 0.5em rgba(0, 0, 0, 0.2);\n"
	<< "}\n"
	<< "\n"
	<< ".one {\n"
	<< "  background: rgba(16, 63, 236, 0.75);\n"
	<< "  -webkit-transform: rotateZ(225deg);\n"
	<< "          transform: rotateZ(225deg);\n"
	<< "}\n"
	<< "\n"
	<< ".two {\n"
	<< "  background: rgba(37, 172, 162, 0.75);\n"
	<< "  -webkit-transform: rotateZ(180deg);\n"
	<< "          transform: rotateZ(180deg);\n"
	<< "}\n"
	<< "\n"
	<< ".three {\n"
	<< "  background: rgba(233, 124, 32, 0.75);\n"
	<< "  -webkit-transform: rotateZ(135deg);\n"
	<< "          transform: rotateZ(135deg);\n"
	<< "}\n"
	<< "\n"
	<< ".four {\n"
	<< "  background: rgba(235, 67, 35, 0.75);\n"
	<< "  -webkit-transform: rotateZ(90deg);\n"
	<< "          transform: rotateZ(90deg);\n"
	<< "}\n"
	<< "\n"
	<< ".five {\n"
	<< "  background: rgba(190, 28, 65, 0.75);\n"
	<< "  -webkit-transform: rotateZ(45deg);\n"
	<< "          transform: rotateZ(45deg);\n"
	<< "}\n"
	<< "\n"
	<< ".six {\n"
	<< "  background: rgba(208, 57, 159, 0.75);\n"
	<< "  -webkit-transform: rotateZ(0);\n"
	<< "          transform: rotateZ(0);\n"
	<< "}\n"
	<< "\n"
	<< ".seven {\n"
	<< "  background: rgba(150, 32, 198, 0.75);\n"
	<< "  -webkit-transform: rotateZ(-45deg);\n"
	<< "          transform: rotateZ(-45deg);\n"
	<< "}\n"
	<< "\n"
	<< ".eight {\n"
	<< "  background: rgba(95, 33, 203, 0.75);\n"
	<< "  -webkit-transform: rotateZ(-90deg);\n"
	<< "          transform: rotateZ(-90deg);\n"
	<< "}\n"
	<< "\n"
	<< ".small.squircle {\n"
	<< "  background: none;\n"
	<< "  box-shadow: none;\n"
	<< "}\n"
	<< ".small.squircle::after {\n"
	<< "  content: \"\";\n"
	<< "  border-radius: 25%;\n"
	<< "  width: 100%;\n"
	<< "  height: 100%;\n"
	<< "  position: absolute;\n"
	<< "  background: red;\n"
	<< "  -webkit-transform: rotateZ(-45deg);\n"
	<< "          transform: rotateZ(-45deg);\n"
	<< "  box-shadow: -0.25em 0.25em 0.5em rgba(0, 0, 0, 0.2);\n"
	<< "}\n"
	<< ".small.squircle.two::after {\n"
	<< "  background: rgba(37, 172, 162, 0.75);\n"
	<< "}\n"
	<< ".small.squircle.four::after {\n"
	<< "  background: rgba(235, 67, 35, 0.75);\n"
	<< "}\n"
	<< ".small.squircle.six::after {\n"
	<< "  background: rgba(208, 57, 159, 0.75);\n"
	<< "}\n"
	<< ".small.squircle.eight::after {\n"
	<< "  background: rgba(95, 33, 203, 0.75);\n"
	<< "}\n"
	<< "\n"
	<< ".large.squircle {\n"
	<< "  position: absolute;\n"
	<< "  background: rgba(30, 7, 66, 0.65);\n"
	<< "  border: none;\n"
	<< "  left: calc(50% - 7.5em);\n"
	<< "  top: calc(50% - 7.5em);\n"
	<< "  width: 15em;\n"
	<< "  height: 15em;\n"
	<< "  -webkit-transform: none;\n"
	<< "          transform: none;\n"
	<< "}\n"
	<< ".large.squircle.one {\n"
	<< "  -webkit-transform: rotateZ(45deg);\n"
	<< "          transform: rotateZ(45deg);\n"
	<< "}\n"
	<< "\n"
	<< ".content {\n"
	<< "  text-align: center;\n"
	<< "}\n"
	<< ".content svg {\n"
	<< "  fill: #fff;\n"
	<< "  width: 3em;\n"
	<< "  margin: 1.25em auto 1em;\n"
	<< "}\n"
	<< ".content h1 {\n"
	<< "  font-weight: lighter;\n"
	<< "  font-size: 1.75em;\n"
	<< "  margin: 0.25em auto 1em;\n"
	<< "  max-width: 6em;\n"
	<< "}\n"
	<< "\n"
	<< ".message {\n"
	<< "  position: absolute;\n"
	<< "  left: 1em;\n"
	<< "  bottom: 1em;\n"
	<< "  right: 0;\n"
	<< "  color: #222;\n"
	<< "  text-align: left;\n"
	<< "}\n"
	<< ".message a {\n"
	<< "  text-decoration: none;\n"
	<< "  font-weight: bold;\n"
	<< "  color: #999;\n"
	<< "}\n"
	<< ".item{\n"
	<< "  width: max-content;\n"
	<< "  display: block;\n"
	<< "  border-radius: 16pt;\n"
	<< "  padding: 8pt;\n"
	<< "}\n"
	<< ".check {\n"
	<< "  position: absolute;  \n"
	<< "  vertical-align: middle; \n"
	<< "}\n"
	<< ".check:checked ~ .item {\n"
	<< "  background: #ffa600;\n"
	<< "}"
	<< ".button {\n"
	<< "    font-family: 'HelveticaNeue-Light', 'Helvetica Neue Light', 'Helvetica Neue', Helvetica, Arial, sans-serif;\n"
	<< "    color: #fff;\n"
	<< "    font-size: 24pt;\n"
	<< "    display: inline-block;\n"
	<< "    padding: 8pt;\n"
	<< "    border-radius: 16pt;\n"
	<< "    position: absolute;\n"
	<< "    background: #ffa600;\n"
	<< "    border: none;\n"
	<< "}"
	<< "</style>\n"
	<< ""
	
	<< "</head>" << std::endl;
	// using try and catch to allow testing an executable instead of cgi
	// very useful for html and cgi debugging
	try{
		char* env = getenv("QUERY_STRING");
		if(env == nullptr) throw std::exception();
		else _query_string = env;
	}
	catch (std::exception& e)
	{
		if(_title == "Inventory")
			_query_string = "Inventory=Inventory.txt";
		else if (_title == "Map")
			_query_string = "Inventory=Inventory.txt&item=buckel&item=checkbook&item=drill+press&item=leg+warmers&item=sand+paper&item=spring&item=towel&item=white+out";
		else
			_query_string = "Inventory=Inventory.txt&Map=Map.tsv&item=buckel&item=checkbook&item=drill+press&item=leg+warmers&item=sand+paper&item=spring&item=towel&item=white+out";
	}
	////~ _query_string = "Inventory=Inventory.txt&Cart=cart.txt&Map=Map.tsv";
	// changes the '+' in the query string to a space
	for(size_t i = 0; i < _query_string.length(); i++)
		if(_query_string[i]=='+')
			_query_string[i] = ' ';
}

// setters and getters
void		UI::set_query_string(std::string qs)
{
	_query_string = qs;
}
std::string	UI::get_query_string()	const
{
	return _query_string;
}
void		UI::set_argc(size_t	ac)
{
	_argc = ac;
}
size_t		UI::get_argc()	const
{
	return _argc;
}
std::vector<std::string>	UI::queries() const
{
	return _queries;
}

std::vector<std::string>	UI::params() const
{
	return _params;
}

// parse query string
void		UI::parse()
{
	// query and parm strings
	std::string query, param;
	// start and current positions
	size_t		start = 0, curr;
	//// std::cout << "parsing qs: " << _query_string << std::endl;
	// assume query_string = query=param
	for (size_t i = 0; i < _argc; i++)
	{
		//// std::cout << "at arg: " << i << std::endl;
		curr = _query_string.find("=", start);
		if(curr == std::string::npos)
		{
			// if no '=' found break out of the string
			break;
		}
		// query = query
		query = _query_string.substr(start, curr - start);
		//// std::cout << "query: " << query << std::endl;
		start = curr + 1;
		curr = _query_string.find("&", start);
		// param = param 
		param = _query_string.substr(start, curr-start);
		//// std::cout << "param: " << param << std::endl;
		// add query and param to vectors
		_queries.push_back(query);
		_params.push_back(param);
		start = curr + 1;
	}
	////~ for(size_t i = 0; i < _queries.size(); i++)
		////~ std::cout << _queries[i] << " --> " << _params[i] << std::endl;
}

// gets param associated with query
std::string	UI::param(std::string query)
{
	size_t i = 0;
	while( i < _queries.size())
	{
		if(_queries[i] == query) break;
		i++;
	}
	return _params[i];
}

// prints checkbox list in html format
void		UI::print_check_box_from_list(std::map<std::string, size_t>& map)
{
	int i = 0; 
	// using bootstrap container; a bunch of html
	std::cout << "\n<div class=\"container\">" <<std::endl; 
	for(auto iter = map.begin(); iter != map.end(); iter++)
	{
		if(iter->second > 4)
		{
			if(i % 4 == 0 )
			{
				if(i != 0)
					std::cout<<"</div>";
				std::cout <<"<div class = \"row\">";
			}
			std::cout << "<div class=\"col-sm-3\">\n";
			//// std::cout << "<label><div class=\"checkbox-div\"><input type=\"checkbox\" name=\"item\" value=\""<< iter->first <<"\">"<< iter->first <<"</div></label>";
			std::cout	<<	"<label for=\""<<iter->first<<"\">\n"
						<<	"    <input type=\"checkbox\" id=\""<<iter->first<<"\" name=\"item\" value=\""<<iter->first<<"\" class=\"check\" style=\"display: none;\" />\n"
						<<	"    <div class=\"item\">\n"
						<<	"       <div class=\"content\" style=\"display: inline-block\">\n"
						<<	"          "<<iter->first<<"\n"
						<<	"       </div>\n"
						<<	"    </div>\n"
						<<	"</label>";
			std::cout << "</div>" << std::endl;
			//// std::cout <<"<label><input type=\"checkbox\" name=\"item\" value=\""<< iter->first <<"\">"<< iter->first <<"</label>" <<std::endl;
		i++;
		}
	}
	std::cout << "</div></div>" << std::endl;
}