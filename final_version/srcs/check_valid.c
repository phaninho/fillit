/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:28:40 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/27 11:52:32 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

static void		mode_pls_sous_la_couette(char *buff)
{
	char	**split;
	int		i;
	int		status;

	i = 0;
	status = 0;
	split = ft_strsplit(buff, '\n');
	while (split[i])
	{
		if (ft_strlen(split[i]) > 4)
			status = 1;
		i++;
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	if (status)
		ft_error();
}

static int		checkbuff(char *buff)
{
	int			i;
	int			j;
	int			l;

	i = 0;
	j = 0;
	l = 0;
	mode_pls_sous_la_couette(buff);
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
				break ;
			if (buff[i] == '#')
				diez++;
			i++;
		}
		if (diez == 4)
			return (1);
	}
	free(buff);
	ft_error();
	return (0);
}
