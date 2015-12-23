/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 17:42:16 by jmaccion          #+#    #+#             */
/*   Updated: 2015/12/21 22:13:36 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>


typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_tetris
{
	t_coord				coord[4];
	struct s_tetris		*next;
}				t_tetris;

typedef	struct	s_def
{
	int		row;
	int		nbr_blocs;
	int		status;
}			t_def;

void		putstr_red(char *str);
t_tetris	*create_form(void);
void		add_form(t_tetris **tetris, t_tetris *new_form);
void		print_bloc(t_tetris *tetris);
#endif

