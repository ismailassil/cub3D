/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:30:32 by iassil            #+#    #+#             */
/*   Updated: 2024/07/17 11:06:12 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void leaks()
// {
//     fclose(gfp);
//     system("leaks cub3d");
//     usleep(1000 * 100 *10000);
// }

// void	leaks()
// {
// 	system("leaks cub3d");	
// }

int	main(int ac, char **av)
{
	int		fd;
	t_data	*data;

	// gfp = fopen("leaks", "w");
	// atexit(leaks);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->path = malloc(sizeof(t_path));
	if (!data->path)
		return (free(data), 1);
	data->path->east = NULL;
	data->path->north = NULL;
	data->path->west = NULL;
	data->path->south = NULL;
	if (ft_check_input_file(ac, av))
		return (free(data->path), free(data), 1);
	fd = ft_open_file(av[1]);
	t_list *tmp = ft_get_map(fd);
	if (!tmp)
		return (close(fd), free(data->path), free(data), 1);
	data->data = ft_to_2d(tmp);
	if (!data->data)
		return (close(fd), ft_free_list(tmp), free(data->path), free(data), 1);
	if (!ft_check_parse(data))
		return (close(fd), ft_free_data(&tmp),ft_free_data_utils(data),free(data->data), free(data), 1);
	// ft_free_data_utils(data);
	// free(data->data);
	// ft_free_data(&tmp);
	// free(data);
	// close(fd);
	ft_execute(data);
}