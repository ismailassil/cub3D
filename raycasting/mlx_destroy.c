/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:31:03 by iassil            #+#    #+#             */
/*   Updated: 2024/07/22 09:36:14 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	exit(1);
}
