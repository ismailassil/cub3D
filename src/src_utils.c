/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:45:00 by iassil            #+#    #+#             */
/*   Updated: 2024/05/11 10:39:56 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	p_error(char *str1, char *str2, int newline)
{
	write(2, "Error\n ", 7);
	if (str1 && *str1)
		write(2, str1, ft_strlen(str1));
	if (str2 && *str2)
		write(2, str2, ft_strlen(str2));
	if (newline)
		write(2, "\n", 1);
}

void	ft_check_allocation(void *ptr)
{
	if (!ptr)
	{
		p_error("Allocation failed (malloc)", NULL, 1);
		exit(FAIL);
	}
}

void	ft_free_all(t_data **parse)
{
	ft_free_map(&(*parse)->data);
	free((*parse)->directions);
	free((*parse)->colors);
	free(*parse);
	exit(FAIL);
}

void	ft_free_map(char ***map)
{
	int	i;

	i = 0;
	while (*map && (*map)[i])
		free((*map)[i++]);
	free(*map);
	*map = NULL;
}

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		printf("[%d]	{%s} | [%d]\n", i, map[i], (int)ft_strlen(map[i]));
		i++;
	}
	printf("\n");
}
