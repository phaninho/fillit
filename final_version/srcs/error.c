/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:42:03 by stmartin          #+#    #+#             */
/*   Updated: 2016/01/24 21:58:11 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libit.h"

void	space_error(int i, char buff)
{
	if (i == 0 && buff == '\n')
		ft_error();
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(1);
}