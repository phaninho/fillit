#include "libit.h"

t_coord		**init_tet(t_coord **coord, int x, int y)
{
	int	space;

	space = 0;
	while (space != 1)
	{
		while (y < 4 && space < 1)
		{
			coord[x][y].x = coord[x][y].x - 1;
			if (coord[x][y].x == 0)
				space++;
			y++;
		}
	}
		y = 0;
		space = 0;
	while (space != 1)
	{
		while (y < 4)
		{
			coord[x][y].y = coord[x][y].y - 1;
			if (coord[x][y].y == 0)
				space++;
			y++;
		}
	}
	return (coord);
}
