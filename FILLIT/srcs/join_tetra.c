/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tetra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:36:18 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/17 05:22:11 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libit.h"
#include <stdio.h>

void			init_var(int i, int j, int x, int y)
{
	i = 0;
	j = 0;
	x = 0;
	y = 0;
}
char			**join_tetra(int ***tetra, int cnt, int i, int size)
{
	int		x;
	int		y;
	int		j;
	int		diez;
	char	**map;
	int		check_size;

	init_var(i, j, x, y);
	check_size = 0;
	diez = 0;
	while (tetra && tetra[i])
	{
		if (check_size != size)
		{
			if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
				return (NULL);
			map[size] = NULL;
			check_size = size;
		}	
		if (!(map[y] = (char *)malloc(sizeof(char) * (size + 1))))
				return (NULL);
		map[y][size] = '\0';
		if (tetra[i][j][0] != 0)
		{
			cnt = x + tetra[i][j][1];
			while (x < cnt && map[y][x])
			{
				map[y][x] = '.';
				x++;
			}
			cnt = 0;
			while (cnt < tetra[i][j][0])
			{
				map[y][x] = 'A' + i;
				x++;
				diez++;
				cnt++;
			}
			while (x < size)
			{
				map[y][x] = '.';
				x++;
			}
			j++;
			y++;
		}
		else
		{
			map[y][x] = '.';
			x++;
		}
		if (x == size && y == size && tetra[i] != NULL)
		{
			size++;
			init_var(i, j, x, y);
			diez = 0;
		}
		if (diez == 4)
		{
			i++;
			y++;
			j = 0;
			x = 0;
			diez = 0;
		}
	}
	return (map);
}
