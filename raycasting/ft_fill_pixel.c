/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:51:46 by iassil            #+#    #+#             */
/*   Updated: 2024/05/11 16:58:55 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_fill_pixel_player(t_mlx *data, int color)
{
	t_tools	t;

	ft_init_tools(&t);
	t.y = data->cur_pos.y_pixels;
	t.x = data->cur_pos.x_pixels;
	t.y_max = t.y + PLAYER_PX;
	t.x_max = t.x + PLAYER_PX;
	t.x_begin = t.x;
	while (t.y < t.y_max && t.y < HEIGHT)
	{
		t.x = t.x_begin;
		while (t.x < t.x_max && t.x < WIDTH)
		{
			mlx_put_pixel(data->img, t.x, t.y, color);
			t.x++;
		}
		t.y++;
	}
}

void	ft_fill_square(t_mlx *data, int x, int y, int color)
{
	int	x_begin;
	int	y_max;
	int	x_max;

	y *= data->pixel.height;
	x *= data->pixel.width;
	y_max = y + data->pixel.height;
	x_max = x + data->pixel.width;
	x_begin = x;
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
