/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:39:53 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/21 17:00:59 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_size_map(t_data *data, int i)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (data->data[j])
	{
		if (ft_find(data->data[j], '0') || ft_find(data->data[j], '1'))
			count++;
		j++;
	}
	return (count);
}

int	ft_my_strl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '1' || str[i] == '0')
			break ;
		i++;
	}
	return (i);
}

int	is_there(char *str, char *str1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str && str1 && str[i] && str1[j])
	{
		if (str[i] != str1[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	ft_my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	if (i > 0)
		i--;
	while (i > 0 && str[i] && (str[i] != '1' || str[i] != '0'))
		i--;
	return (i);
}
