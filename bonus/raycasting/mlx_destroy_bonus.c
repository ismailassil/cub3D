/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:31:03 by iassil            #+#    #+#             */
/*   Updated: 2024/07/23 10:29:26 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	ft_mlx_error(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}

void	ft_destroy_cube(t_cube *cube)
{
	mlx_delete_image(cube->mlx, cube->img);
	mlx_terminate(cube->mlx);
	ft_fr_all_text(cube);
}

void	ft_exit(t_cube *cube)
{
	mlx_delete_image(cube->mlx, cube->img);
	mlx_terminate(cube->mlx);
	ft_fr_all_text(cube);
	exit(FAIL);
}
