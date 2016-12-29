#include "libit.h"

void	usage_error(int ac)
{
	if (ac == 1)
	{
		ft_putstr("usage: fillit map_file [--beautiful-map]\n");
		exit (1);
	}
}
