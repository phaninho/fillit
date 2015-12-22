/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:45:57 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/22 22:20:11 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBIT_H
# define LIBIT_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_coord
{
	int	x;
	int	y;
}					t_coord;

int					checkbuff(char *buff);
int					check_valid(char *buff);
t_coord				**add_coord(char *buff, int i, int x, int y);
char				*fill_buff(int fd);
#endif
