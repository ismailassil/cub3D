/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:30:32 by iassil            #+#    #+#             */
/*   Updated: 2024/05/26 17:42:48 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	leaks(void)
{
	system("leaks cub3d");
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	*data;

	data = NULL;
	if (ft_check_input_file(ac, av))
		exit(FAIL);
	fd = ft_open_file(av[1]);
	// ft_parse(fd, data);
	ft_execute(data);
}
