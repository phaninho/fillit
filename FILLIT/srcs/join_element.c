/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 08:27:53 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/18 20:45:37 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

/* void	init_var(int *i, int *j, int *x, int *y) */
/* { */
/* 	*i = 0; */
/* 	*j = 0; */
/* 	*x = 0; */
/* 	*y = 0; */
/* } */

/* char	**map_alloc(char **map, int len, int size) */
/* { */
/* 	int		i; */
/*  */
/* 	i = 0; */
/* 	while (i < len) */
/* 	{ */
/* 		if (map[i]) */
/* 			free(map[i]); */
/* 		i++; */
/* 	} */
/* 	// free(map); */
/* 	// map = NULL; */
/* 	if(!(map = (char **)malloc(sizeof(char *) * (size + 1)))) */
/* 		return (NULL); */
/* 	map[size] = NULL; */
/* 	return (map); */
/* } */

/* char	**join_element(int ***tetra, int stop, int check_size, int size) */
/* { */
/* 	int		x; */
/* 	int		y; */
/* 	int		i; */
/* 	int		j; */
/* 	char	**map; */
/*  */
/* 	map = NULL; */
/* 	init_var(&i, &j, &x, &y); */
/* 	while (tetra && tetra[i]) */
/* 	{ */
/* 		if (len < size) */
/* 		{ */
/* 			if (!()) */
/* 		} */
/* 		i++; */
/* 	} */
/* 	return (map); */
/* } */

void	solver(int ***tetra)
{
	/* int		statut; */
	char	**map;
	int		size;

	map = NULL;
	size = 2;
	if (!tetra)
		return ;
	map = map_alloc(map, size); // 2x2
	/* map = memset(map, 'x', sizeof(char *) * size * size); */
	/* statut = placement_tetri(liste); */
	/* while (status == false) */
	/* { */
			/* map_alloc(map, ++size); */
	/* 		status = placement_tetri(liste); */
	/* } */
	print_map(map);
}
