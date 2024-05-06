/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:11:27 by iassil            #+#    #+#             */
/*   Updated: 2024/05/06 21:28:29 by iassil           ###   ########.fr       */
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
		ft_fill_pixel_player(data, data->position.x, data->position.y - 1, CYAN);
		ft_fill_pixel_player(data, data->position.x, data->position.y, WHITE);
	}
	else if (key == MLX_KEY_DOWN && ft_check_before_moving(data, MLX_KEY_DOWN))
	{
		ft_fill_pixel_player(data, data->position.x, data->position.y + 1, CYAN);
		ft_fill_pixel_player(data, data->position.x, data->position.y, WHITE);
	}
	else if (key == MLX_KEY_RIGHT && ft_check_before_moving(data, MLX_KEY_RIGHT))
	{
		ft_fill_pixel_player(data, data->position.x + 1, data->position.y, CYAN);
		ft_fill_pixel_player(data, data->position.x, data->position.y, WHITE);
	}
	else if (key == MLX_KEY_LEFT && ft_check_before_moving(data, MLX_KEY_LEFT))
	{
		ft_fill_pixel_player(data, data->position.x - 1, data->position.y, CYAN);
		ft_fill_pixel_player(data, data->position.x, data->position.y, WHITE);
	}
}

bool	ft_check_before_moving(t_mlx *data, int key)
{
	int	x;
	int	y;

	(1) && (x = data->position.x, y = data->position.y);
	if (key == MLX_KEY_UP && data->info->map[y - 1][x] != '1')
	{
		data->info->map[y][x] = '0';
		return (data->info->map[y - 1][x] = 'P', true);
	}
	else if (key == MLX_KEY_DOWN && data->info->map[y + 1][x] != '1')
	{
		data->info->map[y][x] = '0';
		return (data->info->map[y + 1][x] = 'P', true);
	}
	else if (key == MLX_KEY_RIGHT && data->info->map[y][x + 1] != '1')
	{
		data->info->map[y][x] = '0';
		return (data->info->map[y][x + 1] = 'P', true);
	}
	else if (key == MLX_KEY_LEFT && data->info->map[y][x - 1] != '1')
	{
		data->info->map[y][x] = '0';
		return (data->info->map[y][x - 1] = 'P', true);
	}
	return (false);
}
