#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>
#include <map>

// UI Class inspired by professor degalier's final labs
// Learned while tutoring professors degalier's students
class UI
{
private:
	// number of arguments
	size_t			_argc = 0;
	// query string and title of page
	std::string		_query_string, _title;
	// parrelel vector mapping queries to params
	// via index
	std::vector<std::string>	_queries;
	std::vector<std::string>	_params;
	
public:
	// Constructor
	UI(std::string title);
	// Destructor
	~UI();
	// getters and setters for variables
	void		set_query_string(std::string qs);
	std::string	get_query_string()	const;
	void		set_argc(size_t	ac);
	size_t		get_argc()	const;
	std::string	get_title()	const;
	void		set_title(std::string title)	const;
	std::vector<std::string>	queries() const; 
	std::vector<std::string>	params() const; 
	// print html header
	void		print_html_header();
	// parse query string
	void		parse();
	// set body color to random
	void		color_body();
	// returns param based on query
	std::string	param(std::string query);
	// print check box from list;
	// made this function for customizability and later use
	void		print_check_box_from_list(std::map<std::string, size_t>& map);
};




#endif
