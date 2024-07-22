/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:22:30 by iassil            #+#    #+#             */
/*   Updated: 2024/07/22 09:30:03 by iassil           ###   ########.fr       */
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

static char	*ft_get_path(int i, char *dir)
{
	char	*num;
	char	*tmp;
	char	*path;

	num = ft_itoa(i);
	ft_check_allocation(num);
	tmp = ft_strjoin(dir, num);
	free(num);
	ft_check_allocation(tmp);
	path = ft_strjoin(tmp, ".png");
	free(tmp);
	ft_check_allocation(path);
	return (path);
}

void	ft_load_weapon_textures(t_cube *cube)
{
	int		i;
	char	*path;

	i = 0;
	while (i < SECND)
	{
		path = ft_get_path(i + 1, "./textures/csgo/");
		cube->textures.weapon[i] = mlx_load_png(path);
		if (!cube->textures.weapon[i])
		{
			while (--i)
				mlx_delete_texture(cube->textures.weapon[i]);
			ft_fr_wtxt(cube, 4);
			ft_fr_all(cube);
			(p_error(path, " - Failed to load", 1), free(path), exit(FAIL));
		}
		free(path);
		i++;
	}
}

void	ft_load_bar_textures(t_cube *cube)
{
	int		i;
	char	*path;

	i = 0;
	while (i < BAR)
	{
		path = ft_get_path(i, "./textures/bar/");
		cube->textures.bar[i] = mlx_load_png(path);
		if (!cube->textures.bar[i])
		{
			ft_destroy_weapon_texture(&cube->textures);
			while (--i)
				mlx_delete_texture(cube->textures.bar[i]);
			ft_fr_wtxt(cube, 4);
			ft_fr_all(cube);
			(p_error(path, " - Failed to load", 1), free(path), exit(FAIL));
		}
		free(path);
		i++;
	}
}
