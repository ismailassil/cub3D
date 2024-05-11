/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:10:19 by iassil            #+#    #+#             */
/*   Updated: 2024/05/11 17:05:12 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_press_and_release_key(mlx_key_data_t keydata, int *data, int value)
{
	if (keydata.action == MLX_RELEASE)
		*data = 0;
	else
		*data = value;
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_exit(data);
	else if (keydata.key == MLX_KEY_UP)
		ft_press_and_release_key(keydata, &data->cur_pos.walk_direction, 1);
	else if (keydata.key == MLX_KEY_DOWN)
		ft_press_and_release_key(keydata, &data->cur_pos.walk_direction, -1);
	else if (keydata.key == MLX_KEY_RIGHT)
		ft_press_and_release_key(keydata, &data->cur_pos.turn_direction, 1);
	else if (keydata.key == MLX_KEY_LEFT)
		ft_press_and_release_key(keydata, &data->cur_pos.turn_direction, -1);
	else
		return ;
	ft_move_player(data);
}

void	ft_loop_hook(void *param)
{
	t_mlx	*data;
	t_tools	t;

	ft_init_tools(&t);
	data = (t_mlx *)param;
	while (data->info->map && data->info->map[t.y])
	{
		t.x = 0;
		while (data->info->map[t.y][t.x])
		{
			if (data->info->map[t.y][t.x] == '1')
				ft_fill_square(data, t.x, t.y, BLACK);
			else
				ft_fill_square(data, t.x, t.y, get_rgba(255, 255, 255));
			t.x++;
		}
		t.y++;
	}
	ft_fill_pixel_player(data, CYAN);
	ft_draw_line_of_view(data, get_rgba(255, 0, 0));
}

void	ft_close_hook(void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
	exit(SUCCESS);
}

void ft_mlx_error(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}
