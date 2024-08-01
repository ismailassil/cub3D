/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validity_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:36:35 by ybellakr          #+#    #+#             */
/*   Updated: 2024/08/01 10:39:54 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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

int	ft_duplicate(t_data *data)
{
	t_dup	t;

	(1) && (t.i = 0, t.c = 0, t.f = 0, t.ea = 0, t.no = 0, t.so = 0, t.we = 0);
	while (data->data[t.i])
	{
		if (my_strc1(data->data[t.i], "F "))
			t.f++;
		if (my_strc1(data->data[t.i], "C "))
			t.c++;
		if (my_strc1(data->data[t.i], "NO "))
			t.no++;
		if (my_strc1(data->data[t.i], "SO "))
			t.so++;
		if (my_strc1(data->data[t.i], "EA "))
			t.ea++;
		if (my_strc1(data->data[t.i], "WE "))
			t.we++;
		t.i++;
	}
	if (t.no != 1 || t.so != 1 || t.ea != 1
		|| t.we != 1 || t.f != 1 || t.c != 1)
		return (0);
	return (1);
}

int	ft_check_parse(t_data *data)
{
	int		i;
	t_parse	t;
	int		count;

	(1) && (t.flag = 0, i = 0, count = 0);
	while (data && data->data[i] && (ft_strcmp(data->data[i], "\n")
			|| !ft_strcmp3(data->data[i], ' ')))
		i++;
	t.k = i + 5;
	while (data->data[i])
	{
		if (ft_check_parse1(&data, i, &count, t) == -1337)
			return (0);
		if (ft_check_parse1(&data, i, &count, t))
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
