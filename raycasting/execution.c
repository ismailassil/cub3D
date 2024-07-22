/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:05:10 by iassil            #+#    #+#             */
/*   Updated: 2024/07/22 12:52:53 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mousefunc(double xpos, double ypos, void *param)
{
	t_cube			*cube;
	static double	last_xpos;

	(void)ypos;
	cube = (t_cube *)param;
	if (last_xpos && last_xpos > xpos && last_xpos - xpos > TURN)
		cube->player.turn_direction = -1;
	else if (last_xpos && last_xpos < xpos && last_xpos - xpos < TURN)
		cube->player.turn_direction = 1;
	last_xpos = xpos;
	cube->player.rot_angle += cube->player.turn_direction
		* cube->player.rotation_speed;
	cube->player.turn_direction = 0;
}

void	ft_free_parsing(t_data *data, t_list **file_input)
{
	ft_free_data_utils(data);
	free(data->data);
	ft_free_data(file_input);
	free(data->map);
	free(data);
}

void	ft_execute(t_data *info, t_list **f_input)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	if (!cube)
	{
		ft_free_parsing(info, f_input);
		p_error("Allocation Failed", 0, 1);
		return ;
	}
	cube->info = info;
	cube->file_input = *f_input;
	ft_get_window_data(cube);
	ft_init_mlx_window(cube);
	ft_initialize_data(cube);
	mlx_key_hook(cube->mlx, ft_key_hook, cube);
	mlx_loop_hook(cube->mlx, ft_loop_hook, cube);
	mlx_set_cursor_mode(cube->mlx, MLX_MOUSE_DISABLED);
	mlx_cursor_hook(cube->mlx, mousefunc, cube);
	mlx_loop(cube->mlx);
	mlx_close_hook(cube->mlx, ft_close_hook, cube);
	ft_destroy_cube(cube);
}
