#include "UI.hpp"

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
	<< "</head>" << std::endl;
	_query_string = getenv("QUERY_STRING");
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
