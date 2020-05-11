#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>

class UI
{
private:
	/* data */
	size_t			_argc = 0;
	std::string		_query_string, _title;
	std::vector<std::string>	_queries;
	std::vector<std::string>	_params;
	
public:
	UI(std::string title);
	~UI();
	void		set_query_string(std::string qs);
	std::string	get_query_string()	const;
	void		set_argc(size_t	ac);
	size_t		get_argc()	const;
	std::string	get_title()	const;
	void		set_title(std::string title)	const;
	void		print_html_header();
	void		parse();
	std::string	param(std::string query);
	std::vector<std::string>	queries() const; 
	std::vector<std::string>	params() const; 

};




#endif
