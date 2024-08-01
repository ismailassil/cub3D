/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:04:01 by ybellakr          #+#    #+#             */
/*   Updated: 2024/08/01 10:38:57 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_strcmp3(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] == c)
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
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

int	ft_find1(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == 'E' || str[i] == 'W' || str[i] == 'N' || str[i] == 'S')
			count++;
		i++;
	}
	return (count);
}

int	ft_player(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == 'S' || str[i] == 'W' || str[i] == 'N' || str[i] == 'E')
		{
			if ((str[i + 1] && str[i + 1] == ' ')
				|| (i > 0 && str[i - 1] == ' '))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_player(t_data *data, int i)
{
	while (data->data[i])
	{
		if (ft_find(data->data[i], 'S') || ft_find(data->data[i], 'N')
			|| ft_find(data->data[i], 'W') || ft_find(data->data[i], 'E'))
		{
			if (!ft_player(data->data[i]))
				return (0);
		}
		i++;
	}
	return (1);
}
