#include "libit.h"

void	usage_error(int ac)
{
	if (ac == 1)
	{
		ft_putstr("usage: ./fillit [--beautiful-map] map_file\n");
		exit (1);
	}
}
