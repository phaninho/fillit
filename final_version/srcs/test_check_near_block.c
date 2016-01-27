/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_near_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 20:04:34 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/27 21:03:04 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

int			matching_test(t_coord **coord, int x, int y, int i)
{
	int		diffx;
	int		diffy;
	int		nbr_match;

	nbr_match = 0;
	diffx = coord[i][x].x - coord[i][y].x;
	diffy = coord[i][x].y - coord[i][y].y;
	diffx = (diffx < 0) ? diffx * -1 : diffx;
	diffy = (diffy < 0) ? diffy * -1 : diffy;
	if (((coord[i][x].x == coord[i][y].x) && (diffy == 1)) ||
	((coord[i][x].y == coord[i][y].y) && (diffx == 1)))
		nbr_match++;
	return (nbr_match);
}

int				check_near_block(t_coord **coord, int x, int y, int i)
{
	int		diffx;
	int		diffy;
	int		nbr_match;

	diffx = 0;
	diffy = 0;
	nbr_match = 0;
	while (coord && coord[i])
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
		i++;
	}
	return (nbr_match);
}

int			check_diez(t_coord **coord, int x, int y, int i)
{
	int		return_val;
	int		j;

	j = 0;
	return_val = check_near_block(coord, x, y, i);
	while (coord && coord[j])
		j++;
	if (return_val >= j * 6)
		return (1);
	return (0);
}
