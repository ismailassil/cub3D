/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:57:55 by iassil            #+#    #+#             */
/*   Updated: 2024/07/21 20:19:06 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_get_position_of_player(char **map, t_point *p)
{
	p->y = 0;
	p->x = 0;
	while (map && map[p->y])
	{
		p->x = 0;
		while (map[p->y][p->x])
		{
			if (ft_strchr("NEWS", map[p->y][p->x]))
				return ;
			p->x++;
		}
		p->y++;
	}
}
