/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:22:30 by iassil            #+#    #+#             */
/*   Updated: 2024/06/02 18:40:25 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_load_wall_textures(t_cube *cube)
{
	// cube->textures.north = mlx_load_png(cube->info->path->north);
	cube->textures.north = mlx_load_png("./textures/walls/hitler.png");
	if (!cube->textures.north)
		(p_error("North texture failed to load", NULL, 1), exit(FAIL));
	// cube->textures.south = mlx_load_png(cube->info->path->south);
	cube->textures.south = mlx_load_png("./textures/walls/nazi.png");
	if (!cube->textures.south)
		(p_error("South texture failed to load", NULL, 1), exit(FAIL));
	// cube->textures.west = mlx_load_png(cube->info->path->west);
	cube->textures.west = mlx_load_png("./textures/walls/wall.png");
	if (!cube->textures.west)
		(p_error("West texture failed to load", NULL, 1), exit(FAIL));
	// cube->textures.east = mlx_load_png(cube->info->path->east);
	cube->textures.east = mlx_load_png("./textures/walls/eagle.png");
	if (!cube->textures.east)
		(p_error("East texture failed to load", NULL, 1), exit(FAIL));
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
			(p_error(path, " - Failed to load", 1), exit(1));
		free(path);
		i++;
	}
}

void	ft_load_bar_textures(t_cube *cube)
{
	int		i;
	char	*path;

	i = 0;
	while (i < 218)
	{
		path = ft_get_path(i, "./textures/bar/");
		cube->textures.bar[i] = mlx_load_png(path);
		if (!cube->textures.bar[i])
			(p_error(path, " - Failed to load", 1), exit(1));
		free(path);
		i++;
	}
}
