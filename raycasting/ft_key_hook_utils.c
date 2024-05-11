/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:11:27 by iassil            #+#    #+#             */
/*   Updated: 2024/05/11 17:16:49 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_move_player(t_mlx *data)
{
	int	current_y;
	int	current_x;
	int	current_yy;
	int	current_xx;

	data->cur_pos.rotation_angle += data->cur_pos.turn_direction * data->cur_pos.rotation_speed;
	current_x = data->cur_pos.x_pixels + \
		(cos(data->cur_pos.rotation_angle) * data->cur_pos.walk_direction * PLAYER_MOVE);
	current_xx = (data->cur_pos.x_pixels + PLAYER_PX) + \
		(cos(data->cur_pos.rotation_angle) * data->cur_pos.walk_direction * PLAYER_MOVE);
	current_y = data->cur_pos.y_pixels + \
		(sin(data->cur_pos.rotation_angle) * data->cur_pos.walk_direction * PLAYER_MOVE);
	current_yy = (data->cur_pos.y_pixels + PLAYER_PX) + \
		(sin(data->cur_pos.rotation_angle) * data->cur_pos.walk_direction * PLAYER_MOVE);
	if (data->info->map[current_y / data->pixel.height][current_x / data->pixel.width] != '1'
		&& data->info->map[current_yy / data->pixel.height][current_xx / data->pixel.width] != '1')
	{
			data->cur_pos.x_pixels = current_x;
			data->cur_pos.y_pixels = current_y;
	}
}
