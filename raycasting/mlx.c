/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:05:25 by iassil            #+#    #+#             */
/*   Updated: 2024/05/23 00:05:40 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_key_hook(mlx_key_data_t keycube, void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (keycube.key == MLX_KEY_ESCAPE)
		ft_exit(cube);
	else if (keycube.key == MLX_KEY_UP)
		ft_press_and_release_key(keycube, &cube->player.walk_direction, 1);
	else if (keycube.key == MLX_KEY_DOWN)
		ft_press_and_release_key(keycube, &cube->player.walk_direction, -1);
	else if (keycube.key == MLX_KEY_RIGHT)
		ft_press_and_release_key(keycube, &cube->player.turn_direction, 1);
	else if (keycube.key == MLX_KEY_LEFT)
		ft_press_and_release_key(keycube, &cube->player.turn_direction, -1);
	else
		return ;
	ft_move_player(cube);
}

void	ft_loop_hook(void *param)
{
	t_cube	*cube;
	t_tools	t;

	ft_init_tools(&t);
	cube = (t_cube *)param;
	while (cube->info->map && cube->info->map[t.y])
	{
		t.x = 0;
		while (cube->info->map[t.y][t.x])
		{
			if (cube->info->map[t.y][t.x] == '1')
				ft_fill_square(cube, t.x, t.y, BLACK);
			else
				ft_fill_square(cube, t.x, t.y, rgba(255, 255, 255, 255));
			t.x++;
		}
		t.y++;
	}
	ft_fill_pixel_player(cube, CYAN);
	ft_cast_all_rays(cube);
	ft_render_rays(cube);
	ft_draw_line_of_view(cube, rgba(0, 0, 255, 200));
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
