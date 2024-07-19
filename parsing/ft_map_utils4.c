/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:32:09 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/19 11:23:31 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check2(t_data *data, int count)
{
	int k;
	int i;

	k = 0;
	i = ft_my_strl2(data->data[count]);
	if (data->data[count + 1] && (ft_strlen (data->data[count]) < ft_strlen(data->data[count + 1])))
	{
		k = ft_my_strl2(data->data[count + 1]);
		while (k > i)
		{
			if (data->data[count + 1][k] == '0')
				return (0);
			k--;
		}
	}
	return (1);
}

int	ft_check3(t_data *data, int count)
{
	int k;
	int i;

	k = 0;
	count--;
	i = ft_my_strl2(data->data[count]);
	if (data->data[count + 1] && (ft_strlen(data->data[count]) > ft_strlen(data->data[count + 1])))
	{
		k = ft_my_strl2(data->data[count + 1]);
		while (i > k)
		{
			if (data->data[count][i] == '0')
				return (0);
			i--;
		}
	}
	return (1);
}

int	ft_borders_utils(t_data *data, int count)
{
	int	l;
	int a;
	int	i;

	i = 0, a = 0;

	int kk = ft_get_last_line(data, count);
	while (data->data[kk][a])
	{
		if (data->data[kk][a] != '1' && data->data[kk][a] != ' ' && data->data[kk][a] != '\n')
			return (0);
		a++;
	}
	
	while (data->data && data->data[count])
	{
		i = 0;
		while (data->data[count][i] == ' ')
			i++;
		if (data->data[count][i] == '1')
		{
			l = ft_strlen(data->data[count]) - 1;
			if (data->data[count][l] && data->data[count][l] == '\n')
				l--;
			while (data->data[count][l] && (data->data[count][l] == ' ') && l >= 0)
				l--;
			if (data->data[count][l] != '1')
				return (0);
		}
		else
			return (0);
		count++;
	}
	return (1);
}

int	ft_map_validity(t_data	*data, int count)
{
	int	prev_line;
	int	line, i = 0, j = 0, player = 0;

	line = count;
	while (data->data && data->data[count])
	{
		if (ft_find_char(data->data[count], 'N') || ft_find_char(data->data[count], 'S') 
			|| ft_find_char(data->data[count], 'E') || ft_find_char(data->data[count], 'W'))
		{
			player++;
			data->direction = ft_put_direction(data->data[count]);
		}
		if (!ft_find_char(data->data[count], 'N') && !ft_find_char(data->data[count], 'S') 
			&& !ft_find_char(data->data[count], 'E') && !ft_find_char(data->data[count], 'W')
			&& !ft_find_char(data->data[count], '1') && !ft_find_char(data->data[count], '0')
			&& !ft_find_char(data->data[count], ' ') && !ft_find_char(data->data[count], '\n'))
				return (printf("here\n"), 0);
		count++;
	}
	if (player == 1 && ft_check_map_borders(data, line)
		&& ft_borders_utils(data, line))
		return (printf("got here\n"), 1);
	else
	 	return (printf("test111\n"), 0);
}

int	ft_find_chr(char *str)
{
	int	i, flag, flag1;

	i = 0;
	while (str && str[i])
	{
		flag = 0;
		flag = 0;
		if (str[0] == '\n')
			return (1);
		if (str[i] == 'N' || str[i] == 'W' || str[i] == 'S' || str[i] == 'E')
			flag = 1;
		if ((str[i] == '0' || str[i] == '1'))
			flag1 = 1;
		if (str[i] != 'N' && str[i] != 'W' && str[i] != 'S' && str[i] != 'E'
			&& str[i] != '0' && str[i] != '1' && str[i] != ' ' && str[i] != '\n')
				return (0);
		if (str[i])
			i++;
	}
	if (flag == 1 && flag1 == 1)
		return (1);
	else if (flag == 0 && flag1 == 1)
		return (1);
	else
		return (0);
}
