/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:45:57 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/28 12:01:13 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBIT_H
# define LIBIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>

# define BUFF_SIZE 130

typedef struct		s_coord
{
	int	x;
	int	y;
}					t_coord;

typedef struct		s_data
{
	char	**map;
	char	**map_saved;
	int		map_size;
	int		coord[2];
	char	letter;
	int		total_shapes;
	int		nb_placed;
}					t_data;

/*
** CONTROL
*/

void				control(int ac, char **av, t_coord ***coord, int *param);
int					check_env_exec(int ac, char **av, char **buff, int *fd);
int					check_valid(char *buff);
int					check_diez(t_coord **coord);

/*
** SET DATA
*/

char				*fill_buff(int fd);
int					***set_data(int ***shapes, t_coord **coord);
int					**add_element(t_coord *cord);

/*
** SOLVER
*/

void				solver(int ***shapes, int param);
int					core(int ***shapes, t_data *data, int nbr, int param);

/*
** MAP HANDLING
*/

void				print_map(char **map, int param);
char				**map_alloc(char **map, char ***oldmap, int size);

/*
** PRINT
*/

void				stylised_output(char **pattern);

/*
** TOOL
*/

void				print_data(int ***shapes);

/*
** ERROR
*/

void				ft_error(void);
void				usage_error(int ac);

/*
** CLEAR
*/

void				clean_tab2(char **tab);
void				clean_tab3(int ***tab);
void				clean_tab_t_coord(t_coord **coord);
int					clear_data(t_data *data, char **local_map,
		int param, int mode);
#endif
