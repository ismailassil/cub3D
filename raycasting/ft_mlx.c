/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:10:19 by iassil            #+#    #+#             */
/*   Updated: 2024/05/13 17:01:50 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_press_and_release_key(mlx_key_data_t keycube, int *cube, int value)
{
	if (keycube.action == MLX_RELEASE)
		*cube = 0;
	else
		*cube = value;
}

// Its purpose is to let the angle between 0_deg and 360_deg
double	ft_normalize_angle(double ray_angle)
{
	double new_angle;

	new_angle = fmod(ray_angle, (2.0 * M_PI));
	if (new_angle < 0)
		new_angle += (2.0 * M_PI);
	return (new_angle);
}

bool	ft_is_a_wall(t_cube *cube, double x, double y)
{
	int	grid_x;
	int	grid_y;

	if (x < 0 || x > (cube->info->xlen * TILE) || y < 0 || y > (cube->info->ylen * TILE))
		return (false);
	grid_x = floor(x / TILE);
	grid_y = floor(y / TILE);
	if (grid_y > 16)
		grid_y = cube->info->ylen - 1;
	if (grid_x > (int)ft_strlen(cube->info->map[grid_y]) - 1)
		grid_x = ft_strlen(cube->info->map[grid_y]) - 1;
	if (cube->info->map[grid_y][grid_x] == '1')
		return (true);
	return (false);
}

double	ft_get_point_to_point_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ft_init_directions(t_cube *cube, t_info *f, double rayangle)
{
	f->found_horz_wall = false;
	f->found_vert_wall = false;
	f->py = cube->player.y;
	f->px = cube->player.x;
	f->ray_angle = ft_normalize_angle(rayangle);
	f->ytile = TILE;
	f->xtile = TILE;
	f->win_width = cube->info->xlen * TILE;
	f->win_height = cube->info->ylen * TILE;
	f->is_down = false;
	if (f->ray_angle > 0 && f->ray_angle < M_PI)
		f->is_down = true;
	f->is_up = !f->is_down;
	f->is_right = false;
	if (f->ray_angle < 0.5 * M_PI || f->ray_angle > 1.5 * M_PI)
		f->is_right = true;
	f->is_left = !f->is_right;
}

void	ft_check_horizontal_wall_collision(t_cube *cube, t_info *f)
{
	double	xtocheck;
	double	ytocheck;

	while (f->next_horz_x >= 0 && f->next_horz_x <= cube->size.win_width
		&& f->next_horz_y >= 0 && f->next_horz_y <= cube->size.win_height)
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

void	ft_check_vertical_wall_collision(t_cube *cube, t_info *f)
{
	double	xtocheck;
	double	ytocheck;

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

double	ft_get_horizontal_dist(t_cube *cube, t_info *f)
{
	f->y_intersection = floor(f->py / f->ytile) * f->ytile;
	if (f->is_down)
		f->y_intersection += f->ytile;
	f->x_intersection = f->px + ((f->y_intersection - f->py) / tan(f->ray_angle));
	f->ystep = (double)f->ytile;
	if (f->is_up)
		f->ystep *= -1;
	f->xstep = (double)f->ystep / tan(f->ray_angle);
	if (f->is_left && f->xstep > 0)
		f->xstep *= -1;
	if (f->is_right && f->xstep < 0)
		f->xstep *= -1;
	f->next_horz_x = f->x_intersection;
	f->next_horz_y = f->y_intersection;
	ft_check_horizontal_wall_collision(cube, f);
	if (!f->found_horz_wall)
		return (DBL_MAX);
	return (ft_get_point_to_point_distance(f->px, f->py, f->horzwallx, f->horzwally));
}

double	ft_get_vertical_dist(t_cube *cube, t_info *f)
{
	f->x_intersection = floor(f->px / f->xtile) * f->xtile;
	if (f->is_right)
		f->x_intersection += f->xtile;
	f->y_intersection = f->py + ((f->x_intersection - f->px) * tan(f->ray_angle));
	f->xstep = (double)f->xtile;
	if (f->is_left)
		f->xstep *= -1;
	f->ystep = (double)f->xstep * tan(f->ray_angle);
	if (f->is_up && f->ystep > 0)
		f->ystep *= -1;
	if (f->is_down && f->ystep < 0)
		f->ystep *= -1;
	f->next_vert_x = f->x_intersection;
	f->next_vert_y = f->y_intersection;
	ft_check_vertical_wall_collision(cube, f);
	if (!f->found_vert_wall)
		return (DBL_MAX);
	return (ft_get_point_to_point_distance(f->px, f->py, f->vertwallx, f->vertwally));
}

void	ft_fill_ray_data(t_cube *cube, t_info *f, int id)
{
	if (f->vert_dist < f->horz_dist)
	{
		cube->rays[id].distance = f->vert_dist;
		cube->rays[id].wall_hit_x = f->vertwallx;
		cube->rays[id].wall_hit_y = f->vertwally;
		cube->rays[id].was_hit_vert = true;
	}
	else
	{
		cube->rays[id].distance = f->horz_dist;
		cube->rays[id].wall_hit_x = f->horzwallx;
		cube->rays[id].wall_hit_y = f->horzwally;
		cube->rays[id].was_hit_vert = false;
	}
	cube->rays[id].ray_angle = f->ray_angle;
	cube->rays[id].is_down = f->is_down;
	cube->rays[id].is_up = f->is_up;
	cube->rays[id].is_left = f->is_left;
	cube->rays[id].is_right = f->is_right;
}

void	ft_determine_ray_cast(t_cube *cube, int id, double rayangle)
{
	t_info	f;

	ft_init_directions(cube, &f, rayangle);
	f.horz_dist = ft_get_horizontal_dist(cube, &f);
	f.vert_dist = ft_get_vertical_dist(cube, &f);
	ft_fill_ray_data(cube, &f, id);
}

void	ft_cast_all_rays(t_cube *cube)
{
	double	ray_angle;
	int		i;

	ray_angle = cube->player.rotation_angle - (cube->player.fov_angle / 2);
	i = -1;
	while (++i < NUM_RAYS)
	{
		ft_determine_ray_cast(cube, i, ray_angle);
		ray_angle += cube->player.fov_angle / NUM_RAYS;
	}
}

void	ft_render_rays(t_cube *cube)
{
	t_line	l;
	int		i;

	i = -1;
	while (++i < NUM_RAYS)
	{
		l.x_begin = cube->player.x + ((double)PLAYER_PX / 2);
		l.y_begin = cube->player.y + ((double)PLAYER_PX / 2);
		l.x_end = cube->rays[i].wall_hit_x;
		l.y_end = cube->rays[i].wall_hit_y;
		ft_draw_line(cube, l, rgba(255, 0, 0, 255));
	}
}

void	ft_key_hook(mlx_key_data_t keycube, void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (keycube.key == MLX_KEY_ESCAPE)
		ft_exit(cube);
	else if (keycube.key == MLX_KEY_UP)
		ft_press_and_release_key(keycube, &cube->player.walk_direction, 1);
	else if (keycube.key == MLX_KEY_DOWN)
		ft_press_and_release_key(keycube, &cube->player.walk_direction, -1);
	else if (keycube.key == MLX_KEY_RIGHT)
		ft_press_and_release_key(keycube, &cube->player.turn_direction, 1);
	else if (keycube.key == MLX_KEY_LEFT)
		ft_press_and_release_key(keycube, &cube->player.turn_direction, -1);
	else
		return ;
	ft_move_player(cube);
}

void	ft_loop_hook(void *param)
{
	t_cube	*cube;
	t_tools	t;

	ft_init_tools(&t);
	cube = (t_cube *)param;
	while (cube->info->map && cube->info->map[t.y])
	{
		t.x = 0;
		while (cube->info->map[t.y][t.x])
		{
			if (cube->info->map[t.y][t.x] == '1')
				ft_fill_square(cube, t.x, t.y, BLACK);
			else
				ft_fill_square(cube, t.x, t.y, rgba(255, 255, 255, 255));
			t.x++;
		}
		t.y++;
	}
	ft_fill_pixel_player(cube, CYAN);
	ft_cast_all_rays(cube);
	ft_render_rays(cube);
	ft_draw_line_of_view(cube, rgba(0, 0, 255, 200));
}

void	ft_close_hook(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	mlx_delete_image(cube->mlx, cube->img);
	mlx_terminate(cube->mlx);
	exit(SUCCESS);
}

void ft_mlx_error(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}
