/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tetra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:36:18 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/13 18:36:49 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libit.h"
#include <stdio.h>

int			square_meter(int **tetra, int i)
{
	int		sm;
	int		haut;
	int		larg;

	larg = 1;
	haut = 0;
	while (tetra && i < 4)
	{
		if (tetra[i][0] != 0)
		{
			if (i + 1 < 4 && tetra[i + 1][0] + tetra[i + 1][1] > larg)
				larg = tetra[i + 1][0] + tetra[i + 1][1];
			haut++;
		}
		i++;
	}
	sm = larg * haut;
	return (sm);
}

void		join_tetra(int **tetra)
{
	int		i;
	int		sm;

	i = 0;
	while (tetra && tetra[i])
	{
		sm = square_meter(tetra, 0);
		printf("%d  : sm = %d tetra[%d %d]\n", i, sm, tetra[i][0], tetra[i][1]);
		i++;
	}
}
