/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 17:47:54 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/23 14:33:04 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

int		checkbuff(char *buff)
{
	int			i;
	int			j;
	int			l;
	int			div;

	i = 0;
	j = 0;
	l = 0;
	div = 1;
	while (buff && buff[l])
	{
		if ((buff[l] == '.' && i < 4) || (buff[l] == '#' && i < 4))
			i++;
		if (buff[l] == '\n' && i == 4)
		{
			i = 0;
			j++;
			if (j % 4 == 0 && buff[l + 1] == '\0')
				return (1);
			else if (j % 4 == 0 && buff[l + 1] == '\n')
				return (1);
		}
		l++;
	}
	return (0);
}
