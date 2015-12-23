/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:44:20 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/22 23:45:20 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

/* ne pas oublier d'initialiser le i a -1 a cause de la ligne 21*/
 
t_coord		**add_coord(char *buff, int i, int x, int y)
{
	t_coord		**coord;

	if (!(coord = (t_coord)malloc()))
	if (check_valid(buff) == 1)
	{
		while (buff && buff[++i])
		{
			if (buff[i] == '#' || buff[i] == '.')
			{
				if (buff[i] == '#')
				{
					coord[i % 4][i / 4].x = x;
					coord[i % 4][i / 4].y = y % 5;
				}
				x++;
			}
			if (buff[i] == '\n')
			{
				x = 0;
				y++;
			}
		}
		return (coord);
	}
	else
		return (NULL);
}
