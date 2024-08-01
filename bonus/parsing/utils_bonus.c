/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:22:54 by ybellakr          #+#    #+#             */
/*   Updated: 2024/08/01 10:41:49 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	ft_strcmp3(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] == c)
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

void	ft_remove_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
}

int	ft_find1(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == 'E' || str[i] == 'W' || str[i] == 'N' || str[i] == 'S')
			count++;
		i++;
	}
	return (count);
}

int	ft_player(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == 'S' || str[i] == 'W' || str[i] == 'N' || str[i] == 'E')
		{
			if ((str[i + 1] && str[i + 1] == ' ')
				|| (i > 0 && str[i - 1] == ' '))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_player(t_data *data, int i)
{
	while (data->data[i])
	{
		if (ft_find(data->data[i], 'S') || ft_find(data->data[i], 'N')
			|| ft_find(data->data[i], 'W') || ft_find(data->data[i], 'E'))
		{
			if (!ft_player(data->data[i]))
				return (0);
		}
		i++;
	}
	return (1);
}
