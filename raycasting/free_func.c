/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:30:10 by iassil            #+#    #+#             */
/*   Updated: 2024/07/22 09:33:07 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_fr_all_text(t_cube *cube)
{
	ft_destroy_weapon_texture(&cube->textures);
	ft_destroy_bar_texture(&cube->textures);
	ft_fr_wtxt(cube, 4);
	ft_fr_all(cube);
}

void	ft_fr_all(t_cube *cube)
{
	ft_free_parsing(cube->info, cube->file_input);
	free(cube);	
}

void	ft_destroy_weapon_texture(t_textures *texture)
{
	int	i;

	i = 0;
	while (i < SECND)
		mlx_delete_texture(texture->weapon[i++]);
}

void	ft_destroy_bar_texture(t_textures *texture)
{
	int	i;

	i = 0;
	while (i < BAR)
		mlx_delete_texture(texture->bar[i++]);
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
