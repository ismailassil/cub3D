/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_of_view.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:42:43 by iassil            #+#    #+#             */
/*   Updated: 2024/05/11 12:37:50 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

typedef struct s_line
{
	int	x_pixel_begin;
	int	y_pixel_begin;
	int	x_pixel_end;
	int	y_pixel_end;
}		t_line;

void draw_line(t_mlx *data, t_line line, int color);

void	ft_draw_line_of_view(t_mlx *data, int color)
{
	t_line	l;

	l.x_pixel_end = data->cur_pos.x_pixels + cos(data->cur_pos.rotation_angle * 30);
	l.y_pixel_end = data->cur_pos.y_pixels + sin(data->cur_pos.rotation_angle * 30);
	l.x_pixel_begin = data->cur_pos.x_pixels;
	l.y_pixel_begin = data->cur_pos.y_pixels + (PLAYER_PX / 2);
	draw_line(data, l, color);
}

void draw_line(t_mlx *data, t_line line, int color)
{
    int dx = abs(line.x_pixel_end - line.x_pixel_begin);
    int dy = abs(line.y_pixel_end - line.y_pixel_begin);
    int sx = (line.x_pixel_begin < line.x_pixel_end) ? 1 : -1;
    int sy = (line.y_pixel_begin < line.y_pixel_end) ? 1 : -1;
    int err = dx - dy;

    while (line.x_pixel_begin != line.x_pixel_end || line.y_pixel_begin != line.y_pixel_end)
    {
        if (line.y_pixel_begin >= 0 && line.y_pixel_begin < data->pixel.win_height
            && line.x_pixel_begin >= 0 && line.x_pixel_begin < data->pixel.win_width)
            mlx_put_pixel(data->img, line.x_pixel_begin, line.y_pixel_begin, color);
        int err2 = 2 * err;
        if (err2 > -dy)
        {
            err -= dy;
            line.x_pixel_begin += sx;
        }
        if (err2 < dx)
        {
            err += dx;
            line.y_pixel_begin += sy;
        }
    }
}
