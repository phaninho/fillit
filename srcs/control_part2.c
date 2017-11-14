/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 11:35:45 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/28 10:36:58 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

static int				matching_test(t_coord **coord, int x, int y, int i)
{
	int		diffx;
	int		diffy;
	int		nbr_match;

	nbr_match = 0;
	diffx = coord[i][x].x - coord[i][y].x;
	diffy = coord[i][x].y - coord[i][y].y;
	diffx = (diffx < 0) ? diffx * -1 : diffx;
	diffy = (diffy < 0) ? diffy * -1 : diffy;
	if (((coord[i][x].x == coord[i][y].x) && (diffy == 1))
		|| ((coord[i][x].y == coord[i][y].y) && (diffx == 1)))
		nbr_match++;
	return (nbr_match);
}

static int				check_near_block(t_coord **coord)
{
	int		i;
	int		x;
	int		y;
	int		nbr_match;

	i = -1;
	x = 0;
	y = 0;
	nbr_match = 0;
	while (coord && coord[++i])
	{
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (x != y)
					nbr_match = (matching_test(coord, x, y, i) + nbr_match);
				x++;
			}
			y++;
		}
	}
	return (nbr_match);
}

int						check_diez(t_coord **coord)
{
	int		return_val;
	int		j;

	j = 0;
	return_val = check_near_block(coord);
	while (coord && coord[j])
		j++;
	if (return_val >= j * 6)
		return (1);
	return (0);
}

int						check_env_exec(int ac, char **av, char **buff, int *fd)
{
	if ((ac < 2 || ac > 3)
			|| (ac == 3 && ft_strcmp(av[1], "--beautiful-map"))
			|| (*fd = open((ac == 3) ? av[2] : av[1], O_RDONLY)) == -1
			|| (!(*buff = fill_buff(*fd))))
	{
		ft_error();
		return (0);
	}
	if (ac == 3 && !ft_strcmp(av[1], "--beautiful-map"))
		return (1);
	else
		return (0);
}
