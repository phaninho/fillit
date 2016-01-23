/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 18:34:25 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/19 14:07:09 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

int		main(int ac, char **av)
{
	int			fd;
	char		*buff;
	int			i;
	int			check;
	char		*tmp;
	t_coord		**coord;
	int			x;
	int			***tetra;

	i = 0;
	x = 0;
	check = 0;
	if (ac == 2 && (fd = open(av[1], O_RDONLY)) != -1)
	{
		buff = fill_buff(fd);
		printf("HERE\n");
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
		printf("HERE\n");
		if (check == 1)
		{
			coord = add_coord(buff, 0, 0, 0);
			check = check_diez(coord, 0, 0, 0);
		}
		printf("HERE\n");
		if (check == 1)
		{
			printf("HERE1\n");
			while (coord && coord[x])
			{
				coord[x] = init_tet(coord[x], 0);
				x++;
			}
			printf("HERE1\n");
			if (!(tetra = (int ***)malloc(sizeof(int **) * (x + 1))))
				return 0;
			tetra[x] = 0;
			x = 0;
			while (coord && coord[x])
			{
				tetra[x] = add_element(coord[x]);
				x++;
			}
			/* map = join_tetra(tetra, 0, 0, 2); */
			// PLACEMENT DES FORMES
			printf("call solver()\n");
			solver(tetra);

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
	return (0);
}
