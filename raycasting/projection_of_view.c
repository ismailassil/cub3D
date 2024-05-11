/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_of_view.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:42:43 by iassil            #+#    #+#             */
/*   Updated: 2024/05/11 19:49:17 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void ft_draw_line(t_mlx *data, t_line line, int color)
{
	int dx = abs(line.x_end - line.x_begin);
	int dy = abs(line.y_end - line.y_begin);
	int sx = (line.x_begin < line.x_end) ? 1 : -1;
	int sy = (line.y_begin < line.y_end) ? 1 : -1;
	int err = dx - dy;

	while (line.x_begin != line.x_end || line.y_begin != line.y_end)
	{
		if (line.y_begin >= 0 && line.y_begin < data->pixel.win_height
			&& line.x_begin >= 0 && line.x_begin < data->pixel.win_width)
			mlx_put_pixel(data->img, line.x_begin, line.y_begin, color);
		int err2 = 2 * err;
		if (err2 > -dy)
		{
			err -= dy;
			line.x_begin += sx;
		}
		if (err2 < dx)
		{
			err += dx;
			line.y_begin += sy;
		}
	}
}

void	ft_draw_line_of_view(t_mlx *data, int color)
{
	t_line	l;

	l.x_begin = data->cur_pos.x_pixels + (PLAYER_PX / 2);
	l.y_begin = data->cur_pos.y_pixels;
	l.x_end = l.x_begin + cos(data->cur_pos.rotation_angle) * LINE;
	l.y_end = l.y_begin + sin(data->cur_pos.rotation_angle) * LINE;
	ft_draw_line(data, l, color);
}
