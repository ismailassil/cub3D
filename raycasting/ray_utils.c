/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:09:39 by iassil            #+#    #+#             */
/*   Updated: 2024/05/06 21:09:23 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_get_position_of_player(char **map, t_point *p)
{
	p->y = 0;
	p->x = 0;
	while (map && map[p->y])
	{
		p->x = 0;
		while (map[p->y][p->x])
		{
			if (map[p->y][p->x] == 'P')
				return ;
			p->x++;
		}
		p->y++;
	}
}

void	ft_get_data(t_mlx *data)
{
	int	x;
	int	y;
	int	width;
	
	x = 0;
	y = 0;
	width = 0;
	while (data->info->map && data->info->map[y])
	{
		width = ft_strlen(data->info->map[y]);
		if (width > x)
			x = width;
		y++;
	}
	data->pixel.width = round(((double)WIDTH / (double)x));
	data->pixel.height =  round(((double)HEIGHT / (double)y));
}

void	ft_exit(t_mlx *data)
{
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
	exit(FAIL);
}
