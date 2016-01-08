/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:12:42 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/08 16:12:46 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"
#include <stdio.h>

int			check_spacex(t_coord *coord)
{
	int		y;
	int		spacex;

	spacex = 0;
	y = 0;
	while (y < 4)
	{
		if (coord[y].x == 0)
			spacex++;
		y++;
	}
	return (spacex);
}

int			check_spacey(t_coord *coord)
{
	int		y;
	int		spacey;

	spacey = 0;
	y = 0;
	while (y < 4)
	{
		if (coord[y].y == 0)
			spacey++;
		y++;
	}
	return (spacey);
}

t_coord		*init_tet(t_coord *coord, int y)
{
	int	spacex;
	int	spacey;

	spacex = check_spacex(coord);
	spacey = check_spacey(coord);
	y = 0;
	while (spacex < 1)
	{
		while (y != 4)
		{
			coord[y].x = coord[y].x - 1;
			if (coord[y].x == 0)
				spacex++;
			y++;
		}
	}
		y = 0;
	while (spacey < 1)
	{
		while (y < 4)
		{
			coord[y].y = coord[y].y - 1;
			if (coord[y].y == 0)
				spacey++;
			y++;
		}
	}
	return (coord);
}
