/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:45:57 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/24 23:17:06 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBIT_H
# define LIBIT_H

# include "libft.h"
# include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFF_SIZE 130

typedef struct		s_coord
{
	int	x;
	int	y;
}					t_coord;

typedef struct		s_data
{
	// si int		total_shapes en 1er -> SEGV;
	char	**map;
	char	**map_saved;
	int		map_size;
	int		coord[2];
	char	letter;
	int		total_shapes;
}					t_data;

// CONTROL
void				control(int ac, char **av, t_coord ***coord, int i);
int					check_valid(char *buff);
int					check_diez(t_coord **coord, int x, int y, int valid);
// SET DATA
int					***set_data(int ***shapes, t_coord **coord);
int					**add_element(t_coord *cord);
// SOLVER
void				solver(int ***shapes);
int					core(int ***shapes, t_data *data, int nbr, int status);
// MAP HANDLING
void				print_map(char **map);
char				**map_alloc(char **map, int size);
// TOOL
void	print_data(int ***shapes);
// ERROR
void				space_error(int i, char buff);
void				ft_error(void);
#endif
