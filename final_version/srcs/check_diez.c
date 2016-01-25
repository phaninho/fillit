/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diez.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 15:39:15 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/24 20:04:46 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

int		first_check(t_coord **coord, int x, int y)
{
	int		valid;

	valid = 0;
	if (y == 0 && coord[x][y].y == coord[x][y + 3].y && (coord[x][y].x -
	coord[x][y + 3].x == 1 || coord[x][y].x - coord[x][y + 3].x == -1))
		valid++;
	if (y == 3 && coord[x][y].y == coord[x][y - 3].y && (coord[x][y].x -
	coord[x][y - 3].x == 1 || coord[x][y].x - coord[x][y - 3].x == -1))
		valid++;
	if (x == 0 && coord[x][y].x == coord[x][y - 3].x && (coord[x][y].y -
	coord[x][y - 3].y == 1 || coord[x][y].y - coord[x][y + 3].y == -1))
		valid++;
	if (x == 3 && coord[x][y].x == coord[x][y - 3].x && (coord[x][y].y -
	coord[x][y - 3].y == 1 || coord[x][y].y - coord[x][y - 3].y == -1))
		valid++;
	return (valid);
}

int		second_check(t_coord **coord, int x, int y)
{
	int		valid;

	valid = 0;
	if (coord[x][y].y == coord[x][y + 1].y && (coord[x][y].x -
	coord[x][y + 1].x == 1 || coord[x][y].x - coord[x][y + 1].x == -1))
		valid++;
	if (coord[x][y].y == coord[x][y - 1].y && (coord[x][y].x -
	coord[x][y - 1].x == 1 || coord[x][y].x - coord[x][y - 1].x == -1))
		valid++;
	if (coord[x][y].x == coord[x][y + 1].x && (coord[x][y].y -
	coord[x][y + 1].y == 1 || coord[x][y].y - coord[x][y + 1].y == -1))
		valid++;
	if (coord[x][y].x == coord[x][y - 1].x && (coord[x][y].y -
	coord[x][y - 1].y == 1 || coord[x][y].y - coord[x][y - 1].y == -1))
		valid++;
	return (valid);
}

int		last_check(t_coord **coord, int x, int y)
{
	int		valid;

	valid = 0;
	if (y < 2 && coord[x][y].y == coord[x][y + 2].y && (coord[x][y].x -
	coord[x][y + 2].x == 1 || coord[x][y].x - coord[x][y + 2].x == -1))
		valid++;
	if (y < 2 && coord[x][y].x == coord[x][y + 2].x && (coord[x][y].y -
	coord[x][y + 2].y == 1 || coord[x][y].y - coord[x][y + 2].y == -1))
		valid++;
	if (y > 1 && coord[x][y].y == coord[x][y - 2].y && (coord[x][y].x -
	coord[x][y - 2].x == 1 || coord[x][y].x - coord[x][y - 2].x == -1))
		valid++;
	if (y > 1 && coord[x][y].x == coord[x][y - 2].x && (coord[x][y].y -
	coord[x][y - 2].y == 1 || coord[x][y].y - coord[x][y - 2].y == -1))
		valid++;
	return (valid);
}

int		check_diez(t_coord **coord, int x, int y, int valid)
{
	while (coord && coord[x] != NULL)
	{
		valid = first_check(coord, x, y) + valid;
		valid = second_check(coord, x, y) + valid;
		valid = last_check(coord, x, y) + valid;
		y++;
		if (y == 4)
		{
			y = 0;
			x++;
		}
	}
	if (valid >= x * 6)
		return (1);
	return (0);
}
