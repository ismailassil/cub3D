/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:09:39 by iassil            #+#    #+#             */
/*   Updated: 2024/05/26 17:05:19 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_load_textures(t_cube *cube)
{
	// cube->textures.north = mlx_load_png(cube->info->path->north);
	cube->textures.north = mlx_load_png("./textures/hitler.png");
	if (!cube->textures.north)
		(p_error("North texture failed to load", NULL, 1), exit(FAIL));
	// cube->textures.south = mlx_load_png(cube->info->path->south);
	cube->textures.south = mlx_load_png("./textures/nazi.png");
	if (!cube->textures.south)
		(p_error("South texture failed to load", NULL, 1), exit(FAIL));
	// cube->textures.west = mlx_load_png(cube->info->path->west);
	cube->textures.west = mlx_load_png("./textures/wall.png");
	if (!cube->textures.west)
		(p_error("West texture failed to load", NULL, 1), exit(FAIL));
	// cube->textures.east = mlx_load_png(cube->info->path->east);
	cube->textures.east = mlx_load_png("./textures/eagle.png");
	if (!cube->textures.east)
		(p_error("East texture failed to load", NULL, 1), exit(FAIL));
}

void	ft_init_mlx_window(t_cube *cube)
{
	ft_load_textures(cube);
	cube->mlx = mlx_init(WIDTH, HEIGHT, "DOOM", false);
	if (!cube->mlx)
		ft_mlx_error();
	cube->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->img)
		ft_mlx_error();
	if (mlx_image_to_window(cube->mlx, cube->img, 0, 0) < 0)
		ft_mlx_error();
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
	cube->player.ud_direction = 0;
	cube->player.lr_direction = 0;
	// cube->player.rot_angle = ft_check_pl_direction(cube->info->direction);
	cube->player.rot_angle = (3.0 * M_PI) / 2.0;
	cube->player.rotation_speed = ROT_SPEED * (M_PI / 180);
	cube->player.fov_angle = 60 * (M_PI / 180);
	cube->player.wall_strip_width = 1;
	cube->player.num_of_rays = TILE / cube->player.wall_strip_width;
}
