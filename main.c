/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 18:34:25 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/22 23:21:13 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

int		main(int ac, char **av)
{
	int			fd;
	char		*buff;
	int			check;
//	char		**final_tet;
//	t_coord		coord[4][26];

	if (ac == 2 && (fd = open(av[1], O_RDONLY)) != -1)
	{
		buff = fill_buff(fd);
		check = checkbuff(buff);
		if (check == 1)
		{
			ft_putstr("good map\n");
			ft_putstr(buff);
		}
		else
		{
			ft_putstr("bad map\n");
			ft_putstr(buff);
			return (0);
		}
		return (0);	
	}
	else
	{
		ft_putstr("error\n");
		return (0);
	}
}
