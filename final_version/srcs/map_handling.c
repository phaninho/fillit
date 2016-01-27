/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 05:09:52 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/27 15:01:53 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"
#define DEB		"\033[48;5;"
#define FIN		"m  \033[0m"
#define TAB	"1;2;3;4;5;6;7;8;9;10;11;12;13;14;15;18;23;33;51;82;105;196;202;214;223;225;226"

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
			ft_putchar(' ');
			j++;
		}
		i++;
		j = 0;
		ft_putchar('\n');
	}
}

static void			stylised_output(char **pattern)
{
	int		i;
	int		j;
	int		size_map;
	char	**tmp;

	i = 0;
	j = 0;
	size_map = (pattern && pattern[0]) ? ft_strlen(pattern[0]) : 0;
	tmp = ft_strsplit(TAB, ';');
	while (i++ <= size_map + 1)
		ft_putstr("\033[48;5;137m  \033[0m");
	ft_putchar('\n');
	i = 0;
	while (pattern && pattern[i])
	{
		ft_putstr("\033[48;5;137m  \033[0m");
		while (pattern[i][j])
		{
			if (pattern[i][j] != '.')
			{
				ft_putstr(DEB);
				ft_putstr(tmp[(pattern[i][j] - 'A')]);
				ft_putstr(FIN);
			}
			else
				ft_putstr("  ");
			j++;
		}
		i++;
		j = 0;
		ft_putstr("\033[48;5;137m  \033[0m\n");
	}
	size_map += 2;
	while (size_map--)
		ft_putstr("\033[48;5;137m  \033[0m");
	ft_putchar('\n');
	clean_tab2(tmp);
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

/*
** Cree une nouvelle pattern a la bonne taille
** Si une pattern existait auparavant, ses donnees sont copiees dans la nouvelle
** pattern et la memoire est liberee.
*/

char				**map_alloc(char **pattern, char ***old_map, int size)
{
	int		i;
	int		j;
	int		len;
	char	**new_map;

	i = 0;
	len = 0;
	while (pattern && pattern[0] && pattern[0][len])
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
	if (old_map)
	{
		clean_tab2(*old_map);
		*old_map = NULL;
	}
	return (new_map);
}
