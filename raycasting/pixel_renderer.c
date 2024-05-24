/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:51:46 by iassil            #+#    #+#             */
/*   Updated: 2024/05/24 15:29:10 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_fill_pixel_player(t_cube *data, int color)
{
	t_tools	t;

	ft_init_tools(&t);
	t.y = (data->player.y * MINIMAP);
	t.x = (data->player.x * MINIMAP);
	t.y_max = (t.y + PLAYER_PX) * MINIMAP;
	t.x_max = (t.x + PLAYER_PX) * MINIMAP;
	t.x_begin = t.x;
	while (t.y < t.y_max && t.y < (data->info->ylen * TILE * MINIMAP))
	{
		t.x = t.x_begin;
		while (t.x < t.x_max && t.x < (data->info->xlen * TILE * MINIMAP))
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

	y *= (TILE * MINIMAP);
	x *= (TILE * MINIMAP);
	y_max = y + (TILE * MINIMAP);
	x_max = x + (TILE * MINIMAP);
	x_begin = x;
	while (y < y_max && y < (data->info->ylen * (TILE * MINIMAP)))
	{
		x = x_begin;
		while (x < x_max && x < (data->info->xlen * (TILE * MINIMAP)))
		{
			mlx_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_render_rays(t_cube *cube)
{
	t_line	l;
	int		i;

	i = -1;
	while (++i < NUM_RAYS)
	{
		l.x_begin = (cube->player.x + ((double)PLAYER_PX / 2)) * MINIMAP;
		l.y_begin = (cube->player.y + ((double)PLAYER_PX / 2)) * MINIMAP;
		l.x_end = (cube->rays[i].wall_hit_x * MINIMAP);
		l.y_end = (cube->rays[i].wall_hit_y * MINIMAP);
		ft_draw_line(cube, l, rgba(255, 0, 0, 255));
	}
}
