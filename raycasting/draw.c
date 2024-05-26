/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:42:43 by iassil            #+#    #+#             */
/*   Updated: 2024/05/26 16:31:51 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_floor_and_ceiling(t_cube *cube)
{
	int			x;
	int			y;
	uint32_t	color;

	// color = cube->colors.ceiling;
	color = rgba(153, 153, 153, MC);
	y = 0;
	while (y < HEIGHT)
	{
		if (y >= HEIGHT / 2)
		{
			// color = cube->colors.floor;
			color = rgba(1, 0, 70, MC);
		}
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(cube->img, x, y, color);
			x++;
		}
		y++;
	}
}

static void	ft_init_draw_line(t_draw_line *l, t_line line)
{
	l->dx = abs(line.x_end - line.x_begin);
	l->dy = abs(line.y_end - line.y_begin);
	if (line.x_begin < line.x_end)
		l->sx = 1;
	else
		l->sx = -1;
	if (line.y_begin < line.y_end)
		l->sy = 1;
	else
		l->sy = -1;
	l->err = l->dx - l->dy;
}

void	ft_draw_line(t_cube *data, t_line line, int color)
{
	t_draw_line	l;

	ft_init_draw_line(&l, line);
	while (line.x_begin != line.x_end || line.y_begin != line.y_end)
	{
		if (line.y_begin >= 0 && line.y_begin < (data->info->ylen * TILE)
			&& line.x_begin >= 0 && line.x_begin < (data->info->xlen * TILE))
			mlx_put_pixel(data->img, line.x_begin, line.y_begin, color);
		l.err2 = 2 * l.err;
		if (l.err2 > -l.dy)
		{
			l.err -= l.dy;
			line.x_begin += l.sx;
		}
		if (l.err2 < l.dx)
		{
			l.err += l.dx;
			line.y_begin += l.sy;
		}
	}
}

void	ft_draw_line_of_view(t_cube *data, int color)
{
	t_line		l;

	l.x_begin = (data->player.x + ((float)PLAYER_PX / 2)) * MINIMAP;
	l.y_begin = (data->player.y + ((float)PLAYER_PX / 2)) * MINIMAP;
	l.x_end = (l.x_begin + cos(data->player.rot_angle) * LINE) * MINIMAP;
	l.y_end = (l.y_begin + sin(data->player.rot_angle) * LINE) * MINIMAP;
	ft_draw_line(data, l, color);
}
