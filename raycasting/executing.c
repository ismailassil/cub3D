/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:05:10 by iassil            #+#    #+#             */
/*   Updated: 2024/05/23 00:05:10 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_mlx_window(t_cube *cube)
{
	t_size	s;

	s.win_height = cube->info->ylen * TILE;
	s.win_width = cube->info->xlen * TILE;
	// This declaration is for the fixed size for WIDTH and HEIGHT
	// cube->mlx = mlx_init(WIDTH, HEIGHT, "DOOM", false);
	cube->mlx = mlx_init(s.win_width, s.win_height, "DOOM", false);
	if (!cube->mlx)
		ft_mlx_error();
	// This declaration is for the fixed size for WIDTH and HEIGHT
	// cube->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	cube->img = mlx_new_image(cube->mlx, s.win_width, s.win_height);
	if (!cube->img)
		ft_mlx_error();
	if (mlx_image_to_window(cube->mlx, cube->img, 0, 0) < 0)
		ft_mlx_error();
}

void	ft_execute(t_data *info)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	ft_check_allocation(cube);
	info = malloc(sizeof(t_data));
	ft_check_allocation(info);
	/****To be deleted****/
	ft_map(info);
	cube->info = info;
	ft_get_window_data(cube);
	/********************/
	ft_init_mlx_window(cube);
	ft_initialize_data(cube);
	mlx_key_hook(cube->mlx, &ft_key_hook, cube);
	mlx_loop_hook(cube->mlx, &ft_loop_hook, cube);
	mlx_loop(cube->mlx);
	mlx_close_hook(cube->mlx, &ft_close_hook, cube);
	ft_destroy_mlx(cube);
}
