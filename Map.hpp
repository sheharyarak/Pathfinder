#ifndef BE5B36D2_D02A_4534_8FE2_70361B8E6565
#define BE5B36D2_D02A_4534_8FE2_70361B8E6565

#include <iostream>

class Map
{
private:
		/* data */
		int		_width = 0;
		int		_height = 0;
unsigned int	**_map = nullptr;
void	generateArray();
public:
	Map(){}
	// ~Map();
	void	readMap(std::string filename);
	void	printMap();
	int		height()	const;
	int		width()		const;
};



#endif /* BE5B36D2_D02A_4534_8FE2_70361B8E6565 */
