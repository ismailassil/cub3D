/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:11:27 by iassil            #+#    #+#             */
/*   Updated: 2024/05/11 12:30:29 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*	Function prototype	*/
bool	ft_check_before_moving(t_mlx *data, int key);
/////////////////////////////////////////////////////

void	ft_move_player(t_mlx *data, int key)
{
	(void)key;
	if (key == MLX_KEY_UP && ft_check_before_moving(data, MLX_KEY_UP))
	{
		data->position.y_move -= PLAYER_MOVE;
		data->cur_pos.y_pixels -= PLAYER_MOVE;
	}
	else if (key == MLX_KEY_DOWN && ft_check_before_moving(data, MLX_KEY_DOWN))
	{
		data->position.y_move += PLAYER_MOVE;
		data->cur_pos.y_pixels += PLAYER_MOVE;
	}
	else if (key == MLX_KEY_RIGHT && ft_check_before_moving(data, MLX_KEY_RIGHT))
	{
		data->position.x_move += PLAYER_MOVE;
		data->cur_pos.x_pixels += PLAYER_MOVE;
	}
	else if (key == MLX_KEY_LEFT && ft_check_before_moving(data, MLX_KEY_LEFT))
	{
		data->position.x_move -= PLAYER_MOVE;
		data->cur_pos.x_pixels -= PLAYER_MOVE;
	}
}

void	ft_update_data(t_mlx *data, t_tools *t, int key)
{
	if (key == MLX_KEY_UP)
	{
		if (data->info->map[data->cur_pos.y_map - 1][data->cur_pos.x_map] != '1'
			&& t->current_y < t->nextpx_y)
		{
			data->cur_pos.y_map -= 1;
			data->cur_pos.walk_direction -= 1;
		}
	}
	else if (key == MLX_KEY_DOWN)
	{
		if (data->info->map[data->cur_pos.y_map + 1][data->cur_pos.x_map] != '1'
			&& t->current_y > t->nextpx_y)
		{
			data->cur_pos.y_map += 1;
			data->cur_pos.walk_direction += 1;
		}
	}
}

bool	ft_check_before_moving(t_mlx *data, int key)
{
	t_tools	t;

	ft_init_tools(&t);
	if (key == MLX_KEY_UP)
	{
		t.nextpx_y = ((data->cur_pos.y_map - 1) * data->pixel.height) + data->pixel.height;
		t.current_y = data->cur_pos.y_pixels - PLAYER_MOVE;
		if (data->info->map[data->cur_pos.y_map - 1][data->cur_pos.x_map] == '1'
			&& t.current_y <= t.nextpx_y)
			return (false);
		ft_update_data(data, &t, MLX_KEY_UP);
	}
	else if (key == MLX_KEY_DOWN)
	{
		t.nextpx_y = (data->cur_pos.y_map + 1) * data->pixel.height;
		t.current_y = data->cur_pos.y_pixels + PLAYER_PX + PLAYER_MOVE;
		if (data->info->map[data->cur_pos.y_map + 1][data->cur_pos.x_map] == '1'
			&& t.current_y >= t.nextpx_y)
			return (false);
		ft_update_data(data, &t, MLX_KEY_DOWN);
	}
	else if (key == MLX_KEY_RIGHT)
	{
		data->cur_pos.rotation_angle += data->cur_pos.turn_direction * data->cur_pos.rotation_speed;
	}
	else if (key == MLX_KEY_LEFT)
	{
		data->cur_pos.rotation_angle -= data->cur_pos.turn_direction * data->cur_pos.rotation_speed;
	}
	return (true);
}
