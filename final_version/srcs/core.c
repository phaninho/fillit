/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:57:18 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/27 14:36:24 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

static int		check_line(int *tetra, t_data *data, int y, int x)
{
	int		nbr;

	nbr = 0;
	if (tetra[0] == 0)
		return (0);
	if (y < 0 || x < 0)
		return (1);
	while (nbr != tetra[0] && data->map[y] && data->map[y][x])
	{
		if (data->map[y][x] == '.')
		{
			data->map[y][x] = data->letter;
			nbr++;
			x++;
		}
		else
			return (1);
	}
	return ((nbr == tetra[0]) ? 0 : 1);
}

static int		check_position(int **tetra, t_data *data)
{
	int		i;
	int		x;
	int		y;
	int		save_x;

	i = 0;
	x = data->coord[0];
	y = data->coord[1];
	save_x = data->coord[0];
	while (i < 4)
	{
		if (check_line(tetra[i], data, y, x))
			return (1);
		i++;
		if (i == 4)
			break ;
		x = save_x;
		if (tetra[0][1] > tetra[i][1])
			x -= tetra[0][1] - tetra[i][1];
		else if (tetra[0][1] < tetra[i][1])
			x += tetra[i][1];
		y++;
	}
	return (0);
}

int				core(int ***tetra, t_data *data, int nbr, int param)
{
	int		x;
	int		y;
	int		status;
	char	**local_map;
	int		found;

	y = 0;
	x = 0;
	status = 0;
	found = 0;
	if (!tetra)
		return (1);
	data->letter = 'A' + nbr;
	local_map = map_alloc(data->map, NULL, data->map_size);
	while (tetra[nbr] && data->map[y])
	{
		while (tetra[nbr] && data->map[y][x])
		{
			data->coord[0] = x;
			data->coord[1] = y;
			if (!check_position(tetra[nbr], data))
			{
				nbr++;
				status++;
				if (nbr == data->total_shapes)
				{
					print_map(data->map, param);
					clean_tab2(local_map);
					return (42);
				}
				data->map_saved = map_alloc(data->map,
					&(data->map_saved), data->map_size);
				if (tetra[nbr])
					found = core(tetra, data, nbr, param);
				nbr--;
				data->letter = 'A' + nbr;
				if (found == 42)
				{
					clean_tab2(local_map);
					return (42);
				}
			}
			data->map = map_alloc(local_map, &(data->map), data->map_size);
			x++;
		}
		y++;
		x = 0;
		if (!data->map[y] && nbr == 0)
		{
			data->map_size++;
			data->map = map_alloc(local_map, &(data->map), data->map_size);
			local_map = map_alloc(data->map, &(local_map), data->map_size);
			y = 0;
		}
		if (!data->map[y] && !data->map[x] && status != 0)
			return (0);
	}
	clean_tab2(local_map);
	return (2);
}
