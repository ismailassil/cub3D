/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:03:19 by iassil            #+#    #+#             */
/*   Updated: 2024/07/21 19:58:16 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_walls_projection(t_cube *cube)
{
	t_ray	ray;
	float	ray_angle;
	int		strip_id;

	strip_id = 0;
	ray_angle = cube->player.rot_angle - (cube->player.fov_angle / 2);
	ft_draw_floor_and_ceiling(cube);
	while (strip_id < WIDTH)
	{
		ray = ft_get_distance(cube, ray_angle);
		ft_3dprojection(cube, ray, strip_id);
		ray_angle += cube->player.fov_angle / WIDTH;
		strip_id++;
	}
}

t_ray	ft_get_distance(t_cube *cube, float ray_angle)
{
	t_info	f;

	ft_init_directions(cube, &f, ray_angle);
	f.horz_dist = ft_get_horizontal_distance(cube, &f);
	f.vert_dist = ft_get_vertical_distance(cube, &f);
	return (ft_fill_ray_data(&f));
}

void	ft_3dprojection(t_cube *cube, t_ray ray, int strip_id)
{
	t_3dprojection	p;

	p.corrected_angle = ray.distance
		* cos(ray.ray_angle - cube->player.rot_angle);
	p.ply_to_proj_plane = ((float)WIDTH / 2) / tan(cube->player.fov_angle / 2);
	p.strip_wall_height = ((TILE) / p.corrected_angle) * p.ply_to_proj_plane;
	p.strip_height = p.strip_wall_height;
	ft_get_wall_measurement(&p);
	ft_get_texture(cube, &p, ray);
	p.img_px = (int32_t *)p.img->pixels;
	p.offset = (float)(p.img->height / p.strip_wall_height);
	p.xcord = get_xcord(ray, p.img);
	p.ycord = (p.wall_top - (HEIGHT / 2.0) + (p.strip_wall_height / 2))
		* p.offset;
	if (p.ycord < 0)
		p.ycord = 0;
	while (p.wall_top < p.wall_bottom)
	{
		mlx_put_pixel(cube->img, strip_id, p.wall_top, \
			ft_reverse_color(p.img_px[((int)p.ycord * p.img->width)
				+ (int)p.xcord]));
		p.ycord += p.offset;
		p.wall_top++;
	}
}
