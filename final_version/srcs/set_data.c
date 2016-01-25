/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 16:16:42 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/24 21:04:49 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

static int			check_spacex(t_coord *coord)
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

static int			check_spacey(t_coord *coord)
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

t_coord				*tool_init_tet(t_coord *coord, int y, int spx, int spy)
{
	while (spx < 1)
	{
		while (y != 4)
		{
			coord[y].x = coord[y].x - 1;
			if (coord[y].x == 0)
				spx++;
			y++;
		}
		y = 0;
	}
	y = 0;
	while (spy < 1)
	{
		while (y < 4)
		{
			coord[y].y = coord[y].y - 1;
			if (coord[y].y == 0)
				spy++;
			y++;
		}
		y = 0;
	}
	return (coord);
}

static t_coord		*init_tet(t_coord *coord, int y)
{
	int		spacex;
	int		spacey;

	spacex = check_spacex(coord);
	spacey = check_spacey(coord);
	coord = tool_init_tet(coord, y, spacex, spacey);
	return (coord);
}

int					***set_data(int ***shapes, t_coord **coord)
{
	int		x;

	x = 0;
	while (coord && coord[x])
	{
		coord[x] = init_tet(coord[x], 0);
		x++;
	}
	if (!(shapes = (int ***)malloc(sizeof(int **) * (x + 1))))
		ft_error();
	shapes[x] = 0;
	x = 0;
	while (coord && coord[x])
	{
		shapes[x] = add_element(coord[x]);
		x++;
	}
	return (shapes);
}
