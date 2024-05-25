/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:05:25 by iassil            #+#    #+#             */
/*   Updated: 2024/05/25 19:33:34 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_key_hook(mlx_key_data_t keycube, void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (keycube.key == MLX_KEY_ESCAPE)
		ft_exit(cube);
	else if (keycube.key == MLX_KEY_W)
		ft_press_and_release_key(keycube, &cube->player.up_down_direction, 1);
	else if (keycube.key == MLX_KEY_S)
		ft_press_and_release_key(keycube, &cube->player.up_down_direction, -1);
	else if (keycube.key == MLX_KEY_A)
		ft_press_and_release_key(keycube, &cube->player.left_right_direction, -1);
	else if (keycube.key == MLX_KEY_D)
		ft_press_and_release_key(keycube, &cube->player.left_right_direction, 1);
	else if (keycube.key == MLX_KEY_RIGHT)
		ft_press_and_release_key(keycube, &cube->player.turn_direction, 1);
	else if (keycube.key == MLX_KEY_LEFT)
		ft_press_and_release_key(keycube, &cube->player.turn_direction, -1);
	else
		return ;
	ft_move_player(cube);
}

void	ft_render_grid_map(t_cube *cube)
{
	t_tools	t;

	ft_init_tools(&t);
	while (t.y < MAPHEIGHT)
	{
		t.x = 0;
		while (t.x < MAPWIDTH)
		{
			if ((t.x >= 0 && t.x <= 5) || (t.x >= (MAPWIDTH - 5) && t.x <= MAPWIDTH)
					|| (t.y >= 0 && t.y <= 5) || (t.y >= (MAPHEIGHT - 5) && t.y <= MAPHEIGHT))
				t.color = rgba(0, 120, 255, 255);
			else
				t.color = rgba(255, 255, 255, 255);
			mlx_put_pixel(cube->img, t.x, t.y, t.color);
			t.x++;
		}
		t.y++;
	}
	ft_fill_pixel_player(cube, rgba(0, 120, 255, 255));
}

// void	ft_render_grid_map(t_cube *cube)
// {
// 	t_tools	t;

// 	ft_init_tools(&t);
// 	while (cube->info->map && cube->info->map[t.y])
// 	{
// 		t.x = 0;
// 		while (cube->info->map[t.y][t.x])
// 		{
// 			if (cube->info->map[t.y][t.x] == '1')
// 				ft_fill_square(cube, t.x, t.y, BLACK);
// 			else
// 				ft_fill_square(cube, t.x, t.y, rgba(255, 255, 255, 255));
// 			t.x++;
// 		}
// 		t.y++;
// 	}
// 	ft_fill_pixel_player(cube, CYAN);
// }

void	ft_reinit_mlx_window(t_cube *cube)
{
	mlx_delete_image(cube->mlx, cube->img);
	cube->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->img)
		ft_mlx_error();
	if (mlx_image_to_window(cube->mlx, cube->img, 0, 0) < 0)
		ft_mlx_error();
}

void	ft_render_gun(t_cube *cube)
{
	(void)cube;
	// if (mlx_image_to_window(cube->mlx, cube->textures.gun_text, 0, 0) < 0)
	// 	ft_mlx_error();
}

void	ft_loop_hook(void *param)
{
	t_cube	*cube;
	cube = (t_cube *)param;

	ft_reinit_mlx_window(cube);
	ft_cast_walls(cube);
	ft_render_grid_map(cube);
	ft_render_gun(cube);
	/******************************/
	// ft_cast_all_rays(cube);
	// ft_draw_line_of_view(cube, rgba(0, 0, 255, 200));
	/******************************/
}

void	ft_close_hook(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	mlx_delete_image(cube->mlx, cube->img);
	mlx_terminate(cube->mlx);
	exit(SUCCESS);
}

void	ft_mlx_error(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}

void	ft_destroy_mlx(t_cube *data)
{
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
}
