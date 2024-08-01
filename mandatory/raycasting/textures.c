/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:22:30 by iassil            #+#    #+#             */
/*   Updated: 2024/07/23 10:21:40 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_load_wall_textures(t_cube *cube)
{
	cube->textures.north = mlx_load_png(cube->info->path->north);
	if (!cube->textures.north)
	{
		p_error("North texture failed to load", NULL, 1);
		(ft_fr_all(cube), exit(FAIL));
	}
	cube->textures.south = mlx_load_png(cube->info->path->south);
	if (!cube->textures.south)
	{
		(p_error("South texture failed to load", NULL, 1), ft_fr_wtxt(cube, 1));
		(ft_fr_all(cube), exit(FAIL));
	}
	cube->textures.west = mlx_load_png(cube->info->path->west);
	if (!cube->textures.west)
	{
		(p_error("West texture failed to load", NULL, 1), ft_fr_wtxt(cube, 2));
		(ft_fr_all(cube), exit(FAIL));
	}
	cube->textures.east = mlx_load_png(cube->info->path->east);
	if (!cube->textures.east)
	{
		(p_error("East texture failed to load", NULL, 1), ft_fr_wtxt(cube, 3));
		(ft_fr_all(cube), exit(FAIL));
	}
}
