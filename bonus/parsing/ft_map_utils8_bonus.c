/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils8_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:21:26 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/23 10:29:26 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	ft_check_borders_utils1(t_data *data, int count, int i)
{
	int	k;
	int	a;

	if (data->data[count][i] == ' ' && data->data[count + 1]
		&& i <= ft_my_strl2(data->data[count + 1])
		&& (data->data[count + 1][i] == ' '))
	{
		k = i;
		a = count;
		while (data->data[a + 1])
		{
			if (data->data[a + 1] && k <= ft_my_strlen(data->data[a + 1])
				&& (data->data[a + 1][k] == '0'
				|| data->data[a + 1][k] == 'N' || data->data[a + 1][k] == 'S'
				|| data->data[a + 1][k] == 'E' || data->data[a + 1][k] == 'W'))
				return (0);
			else if (data->data[a + 1] && k <= ft_my_strlen(data->data[a + 1])
				&& data->data[a + 1][k] == '1')
				break ;
			a++;
		}
	}
	return (1);
}

int	ft_check_borders_utils(t_data *data, int c, int i)
{
	while (data->data && data->data[c + 1])
	{
		i = 0;
		while (data->data[c][i])
		{
			if (!ft_check_borders_utils1(data, c, i))
				return (0);
			else if (data->data[c][i] == ' ' && data->data[c + 1]
				&& i <= ft_my_strl2(data->data[c + 1])
				&& (data->data[c + 1][i] == '0' || data->data[c + 1][i] == 'N'
				|| data->data[c + 1][i] == 'S' || data->data[c + 1][i] == 'E'
				|| data->data[c + 1][i] == 'W'))
				return (0);
			i++;
		}
		c++;
	}
	if (!ft_check2(data, c))
		return (0);
	return (1);
}

int	ft_chek_borders_utils(t_data *data, int last_line, int i)
{
	int	k;
	int	a;

	if (data->data[last_line][i] == ' ' && data->data[last_line - 1]
		&& i <= ft_my_strl2(data->data[last_line - 1])
		&& (data->data[last_line - 1][i] == ' '))
	{
		k = i;
		a = last_line;
		while (a != 0 && data->data[a - 1])
		{
			if (data->data[a - 1] && k < ft_my_strlen(data->data[a - 1])
				&& (data->data[a - 1][k] == '0' || data->data[a - 1][k] == 'N'
				|| data->data[a - 1][k] == 'S' || data->data[a - 1][k] == 'E'
				|| data->data[a - 1][k] == 'W'))
				return (0);
			else if (data->data[a - 1] && k <= ft_my_strlen(data->data[a + 1])
				&& data->data[a - 1][k] == '1')
				break ;
			a--;
		}
	}
	return (1);
}

int	ft_chek_borders(t_data *data, int last, int a, int i)
{
	while (data->data && data->data[last] && last > a)
	{
		i = 0;
		while (data->data[last][i])
		{
			if (!ft_chek_borders_utils(data, last, i))
				return (0);
			if (i <= ft_my_strl2(data->data[last - 1])
				&& data->data[last][i] == ' ' && data->data[last - 1]
				&& (data->data[last - 1][i] == '0'
				|| data->data[last - 1][i] == 'N'
				|| data->data[last - 1][i] == 'S'
				|| data->data[last - 1][i] == 'E'
				|| data->data[last - 1][i] == 'W'))
				return (0);
			i++;
		}
		last--;
	}
	return (1);
}

int	ft_check_map_borders(t_data *data, int count)
{
	int	i;
	int	a;
	int	last_line;

	(1) && (a = count, i = 0, last_line = ft_get_last_line(data, count));
	if ((last_line == -1337 && last_line != 0 && last_line != 1)
		|| data->data[last_line - 1][0] == '\n')
		return (0);
	i = ft_size(data->data[last_line]) - 1;
	while (data->data[last_line][i] == ' ')
		i--;
	if (data->data[last_line][i] == '\n')
		return (0);
	if (!ft_find(data->data[count], '1') && !ft_find(data->data[count], ' ')
		&& !ft_find(data->data[count], '\n'))
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
