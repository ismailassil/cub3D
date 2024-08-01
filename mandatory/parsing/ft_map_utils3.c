/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:29:23 by ybellakr          #+#    #+#             */
/*   Updated: 2024/08/01 09:46:11 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_color(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (ft_count_semi(str) == 2 && ft_is_num(str, data))
		return (1);
	return (0);
}

int	ft_find(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_put_direction(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			return (str[i]);
		i++;
	}
	return (0);
}

int	ft_get_last_line(t_data *data, int count)
{
	while (data->data && data->data[count + 1])
		count++;
	if (!ft_find(data->data[count], '1'))
		return (-1337);
	return (count);
}

int	ft_size(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
