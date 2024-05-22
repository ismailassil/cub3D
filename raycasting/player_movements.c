/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:37:15 by iassil            #+#    #+#             */
/*   Updated: 2024/05/23 00:18:10 by iassil           ###   ########.fr       */
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
	int	current_y;
	int	current_x;
	int	current_yy;
	int	current_xx;

	cube->player.rotation_angle += cube->player.turn_direction 
		* cube->player.rotation_speed;
	current_x = cube->player.x + (cos(cube->player.rotation_angle) 
			* cube->player.walk_direction * PLAYER_SPEED);
	current_xx = (cube->player.x + PLAYER_PX) 
		+ (cos(cube->player.rotation_angle)
			* cube->player.walk_direction * PLAYER_SPEED);
	current_y = cube->player.y + (sin(cube->player.rotation_angle) 
			* cube->player.walk_direction * PLAYER_SPEED);
	current_yy = (cube->player.y + PLAYER_PX) 
		+ (sin(cube->player.rotation_angle) 
			* cube->player.walk_direction * PLAYER_SPEED);
	if (cube->info->map[current_y / TILE][current_x / TILE] != '1'
		&& cube->info->map[current_yy / TILE][current_xx / TILE] != '1')
	{
		cube->player.x = current_x;
		cube->player.y = current_y;
	}
}
