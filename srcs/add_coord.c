/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:44:20 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/26 17:30:28 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"
#include <stdio.h>

t_coord		**add_coord(char *buff, size_t i, int x, int y)
{
	t_coord		**coord;
	int			tmp;

	tmp = 0;
	if (!(coord = (t_coord**)malloc(sizeof(t_coord*) * 
					((ft_strlen(buff) + 1) / 21) + 1)))
		return (NULL);
	coord[(ft_strlen(buff) + 1) / 21] = NULL;
	while (i < (ft_strlen(buff) + 1) / 21)
	{
			if (!(coord[i] = (t_coord*)malloc(sizeof(t_coord) * 4)))
				return (NULL);
			i++;
	}
	i = 0;
	while (buff && buff[i])
	{
		if (buff[i] == '#')
		{
			coord[x][y].x = x;
			coord[x][y].y = tmp;
			tmp++;
			printf("dans le while de add coord x = %d et y = %d sur le char %c en i = %zu\n", x, y, buff[i], i);
			y++;
		}
		if (buff[i] == '.')
			tmp++;
		if (buff[i] == '\n')
			tmp = 0;
		if (buff[i] == '\n' && buff[i - 1] == '\n')
		{
			x++;
			y = 0;
		}
		i++;
	}
	return (coord);
}
