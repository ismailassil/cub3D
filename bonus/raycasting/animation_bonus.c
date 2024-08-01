/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:20:26 by iassil            #+#    #+#             */
/*   Updated: 2024/07/23 10:29:26 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	ft_put_weapon(t_cube *cube, mlx_texture_t *img)
{
	t_weapon	w;

	w.img = img;
	w.img_px = (int32_t *)w.img->pixels;
	w.y = 0;
	while (w.y < w.img->height)
	{
		w.x = 0;
		while (w.x < w.img->width)
		{
			w.nx = w.x + WIDTH - (WIDTH * 0.65);
			w.ny = w.y + HEIGHT - w.img->height;
			w.color = w.img_px[((int)w.y * w.img->width) + (int)w.x];
			if ((w.color & 0xFF000000) != 0 && (w.color & 0xD0D0D0) != 0xD0D0D0)
				mlx_put_pixel(cube->img, w.nx, w.ny, ft_reverse_color(w.color));
			w.x++;
		}
		w.y++;
	}
}

void	ft_render_weapon(t_cube *cube)
{
	static int	i;

	if (!cube->player.reload)
	{
		ft_put_weapon(cube, cube->textures.weapon[35]);
		return ;
	}
	if (i < SECND)
		ft_put_weapon(cube, cube->textures.weapon[i++]);
	if (i == SECND)
	{
		i = 0;
		cube->player.reload = 0;
	}
}

void	ft_put_bar(t_cube *cube, mlx_texture_t *img)
{
	t_weapon	w;

	w.img = img;
	w.img_px = (int32_t *)w.img->pixels;
	w.y = 0;
	while (w.y < w.img->height)
	{
		w.x = 0;
		while (w.x < w.img->width)
		{
			w.nx = w.x + WIDTH - w.img->width;
			w.ny = w.y + HEIGHT - (HEIGHT * 0.65);
			w.color = w.img_px[((int)w.y * w.img->width) + (int)w.x];
			if ((w.color & 0xFF000000) != 0
				&& (w.color & 0x00FFFFFF) != 0x00FFFFFF
				&& (w.color & 0xF8F8F8) != 0xF8F8F8)
				mlx_put_pixel(cube->img, w.nx, w.ny, ft_reverse_color(w.color));
			w.x++;
		}
		w.y++;
	}
}

void	ft_render_stat_bar(t_cube *cube)
{
	static int	i;

	if (i < BAR)
		ft_put_bar(cube, cube->textures.bar[i++]);
	if (i == BAR)
		i = 0;
}
