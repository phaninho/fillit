/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 21:04:20 by jmaccion          #+#    #+#             */
/*   Updated: 2015/12/21 22:36:22 by jmaccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*create_form(void)
{
	t_tetris	*form;

	if (!(form = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	ft_memset(form, 0, sizeof(t_tetris));
	return (form);
}

void		add_form(t_tetris **tetris, t_tetris *new_form)
{
	t_tetris	*start;

	if (!tetris)
		return ;
	if (!*tetris)
		*tetris = new_form;
	else
	{
		start = *tetris;
		while (*tetris && (*tetris)->next)
			*tetris = (*tetris)->next;
		(*tetris)->next = new_form;
		*tetris = start;
	}
}

void	print_bloc(t_tetris *tetris)
{
	int		i;

	i = 0;
	while (tetris)
	{
		ft_putendl("-- TETRIMINOS -- ");
		while (i < 4)
		{
			printf("[ x = %d | y = %d ]\n", tetris->coord[i].x,
					tetris->coord[i].y);
			i++;
		}
		ft_putendl("-- END --");
		i = 0;
		tetris = tetris->next;
	}
}
