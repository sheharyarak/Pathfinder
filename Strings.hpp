#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <locale>
#include <cctype>

bool	not_space(char ch);
void	trim_from_start(std::string &str);
void	trim_from_end(std::string &str);
void	trim(std::string& str);

#endif