/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:03:19 by iassil            #+#    #+#             */
/*   Updated: 2024/05/05 21:52:17 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	map(t_data *info)
{
	int	i;
	int	num_rows;

	i = 0;
	num_rows = 15;
	char	*map[] = {
		"   1111111111111111111111",
		"1110000000110000000000001",
		"   101100000111000000001111111111",
		"1111000000000000000000001",
		"111111111011000001110000011111111",
		"100000000011000001110111111111111",
		"11110111111101011111110010001",
		"      1111110111     110001",
		"11110111111101011101010010001",
		"11000000110101011100000010001",
		"10000000000000001100000000001",
		"1000000000000000001010010001",
		"11000001110101011111011110N0111",
		"11110111011        01111010001",
		"    1  111111111111111111111"
	};
	info->map = malloc((num_rows + 1) * sizeof(char *));
	ft_check_allocation(info->map);
	while (i < num_rows)
	{
    	info->map[i] = ft_strdup(map[i]);
		i++;
	}
	info->map[i] = 0;
}

void	ft_get_data(t_mlx *data)
{
	int	w;
	int	h;

	h = 0;
	w = 0;
	
	data->width = 0;
	while (data->info->map && data->info->map[h])
	{
		w = ft_strlen(data->info->map[h]);
		if (w > data->width)
			data->width = w;
		h++;
	}
	data->height = h * PIXEL;
	data->width *= PIXEL;
}

void	ft_fill_square(t_mlx *data, int x, int y, int color)
{
	int	y_max;
	int	x_max;

	y_max = y * PIXEL;
	x_max = x * PIXEL;
	while (y < y_max)
	{
		while (x < x_max)
		{
			
		}
	}
}

void	ft_put_pixel_in_window(t_mlx *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->info->map && data->info->map[y])
	{
		x = 0;
		while (data->info->map[y][x])
		{
			if (data->info->map[y][x] == '1')
				ft_fill_square(data, x, y, BLACK);
			else if (data->info->map[y][x] == 'N')
				ft_fill_square(data, x, y, BLUE);
			else
				ft_fill_square(data, x, y, WHITE);
			x++;
		}
		y++;
	}
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
	data->mlx = mlx_init(data->width, data->height, "CUB3D", false);
	if (!data->mlx)
		mlx_error();
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img)
		mlx_error();
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		mlx_error();
	ft_put_pixel_in_window(data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
