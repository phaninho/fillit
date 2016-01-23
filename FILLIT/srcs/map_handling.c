/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:48:34 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/20 21:47:31 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

/*
** Affiche la map recue en parametre sur la sortie standard
*/

void	print_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map && map[i])
	{
		while (map[i][j])
		{
			ft_putchar(map[i][j]);
			ft_putchar(' ');
			j++;
		}
		i++;
		j = 0;
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

/*
** Cree une nouvelle map a la bonne taille
** Si une map existait auparavant, ses donnees sont copiees dans la nouvelle
** map et la memoire est liberee.
*/

char		**map_alloc(char **map, int size, int mode)
{
	int		i;
	int		j;
	int		len;
	char 	**new_map;

	i = 0;
	len = 0;
	while (map && map[0][len])
		len++;
	if (!(new_map = (char **)malloc(sizeof(char *) * (size + 1))))
		ft_error();
	new_map[size] = NULL;
	while (i < size)
	{
		if (!(new_map[i] = (char *)malloc(sizeof(char) * size + 1)))
			ft_error();
		new_map[i][size] = '\0';
		ft_memset(new_map[i], '.', size);
		ft_putstr(C_GREEN);
		printf("I: %d\n", i);
		if (i < len && map && map[i])
		{
			j = 0;
			while (map[i][j])
			{
				new_map[i][j] = map[i][j];
				j++;
			}
			mode = mode + 1;
			/* printf("SIZE: %d\n", size - 1); */
			ft_putstr(C_NONE);
			/* if (i < size - 1) */
			/* ft_memcpy(new_map[i], map[i], (mode) ? size - 1 : size); */
			/* free(map[i]); */
		}
		i++;
	}
	/* if (map) */
	/* 	free(map); */
	return (new_map);
}

char		**map_dup(char **map)
{
	int		i;
	int		map_size;
	char	**save;

	i = 0;
	if (!map)
		return (NULL);
	map_size = sizeof(map) / 4;
	if (!(save = (char **)malloc(sizeof(char *) *(map_size + 1))))
		ft_error();
	while (map[i])
	{
		save[i] = ft_strdup(map[i]);
		i++;
	}
	return (save);
}
