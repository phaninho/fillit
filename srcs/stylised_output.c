/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stylised_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:30:17 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/28 11:45:34 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"
#define DEB		"\033[48;5;"
#define FIN 	"m  \033[0m"
#define PART1	"1;2;3;4;5;6;7;8;9;10;11;12;13;"
#define PART2	"14;15;18;23;33;51;82;105;196;202;214;223;225;226"
#define TAB		PART1 PART2

static void			print(char **pattern, char **tmp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
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
}

void				stylised_output(char **pattern)
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
	print(pattern, tmp);
	size_map += 2;
	while (size_map--)
		ft_putstr("\033[48;5;137m  \033[0m");
	ft_putchar('\n');
	clean_tab2(tmp);
}
