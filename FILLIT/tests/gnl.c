/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <jmaccion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 21:08:31 by jmaccion          #+#    #+#             */
/*   Updated: 2015/12/23 17:10:28 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <fcntl.h>
#include <stdio.h>

#define SIZE	5

int		check(char **str, char **line)
{
	char			*eol;

	if (*str)
	{
		if ((eol = ft_strchr(*str, '\n')))
		{
			*line = ft_strsub(*str, 0, ft_strlen(*str) - ft_strlen(eol));
			eol = (ft_strlen(eol) > 1) ? ft_strdup(++eol) : NULL;
			ft_strdel(str);
			*str = eol;
			/* printf("GNL 1\n"); */
			return (1);
		}
		*line = ft_strdup(*str);
		ft_strdel(str);
		*str = NULL;
		/* printf("GNL 2\n"); */
		return (1);
	}
	return (0);
}

int		gnl(int const fd, char **line)
{
	char			*buffer;
	int				ret;
	static char		*string = NULL;
	char			*eol;

	if (!(buffer = (char *)malloc(sizeof(char) * SIZE + 1)))
		return (-1);
	ft_memset(buffer, 0, SIZE + 1);
	while ((ret = read(fd, buffer, SIZE)))
	{
		if (-1 == ret)
			return (ret);
		string = (string) ? ft_strjoin(string, buffer) : ft_strdup(buffer);
		ft_memset(buffer, 0, SIZE);
		if ((eol = ft_strchr(string, '\n')))
		{
			*line = ft_strsub(string, 0, ft_strlen(string) - ft_strlen(eol));
			eol = (ft_strlen(eol) > 1) ? ft_strdup(++eol) : NULL;
			ft_strdel(&string);
			string = eol;
			free(buffer);
			return (1);
		}
	}
	return (check(&string, line));
}
