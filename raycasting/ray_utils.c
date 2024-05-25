/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:09:39 by iassil            #+#    #+#             */
/*   Updated: 2024/05/25 17:37:07 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	ft_check_pl_direction(char direction)
{
	float	angle;

	angle = 0.0;
	if (direction == 'N')
		angle = (3.0 * M_PI) / 2.0;
	else if (direction == 'W')
		angle = M_PI;
	else if (direction == 'E')
		angle = 0.0;
	else if (direction == 'S')
		angle = M_PI / 2.0;
	return (angle);
}

void	ft_initialize_data(t_cube *cube)
{
	t_point	position;

	ft_get_position_of_player(cube->info->map, &position);
	cube->player.x = (position.x * TILE) + ((float)TILE / 2);
	cube->player.y = (position.y * TILE) + ((float)TILE / 2);
	cube->player.turn_direction = 0;
	cube->player.up_down_direction = 0;
	cube->player.left_right_direction = 0;
	// Which direction the player will be facing (N, S, W, E)
	// cube->player.rotation_angle = ft_check_pl_direction(cube->info->direction);
	// This is north
	cube->player.rotation_angle = (3.0 * M_PI) / 2.0;
	cube->player.rotation_speed = ROT_SPEED * (M_PI / 180);
	// formula to convert degree to radian
	cube->player.fov_angle = 60 * (M_PI / 180);
	cube->player.wall_strip_width = 1;
	cube->player.num_of_rays = TILE / cube->player.wall_strip_width;
	cube->rays = malloc(sizeof(t_ray) * NUM_RAYS);
	ft_check_allocation(cube->rays);
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
	data->info->ylen = y;
	data->info->xlen = x;
	data->size.width = round(((float)WIDTH / (float)x));
	data->size.win_width = round(WIDTH * data->size.width);
	data->size.height = round(((float)HEIGHT / (float)y));
	data->size.win_height = round(HEIGHT * data->size.height);
}

void	ft_exit(t_cube *data)
{
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
	exit(FAIL);
}
