/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:30:32 by iassil            #+#    #+#             */
/*   Updated: 2024/07/21 18:19:26 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_parsing(int fd, t_data *cube, t_list *file_input)
{
	cube->path->east = NULL;
	cube->path->north = NULL;
	cube->path->west = NULL;
	cube->path->south = NULL;
	file_input = ft_get_map(fd);
	if (!file_input)
		return (close(fd), free(cube->path), free(cube), 1);
	cube->data = ft_to_2d(file_input);
	if (!cube->data)
		return (close(fd), ft_free_list(file_input), free(cube->path), free(cube), 1);
	if (!ft_check_parse(cube))
	{
		close(fd);
		(ft_free_data(&file_input), ft_free_data_utils(cube));
		(free(cube->data), free(cube));
		return (1);
	}
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	*cube;
	t_list	*file_input;

	cube = malloc(sizeof(t_data));
	if (!cube)
		return (1);
	cube->path = malloc(sizeof(t_path));
	if (!cube->path)
		return (free(cube), 1);
	fd = ft_open_file(av[1], cube);
	if (ft_check_input_file(ac, av))
		return (free(cube->path), free(cube), 1);
	if (ft_parsing(fd, cube, file_input))
		return (1);
	ft_execute(cube, file_input);
}
