/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:36:35 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/21 15:45:34 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_map_valid_urils(int line, t_data *data, int a)
{
	int i;
	int k;

	(1) && (i = 0, k = 0);
	if (line != 0 && ft_my_strl2(data->data[line]) < ft_my_strl2(data->data[line - 1]))
	{
		a = 0;
		k = ft_my_strl2(data->data[line - 1]);
		i = ft_my_strl2(data->data[line]);
		if (i == 0 && k == 0)
			return (printf("hhhh2\n"), 0);
		while (i < k && a != i)
		{
			if (data->data[line - 1][k] == '0')
				return (printf("hhhh3\n"), 0);
			k--;
			a++;
		}
	}
	return (1);
}

int	inside_map_validity(t_data *data, int line)
{
	t_validity	t;

	(1) && (t.k = 0, t.i = 0, line++, line++);
	while (data->data[line])
	{
		if (line != 0 && ft_my_strl2(data->data[line]) > ft_my_strl2(data->data[line - 1]))
		{
			(1) && (t.k = ft_my_strl2(data->data[line - 1]), t.i = ft_my_strl2(data->data[line]));
			(1) && (t.a  = 0, t.ss = t.i - t.k + 1);
			if (t.i == 0 && t.k == 0)
				return (printf("hhhh\n"), 0);
			while (t.k < t.i && t.a != t.ss)
			{
				if (data->data[line][t.i] == '0')
					return (printf("hhhh1\n"), 0);
				(1) && (t.i--, t.a++);
			}
			return (1);
		}
		if (!ft_map_valid_urils(line, data, t.a))
			return (0);
		line++;
	}
	return (1);
}
