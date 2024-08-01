/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:30:32 by iassil            #+#    #+#             */
/*   Updated: 2024/07/31 21:39:46 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	ft_trim_textures(t_data *data)
{
	data->path->north[ft_strlen(data->path->north) - 1] = '\0';
	data->path->south[ft_strlen(data->path->south) - 1] = '\0';
	data->path->west[ft_strlen(data->path->west) - 1] = '\0';
	data->path->east[ft_strlen(data->path->east) - 1] = '\0';
}

void	ft_init_struct_data(t_data *cube)
{
	cube->path->east = NULL;
	cube->path->north = NULL;
	cube->path->west = NULL;
	cube->path->south = NULL;
	cube->map = NULL;
	cube->data = NULL;
}

int	ft_parsing(int fd, t_data *cube, t_list **file_input)
{
	ft_init_struct_data(cube);
	*file_input = ft_get_map(fd);
	if (!*file_input)
		return (close(fd), free(cube->path), free(cube), 1);
	cube->data = ft_to_2d(*file_input);
	if (!cube->data)
	{
		(close(fd), ft_free_list(*file_input), free(cube->path), free(cube));
		return (1);
	}
	if (!ft_check_parse(cube))
	{
		close(fd);
		ft_free_data(file_input);
		ft_free_data_utils(cube);
		free(cube->data);
		if (cube->map)
			free(cube->map);
		free(cube);
		return (1);
	}
	ft_trim_textures(cube);
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	*cube;
	t_list	*file_input;

	if (ac != 2)
	{
		p_error("Please enter one input file with `.cub` extension", 0, 1);
		return (1);
	}
	file_input = NULL;
	cube = malloc(sizeof(t_data));
	if (!cube)
		return (p_error("Allocation failed", 0, 1), 1);
	cube->path = malloc(sizeof(t_path));
	if (!cube->path)
		return (p_error("Allocation failed", 0, 1), free(cube), 1);
	fd = ft_open_file(av[1], cube);
	if (ft_check_input_file(ac, av))
		return (free(cube->path), free(cube), 1);
	if (ft_parsing(fd, cube, &file_input))
		return (p_error(av[1], ": file contains invalid `elements or map`", \
			1), 1);
	ft_execute(cube, &file_input);
}
