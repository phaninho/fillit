/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:23:05 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/25 18:56:58 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

void		clear_coord(t_coord **coord)
{
	int		i;

	i = 0;
	if (!coord)
		ft_error();
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
	if (!shapes)
		ft_error();
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
	if (!map)
		ft_error();
	while (map && map[i])
		free(map[i++]);
	free(map);
}

void		clear_int_coord(int *coord)
{
	if (!coord)
		ft_error();
	free(coord);
}

void		clear_data(t_data *data)
{
	if (!data)
		ft_error();
	free(data);
}
