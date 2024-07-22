/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:30:32 by iassil            #+#    #+#             */
/*   Updated: 2024/07/22 10:04:48 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_trim_textures(t_data *data)
{
	data->path->north[ft_strlen(data->path->north) - 1] = '\0';
	data->path->south[ft_strlen(data->path->south) - 1] = '\0';
	data->path->west[ft_strlen(data->path->west) - 1] = '\0';
	data->path->east[ft_strlen(data->path->east) - 1] = '\0';
}

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
		ft_free_data(&file_input);
		ft_free_data_utils(cube);
		(free(cube->data), free(cube));
		return (1);
	}
	ft_trim_textures(cube);
	close(fd);
	return (0);
}

// void	leaks(void)
// {
// 	system("leaks cub3d");
// }
void	leaks()
{
	fclose(gfp);
	system("leaks cub3d");
	usleep(1000 * 100 *10000);
}


int	main(int ac, char **av)
{
	int		fd;
	t_data	*cube;
	t_list	*file_input;

	gfp = fopen("leaks.t", "w");
	atexit(leaks);
	// atexit(leaks);
	file_input = NULL;
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
