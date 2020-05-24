#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int		main(int argc, char* argv[])
{
	if(argc < 3)
		return -1;
	std::ifstream ifs(argv[1]);
	std::ofstream ofs(argv[2]);
	std::string item;
	std::vector<std::string> items;
	while (std::getline(ifs, item))
	{
		items.push_back(item);
	}
	ofs			<<	"0\tP\t#Path\n"
				<<	"1\tX\t# Wall or not a Path\n"
				<<	"2\tI\t# Entrance or in route\n"
				<<	"3\tO\t#Exit or out route\n"
				<<	"4\tB\t# bathroom\n";
	for (size_t i = 0; i < items.size(); i++)
	{
		std::clog << i + 10 << "\t" << items[i] << std::endl;
		ofs << i + 10 << "\t" << items[i] << std::endl;
	}
	
}