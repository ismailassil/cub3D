/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:09:39 by iassil            #+#    #+#             */
/*   Updated: 2024/05/13 17:04:02 by iassil           ###   ########.fr       */
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
			if (map[p->y][p->x] == 'P')
				return ;
			p->x++;
		}
		p->y++;
	}
}

void	ft_init_data(t_cube *data)
{
	t_point	position;

	ft_get_position_of_player(data->info->map, &position);
	data->player.x = (position.x * data->size.width) + (data->size.width / 2);
	data->player.y = (position.y * data->size.height) + (data->size.height / 2);
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.rotation_angle = M_PI_4; // Which direction the player will be facing (N, S, W, E)
	data->player.rotation_speed = ROT_SPEED * (M_PI / 180);
	data->player.fov_angle = 60 * (M_PI / 180); // formula to convert degree to radian
	data->player.wall_strip_width = 1;
	data->player.num_of_rays = data->size.width / data->player.wall_strip_width;
	data->ray = malloc(sizeof(t_ray) * data->player.num_of_rays);
	ft_check_allocation(data->ray);
}

void	ft_get_window_data(t_cube *data)
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
	data->size.width = round(((double)WIDTH / (double)x));
	data->size.win_width = round(WIDTH * data->size.width);
	data->size.height =  round(((double)HEIGHT / (double)y));
	data->size.win_height = round(HEIGHT * data->size.height);
}

void	ft_exit(t_cube *data)
{
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
	exit(FAIL);
}
