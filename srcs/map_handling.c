/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 05:09:52 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/28 12:08:14 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

static void			basic_output(char **pattern)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (pattern && pattern[i])
	{
		while (pattern[i][j])
		{
			ft_putchar(pattern[i][j]);
			j++;
		}
		i++;
		j = 0;
		ft_putchar('\n');
	}
}

/*
** Affiche la pattern recue en parametre sur la sortie standard
*/

void				print_map(char **pattern, int param)
{
	if (param)
		stylised_output(pattern);
	else
		basic_output(pattern);
}

void				map_alloc_part2(char **new_map, char **pattern, int size)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = (pattern && pattern[0]) ? ft_strlen(pattern[0]) : 0;
	while (i < size)
	{
		if (!(new_map[i] = (char *)malloc(sizeof(char) * size + 1)))
			ft_error();
		new_map[i][size] = '\0';
		ft_memset(new_map[i], '.', size);
		if (i < len && pattern && pattern[i])
		{
			j = 0;
			while (j < len && pattern[i][j])
			{
				new_map[i][j] = pattern[i][j];
				j++;
			}
		}
		i++;
	}
}

/*
** Cree une nouvelle pattern a la bonne taille
** Si une pattern existait auparavant, ses donnees sont copiees dans la nouvelle
** pattern et la memoire est liberee.
*/

char				**map_alloc(char **pattern, char ***old_map, int size)
{
	char	**new_map;

	if (!(new_map = (char **)malloc(sizeof(char *) * (size + 1))))
		ft_error();
	new_map[size] = NULL;
	map_alloc_part2(new_map, pattern, size);
	if (old_map)
	{
		clean_tab2(*old_map);
		*old_map = NULL;
	}
	return (new_map);
}
