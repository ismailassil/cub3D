/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:40:20 by iassil            #+#    #+#             */
/*   Updated: 2024/05/26 17:42:14 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_get_wall_measurement(t_3dprojection *p)
{
	p->wall_top = (HEIGHT / 2.0) - (p->strip_height / 2.0);
	if (p->wall_top < 0)
		p->wall_top = 0;
	p->wall_bottom = (HEIGHT / 2.0) + (p->strip_height / 2.0);
	if (p->wall_bottom > HEIGHT)
		p->wall_bottom = HEIGHT;
}

void	ft_get_texture(t_cube *cube, t_3dprojection	*p, t_ray ray)
{
	if (ray.was_hit_vert)
	{
		if (ray.ray_angle < 0.5 * M_PI || ray.ray_angle > 1.5 * M_PI)
			p->img = cube->textures.east;
		else
			p->img = cube->textures.west;
	}
	else
	{
		if (ray.ray_angle > 0 && ray.ray_angle < M_PI)
			p->img = cube->textures.south;
		else
			p->img = cube->textures.north;
	}
}

float	get_xcord(t_ray ray, mlx_texture_t *img)
{
	if (ray.was_hit_vert)
		return (fmodf(ray.wall_hit_y * (img->width / (float)TILE), img->width));
	return (fmodf(ray.wall_hit_x * (img->width / (float)TILE), img->width));
}
