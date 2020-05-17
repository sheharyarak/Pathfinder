#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <locale>
#include <cctype>

// Was facing strange bug where item names were surrounded by large amounts of white space
// To remove the white space I used previously coded functions
// learned during development of other programs and 42
// tests if character is space or not using std::isspace(char)
bool	not_space(char ch);
// function to remove white space from start of string
void	trim_from_start(std::string &str);
// function to remove white space from end of string
void	trim_from_end(std::string &str);
// function to remove whitespace from both ends of string
void	trim(std::string& str);

#endif