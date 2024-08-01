/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:37:15 by iassil            #+#    #+#             */
/*   Updated: 2024/08/02 00:40:44 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*	When a user click on a key and release it, it will be assigned to click
	(walk || turn)
*/
void	ft_press_and_release_key(mlx_key_data_t keycube, int *click, int value)
{
	if (keycube.action == MLX_RELEASE)
		*click = 0;
	else
		*click = value;
}

// Its Purpose is to let the angle between 0_deg and 360_deg
static float	ft_normalizee_angle(float ray_angle)
{
	float	new_angle;

	new_angle = fmod(ray_angle, (2.0 * M_PI));
	if (new_angle < 0)
		new_angle += (2.0 * M_PI);
	return (new_angle);
}

void	ft_player_direction(t_cube *cube, int *x, int *y)
{
	t_info	f;
	float	ray;

	(void)x;
	ray = ft_normalizee_angle(cube->player.rot_angle);
	f.is_up = false;
	f.is_down = false;
	if (ray > 0 && ray < M_PI)
		f.is_down = true;
	f.is_up = !f.is_down;
	f.is_right = false;
	f.is_left = false;
	if (ray < 0.5 * M_PI || ray > 1.5 * M_PI)
		f.is_right = true;
	if (!f.is_right)
		f.is_left = true;
	f.is_left = !f.is_right;
	if (f.is_up)
		*y -= RANGE;
	if (f.is_down)
		*y += RANGE;
}

bool	ft_is_wall(t_cube *cube, int x, int y)
{
	int		new_x;
	int		new_y;
	int		new_xx;
	int		new_yy;

	ft_player_direction(cube, &x, &y);
	new_x = x / TILE;
	new_y = y / TILE;
	new_xx = (x + RANGE) / TILE;
	new_yy = (y + RANGE) / TILE;
	if (new_y < 0 || new_y > cube->info->ylen
		|| new_yy < 0 || new_yy > cube->info->ylen)
		return (false);
	if (new_x < 0 || new_x > (int)ft_strlen(cube->info->map[new_y])
		|| new_xx < 0 || new_xx > (int)ft_strlen(cube->info->map[new_yy]))
		return (false);
	if (cube->info->map[new_y][new_x] != '1'
		&& cube->info->map[new_yy][new_xx] != '1')
		return (true);
	return (false);
}

/*	This functions checks the player's movements, if their is a wall or not */
void	ft_move_player(t_cube *cube)
{
	float	new_x;
	float	new_y;

	cube->player.rot_angle += cube->player.turn_direction
		* cube->player.rotation_speed;
	new_x = cube->player.x + cos(cube->player.rot_angle)
		* cube->player.ud_direction * PLAYER_SPEED;
	new_y = cube->player.y + sin(cube->player.rot_angle)
		* cube->player.ud_direction * PLAYER_SPEED;
	new_x += (cos(cube->player.rot_angle + M_PI_2)
			* cube->player.lr_direction * (PLAYER_SPEED - 5));
	new_y += (sin(cube->player.rot_angle + M_PI_2)
			* cube->player.lr_direction * (PLAYER_SPEED - 5));
	if (ft_is_wall(cube, new_x, new_y))
	{
		cube->player.x = new_x;
		cube->player.y = new_y;
	}
}
