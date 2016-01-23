/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:57:18 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/23 15:31:02 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

int		check_line(int *tetra, t_data *data, int y, int x)
{
	int		nbr;

	nbr = 0;
	if (tetra[0] == 0)
		return (0);
	while (nbr != tetra[0] && data->map[y] && data->map[y][x])
	{
		if (data->map[y][x] == '.')
		{
			data->map[y][x] = data->letter;
			nbr++;
			x++;
		}
		else
			return (1);
	}
	return ((nbr == tetra[0]) ? 0 : 1);
}

int		check_position(int **tetra, t_data *data)
{
	int		i;
	int		x;
	int		y;
	int		save_x;
	/* char	*save; */

	i = 0;
	x = data->coord[0];
	y = data->coord[1];
	save_x = data->coord[0];
	/* printf("MAP SAUVEGARDEE\n"); */
	/* data->map_saved = map_dup(data->map); */
	/* print_map(data->map_saved); */
	while (i < 4)
	{
		if (check_line(tetra[i], data, y, x))
		{
			printf("[ coord: y=%d - x=%d ]\n", y, x);
			printf("[ Error retour check_line() ]\n");
			printf("  ------------- \n");
			/* data->map = data->map_saved; */
			return (1);
		}
		i++;
		if (i == 4)
			break ;
		x = save_x;
		if (i > 0 && tetra[i -1][1] > tetra[i][1])
			x -= tetra[i-1][1] - tetra[i][1];
		else
			x = (tetra[i][1] == x) ? x : x + tetra[i][1];
		/* if (x >= data->map_size && i != 3) */
		/* { */
		/* 	data->map = data->map_saved; */
		/* 	return (1); */
		/* } */
		y++;
	}
	return (0);
}

int		core(int ***tetra, t_data *data, int nbr)
{
	int		x;
	int		y;
	int		status;
	char	**local_map;
	/* int		ret; */

	y = 0;
	x = 0;
	status = 0;
	/* ret = 0; */
	/* nbr = 0; */
	if (!tetra)
		return (1);
	local_map = map_alloc(data->map, data->map_size, 0);
	printf(C_YEL);
	printf("---------------\n");
	printf("   LEVEL UP  [ lvl %d ]\n", nbr);
	printf("data->map\n");
	print_map(data->map);
	printf("\n\nlocal_map\n");
	print_map(local_map);
	printf("---------------\n");
	printf(C_NONE);
	data->letter = 'A' + nbr;
	while (tetra[nbr] && data->map[y])
	{
		while (tetra[nbr] && data->map[y][x])
		{
			/* printf("%c ", map[y][x]); */
			data->coord[0] = x;
			data->coord[1] = y;
			if (!check_position(tetra[nbr], data))
			{
				printf(C_GREEN);
				printf("-- forme n* %d placed --\n", nbr);
				printf(C_NONE);
				ft_putstr(C_NONE);
				nbr++;
				/* y = 0; */
				/* x = 0; */
				status++;
				if (nbr == data->total_shapes)
				{
					printf("resultat final\n\n");
					print_map(data->map);
					/* print_data(tetra); */
					exit(1);
				}

				data->map_saved = map_alloc(data->map, data->map_size, 0);
				if (tetra[nbr])
				{
					core(tetra, data, nbr);
					nbr--;
				}
				else
					nbr--;
				data->letter = 'A' + nbr;
				printf("   ---------------\n");
				printf("  solution [ level %d ]\n", nbr);
				print_map(data->map);
				printf("\n\nlocal_map\n");
				print_map(local_map);
				printf("map size: %d\n", data->map_size);
				printf("   ---------------\n");
				/* if (nbr == 4) */
					/* return (0) ; */
			}
			/* data->map = map_alloc(data->map_saved, data->map_size, 0); */
			/* if (ret != 0) */
				data->map = map_alloc(local_map, data->map_size, 1);
			/* else */
			/* 	data->map = map_alloc(local_map, ++data->map_size, 0); */
			printf(C_BLUE);
			printf("---------------\n");
			printf("   LEVEL DOWN [ lvl %d ]\n", nbr);
			printf("data->map\n");
			print_map(data->map);
			printf("---------------\n");
			printf(C_NONE);

						x++;
		}
		printf(C_RED);
		printf("Ordonne ++\n");
		/* print_map(data->map); */
		/* printf("FIN PRINT MAP"); */
		printf(C_NONE);
		y++;
		x = 0;
		if (!data->map[y] && nbr == 0 /*status == 0*/)
		{
			data->map_size++;
			data->map = map_alloc(local_map, data->map_size, 1);
			local_map = map_alloc(data->map, data->map_size, 0);
			y = 0;
			printf(C_GREEN);
			printf("---------------\n");
			printf("   SIZE MAP UP  \n");
			printf("data->map\n");
			print_map(data->map);
			printf("\n\nlocal_map\n");
			print_map(local_map);
			printf("---------------\n");
			printf(C_NONE);

		}
		if (!data->map[y] && !data->map[x] && status != 0)
			return (0);
		printf("\n");
	}
	/* print_map(map); */
	/* print_data(tetra); */
	return (2);
}
