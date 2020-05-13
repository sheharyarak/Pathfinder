#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[])
{
	if(argc != 3) return -1;
	size_t  w = std::atoi(argv[1]);
	size_t  h = std::atoi(argv[2]);
	std::string fname = std::to_string(w) + "x" + std::to_string(h) + ".tsv";
	std::ofstream file;
	file.open(fname);
	file << w << "\t" << h << std::endl;
	for(size_t i = 0; i < h; i++)
	{
		for (size_t j = 0; j < w; j++)
		{
			file << 0;
			if(j == w - 1)
				file << std::endl;
			else
				file << '\t';
			
		}
	}
	file.close();
}