/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils7.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:11:25 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/21 17:39:50 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_put_path(t_data *data, char *str, int j)
{
	if (my_strcmp(str, "NO "))
	{
		data->path->north = ft_strdup(&str[j]);
		if (!data->path->north)
			return (0);
	}
	else if (my_strcmp(str, "SO "))
	{
		data->path->south = ft_strdup(&str[j]);
		if (!data->path->south)
			return (0);
	}
	else if (my_strcmp(str, "WE "))
	{
		data->path->west = ft_strdup(&str[j]);
		if (!data->path->west)
			return (0);
	}
	else if (my_strcmp(str, "EA "))
	{
		data->path->east = ft_strdup(&str[j]);
		if (!data->path->east)
			return (0);
	}
	return (1);
}

int	ft_check_path_utils(t_data *data, char *str, int i)
{
	if (str[i] == '.' || str[i] == '/')
	{
		i++;
		if (str[i] == '\n' || str[i] == '\0')
			return (0);
		i++;
		if (str[i] == '\n' || str[i] == '\0')
			return (0);
		if (str[i] == ' ' || str[i] == '\t')
		{
			while (str && (str[i] == ' '))
				i++;
			if (str[i] == '\n' || str[i] == '\0')
				return (0);
		}
	}
	return (1);
}

int	ft_check_path(char *str, t_data *data)
{
	int	i;
	int	j;

	i = 2;
	while (str && (str[i] == ' '))
		i++;
	j = i;
	if (str[i] == '\n' || str[i] == '\0')
		return (0);
	else
	{
		if (!ft_check_path_utils(data, str, i))
			return (0);
	}
	if (!ft_put_path(data, str, j))
		return (0);
	return (1);
}

int	ft_is_strange_utils(t_data *data, int count, int i)
{
	int	kk;

	kk = 0;
	while (count > 0 && data->data[count])
	{
		i = ft_strlen(data->data[count - 1]) - 1;
		kk = ft_strlen(data->data[count]) - 1;
		if (data->data[count][kk] != '\n')
			kk++;
		while (i >= 0 && data->data[count - 1][i])
		{
			if (data->data[count - 1][i] == '0' && i >= kk)
				return (0);
			i--;
		}
		count++;
	}
	return (1);
}

int	ft_is_strange(t_data *data, int count)
{
	int	i;
	int	k;

	i = 0;
	k = count;
	while (data->data[count + 1])
	{
		i = ft_strlen(data->data[count + 1]) - 1;
		while (i >= 0 && data->data[count + 1][i])
		{
			if (data->data[count + 1][i] == '0'
				&& i >= ft_strlen(data->data[count]) - 1)
				return (0);
			i--;
		}
		count++;
	}
	count = k;
	if (!ft_is_strange_utils(data, count, i))
		return (0);
	return (1);
}
