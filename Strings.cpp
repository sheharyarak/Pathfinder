#include "Strings.hpp"

bool	not_space(char ch)
{
	return	!std::isspace(ch);
}

void	trim_from_start(std::string &str)
{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), not_space));
}

void	trim_from_end(std::string &str)
{
	str.erase(std::find_if(str.rbegin(), str.rend(), not_space).base(), str.end());
}

void	trim(std::string& str)
{
	trim_from_start(str);
	trim_from_end(str);
}