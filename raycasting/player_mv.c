/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:37:15 by iassil            #+#    #+#             */
/*   Updated: 2024/05/26 15:01:19 by iassil           ###   ########.fr       */
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

/*	This functions checks the player's movements, if their is a wall or not */
void	ft_move_player(t_cube *cube)
{
	int	new_x;
	int	new_y;
	int	new_xx;
	int	new_yy;

	cube->player.rot_angle += cube->player.turn_direction
		* cube->player.rotation_speed;
	new_x = cube->player.x + cos(cube->player.rot_angle)
		* cube->player.ud_direction * PLAYER_SPEED;
	new_y = cube->player.y + sin(cube->player.rot_angle)
		* cube->player.ud_direction * PLAYER_SPEED;
	new_x += cos(cube->player.rot_angle + M_PI_2)
		* cube->player.lr_direction * PLAYER_SPEED;
	new_y += sin(cube->player.rot_angle + M_PI_2)
		* cube->player.lr_direction * PLAYER_SPEED;
	new_xx = new_x + PLAYER_PX;
	new_yy = new_y + PLAYER_PX;
	if (cube->info->map[new_y / TILE][new_x / TILE] != '1' &&
		cube->info->map[new_yy / TILE][new_xx / TILE] != '1')
	{
		cube->player.x = new_x;
		cube->player.y = new_y;
	}
}
