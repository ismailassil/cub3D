/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:05:25 by iassil            #+#    #+#             */
/*   Updated: 2024/05/31 23:47:39 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdint.h>

void	ft_reinit_mlx_window(t_cube *cube);

void	ft_key_hook(mlx_key_data_t keycube, void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (keycube.key == MLX_KEY_ESCAPE)
		ft_exit(cube);
	else if (keycube.key == MLX_KEY_W)
		ft_press_and_release_key(keycube, &cube->player.ud_direction, 1);
	else if (keycube.key == MLX_KEY_S)
		ft_press_and_release_key(keycube, &cube->player.ud_direction, -1);
	else if (keycube.key == MLX_KEY_A)
		ft_press_and_release_key(keycube, &cube->player.lr_direction, -1);
	else if (keycube.key == MLX_KEY_D)
		ft_press_and_release_key(keycube, &cube->player.lr_direction, 1);
	else if (keycube.key == MLX_KEY_RIGHT)
		ft_press_and_release_key(keycube, &cube->player.turn_direction, 1);
	else if (keycube.key == MLX_KEY_LEFT)
		ft_press_and_release_key(keycube, &cube->player.turn_direction, -1);
	else
		return ;
	ft_move_player(cube);
}

typedef struct s_weapon
{
	mlx_texture_t	*img;
	int32_t			*img_px;
	float			xcord;
	float			ycord;
	int32_t			color;
	unsigned int	x;
	unsigned int	y;
	unsigned int	nx;
	unsigned int	ny;
}					t_weapon;

void	ft_put_weapon(t_cube *cube, mlx_texture_t *img)
{
	t_weapon	w;

	w.img = img;
	w.img_px = (int32_t *)w.img->pixels;
	w.xcord = 0;
	w.ycord = 0;
	w.y = 0;
	while (w.y < w.img->height)
	{
		w.x = 0;
		while (w.x < w.img->width)
		{
			w.nx = w.x + WIDTH - (WIDTH * 0.65);
			w.ny = w.y + HEIGHT - w.img->height;
			w.color = w.img_px[((int)w.ycord * w.img->width) + (int)w.xcord];
			if ((w.color & 0xFF000000) != 0)
				mlx_put_pixel(cube->img, w.nx, w.ny, ft_reverse_color(w.color));
			w.xcord++;
			w.x++;
		}
		w.y++;
	}
}

void	ft_render_weapon(t_cube *cube)
{
	
}

void	ft_loop_hook(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	ft_reinit_mlx_window(cube);
	ft_walls_projection(cube);
	ft_render_minimap(cube);
	ft_render_weapon(cube);
}

void	ft_close_hook(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	ft_destroy_cube(cube);
	exit(SUCCESS);
}

void	ft_reinit_mlx_window(t_cube *cube)
{
	mlx_delete_image(cube->mlx, cube->img);
	cube->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->img)
		ft_mlx_error(cube);
	if (mlx_image_to_window(cube->mlx, cube->img, 0, 0) < 0)
		ft_mlx_error(cube);
}
