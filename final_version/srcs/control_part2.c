/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 11:35:45 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/27 11:46:01 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

int		check_env_exec(int ac, char **av, char **buff, int *fd)
{
	if ((ac < 2 || ac > 3)
			|| (ac == 3 && ft_strcmp(av[1], "--beautiful-map"))
			|| (*fd = open((ac == 3) ? av[2] : av[1], O_RDONLY)) == -1
			|| (!(*buff = fill_buff(*fd))))
		ft_error();
	if (ac == 3 && !ft_strcmp(av[1], "--beautiful-map"))
		return (1);
	else
		return (0);
}
