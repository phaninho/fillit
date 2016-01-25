/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:57:18 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/24 23:17:16 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

int		check_line(int *tetra, t_data *data, int y, int x)
{
	int		nbr;

	nbr = 0;
	if (tetra[0] == 0)
		return (0);
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

int		check_position(int **tetra, t_data *data)
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
		if (i > 0 && tetra[i - 1][1] > tetra[i][1])
			x -= tetra[i - 1][1] - tetra[i][1];
		else
			x = (tetra[i][1] == tetra[0][1]) ? x : x + tetra[i][1];
		y++;
	}
	return (0);
}

int		core(int ***tetra, t_data *data, int nbr, int status)
{
	int		x;
	int		y;
	char	**local_map;

	y = 0;
	x = 0;
	if (!tetra)
		return (1);
	local_map = map_alloc(data->map, data->map_size);
	data->letter = 'A' + nbr;
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
					print_map(data->map);
					exit(1);
				}
				data->map_saved = map_alloc(data->map, data->map_size);
				if (tetra[nbr])
				{
					core(tetra, data, nbr, 0);
					nbr--;
				}
				else
					nbr--;
				data->letter = 'A' + nbr;
			}
			data->map = map_alloc(local_map, data->map_size);
			x++;
		}
		y++;
		x = 0;
		if (!data->map[y] && nbr == 0)
		{
			data->map_size++;
			data->map = map_alloc(local_map, data->map_size);
			local_map = map_alloc(data->map, data->map_size);
			y = 0;
		}
		if (!data->map[y] && !data->map[x] && status != 0)
			return (0);
	}
	return (2);
}
