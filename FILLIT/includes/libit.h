/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:45:57 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/20 16:51:48 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBIT_H
# define LIBIT_H

# include "libft.h"
# include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFF_SIZE 10

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

int					checkbuff(char *buff);
int					check_valid(char *buff);
t_coord				**add_coord(char *buff, size_t i, int x, int y);
char				*fill_buff(int fd);
int					check_diez(t_coord **coord, int x, int y, int valid);
t_coord				*init_tet(t_coord *coord, int y);
int					**add_element(t_coord *cord);
char				**join_tetra(int ***tetra, int cnt, int i, int size);
//
void				solver(int ***tetra);

// MAP HANDLING
void				print_map(char **map);
char				**map_alloc(char **map, int size, int mode);
char				**map_dup(char **map);

void				ft_error(void);
int					core(int ***tetra, t_data *data, int nbr);

// TOOL
void	print_data(int ***tetra);
#endif
