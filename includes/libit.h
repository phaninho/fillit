/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:45:57 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/10 20:46:01 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBIT_H
# define LIBIT_H

# include "libft.h"
# include <fcntl.h>
#include <stdlib.h>

#define BUFF_SIZE 10

typedef struct		s_coord
{
	int	x;
	int	y;
}					t_coord;

typedef struct		s_map
{
	int	start;
	int	nb;
}					t_map;

int					checkbuff(char *buff);
int					check_valid(char *buff);
t_coord				**add_coord(char *buff, size_t i, int x, int y);
char				*fill_buff(int fd);
int					check_diez(t_coord **coord, int x, int y, int valid);
t_coord				*init_tet(t_coord *coord, int y);
int				**add_element(t_coord *coord);
#endif
