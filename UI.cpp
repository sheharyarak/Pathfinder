#include "UI.hpp"
#include <exception>

UI::~UI()
{
	std::cout << "</html>" << std::endl;
}

UI::UI(std::string title)
{
	size_t ac = 0,pos = -1;
	_title = title;
	print_html_header();
	do{
		pos = _query_string.find("=", pos+1);
		if(pos != std::string::npos)
			ac++;
		// std::cout <<"pos: " << pos << " ac: " << ac << std::endl;
	}
	while (pos != std::string::npos);
	_argc = ac;
	parse();
}
void		UI::print_html_header()
{
	std::cout << "Content-type: text/html\n\n" << std::endl
	<< "<html>" << std::endl
	<< "<head>" << std::endl
	<< "<title>" << _title << "</title>" << std::endl
	<< "<meta charset=\"utf-8\">\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n  <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css\">\n  <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js\"></script>\n  <script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js\"></script>"
	<< "<style>\n\tbody {\n\tbackground: #1b212c;\n\tfont-family: 'HelveticaNeue-Light', 'Helvetica Neue Light', 'Helvetica Neue', Helvetica, Arial, sans-serif;\n\tcolor: #fff;\n\tfont-size: 24px;\n\t}\n\t.ck-button {\n    margin:4px;\n    background-color:rgb(255, 0, 149);\n    border-radius:4px;\n    border:1px solid rgba(0, 0, 0, 0.678);\n    overflow:auto;\n    float:left;\n    /*padding: 5px 5px 5px 5px;*/\n\t}\n\n\t.ck-button label {\n\t\tdisplay:block;\n\t\twidth:5.0em;\n\t}\n\n\t.ck-button label span {\n\t\ttext-align:center;\n\t\tpadding:5px 5px;\n\t\tdisplay:block;\n\t}\n\n\t.ck-button label input {\n\t\tposition:absolute;\n\t\topacity:0;\n\t\t/*top:-20px;  don't use this thing use opacity:0 */\n\t}\n\n\t.ck-button input:checked + span {\n\t\tbackground-color: rgb(96, 226, 154);\n\t\tcolor:#fff;\n\t}\n</style>"
	<< "</head>" << std::endl;
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
	//~ _query_string = "Inventory=Inventory.txt&Cart=cart.txt&Map=Map.tsv";
	for(size_t i = 0; i < _query_string.length(); i++)
		if(_query_string[i]=='+')
			_query_string[i] = ' ';
}
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
void		UI::parse()
{
	std::string query, param;
	size_t		start = 0, curr;

	// std::cout << "parsing qs: " << _query_string << std::endl;
	for (size_t i = 0; i < _argc; i++)
	{
		// std::cout << "at arg: " << i << std::endl;
		curr = _query_string.find("=", start);
		if(curr == std::string::npos)
		{
			break;
		}
		query = _query_string.substr(start, curr - start);
		// std::cout << "query: " << query << std::endl;
		start = curr + 1;
		curr = _query_string.find("&", start);
		param = _query_string.substr(start, curr-start);
		// std::cout << "param: " << param << std::endl;
		_queries.push_back(query);
		_params.push_back(param);
		start = curr + 1;
	}
	//~ for(size_t i = 0; i < _queries.size(); i++)
		//~ std::cout << _queries[i] << " --> " << _params[i] << std::endl;
}
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

std::vector<std::string>	UI::queries() const
{
	return _queries;
}

std::vector<std::string>	UI::params() const
{
	return _params;
}
