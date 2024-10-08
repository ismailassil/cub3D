/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:41:57 by iassil            #+#    #+#             */
/*   Updated: 2024/07/23 11:14:56 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Its Purpose is to let the angle between 0_deg and 360_deg
static float	ft_normalize_angle(float ray_angle)
{
	float	new_angle;

	new_angle = fmod(ray_angle, (2.0 * M_PI));
	if (new_angle < 0)
		new_angle += (2.0 * M_PI);
	return (new_angle);
}

float	ft_get_point_to_point_distance(float x1, float y1,
	float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

bool	ft_is_a_wall(t_cube *cube, float x, float y)
{
	int	grid_x;
	int	grid_y;

	if (x < 0 || x > (cube->info->xlen * TILE)
		|| y < 0 || y > (cube->info->ylen * TILE))
		return (false);
	grid_x = floor(x / TILE);
	grid_y = floor(y / TILE);
	if (grid_y > (cube->info->ylen - 1))
		grid_y = (cube->info->ylen - 1) - 1;
	if (grid_x >= (int)ft_strlen(cube->info->map[grid_y]))
		grid_x = ft_strlen(cube->info->map[grid_y]) - 1;
	if (grid_x < 0)
		grid_x = 0;
	if (grid_y < 0)
		grid_y = 0;
	if (cube->info->map[grid_y][grid_x] == '1')
		return (true);
	return (false);
}

void	ft_init_directions(t_cube *cube, t_info *f, float rayangle)
{
	f->found_horz_wall = false;
	f->found_vert_wall = false;
	f->py = cube->player.y;
	f->px = cube->player.x;
	f->ray_angle = ft_normalize_angle(rayangle);
	f->ytile = TILE;
	f->xtile = TILE;
	f->win_width = WIDTH * TILE;
	f->win_height = HEIGHT * TILE;
	f->is_down = false;
	if (f->ray_angle > 0 && f->ray_angle < M_PI)
		f->is_down = true;
	f->is_up = !f->is_down;
	f->is_right = false;
	if (f->ray_angle < 0.5 * M_PI || f->ray_angle > 1.5 * M_PI)
		f->is_right = true;
	f->is_left = !f->is_right;
}
