/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 17:44:13 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/25 20:46:34 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libit.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_test
{
	char x;
	char y;
}				t_test;


void		del_coord(t_test **coord)
{
	int		i;

	i = 0;
	while (coord && coord[i])
		free(coord[i++]);
	free(coord);
}

int		main()
{
	int	i = 0;
	int	j = 0;
	t_test	**coord;

	if (!(coord = (t_test**)malloc(sizeof(t_test*) * 3)))
		exit (0);
	coord[2] = NULL;
	while (i < 2)
	{
		if (!(coord[i] = (t_test *)malloc(sizeof(t_test) * 3)))
			exit (0);
		i++;
	}
	i = 0;
	coord[0][0].x = '#';
	coord[0][0].y = '#';
	coord[0][1].x = '#';
	coord[0][1].y = '#';
	coord[0][2].x = 'A';
	coord[0][2].y = 'A';
	coord[1][0].x = '#';
	coord[1][0].y = '#';
	coord[1][1].x = '#';
	coord[1][1].y = '#';
	coord[1][2].x = 'B';
	coord[1][2].y = 'B';
	while (coord[j])
	{
		while (i < 3)
		{
			printf("%c%c\n",coord[j][i].x, coord[j][i].y);
			i++;
		}
		j++;
		i = 0;
	}
	del_coord(coord);
	printf("apres free\n");
	return (0);
}
