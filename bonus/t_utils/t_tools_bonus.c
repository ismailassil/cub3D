/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tools_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:38:09 by iassil            #+#    #+#             */
/*   Updated: 2024/07/23 10:29:26 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	ft_init_tools(t_tools *t)
{
	t->i = 0;
	t->j = 0;
	t->ea = 0;
	t->no = 0;
	t->so = 0;
	t->ea = 0;
	t->we = 0;
	t->floor = 0;
	t->ceiling = 0;
	t->error = 0;
	t->flag = 0;
	t->x = 0;
	t->y = 0;
	t->nextpx_x = 0;
	t->nextpx_y = 0;
	t->current_x = 0;
	t->current_y = 0;
	t->move_step = 0;
	t->color = 0;
}
