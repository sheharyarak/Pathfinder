#include "Strings.hpp"

// checks if its a space or not
bool	not_space(char ch)
{
	return	!std::isspace(ch);
}

// uses string erase to remove white space from start till first character
//  that is not a white space
void	trim_from_start(std::string &str)
{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), not_space));
}

// uses string erase to remove white space from end till first character
//  that is not a white space
void	trim_from_end(std::string &str)
{
	str.erase(std::find_if(str.rbegin(), str.rend(), not_space).base(), str.end());
}

// calls trim from start and trim from end
void	trim(std::string& str)
{
	trim_from_start(str);
	trim_from_end(str);
}