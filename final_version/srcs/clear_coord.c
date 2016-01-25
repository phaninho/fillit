/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:23:05 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/25 20:53:47 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

void		clear_coord(t_coord **coord)
{
	int		i;

	i = 0;
	while (coord && coord[i])
		free(coord[i++]);
	free(coord);
}

void		clear_shapes(int ***shapes)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (shapes[j] && shapes[j][i])
		free(shapes[j][i++]);
	while (shapes[j])
		free(shapes[j++]);
	free(shapes);
}

void		clear_map(char **map)
{
	int		i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
}

void		clear_int_coord(int *coord)
{
	free(coord);
}

void		clear_data(t_data *data)
{
	free(data);
}
