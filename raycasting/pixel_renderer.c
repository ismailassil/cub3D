/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:51:46 by iassil            #+#    #+#             */
/*   Updated: 2024/05/24 21:48:48 by iassil           ###   ########.fr       */
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

void	ft_draw_ray(t_cube *cube, int i, int color)
{
	t_line	l;

	l.x_begin = (cube->player.x + ((float)PLAYER_PX / 2)) * MINIMAP;
	l.y_begin = (cube->player.y + ((float)PLAYER_PX / 2)) * MINIMAP;
	l.x_end = (cube->rays[i].wall_hit_x * MINIMAP);
	l.y_end = (cube->rays[i].wall_hit_y * MINIMAP);
	ft_draw_line(cube, l, color);
}

void	ft_3dprojection(t_cube *cube, int strip_id, int color)
{
	float	ply_to_proj_plane;
	float	strip_wall_height;
	float	corrected_angle;
	int		walltop_to_px;
	int		wallbottom_to_px;

	corrected_angle = cube->rays[strip_id].distance * cos(cube->rays[strip_id].ray_angle - cube->player.rotation_angle);
	ply_to_proj_plane = ((float)WIDTH / 2) / tan(cube->player.fov_angle / 2);
	strip_wall_height = ((TILE) / corrected_angle) * ply_to_proj_plane;

	walltop_to_px = (HEIGHT / 2) - ((int)strip_wall_height / 2);
	if (walltop_to_px < 0)
		walltop_to_px = 0;

	wallbottom_to_px = (HEIGHT / 2) + ((int)strip_wall_height / 2);
	if (wallbottom_to_px > HEIGHT)
		wallbottom_to_px = HEIGHT;

	while (walltop_to_px < wallbottom_to_px)
	{
		mlx_put_pixel(cube->img, strip_id, walltop_to_px, color);
		walltop_to_px++;
	}
}

void	ft_cast_walls(t_cube *cube)
{
	float	ray_angle;
	int		strip_id;
	t_info	f;

	strip_id = -1;
	ray_angle = cube->player.rotation_angle - (cube->player.fov_angle / 2);
	while (++strip_id < WIDTH)
	{
		ft_init_directions(cube, &f, ray_angle);
		f.horz_dist = ft_get_horizontal_distance(cube, &f);
		f.vert_dist = ft_get_vertical_distance(cube, &f);
		ft_fill_ray_data(cube, &f, strip_id);
		ft_draw_ray(cube, strip_id, rgba(255, 0, 0, 255));
		ft_3dprojection(cube, strip_id, rgba(100, 100, 20, 255));
		ray_angle += cube->player.fov_angle / WIDTH;
	}
}
