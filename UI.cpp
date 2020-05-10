#include "UI.hpp"

UI::UI(std::string title)
{
	_title = title;
}
void		UI::print_html_header()
{
	std::cout << "Content-type:/html\n\n" << std::endl
	<< "<html>" << std::endl
	<< "<head>" << std::endl
	<< "<title>" << _title << "</title>" << std::endl
	<< "</head>" << std::endl;
	_query_string = getenv("QUERY_STRING");
	parse();
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
	size_t		start, curr;
	for (size_t i = 0; i < _query_string.length(); i++)
	{
		curr = _query_string.find("=", start);
		query = _query_string.substr(start, curr - start);
		start = curr + 1;
		curr = _query_string.find("&", start);
		if(curr == std::string::npos)
			break;
		param = _query_string.substr(start, curr - start);
		start = curr + 1;
		_queries[query] = param;
	}
	
}
std::string	UI::param(std::string query)
{
	return _queries[query];
}

std::map<std::string, std::string>	UI::queries() const
{
	return _queries;
}