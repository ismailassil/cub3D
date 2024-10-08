/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:36:35 by ybellakr          #+#    #+#             */
/*   Updated: 2024/08/13 22:58:48 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	ft_put_map(t_data *data, int i)
{
	int	count;
	int	j;

	count = 0;
	j = i;
	while (data->data[j++])
		count++;
	data->map = malloc((count + 1) * sizeof(char **));
	if (!data->map)
		(p_error("Allocation failed", 0, 1), exit(FAIL));
	count = 0;
	while (data->data[i])
	{
		data->map[count] = data->data[i];
		ft_remove_line(data->map[count]);
		(1) && (i++, count++);
	}
	data->map[count] = NULL;
}

int	ft_check_parse(t_data *data)
{
	t_parse	t;
	int		i;
	int		count;
	int		return_check;

	(1) && (t.flag = 0, i = 0, count = 0);
	while (data && data->data[i] && (ft_strcmp(data->data[i], "\n")
			|| !ft_strcmp3(data->data[i], ' ')))
		i++;
	t.k = i + 5;
	while (data->data[i])
	{
		return_check = 0;
		return_check = ft_check_parse1(&data, i, &count, t);
		if (return_check == -1337)
			return (0);
		if (return_check)
			break ;
		i++;
	}
	if (!data->data[i] || !ft_check_parse_utils(data, count, i)
		|| !ft_duplicate(data) || !ft_check_player(data, i))
		return (0);
	ft_put_map(data, i);
	return (1);
}

int	ft_map_valid_urils(int line, t_data *data, int a)
{
	int	i;
	int	k;

	(1) && (i = 0, k = 0);
	if (line != 0
		&& ft_my_strl2(data->data[line]) < ft_my_strl2(data->data[line - 1]))
	{
		a = 0;
		k = ft_my_strl2(data->data[line - 1]);
		i = ft_my_strl2(data->data[line]);
		if (i == 0 && k == 0)
			return (0);
		while (i < k && a != i)
		{
			if (data->data[line - 1][k] == '0')
				return (0);
			k--;
			a++;
		}
	}
	return (1);
}

int	inside_map_validity(t_data *data, int line)
{
	t_validity	t;

	(1) && (t.k = 0, t.i = 0, line++);
	while (data->data[line++])
	{
		if (line != 0 && ft_my_strl2(data->data[line])
			> ft_my_strl2(data->data[line - 1]))
		{
			(1) && (t.k = ft_my_strl2(data->data[line - 1]),
			t.i = ft_my_strl2(data->data[line]));
			(1) && (t.a = 0, t.ss = t.i - t.k + 1);
			if (t.i == 0 && t.k == 0)
				return (0);
			while (t.k < t.i && t.a != t.ss)
			{
				if (data->data[line][t.i] == '0')
					return (0);
				(1) && (t.i--, t.a++);
			}
			return (1);
		}
		if (!ft_map_valid_urils(line, data, t.a))
			return (0);
	}
	return (1);
}
