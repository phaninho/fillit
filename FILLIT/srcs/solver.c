/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 18:24:21 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/20 18:48:26 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

void	set_data(t_data *data, int size)
{
	ft_memset(data, 0, sizeof(data));
	data->map = map_alloc(data->map, size, 1);
	data->map_size = size;
	data->letter = 'A';
}

void	solver(int ***tetra)
{
	/* int		status; */
	int		i;
	t_data	data;

	if (!tetra)
		return ;
	i = 0;
	printf("HERE\n");
	while (tetra && tetra[i])
		i++;
	set_data(&data, 2);
	data.total_shapes = i;
	data.map_saved = map_alloc(data.map, data.map_size, 0);
	/* status = core(tetra, &data); */
	core(tetra, &data, 0);
	/* while (status == 1) */
	/* { */
	/* 	ft_putstr(C_YEL); */
	/* 	printf("  ---------- \n"); */
	/* 	printf("NEW MAP_SIZE: %d\n", (data.map_size + 1)); */
	/* 	printf("  ---------- \n"); */
	/* 	ft_putstr(C_NONE); */
	/* 	data.map_size++; */
	/* 	data.map = map_alloc(data.map, data.map_size, 1); */
	/* 	data.map_saved = map_alloc(data.map, data.map_size, 0); */
	/* 	#<{(| printf("-- START --\n"); |)}># */
	/* 	#<{(| print_map(data.map_saved); |)}># */
	/* 	#<{(| printf("-- END --\n"); |)}># */
	/* 	status = core(tetra, &data); */
	/* 	#<{(| printf("-- Status: %d\n", status); |)}># */
	/* } */
	print_map(data.map);
}
