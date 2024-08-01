/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:35:41 by iassil            #+#    #+#             */
/*   Updated: 2024/07/23 11:23:25 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	ft_get_horizontal_distance(t_cube *cube, t_info *f)
{
	f->y_intersection = floor(f->py / f->ytile) * f->ytile;
	if (f->is_down)
		f->y_intersection += f->ytile;
	f->x_intersection = f->px + ((f->y_intersection - f->py) \
			/ tan(f->ray_angle));
	f->ystep = (float)f->ytile;
	if (f->is_up)
		f->ystep *= -1;
	f->xstep = (float)f->ystep / tan(f->ray_angle);
	if (f->is_left && f->xstep > 0)
		f->xstep *= -1;
	if (f->is_right && f->xstep < 0)
		f->xstep *= -1;
	f->next_horz_x = f->x_intersection;
	f->next_horz_y = f->y_intersection;
	ft_check_horizontal_wall_collision(cube, f);
	if (!f->found_horz_wall)
		return (__DBL_MAX__);
	return (ft_get_point_to_point_distance(f->px, f->py, \
		f->horzwallx, f->horzwally));
}

void	ft_check_horizontal_wall_collision(t_cube *cube, t_info *f)
{
	float	xtocheck;
	float	ytocheck;

	while (f->next_horz_x >= 0 && f->next_horz_x <= f->win_width
		&& f->next_horz_y >= 0 && f->next_horz_y <= f->win_height)
	{
		xtocheck = f->next_horz_x;
		ytocheck = f->next_horz_y;
		ytocheck -= f->is_up;
		if (ft_is_a_wall(cube, xtocheck, ytocheck))
		{
			f->found_horz_wall = true;
			f->horzwallx = f->next_horz_x;
			f->horzwally = f->next_horz_y;
			break ;
		}
		else
		{
			f->next_horz_y += f->ystep;
			f->next_horz_x += f->xstep;
		}
	}
}

float	ft_get_vertical_distance(t_cube *cube, t_info *f)
{
	f->x_intersection = floor(f->px / f->xtile) * f->xtile;
	if (f->is_right)
		f->x_intersection += f->xtile;
	f->y_intersection = f->py + ((f->x_intersection - f->px) \
			* tan(f->ray_angle));
	f->xstep = (float)f->xtile;
	if (f->is_left)
		f->xstep *= -1;
	f->ystep = (float)f->xstep * tan(f->ray_angle);
	if (f->is_up && f->ystep > 0)
		f->ystep *= -1;
	if (f->is_down && f->ystep < 0)
		f->ystep *= -1;
	f->next_vert_x = f->x_intersection;
	f->next_vert_y = f->y_intersection;
	ft_check_vertical_wall_collision(cube, f);
	if (!f->found_vert_wall)
		return (__DBL_MAX__);
	return (ft_get_point_to_point_distance(f->px, f->py, \
		f->vertwallx, f->vertwally));
}

void	ft_check_vertical_wall_collision(t_cube *cube, t_info *f)
{
	float	xtocheck;
	float	ytocheck;

	while (f->next_vert_x >= 0 && f->next_vert_x <= f->win_width
		&& f->next_vert_y >= 0 && f->next_vert_y <= f->win_height)
	{
		xtocheck = f->next_vert_x;
		xtocheck -= f->is_left;
		ytocheck = f->next_vert_y;
		if (ft_is_a_wall(cube, xtocheck, ytocheck))
		{
			f->found_vert_wall = true;
			f->vertwallx = f->next_vert_x;
			f->vertwally = f->next_vert_y;
			break ;
		}
		else
		{
			f->next_vert_y += f->ystep;
			f->next_vert_x += f->xstep;
		}
	}
}

t_ray	ft_fill_ray_data(t_info *f)
{
	t_ray	ray;

	if (f->vert_dist < f->horz_dist)
	{
		ray.distance = f->vert_dist;
		ray.wall_hit_x = f->vertwallx;
		ray.wall_hit_y = f->vertwally;
		ray.was_hit_vert = true;
	}
	else
	{
		ray.distance = f->horz_dist;
		ray.wall_hit_x = f->horzwallx;
		ray.wall_hit_y = f->horzwally;
		ray.was_hit_vert = false;
	}
	ray.ray_angle = f->ray_angle;
	ray.is_down = f->is_down;
	ray.is_up = f->is_up;
	ray.is_left = f->is_left;
	ray.is_right = f->is_right;
	return (ray);
}
