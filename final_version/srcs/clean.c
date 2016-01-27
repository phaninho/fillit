/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:04:29 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/27 05:07:06 by jmaccion         ###   ########.fr       */
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
