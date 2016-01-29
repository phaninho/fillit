/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:19:45 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/19 15:22:24 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

void	print_data(int ***tetra)
{
	int		i;
	int		j;

	i = 0;
	while (tetra && tetra[i])
	{
		j = 0;
		ft_putstr(C_RED);
		printf("\n-- Forme n* %d --\n", i);
		ft_putstr(C_NONE);
		while (j < 4)
		{
			printf("[ %d - %d ]\n", tetra[i][j][0], tetra[i][j][1]);
			j++;
		}
		i++;
	}
}
