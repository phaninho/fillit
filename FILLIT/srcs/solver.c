/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 18:24:21 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/23 14:47:07 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

void	set_data(t_data *data, int size)
{
	ft_memset(data, 0, sizeof(data));
	data->map = map_alloc(data->map, size, 1);
	data->map_size = size;
	data->letter = 'A';
}

int		get_height(int **tetra)
{
	int		i;
	int		height;

	i = 0;
	height = 0;
	while (i < 4 && tetra[i][0])
	{
		height++;
		i++;
	}
	return (height);
}

void	solver(int ***tetra)
{
	/* int		status; */
	int		i;
	int		j;
	int		k;
	int		larg;
	int		haut;
	int		all;
	t_data	data;

	if (!tetra)
		return ;
	i = 0;
	larg = 2;
	k = 1;
	printf("SOLVER.C\n");
	while (tetra && tetra[i])
	{
		j = 0;
		printf("-- DEBUG 2\n");
		while (tetra[i][j] && j < 4)
		{
			if (tetra[i][j][0] == 4)
			{
				if (larg < 4)
					larg = 4;
				else if (i > 3)
				{
					if (larg / 4 == 1)
						larg = larg + 1;
					else if (((larg % 4) == 0) && (larg / i) != 0)
						larg = larg + 1;
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	printf("larg: %d\n", larg);
	haut = get_height(tetra[0]);
	/* printf("-- DEBUG 2\n"); */
	while (tetra && tetra[i])
	{
		if (get_height(tetra[i]) == 4)
		{
			if (haut < 4)
				haut = 4;
			else if (i > 3)
				haut++;
		}
		i++;
	}
	printf("haut: %d\n", haut);
	/* exit(1); */
	k = (larg > haut) ? larg : haut;
	/* k = larg; */
	all = i * 4;
	while (k * k < all)
		k++;
	printf("K: %d\n - all: %d", k, all);
	set_data(&data, k);
	data.total_shapes = i;
	data.map_saved = map_alloc(data.map, data.map_size, 0);
	/* status = core(tetra, &data); */
	core(tetra, &data, 0);
	/* while (status == 1) */
	/* { */
	/* 	ft_putstr(C_YEL); */
	/* 	printf("  ---------- \n"); */
	/* 	printf("NEW MAP_SIZE: %d\n", (data.map_size + 1)); */
	/* 	printf("  ---------- \n"); */
	/* 	ft_putstr(C_NONE); */
	/* 	data.map_size++; */
	/* 	data.map = map_alloc(data.map, data.map_size, 1); */
	/* 	data.map_saved = map_alloc(data.map, data.map_size, 0); */
	/* 	#<{(| printf("-- START --\n"); |)}># */
	/* 	#<{(| print_map(data.map_saved); |)}># */
	/* 	#<{(| printf("-- END --\n"); |)}># */
	/* 	status = core(tetra, &data); */
	/* 	#<{(| printf("-- Status: %d\n", status); |)}># */
	/* } */
	print_map(data.map);
}
