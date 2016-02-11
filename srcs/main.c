/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 18:34:25 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/29 20:07:09 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

int		main(int ac, char **av)
{
	t_coord		**coord;
	int			***shapes;
	int			param;

	param = 0;
	coord = NULL;
	shapes = NULL;
	usage_error(ac);
	control(ac, av, &coord, &param);
	shapes = set_data(shapes, coord);
	solver(shapes, param);
	clean_tab3(shapes);
	return (0);
}
