/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:30:10 by iassil            #+#    #+#             */
/*   Updated: 2024/07/23 11:15:19 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_fr_all_text(t_cube *cube)
{
	ft_fr_wtxt(cube, 4);
	ft_fr_all(cube);
}

void	ft_fr_all(t_cube *cube)
{
	ft_free_parsing(cube->info, &cube->file_input);
	free(cube);
}

void	ft_fr_wtxt(t_cube *cube, int i)
{
	if (i == 1)
		mlx_delete_texture(cube->textures.north);
	if (i == 2)
	{
		mlx_delete_texture(cube->textures.north);
		mlx_delete_texture(cube->textures.south);
	}
	if (i == 3)
	{
		mlx_delete_texture(cube->textures.north);
		mlx_delete_texture(cube->textures.south);
		mlx_delete_texture(cube->textures.west);
	}
	if (i == 4)
	{
		mlx_delete_texture(cube->textures.north);
		mlx_delete_texture(cube->textures.south);
		mlx_delete_texture(cube->textures.west);
		mlx_delete_texture(cube->textures.east);
	}
}
