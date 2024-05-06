/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:51:46 by iassil            #+#    #+#             */
/*   Updated: 2024/05/06 20:52:00 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_fill_square(t_mlx *data, int x, int y, int color)
{
	int	x_begin;
	int	y_max;
	int	x_max;

	y_max = y * data->pixel.height + data->pixel.height;
	x_max = x * data->pixel.width + data->pixel.width;
	y *= data->pixel.height;
	x *= data->pixel.width;
	x_begin = x;
	(void)color;
	while (y < y_max && y < HEIGHT)
	{
		x = x_begin;
		while (x < x_max && x < WIDTH)
		{
			mlx_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_fill_pixel_player(t_mlx *data, int x, int y, int color)
{
	int	x_begin;
	int	y_max;
	int	x_max;

	y_max = y * data->pixel.height + PLAYER_PX;
	x_max = x * data->pixel.width + PLAYER_PX;
	y *= data->pixel.height;
	x *= data->pixel.width;
	x_begin = x;
	(void)color;
	while (y < y_max && y < HEIGHT)
	{
		x = x_begin;
		while (x < x_max && x < WIDTH)
		{
			mlx_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}
