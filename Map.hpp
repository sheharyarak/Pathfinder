#ifndef BE5B36D2_D02A_4534_8FE2_70361B8E6565
#define BE5B36D2_D02A_4534_8FE2_70361B8E6565

#include <iostream>
#include <map>
#include <utility>

typedef std::pair<size_t, size_t> Coords;

class Map
{
private:
		/* data */
		std::map<size_t, std::string> colors;
		size_t		_width = 0;
		size_t		_height = 0;
		size_t		_scale = 25;
std::map<size_t, Coords>	_also_a_map_lol;
size_t	**_map = nullptr;
void	generateArray();
void	generateColorMap();
public:
	Map(){	generateColorMap();	}
	void	readMap(std::string filename);
	void	printMap();
	void	draw_map();
	size_t	height()	const;
	size_t	width()		const;
	size_t	at_coord(size_t, size_t) const;
	Coords&	operator[](size_t key);
	size_t	scale()	const;
	void	scale(size_t sc);
	std::string	color(size_t c);
};
std::string	coord_to_string(Coords coord);

#endif /* BE5B36D2_D02A_4534_8FE2_70361B8E6565 */
