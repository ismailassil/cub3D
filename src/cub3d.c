/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:30:32 by iassil            #+#    #+#             */
/*   Updated: 2024/07/15 14:25:21 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void leaks()
// {
//     fclose(gfp);
//     system("leaks cub3d");
//     usleep(1000 * 100 *10000);
// }
int	main(int ac, char **av)
{
	int		fd;
	t_data	*data;

	// gfp = fopen("leaks", "w");
	// atexit(leaks);
	data = malloc(sizeof(t_data));
	data->path = malloc(sizeof(t_path));
	if (ft_check_input_file(ac, av))
		exit(FAIL);
	fd = ft_open_file(av[1]);
	t_list *tmp = ft_get_map(fd);
	data->data = ft_to_2d(tmp);
	if (!ft_check_parse(data))
		return (ft_free_data(&tmp),ft_free_data_utils(data),free(data->data), free(data), printf("here\n"), 1);
	ft_free_data_utils(data);
	free(data->data);
	ft_free_data(&tmp);
	free(data);
	// ft_execute(data);
}