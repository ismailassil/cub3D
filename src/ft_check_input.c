/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:44:27 by iassil            #+#    #+#             */
/*   Updated: 2024/05/05 00:18:12 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

bool	ft_check_input_file(int ac, char **av)
{
	int	len;

	if (ac != 2)
		return (p_error("too many arguments", NULL, 1), true);
	if (av && av[1] && ft_strlen(av[1]) < 4)
		return (p_error(av[1], ": Format not supported", 1), true);
	len = ft_strlen(av[1]) - 4;
	if (ft_strncmp(av[1] + len, ".cub", 5))
		return (p_error(av[1], ": Format not supported", 1), true);
	return (false);
}

int	ft_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		p_error(file, ": ", 0);
		perror(NULL);
		close(fd);
		exit(FAIL);
	}
	return (fd);
}
