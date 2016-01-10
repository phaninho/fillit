/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:17:26 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/10 20:57:24 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

t_map		*add_element(t_coord **coord, int nb, int x, int y)
{
	t_map	*tetra;
	int		i;

	i = 0;
	while (coord[x])
		x++;
	if (!(tetra = (t_map *)malloc(sizeof(t_map) * (x * 4) + 1)))
		return (NULL);
	tetra[x * 4] = NULL;
	x = 0;
	while (coord[x])
	{
		while (y < 4)
		{
			tetra[i].start = coord[x][y].y;
			if (coord[x])
			{
				nb++;
				while (coord[x][y].x == coord[x][y + 1].x)
				{
					y++;
					nb++;
				}
			}
			tetra[i].nb = nb;
			nb = 0;
			i++;
			y++;
		}
		if (y == 4 && (i + 1) % 4 != 0)
		{
			while ((i + 1) % 4 != 0)
			{
				tetra[i].start = 0;
				tetra[i].nb = 0;
				i++;
			}
		}
		y = 0;
		x++;
	}
	return (tetra);
}
