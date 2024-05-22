/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_projection_of_view.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:42:43 by iassil            #+#    #+#             */
/*   Updated: 2024/05/23 00:15:02 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

	l.x_begin = data->player.x + ((double)PLAYER_PX / 2);
	l.y_begin = data->player.y + ((double)PLAYER_PX / 2);
	l.x_end = l.x_begin + cos(data->player.rotation_angle) * LINE;
	l.y_end = l.y_begin + sin(data->player.rotation_angle) * LINE;
	ft_draw_line(data, l, color);
}

void	ft_draw_line_of_view_60deg(t_cube *data, int color)
{
	t_line		l;
	int			i;
	float		ra;

	i = 0;
	ra = data->player.rotation_angle - (30 * (M_PI / 180));
	if (ra < 0)
		ra += 2 * M_PI;
	if (ra > 2 * M_PI)
		ra -= 2 * M_PI;
	while (i <= NUM_RAYS)
	{
		l.x_begin = data->player.x + ((double)PLAYER_PX / 2);
		l.y_begin = data->player.y + ((double)PLAYER_PX / 2);
		l.x_end = l.x_begin + cos(ra) * LINE;
		l.y_end = l.y_begin + sin(ra) * LINE;
		ft_draw_line(data, l, color);
		ra += (M_PI / 180);
		if (ra < 0)
			ra += 2 * M_PI;
		if (ra > 2 * M_PI)
			ra -= 2 * M_PI;
		i++;
	}
}
