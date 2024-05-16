/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:11:27 by iassil            #+#    #+#             */
/*   Updated: 2024/05/13 17:04:02 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_move_player(t_cube *data)
{
	int	current_y;
	int	current_x;
	int	current_yy;
	int	current_xx;

	data->player.rotation_angle += data->player.turn_direction * data->player.rotation_speed;
	current_x = data->player.x + \
		(cos(data->player.rotation_angle) * data->player.walk_direction * PLAYER_SPEED);
	current_xx = (data->player.x + PLAYER_PX) + \
		(cos(data->player.rotation_angle) * data->player.walk_direction * PLAYER_SPEED);
	current_y = data->player.y + \
		(sin(data->player.rotation_angle) * data->player.walk_direction * PLAYER_SPEED);
	current_yy = (data->player.y + PLAYER_PX) + \
		(sin(data->player.rotation_angle) * data->player.walk_direction * PLAYER_SPEED);
	if (data->info->map[current_y / data->size.height][current_x / data->size.width] != '1'
		&& data->info->map[current_yy / data->size.height][current_xx / data->size.width] != '1')
	{
			data->player.x = current_x;
			data->player.y = current_y;
	}
}
