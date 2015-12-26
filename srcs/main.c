/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 18:34:25 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/26 17:35:49 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"
#include <stdio.h>
int		main(int ac, char **av)
{
	int			fd;
	char		*buff;
	int			check;
	int			i;
	char		*tmp;
//	char		**final_tet;
	t_coord		**coord;
	
	i = 0;
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
			ft_putstr("good map\n");
			ft_putstr(buff);
		}
		else
		{
			ft_putstr("bad map\n");
			ft_putstr(buff);
			return (0);
		}
		
			printf("x = %d et y = %d", coord[0][1].x, coord[0][1].y);
		return (0);
	}
	else
	{
		ft_putstr("Error\n");
		return (0);
	}
}
