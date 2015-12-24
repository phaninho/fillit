/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:28:40 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/24 13:36:45 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

int		check_valid(char *buff)
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
