/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:04:29 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/28 11:28:25 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

void	clean_tab2(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

void	clean_tab3(int ***tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab && tab[i])
	{
		while (j < 4)
		{
			free(tab[i][j]);
			j++;
		}
		free(tab[i]);
		j = 0;
		i++;
	}
	free(tab);
}

void	clean_tab_t_coord(t_coord **coord)
{
	int		i;

	i = 0;
	while (coord && coord[i])
	{
		free(coord[i]);
		i++;
	}
	free(coord);
}

int		clear_data(t_data *data, char **local_map, int param, int mode)
{
	if (mode == 10)
	{
		print_map(data->map, param);
		clean_tab2(local_map);
		return (42);
	}
	else if (mode == 42)
	{
		clean_tab2(local_map);
		return (42);
	}
	return (0);
}
