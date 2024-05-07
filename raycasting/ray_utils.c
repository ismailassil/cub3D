/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:09:39 by iassil            #+#    #+#             */
/*   Updated: 2024/05/07 21:52:28 by iassil           ###   ########.fr       */
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

void	ft_get_positions(t_mlx *data)
{
	ft_get_position_of_player(data->info->map, &data->position);
	data->position.x_move = 0;
	data->position.y_move = 0;
	data->cur_pos.x_map = data->position.x;
	data->cur_pos.y_map = data->position.y;
	data->cur_pos.x_pixels = data->position.x * data->pixel.width;
	data->cur_pos.y_pixels = data->position.y * data->pixel.height;
	// printf("================\n");
	// printf("x_map::{%d}, y_map::{%d}, x_pixel::{%d}, y_pixel::{%d}\n", \
	// 	data->cur_pos.x_map, data->cur_pos.y_map, data->cur_pos.x_pixels, data->cur_pos.y_pixels);
	// printf("================\n");
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
