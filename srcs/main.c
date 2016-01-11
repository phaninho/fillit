/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 18:34:25 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/10 20:51:55 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"
#include <stdio.h>
int		main(int ac, char **av)
{
	int			fd;
	char		*buff;
	int			i;
	int			check;
	char		*tmp;
	t_coord		**coord;
	int			x;
	int		**tetra;
	i = 0;
	x = 0;
	if (ac == 2 && (fd = open(av[1], O_RDONLY)) != -1)
	{
		buff = fill_buff(fd);
		while (buff && buff[i])
		{
			tmp = ft_strsub(buff, i, 21);
			i += ft_strlen(tmp);
			if ((ft_strlen(tmp) == 20 && buff[i] =='\0') || 
					(ft_strlen(tmp) == 21 && buff[i] != '\0'))
				check = check_valid(tmp);
			else
				check = 0;
		}
		if (check == 1)
		{
			coord = add_coord(buff, 0, 0, 0);
			check = check_diez(coord, 0, 0, 0);
		}
		if (check == 1)
		{
			while (coord[x] != NULL)
			{
				coord[x] = init_tet(coord[x], 0);
				printf("tet nb %d\n", x + 1);
				printf("x = [%d] y = [%d]\n", coord[x][0].x, coord[x][0].y);
				printf("x = [%d] y = [%d]\n", coord[x][1].x, coord[x][1].y);
				printf("x = [%d] y = [%d]\n", coord[x][2].x, coord[x][2].y);
				printf("x = [%d] y = [%d]\n", coord[x][3].x, coord[x][3].y);
				tetra = add_element(coord[x]);
				printf("tetra = [%d %d]\n", tetra[x][0], tetra[x][1]);
				x++;
			}
			
			i = 0;
			while (tetra[i])
			{
				printf("i = %d [%d %d]\n",i, tetra[i][0], tetra[i][1]);
				i++;
			}
			return (1);
		}
		else
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	else
	{
		ft_putstr("error\n");
		return (0);
	}
}
