/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:11:27 by iassil            #+#    #+#             */
/*   Updated: 2024/05/22 23:32:37 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_move_player(t_cube *cube)
{
	int	current_y;
	int	current_x;
	int	current_yy;
	int	current_xx;

	cube->player.rotation_angle += cube->player.turn_direction * cube->player.rotation_speed;
	current_x = cube->player.x + \
		(cos(cube->player.rotation_angle) * cube->player.walk_direction * PLAYER_SPEED);
	current_xx = (cube->player.x + PLAYER_PX) + \
		(cos(cube->player.rotation_angle) * cube->player.walk_direction * PLAYER_SPEED);
	current_y = cube->player.y + \
		(sin(cube->player.rotation_angle) * cube->player.walk_direction * PLAYER_SPEED);
	current_yy = (cube->player.y + PLAYER_PX) + \
		(sin(cube->player.rotation_angle) * cube->player.walk_direction * PLAYER_SPEED);
	if (cube->info->map[current_y / TILE][current_x / TILE] != '1'
		&& cube->info->map[current_yy / TILE][current_xx / TILE] != '1')
	{
			cube->player.x = current_x;
			cube->player.y = current_y;
	}
}
