/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 18:24:21 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/27 12:02:24 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

static void		init_data(t_data *data, int size)
{
	ft_memset(data, 0, sizeof(data));
	data->map = map_alloc(data->map, &(data->map), size);
	data->map_size = size;
	data->letter = 'A';
}

static int		get_height(int **shapes)
{
	int		i;
	int		height;

	i = 0;
	height = 0;
	while (i < 4 && shapes[i][0])
	{
		height++;
		i++;
	}
	return (height);
}

static int		get_size_by_width(int ***shapes)
{
	int		i;
	int		j;
	int		larg;

	i = 0;
	larg = 2;
	while (shapes && shapes[i])
	{
		j = 0;
		while (j < 4 && shapes[i][j])
		{
			if (shapes[i][j++][0] == 4)
			{
				larg = (larg < 4) ? 4 : larg;
				if (i > 3)
				{
					larg = (larg / 4 == 1) ? larg + 1 : larg;
					if (((larg % 4) == 0) && (larg / i) != 0)
						larg = larg + 1;
				}
			}
		}
		i++;
	}
	return (larg);
}

static int		get_size_by_height(int ***shapes)
{
	int		i;
	int		haut;

	i = 0;
	haut = get_height(shapes[0]);
	while (shapes && shapes[i])
	{
		if (get_height(shapes[i]) == 4)
		{
			if (haut < 4)
				haut = 4;
			else if (i > 3)
				haut++;
		}
		i++;
	}
	return (haut);
}

void			solver(int ***shapes, int param)
{
	int		size_by_width;
	int		size_by_height;
	int		coeff;
	int		i;
	t_data	data;

	if (!shapes)
		return ;
	i = 0;
	size_by_width = get_size_by_width(shapes);
	size_by_height = get_size_by_height(shapes);
	coeff = (size_by_width > size_by_height) ? size_by_width : size_by_height;
	while (shapes[i])
		i++;
	while (coeff * coeff < i * 4)
		coeff++;
	init_data(&data, coeff);
	data.total_shapes = i;
	data.map_saved = map_alloc(data.map, NULL, data.map_size);
	core(shapes, &data, 0, param);
	clean_tab2(data.map);
	clean_tab2(data.map_saved);
}
