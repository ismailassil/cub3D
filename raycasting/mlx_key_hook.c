/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:11:27 by iassil            #+#    #+#             */
/*   Updated: 2024/05/07 15:59:33 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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
		printf("cur_pos.y_pixels::{%d}\n", data->cur_pos.y_pixels);
	}
	else if (key == MLX_KEY_DOWN && ft_check_before_moving(data, MLX_KEY_DOWN))
	{
		data->position.y_move += PLAYER_MOVE;
		data->cur_pos.y_pixels += PLAYER_MOVE;
		printf("cur_pos.y_pixels::{%d}\n", data->cur_pos.y_pixels);
	}
	else if (key == MLX_KEY_RIGHT && ft_check_before_moving(data, MLX_KEY_RIGHT))
	{
		data->position.x_move += PLAYER_MOVE;
		data->cur_pos.x_pixels += PLAYER_MOVE;
		printf("cur_pos.x_pixels::{%d}\n", data->cur_pos.x_pixels);
	}
	else if (key == MLX_KEY_LEFT && ft_check_before_moving(data, MLX_KEY_LEFT))
	{
		data->position.x_move -= PLAYER_MOVE;
		data->cur_pos.x_pixels -= PLAYER_MOVE;
		printf("cur_pos.x_pixels::{%d}\n", data->cur_pos.x_pixels);
	}
}

void	ft_update_data(t_mlx *data, int x, int y)
{
	
}

bool	ft_check_before_moving(t_mlx *data, int key)
{
	int	nextpx_x;
	int	nextpx_y;

	(1) && (nextpx_x = 0, nextpx_y = 0);
	if (key == MLX_KEY_UP)
	{
		nextpx_y = ((data->cur_pos.y_map - 1) * data->pixel.height) + data->pixel.height;
		if (data->info->map[data->cur_pos.x_map][data->cur_pos.y_map - 1] == 1
			&& (data->cur_pos.y_pixels - PLAYER_MOVE) <= nextpx_y)
			return (false);
	}
	else if (key == MLX_KEY_DOWN)
	{
		nextpx_y = (data->cur_pos.y_map + 1) * data->pixel.height;
		if (data->info->map[data->cur_pos.x_map][data->cur_pos.y_map + 1] == 1
			&& (data->cur_pos.y_pixels + PLAYER_MOVE) >= nextpx_y)
			return (false);
	}
	else if (key == MLX_KEY_RIGHT)
	{
		nextpx_x = (data->cur_pos.x_map + 1) * data->pixel.width;
		if (data->info->map[data->cur_pos.x_map + 1][data->cur_pos.y_map] == 1
			&& data->cur_pos.x_pixels + PLAYER_MOVE <= nextpx_x)
			return (false);
	}
	else if (key == MLX_KEY_LEFT)
	{
		nextpx_x = ((data->cur_pos.x_map - 1) * data->pixel.width) + data->pixel.width;
		if (data->info->map[data->cur_pos.x_map - 1][data->cur_pos.y_map] == 1
			&& (data->cur_pos.x_pixels - PLAYER_MOVE) >= nextpx_x)
			return (false);
	}
	return (ft_update_data(data, nextpx_x, nextpx_y), true);
}
