/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:44:20 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/24 13:39:04 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"
 
t_coord		**add_coord(char *buff, int i, int x, int y)
{
	t_coord		**coord;

	if (!(coord = (t_coord**)malloc(sizeof(t_coord*) * 
					((ft_strlen(buff) + 1) / 21) + 1)))
		return (NULL);
	coord[(ft_strlen(buff) + 1) / 21] = NULL;
	while (i < (ft_strlen(buff) + 1) / 21)
	{
			if (!(coord[i] = (int*)malloc(sizeof(int) * 5)))
				return (NULL);
			coord[i][4] = '\0';
			i++;
	}
	i = 0;
	while (buff && buff[i])
	{
		if (buff[i] == '#')
		{
			coord[x][y].x = x;
			coord[x][y].y = y;
			y++;
		}
		if (buff[i] == '.')
			y++;
		if (buff[i] == '\n')
		{
			x++;
			y = 0;
		}
		i++;
	}
	return (coord);
}
