/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 18:09:20 by jmaccion          #+#    #+#             */
/*   Updated: 2015/12/23 19:55:53 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	check_column(t_def *form, char *buffer)
{
	if (ft_strlen(buffer) > 4)
		form->status = -1;
}

void	check_char(t_def *form, char *buffer)
{
	int		i;

	i = 0;
	if (!ft_strcmp(buffer, ""))
	{
		form->status = -1;
		return ;
	}
	while (buffer && buffer[i])
	{
		if (buffer[i] != '.' && buffer[i] != '#')
		{
			form->status = -1;
			return ;
		}
		i++;
	}
}

int		check_near_block(t_tetris *new_form)
{
	int		i;
	int		j;
	int		diff_x;
	int		diff_y;
	static int nbr_match = 0;

	i = 0;
	j = 0;
	while (new_form)
	{
		while (i < 4)
		{
			while (j < 4)
			{
				if (i != j)
				{
					diff_x = new_form->coord[j].x - new_form->coord[i].x;
					diff_y = new_form->coord[j].y - new_form->coord[i].y;
					diff_x = (diff_x < 0) ? diff_x * -1 : diff_x;
					diff_y = (diff_y < 0) ? diff_y * -1 : diff_y;
					if (((new_form->coord[i].x == new_form->coord[j].x) && (diff_y == 1))
						  || ((new_form->coord[i].y == new_form->coord[j].y) && (diff_x == 1)))
							  nbr_match++;
				 }
				 j++;
			 }
			 i++;
			 j = 0;
		}
		if (nbr_match < 6)
		{
			return (1);
		}
		nbr_match = 0;
		new_form = new_form->next;
		j = 0;
		i = 0;
	}
	return (0);
}

void	nbr_blocs(t_tetris **new_form, t_def *form, char *buffer)
{
	int				i;
	size_t			len;
	static	int		j = 0;

	i = 0;
	len = ft_strlen(buffer);
	if (form->row == 0)
		j = 0;
	while (buffer && (buffer = ft_strchr(buffer, '#')))
	{
		(*new_form)->coord[j].x = len - ft_strlen(buffer);
		(*new_form)->coord[j].y = form->row;
		i++;
		buffer++;
		j++;
	}
	form->nbr_blocs += i;
}

static void	check(t_tetris **tetris, t_def *form, char *buffer, int create)
{
	static	t_tetris *new_form = NULL;

	if (form->row == 0)
		new_form = create_form();
	check_column(form, buffer);
	check_char(form, buffer);
	nbr_blocs(&new_form, form, buffer);
	if (form->row > 3 || form->nbr_blocs > 4)
		form->status = -1;
	if (form->status == -1)
	{
		/* putstr_red("Error\n"); */
		ft_putstr("Error\n");
		// free structure
		exit(-1);
	}
	if (form->row == 0)
		add_form(tetris, new_form);
}

int		get_minx(t_tetris *tetris, int mode)
{
	int		i;
	int		min;

	i = 0;
	min = 10;
	while (i < 4)
	{
		if (tetris->coord[i].x < min)
			if ((mode != -1 && tetris->coord[i].y == mode) || mode == -1)
				min = tetris->coord[i].x;
		i++;
	}
	return (min);
}

int		get_miny(t_tetris *tetris)
{
	int		i;
	int		min;

	i = 1;
	min = tetris->coord[0].y;
	while (i < 4)
	{
		if (tetris->coord[i].y < min)
			min = tetris->coord[i].y;
		i++;
	}
	return (min);
}

int		blk_in_line(t_tetris *tetris, int line)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (i < 4)
	{
		if (tetris->coord[i].y == line)
			nbr++;
		i++;
	}
	return (nbr);
}

void	reduc_coord(t_tetris *tetris)
{
	int		i;
	int		min;

	i = 0;
	if ((min = get_minx(tetris, -1)) != 0)
	{
		while (i < 4)
		{
			tetris->coord[i].x -= min;
			tetris->coord[i].y -= min;
			i++;
		}
	}
	i = 0;
	if ((min = get_miny(tetris)) != 0)
	{
		while (i < 4)
		{
			tetris->coord[i].y -= min;
			i++;
		}
	}
}

void	clear_coord(t_tetris *tetris)
{
	while (tetris)
	{
		reduc_coord(tetris);
		tetris = tetris->next;
	}
}

int		main(int ac, char **av)
{
	int			fd;
	int			ret;
	int			create;
	char		*buffer;
	t_def		form;
	t_tetris	*tetris;
	int			step;

	buffer = NULL;
	tetris = NULL;
	create = 1;
	step = 0;
	if (ac != 2 || ((fd = open(av[1], O_RDONLY)) == -1))
	{
		putstr_red("Error\n");
		return (-1);
	}
	ft_memset(&form, 0, sizeof(t_def));
	while ((ret = gnl(fd, &buffer)))
	{
		if (ret == -1 || (form.row == 4 && ft_strcmp(buffer, "")))
		{
			/* putstr_red("Error\n"); */
			ft_putstr("Error\n");
			return (-1);
		}
		if (form.row != 4)
		{
			check(&tetris, &form, buffer, create);
			create++;
		}
		if (form.row + 1 == 5)
		{
			form.status = 0;
			form.nbr_blocs = 0;
		}
		step++;
		form.row = step % 5;
	}
	if (!ft_strcmp(buffer, "") || check_near_block(tetris))
	{
		/* putstr_red("Error\n"); */
		ft_putstr("Error\n");
		return (-1);
	}
	/* print_bloc(tetris); */
	clear_coord(tetris);
	/* print_bloc(tetris); */
	solver(tetris);
	return (0);
}
