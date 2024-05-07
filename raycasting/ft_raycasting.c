/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:03:19 by iassil            #+#    #+#             */
/*   Updated: 2024/05/07 21:50:21 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	map(t_data *info)
{
	int	i;
	int	num_rows;

	i = 0;
	char	*map[] = {
		"   1111111111111111111111",
		"1110000000110000000000001",
		"   101100000111000000001111111111",
		" 1111000000000000000000001000000011",
		"111111111011000001110000011111111",
		"100000000011000001110111111111111",
		"11111111111101011111110010001",
		"      1111110111     110001",
		"11111111111101011101010010001",
		"11000000110101011100000010001",
		"1P000000000000001100000000001",
		"1000000000000000000010010001",
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

void	ft_raycasting(t_data *info)
{
	t_mlx	*data;

	data = malloc(sizeof(t_mlx));
	ft_check_allocation(data);
	info = malloc(sizeof(t_data));
	ft_check_allocation(info);
	map(info);
	data->info = info;
	ft_get_data(data);
	data->mlx = mlx_init(WIDTH, HEIGHT, "DOOM", false);
	if (!data->mlx)
		ft_mlx_error();
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		ft_mlx_error();
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		ft_mlx_error();
	ft_get_positions(data);
	mlx_key_hook(data->mlx, &ft_key_hook, (void *)data);
	mlx_loop_hook(data->mlx, &ft_loop_hook, (void *)data);
	mlx_loop(data->mlx);
	mlx_close_hook(data->mlx, &ft_close_hook, (void *)data);
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
}
