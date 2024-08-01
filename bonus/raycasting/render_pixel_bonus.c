/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:51:46 by iassil            #+#    #+#             */
/*   Updated: 2024/07/23 10:29:26 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	ft_fill_pixel_player(t_cube *data, int color)
{
	t_tools	t;

	ft_init_tools(&t);
	t.y = data->player.y;
	t.x = data->player.x;
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

void	ft_fill_square(t_cube *data, int x, int y, int color)
{
	int	x_begin;
	int	y_max;
	int	x_max;

	y *= TILE;
	x *= TILE;
	y_max = y + TILE;
	x_max = x + TILE;
	x_begin = x;
	while (y < y_max && y < (data->info->ylen * TILE))
	{
		x = x_begin;
		while (x < x_max && x < (data->info->xlen * TILE))
		{
			mlx_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_draw_ray(t_cube *cube, t_ray ray, int color)
{
	t_line	l;

	l.x_begin = (cube->player.x + ((float)PLAYER_PX / 2));
	l.y_begin = (cube->player.y + ((float)PLAYER_PX / 2));
	l.x_end = ray.wall_hit_x;
	l.y_end = ray.wall_hit_y;
	ft_draw_line(cube, l, color);
}
