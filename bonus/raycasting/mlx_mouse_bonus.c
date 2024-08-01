/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:16:25 by iassil            #+#    #+#             */
/*   Updated: 2024/07/30 00:18:10 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	mousefunc(double xpos, double ypos, void *param)
{
	t_cube			*cube;
	static double	last_xpos;

	(void)ypos;
	cube = (t_cube *)param;
	if (cube->mouse_key == 0)
	{
		if (last_xpos && last_xpos > xpos && last_xpos - xpos > TURN)
			cube->player.turn_direction = -1;
		else if (last_xpos && last_xpos < xpos && last_xpos - xpos < TURN)
			cube->player.turn_direction = 1;
		last_xpos = xpos;
		cube->player.rot_angle += cube->player.turn_direction
			* cube->player.rotation_speed;
		cube->player.turn_direction = 0;
	}
}

void	ft_mlx_cursor_mode(t_cube *cube)
{
	if (cube->mouse_key == 0)
		mlx_set_cursor_mode(cube->mlx, MLX_MOUSE_DISABLED);
	else if (cube->mouse_key == 1)
		mlx_set_cursor_mode(cube->mlx, MLX_MOUSE_NORMAL);
}

void	ft_press_and_release_mouse_key(mlx_key_data_t keycube, int *click)
{
	if (*click == 0 && keycube.action == MLX_RELEASE)
		*click = 1;
	else if (*click == 1 && keycube.action == MLX_RELEASE)
		*click = 0;
}
