/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:40:20 by iassil            #+#    #+#             */
/*   Updated: 2024/05/26 16:40:31 by iassil           ###   ########.fr       */
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

mlx_texture_t	*ft_get_texture(t_cube *cube, t_ray ray)
{
	if (ray.was_hit_vert)
	{
		if (ray.ray_angle < 0.5 * M_PI || ray.ray_angle > 1.5 * M_PI)
			return (cube->textures.east);
		return (cube->textures.west);
	}
	else
	{
		if (ray.ray_angle > 0 && ray.ray_angle < M_PI)
			return (cube->textures.south);
		return (cube->textures.north);
	}
}

float	get_xcord(t_ray ray, mlx_texture_t *img)
{
	if (ray.was_hit_vert)
		return (fmodf(ray.wall_hit_y * (img->width / 64.0), img->width));
	return (fmodf(ray.wall_hit_x * (img->width / 64.0), img->width));
}
