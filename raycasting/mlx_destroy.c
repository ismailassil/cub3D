/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:31:03 by iassil            #+#    #+#             */
/*   Updated: 2024/05/31 17:23:47 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_mlx_error(t_cube *cube)
{
	mlx_close_window(cube->mlx);
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}

void	ft_destroy_cube(t_cube *cube)
{
	int	i;

	i = 0;
	// while (cube->info->data && cube->info->data[i])
	// 	free(cube->info->data[i++]);
	// free(cube->info->data);
	// free(cube->info);
	while (i < 42)
	{
		mlx_delete_texture(cube->textures.weapon[i]);
		mlx_delete_image(cube->mlx, cube->textures.weapon_img[i]);
		i++;
	}
	mlx_delete_texture(cube->textures.north);
	mlx_delete_texture(cube->textures.east);
	mlx_delete_texture(cube->textures.west);
	mlx_delete_texture(cube->textures.south);
	mlx_delete_image(cube->mlx, cube->img);
	mlx_terminate(cube->mlx);
}

void	ft_exit(t_cube *cube)
{
	mlx_delete_texture(cube->textures.north);
	mlx_delete_texture(cube->textures.east);
	mlx_delete_texture(cube->textures.west);
	mlx_delete_texture(cube->textures.south);
	mlx_delete_image(cube->mlx, cube->img);
	mlx_terminate(cube->mlx);
	exit(1);
}
