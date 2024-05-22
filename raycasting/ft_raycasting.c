/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:03:19 by iassil            #+#    #+#             */
/*   Updated: 2024/05/22 23:33:53 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_map(t_data *info)
{
	int	i;
	int	num_rows;

	i = 0;
	char	*map[] = {
		"           1111111111111111111111",
		"11100011111110000000000001",
		"   111100000111000000001111111111",
		" 1111000000000000000000001000000011",
		"111111111011000001110000011111111",
		"100000000011000001110111111111111",
		"11111111111101011111110010001",
		"      1111110111     110001",
		"11111111111101011101010010001",
		"11000000110101011100000010001",
		"1P1000000000000001100000000001",
		"10000000000000000000010010001",
		"110000011101111111110111100111",
		"11110111011        101101010111",
		"   1000111111111111111111111111",
		"   1000111111111111111111111111",
		"   1111111111111111111111111111"
	};
	num_rows = sizeof(map) / sizeof(map[0]);
	info->map = malloc((num_rows + 1) * sizeof(char *));
	ft_check_allocation(info->map);
	while (i < num_rows)
	{
		info->map[i] = ft_strdup(map[i]);
		i++;
	}
	info->map[i] = 0;
}

void	ft_destroy_mlx(t_cube *data)
{
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
}

void	ft_raycasting(t_data *info)
{
	t_cube	*cube;
	t_size	s;

	cube = malloc(sizeof(t_cube));
	ft_check_allocation(cube);
	info = malloc(sizeof(t_data));
	ft_check_allocation(info);
	ft_map(info);
	cube->info = info;
	ft_get_window_data(cube);
	// This declaration is for the fixed size for WIDTH and HEIGHT
	// cube->mlx = mlx_init(WIDTH, HEIGHT, "DOOM", false);
	s.win_height = cube->info->ylen * TILE;
	s.win_width = cube->info->xlen * TILE;
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
	ft_init_data(cube);
	mlx_key_hook(cube->mlx, &ft_key_hook, cube);
	mlx_loop_hook(cube->mlx, &ft_loop_hook, cube);
	mlx_loop(cube->mlx);
	mlx_close_hook(cube->mlx, &ft_close_hook, cube);
	ft_destroy_mlx(cube);
}
