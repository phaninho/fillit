/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:28:40 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/24 23:57:36 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

static int		checkbuff(char *buff)
{
	int			i;
	int			j;
	int			l;

	i = 0;
	j = 0;
	l = 0;
	while (buff && buff[l])
	{
		if (i < 4 && ((buff[l] == '.') || (buff[l] == '#')))
			i++;
		if (buff[l] == '\n' && i == 4)
		{
			i = 0;
			j++;
			if (j % 4 == 0 &&
					((buff[l + 1] == '\0') || buff[l + 1] == '\n'))
				return (1);
		}
		l++;
	}
	return (0);
}

int				check_valid(char *buff)
{
	int	i;
	int	diez;

	i = 0;
	diez = 0;
	if (checkbuff(buff) == 1)
	{
		while (buff && buff[i])
		{
			if (buff[i] == '\n' && buff[i + 1] == '\n' && buff[i + 2] == '\n')
				return (0);
			if (buff[i] == '#')
				diez++;
			i++;
		}
		if (diez == 4)
			return (1);
	}
	return (0);
}
