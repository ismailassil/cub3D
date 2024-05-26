/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:58:12 by iassil            #+#    #+#             */
/*   Updated: 2024/05/26 15:58:40 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_render_player(t_cube *cube)
{
	int	pl_x;
	int	pl_y;
	int	i;
	int	j;

	i = 0;
	pl_y = SPACE + ((MAPHEIGHT / 2) - (PLAYER_PX / 2));
	while (i < PLAYER_PX)
	{
		pl_x = SPACE + ((MAPWIDTH / 2) - (PLAYER_PX));
		j = 0;
		while (j < PLAYER_PX)
		{
			mlx_put_pixel(cube->img, pl_x, pl_y, rgba(0, 120, MC, MC));
			pl_x++;
			j++;
		}
		pl_y++;
		i++;
	}
}

static void	ft_render_rectangle(t_cube *cube)
{
	t_tools	t;

	ft_init_tools(&t);
	t.y = SPACE;
	while (t.y < MAPHEIGHT)
	{
		t.x = SPACE;
		while (t.x < MAPWIDTH)
		{
			if ((t.x >= SPACE && t.x <= SPACE + BORDER)
				|| (t.x >= (MAPWIDTH - BORDER) && t.x <= MAPWIDTH)
				|| (t.y >= SPACE && t.y <= SPACE + BORDER)
				|| (t.y >= (MAPHEIGHT - BORDER) && t.y <= MAPHEIGHT))
				t.color = rgba(12, 34, 222, MC);
			else
				t.color = rgba(0, 0, 40, MC);
			mlx_put_pixel(cube->img, t.x, t.y, t.color);
			t.x++;
		}
		t.y++;
	}
}

static void	ft_render_grid(t_cube *cube)
{
	t_grid	g;

	(1) && (g.center_x = MAPWIDTH / 2, g.center_y = MAPHEIGHT / 2);
	g.diff_x = g.center_x - floor(cube->player.x);
	g.diff_y = g.center_y - floor(cube->player.y);
	g.y = SPACE + BORDER;
	while (g.y < (MAPHEIGHT - BORDER))
	{
		g.x = SPACE + BORDER;
		while (g.x < (MAPWIDTH - BORDER))
		{
			(1) && (g.map_x = g.x - g.diff_x, g.map_y = g.y - g.diff_y);
			(1) && (g.tile_x = g.map_x / TILE, g.tile_y = g.map_y / TILE);
			if (g.tile_y >= 0 && g.tile_x > 0
				&& g.tile_y < cube->info->ylen
				&& g.tile_x < (int)ft_strlen(cube->info->map[g.tile_y]))
			{
				if (cube->info->map[g.tile_y][g.tile_x] != '1')
					mlx_put_pixel(cube->img, g.x, g.y, rgba(MC, MC, MC, MC));
			}
			g.x++;
		}
		g.y++;
	}
}

void	ft_render_minimap(t_cube *cube)
{
	ft_render_rectangle(cube);
	ft_render_grid(cube);
	ft_render_player(cube);
}
