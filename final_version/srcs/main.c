/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 18:34:25 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/24 21:55:47 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

int		main(int ac, char **av)
{
	t_coord		**coord;
	int			x;
	int			***shapes;

	x = 0;
	coord = NULL;
	shapes = NULL;
	control(ac, av, &coord, x);
	shapes = set_data(shapes, coord);
	solver(shapes);
	// clear()
	return (0);
}
