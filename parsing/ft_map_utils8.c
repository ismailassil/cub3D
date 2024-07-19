/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:21:26 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/19 11:24:37 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int ft_check_borders_utils1(t_data *data, int count, int i)
{
	if (data->data[count][i] == ' ' && data->data[count + 1]
		&& i <= ft_my_strl2(data->data[count + 1]) && (data->data[count + 1][i] == ' '))
		{
			int k = i;
			int a = count;
			while (data->data[a + 1])
			{
				if (data->data[a + 1] && k <= ft_my_strlen(data->data[a + 1]) && (data->data[a + 1][k] == '0'
					|| data->data[a + 1][k] == 'N' || data->data[a + 1][k] == 'S'
					|| data->data[a + 1][k] == 'E' || data->data[a + 1][k] == 'W'))
					return(0);
				else if (data->data[a + 1] && k <= ft_my_strlen(data->data[a + 1]) && data->data[a + 1][k] == '1')
					break;
				a++;
			}
		}
	return (1);
}

int ft_check_borders_utils(t_data *data, int count, int i)
{
	int	k;
	int	a;

	while (data->data && data->data[count + 1])
	{
		i = 0;
		while (data->data[count][i])
		{
			if (!ft_check_borders_utils1(data, count, i))
				return (0);
			else if (data->data[count][i] == ' ' && data->data[count + 1]
				&& i <= ft_my_strl2(data->data[count + 1]) && (data->data[count + 1][i] == '0'
				|| data->data[count + 1][i] == 'N' || data->data[count + 1][i] == 'S'
				|| data->data[count + 1][i] == 'E' || data->data[count + 1][i] == 'W'))
				return (0);
			i++;
		}
		count++;
	}
	if (!ft_check2(data, count))
		return (0);
	return (1);
}

int	ft_chek_borders_utils(t_data *data, int last_line, int i)
{
	if (data->data[last_line][i] == ' ' && data->data[last_line - 1]
		&& i <= ft_my_strl2(data->data[last_line - 1]) && (data->data[last_line - 1][i] == ' '))
	{
		int k = i;
		int a = last_line;
		while (a != 0 && data->data[a - 1])
		{
			if (data->data[a - 1] && k <= ft_my_strlen(data->data[a - 1]) && (data->data[a - 1][k] == '0'
			|| data->data[a - 1][k] == 'N' || data->data[a - 1][k] == 'S'
			|| data->data[a - 1][k] == 'E' || data->data[a - 1][k] == 'W'))
				return(0);
			else if (data->data[a - 1] && k <= ft_my_strlen(data->data[a + 1]) && data->data[a - 1][k] == '1')
				break;
			a--;
		}
	}
	return (1);
}

int	ft_chek_borders(t_data *data, int last_line, int a, int i)
{
	while (data->data && data->data[last_line] && last_line > a)
	{
		i = 0;
		while (data->data[last_line][i])
		{
			if (!ft_chek_borders_utils(data, last_line, i))
				return (0);
			if (i <= ft_my_strl2(data->data[last_line - 1]) && data->data[last_line][i] == ' '
				&& data->data[last_line - 1] && (data->data[last_line - 1][i] == '0'
				|| data->data[last_line - 1][i] == 'N'  || data->data[last_line - 1][i] == 'S'
				|| data->data[last_line - 1][i] == 'E' || data->data[last_line - 1][i] == 'W'))
				return (printf("here2?%s\n", data->data[last_line]), 0);
			i++;
		}
		last_line--;
	}
	return (1);
}

int	ft_check_map_borders(t_data *data, int count)
{
	int	i;
	int a;
	int	last_line;

	(1) && (a = count, i = 0);
	last_line = ft_get_last_line(data, count);
	if ((last_line == -1337 && last_line != 0 && last_line != 1) || data->data[last_line - 1][0] == '\n')
		return (0);
	i = ft_size(data->data[last_line]) - 1;
	while (data->data[last_line][i] == ' ')
		i--;
	if (data->data[last_line][i] == '\n')
		return (0);
	if (!ft_find_char(data->data[count], '1') && !ft_find_char(data->data[count], ' ')
		&& !ft_find_char(data->data[count], '\n'))
		return (0);
	i = 0;
	if (!ft_check_borders_utils(data, count, i))
		return (0);
	i = 0;
	if (!ft_chek_borders(data, last_line, a, i))
		return (0);
	if (!ft_check3(data, last_line))
		return (0);
	return (1);
}
