/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:05:25 by iassil            #+#    #+#             */
/*   Updated: 2024/05/26 16:36:55 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_reinit_mlx_window(t_cube *cube);

void	ft_key_hook(mlx_key_data_t keycube, void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (keycube.key == MLX_KEY_ESCAPE)
		ft_exit(cube);
	else if (keycube.key == MLX_KEY_W)
		ft_press_and_release_key(keycube, &cube->player.ud_direction, 1);
	else if (keycube.key == MLX_KEY_S)
		ft_press_and_release_key(keycube, &cube->player.ud_direction, -1);
	else if (keycube.key == MLX_KEY_A)
		ft_press_and_release_key(keycube, &cube->player.lr_direction, -1);
	else if (keycube.key == MLX_KEY_D)
		ft_press_and_release_key(keycube, &cube->player.lr_direction, 1);
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

	cube = (t_cube *)param;
	ft_reinit_mlx_window(cube);
	ft_walls_projection(cube);
	ft_render_minimap(cube);
}

void	ft_close_hook(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	ft_destroy_cube(cube);
	exit(SUCCESS);
}

void	ft_reinit_mlx_window(t_cube *cube)
{
	mlx_delete_image(cube->mlx, cube->img);
	cube->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->img)
		ft_mlx_error();
	if (mlx_image_to_window(cube->mlx, cube->img, 0, 0) < 0)
		ft_mlx_error();
}
