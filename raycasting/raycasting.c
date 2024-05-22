/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:03:19 by iassil            #+#    #+#             */
/*   Updated: 2024/05/23 00:00:42 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_cast_all_rays(t_cube *cube)
{
	double	ray_angle;
	int		i;

	ray_angle = cube->player.rotation_angle - (cube->player.fov_angle / 2);
	i = -1;
	while (++i < NUM_RAYS)
	{
		ft_cast_ray(cube, i, ray_angle);
		ray_angle += cube->player.fov_angle / NUM_RAYS;
	}
}

void	ft_cast_ray(t_cube *cube, int id, double rayangle)
{
	t_info	f;

	ft_init_directions(cube, &f, rayangle);
	f.horz_dist = ft_get_horizontal_dist(cube, &f);
	f.vert_dist = ft_get_vertical_dist(cube, &f);
	ft_fill_ray_data(cube, &f, id);
}
