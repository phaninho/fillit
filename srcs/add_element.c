/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:17:26 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/10 22:17:05 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"
#include<stdio.h>
int		blk_in_line(t_coord *coord, int line)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (i < 4)
	{
		if (coord[i].x == line)
			nbr++;
		printf ("coord = %d et line = %d nbr = %d\n", coord[i].x, line, nbr);
		i++;
	}
	return (nbr);
}

int		get_minx(t_coord *coord, int mode)
{
	int		i;
	int		min;

	i = 0;
	min = 10;
	while (i < 4)
	{
		if (coord[i].y < min)
			if ((mode != -1 && coord[i].x == mode) || mode == -1)
				min = coord[i].y;
		i++;
	}
	return (min);
}
int		**add_element(t_coord *coord)
{
	int		i;
	int		**tab;

	if (!(tab = (int **)malloc(sizeof(int *) * 4)))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * 2)))
			return (NULL);
		tab[i][0] = blk_in_line(coord, i);
		tab[i][1] = (tab[i][0] == 0) ? 0 : get_minx(coord, i);
		i++;
	}
	return (tab);
}
