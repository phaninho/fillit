/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 18:09:20 by jmaccion          #+#    #+#             */
/*   Updated: 2015/12/22 23:30:01 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	check_column(t_def *form, char *buffer)
{
	if (ft_strlen(buffer) > 4)
	{
		printf("size: %lu\n", ft_strlen(buffer));
		printf("buffer: '%s'", buffer);
		form->status = -1;
		putstr_red("bad column\n");
	}
}

void	check_char(t_def *form, char *buffer)
{
	int		i;

	i = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i] != '.' && buffer[i] != '#')
		{
			form->status = -1;
			putstr_red("bad char found\n");
			return ;
		}
		i++;
	}
}
/*  */
/* int		check_near_block_2(t_coord *form, t_tetris *ref) */
/* { */
/* 	int		i; */
/* 	int		diff_x; */
/* 	int		diff_y; */
/*  */
/* 	i = 0; */
/* 	while (i < 4) */
/* 	{ */
/* 		diff_x = form->x - ref->coord[i].x; */
/* 		diff_y = form->y - ref->coord[i].y; */
/* 		diff_x = (diff_x < 0) ? diff_x * -1 : diff_x; */
/* 		diff_y = (diff_y < 0) ? diff_y * -1 : diff_y; */
/* 		if (((form->x == ref->coord[i].x) && (diff_y == 1)) */
/* 			|| ((form->y == ref->coord[i].y) && (diff_x == 1))) */
/* 		{ */
/* 			#<{(| printf("current[%d-%d]\n",form->x, form->y); |)}># */
/* 			#<{(| printf("ref[%d-%d]\n",ref->coord[i].x, ref->coord[i].y); |)}># */
/* 			#<{(| ft_putstr("OK\n"); |)}># */
/* 			#<{(| return (0); |)}># */
/* 		} */
/* 		i++; */
/* 	} */
/* 	#<{(| ft_putstr("NOPE\n"); |)}># */
/* 	return (1); */
/* } */

int		check_near_block(t_tetris *new_form)
{
	int		i;
	int		j;
	int		diff_x;
	int		diff_y;
	static int nbr_match = 0;

	i = 0;
	j = 0;
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
	return ((nbr_match < 6) ? 1 : 0 );
}

void	nbr_blocs(t_tetris **new_form, t_def *form, char *buffer)
{
	int				i;
	char			*tmp;
	size_t			len;
	static	int		j = 0;

	i = 0;
	tmp = buffer;
	len = ft_strlen(buffer);
	while (buffer && (buffer = ft_strchr(buffer, '#')))
	{
		/* printf("len: %lu\nbuffer: %lu\n\n", len, ft_strlen(buffer)); */
		/* printf("row: %d\n", form->row); */
		(*new_form)->coord[j].x = len - ft_strlen(buffer);
		(*new_form)->coord[j].y = form->row;
		i++;
		buffer++;
		j++;
	}
	form->nbr_blocs = i;
}

static void	check(t_tetris **tetris, t_def *form, char *buffer, int create)
{
	static	t_tetris *new_form = NULL;

	if (create == 1)
		new_form = create_form();
	check_column(form, buffer);
	check_char(form, buffer);
	nbr_blocs(&new_form, form, buffer);
	/* add_form(tetris, new_form); */
	/* printf("row: %d\n", form->row); */
	/* print_bloc(*tetris); */
	if (form->row > 3 || form->nbr_blocs > 4)
	{
		printf("HERE\n");
		form->status = -1;
	}
	if (form->status == -1)
	{
		putstr_red("Error 12\n");
		// free structure
		exit(-1);
	}
	if (create == 1)
		add_form(tetris, new_form);
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
	if (ac != 2)
	{
		putstr_red("Error\n");
		return (-1);
	}
	ft_memset(&form, 0, sizeof(t_def));
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		putstr_red("Error\n");
		return (-1);
	}
	while ((ret = gnl(fd, &buffer)))
	{
		printf("step:%d - buffer: '%s'\n", step, buffer);
		if (ret == -1)
		{
			putstr_red("Error 43\n");
			return (-1);
		}
		if (form.row == 4 && ft_strcmp(buffer, ""))
		{
			/* printf("form.row: %d\n", form.row); */
			printf("buffer: '%s' - %d\n", buffer, step);
			putstr_red("Error 42\n");
			return (-1);
		}
		if (form.row == 5)
		{
			/* ft_memset(&form, 0, sizeof(t_def)); */
			form.status = 0;
			form.nbr_blocs = 0;
			form.row = 0;
			create = 1;
		}
		if (form.row != 4)
		{
			check(&tetris, &form, buffer, create);
			create++;
			/* if (!ft_strcmp(buffer, "")) */
			/* 	break ; */
		}
		form.row++;
		step++;
		/* ft_strdel(&buffer); */
		/* ft_memset(buffer, 0, ft_strlen(buffer)); */
	}
	if (check_near_block(tetris))
	{
		putstr_red("Error 1\n");
		return (-1);
	}
	print_bloc(tetris);
}
