/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils9.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:05:15 by ybellakr          #+#    #+#             */
/*   Updated: 2024/08/13 22:49:08 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_parse_utils1(t_data *data, int count, int a, int i)
{
	int	kk;
	int	ii;

	kk = 0;
	a = 0;
	i++;
	while (data->data[a])
	{
		if (is_there(data->data[a], "NO ") || is_there(data->data[a], "SO ")
			|| is_there(data->data[a], "WE ") || is_there(data->data[a], "EA ")
			|| is_there(data->data[a], "F ") || is_there(data->data[a], "C "))
			kk++;
		a++;
	}
	if (count > 12 || kk != 6 || !data->data[i])
		return (0);
	ii = ++i;
	while (data->data[ii])
	{
		if (!ft_find_chr(data->data[ii]))
			return (0);
		ii++;
	}
	return (1);
}

int	ft_check_parse_util1(t_data *data, int i)
{
	if (!ft_map_validity(data, i) || !ft_borders(data, i)
		|| ft_size_map(data) < 2 || !inside_map_validity(data, i)
		|| !ft_is_surounded(data, i) || !ft_is_strange(data, i))
		return (0);
	return (1);
}

int	ft_check_parse_utils(t_data *data, int count, int i)
{
	int	a;
	int	kk;

	a = 0;
	if (!ft_check_parse_utils1(data, count, a, i))
		return (0);
	(1) && (i = 0, kk = 0);
	while (data->data[i])
	{
		if (is_there(data->data[i], "NO ") || is_there(data->data[i], "SO ")
			|| is_there(data->data[i], "WE ") || is_there(data->data[i], "EA ")
			|| is_there(data->data[i], "F ") || is_there(data->data[i], "C "))
			kk++;
		if (kk == 6)
		{
			i++;
			break ;
		}
		i++;
	}
	while (!ft_find(data->data[i], '1') && !ft_find(data->data[i], '0'))
		i++;
	if (!ft_check_parse_util1(data, i))
		return (0);
	return (1);
}

int	ft_nrm_if(t_data *data, int i, int count)
{
	if (!ft_strcmp2(data->data[i], "NO ")
		&& !ft_strcmp2(data->data[i], "SO ")
		&& !ft_strcmp2(data->data[i], "\n")
		&& !ft_strcmp2(data->data[i], "WE ")
		&& !ft_strcmp2(data->data[i], "EA ")
		&& !ft_strcmp2(data->data[i], "F ")
		&& !ft_strcmp2(data->data[i], "C ") && count < 6)
		return (0);
	return (1);
}

int	ft_check_parse1(t_data **data, int i, int *count, t_parse t)
{
	t.flag = 0;
	if (skipspace_strcmp((*data)->data[i], "NO ")
		|| skipspace_strcmp((*data)->data[i], "SO ")
		|| skipspace_strcmp((*data)->data[i], "WE ")
		|| skipspace_strcmp((*data)->data[i], "EA "))
	{
		t.flag = 1;
		if (!ft_check_path((*data)->data[i], *data))
			return (-1337);
		(1) && (t.k = i, *count += 1);
	}
	if (*count == 12)
		return (1);
	else if (skipspace_strcmp((*data)->data[i], "F ")
		|| skipspace_strcmp((*data)->data[i], "C "))
	{
		t.flag = 1;
		if (!ft_check_color((*data)->data[i], *data))
			return (-1337);
		(1) && (*count += 1, t.k = i);
	}
	if (*count == 12)
		return (1);
	if (!ft_nrm_if(*data, i, *count))
		return (-1337);
	return (0);
}
