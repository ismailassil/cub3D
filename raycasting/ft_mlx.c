/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:10:19 by iassil            #+#    #+#             */
/*   Updated: 2024/05/07 14:30:38 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_render(void *param)
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
				ft_fill_square(data, t.x, t.y, WHITE);
			t.x++;
		}
		t.y++;
	}
	ft_fill_pixel_player(data, CYAN);
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	ft_get_position_of_player(data->info->map, &data->position);
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_exit(data);
	else if (keydata.key == MLX_KEY_UP)
		ft_move_player(data, MLX_KEY_UP);
	else if (keydata.key == MLX_KEY_DOWN)
		ft_move_player(data, MLX_KEY_DOWN);
	else if (keydata.key == MLX_KEY_RIGHT)
		ft_move_player(data, MLX_KEY_RIGHT);
	else if (keydata.key == MLX_KEY_LEFT)
		ft_move_player(data, MLX_KEY_LEFT);
}

void	ft_close(void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
	exit(SUCCESS);
}

void _mlx_error_(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}
