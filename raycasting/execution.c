/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:05:10 by iassil            #+#    #+#             */
/*   Updated: 2024/05/26 16:33:39 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	mlx_key_hook(cube->mlx, ft_key_hook, cube);
	mlx_loop_hook(cube->mlx, ft_loop_hook, cube);
	mlx_loop(cube->mlx);
	mlx_close_hook(cube->mlx, ft_close_hook, cube);
	ft_destroy_cube(cube);
}
