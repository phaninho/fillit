/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 15:43:50 by jmaccion          #+#    #+#             */
/*   Updated: 2016/01/27 11:55:07 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

#define ORD		coord[0]
#define ABS		coord[1]

char				*fill_buff(int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*str;
	int		oct;
	char	*tmp;

	str = NULL;
	while ((oct = read(fd, buff, BUFF_SIZE)))
	{
		if (oct == -1)
			return (NULL);
		buff[oct] = '\0';
		if (!str)
			str = ft_strdup(buff);
		else
		{
			tmp = str;
			str = ft_strjoin(str, buff);
			free(tmp);
		}
	}
	return (str);
}

static void			set_var(int *var1, int *var2, int value1, int value2)
{
	if (var1)
		*var1 = value1;
	if (var2)
		*var2 = value2;
}

static t_coord		**set_value(t_coord **shapes, char *buff)
{
	int		i;
	int		coord[2];
	int		abs;
	int		ord;

	i = -1;
	set_var(&ord, &abs, 0, 0);
	ft_memset(coord, 0, sizeof(coord));
	while (buff && buff[++i])
	{
		if (buff[i] == '#' && shapes[ORD])
		{
			set_var(&(shapes[ORD][ABS].x), &(shapes[ORD][ABS].y), ord, abs);
			ABS++;
		}
		abs = (buff[i] == '#' || buff[i] == '.') ? abs + 1 : abs;
		if (buff[i] == '\n')
			set_var(&abs, &ord, 0, ++ord);
		if (buff[i] == '\n' && buff[i - 1] == '\n')
		{
			ORD++;
			set_var(&ord, &ABS, 0, 0);
		}
	}
	return (shapes);
}

static t_coord		**add_coord(char *buff)
{
	t_coord		**coord;
	size_t		i;

	i = 0;
	if (!(coord = (t_coord **)malloc((sizeof(t_coord *) *
		(((ft_strlen(buff) + 1) / 21) + 1)))))
		return (NULL);
	coord[(ft_strlen(buff) + 1) / 21] = NULL;
	while (i < (ft_strlen(buff) + 1) / 21)
	{
		if (!(coord[i] = (t_coord*)malloc(sizeof(t_coord) * 4)))
			return (NULL);
		i++;
	}
	coord[(ft_strlen(buff) + 1) / 21] = NULL;
	coord = set_value(coord, buff);
	return (coord);
}

void				control(int ac, char **av, t_coord ***coord, int *param)
{
	char	*buff;
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	buff = NULL;
	*param = check_env_exec(ac, av, &buff, &fd);
	while (buff && buff[i])
	{
		if (i == 0 && buff[i] == '\n')
			ft_error();
		tmp = ft_strsub(buff, i, 21);
		i += ft_strlen(tmp);
		check_valid(tmp);
		ft_strdel(&tmp);
	}
	if (buff[i - 1] == '\n' && buff[i - 2] == '\n')
		ft_error();
	*coord = add_coord(buff);
	free(buff);
	if (check_diez(*coord, 0, 0, 0) == 0)
		ft_error();
}
