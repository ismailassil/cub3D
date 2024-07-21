/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:32:09 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/21 17:00:38 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check2(t_data *data, int count)
{
	int	k;
	int	i;

	k = 0;
	i = ft_my_strl2(data->data[count]);
	if (data->data[count + 1] && 
		(ft_strlen (data->data[count]) < ft_strlen(data->data[count + 1])))
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
	int	k;
	int	i;

	k = 0;
	count--;
	i = ft_my_strl2(data->data[count]);
	if (data->data[count + 1] 
		&& (ft_strlen(data->data[count]) > ft_strlen(data->data[count + 1])))
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

int	ft_borders_utils1(t_data *data, int count)
{
	int	kk;
	int	a;

	kk = ft_get_last_line(data, count);
	a = 0;
	while (data->data[kk][a])
	{
		if (data->data[kk][a] != '1' 
			&& data->data[kk][a] != ' ' && data->data[kk][a] != '\n')
			return (0);
		a++;
	}
	return (1);
}

int	ft_borders_utils(t_data *data, int a)
{
	int	l;
	int	i;

	if (!ft_borders_utils1(data, a))
		return (0);
	while (data->data && data->data[a])
	{
		i = 0;
		while (data->data[a][i] == ' ')
			i++;
		if (data->data[a][i] == '1')
		{
			l = ft_strlen(data->data[a]) - 1;
			if (data->data[a][l] && data->data[a][l] == '\n')
				l--;
			while (data->data[a][l] && (data->data[a][l] == ' ') && l >= 0)
				l--;
			if (data->data[a][l] != '1')
				return (0);
		}
		else
			return (0);
		a++;
	}
	return (1);
}

int	ft_map_validity(t_data	*data, int c)
{
	t_utils	t;

	(1) && (t.player = 0, t.j = 0, t.i = 0, t.line = c);
	while (data->data && data->data[c])
	{
		if (ft_find(data->data[c], 'N') || ft_find(data->data[c], 'S') 
			|| ft_find(data->data[c], 'E') || ft_find(data->data[c], 'W'))
		{
			t.player++;
			data->direction = ft_put_direction(data->data[c]);
		}
		if (!ft_find(data->data[c], 'N') && !ft_find(data->data[c], 'S') 
			&& !ft_find(data->data[c], 'E') && !ft_find(data->data[c], 'W')
			&& !ft_find(data->data[c], '1') && !ft_find(data->data[c], '0')
			&& !ft_find(data->data[c], ' ') && !ft_find(data->data[c], '\n'))
			return (printf("here\n"), 0);
		c++;
	}
	if (t.player == 1 && ft_check_map_borders(data, t.line)
		&& ft_borders_utils(data, t.line))
		return (printf("got here\n"), 1);
	else
		return (printf("test111\n"), 0);
}
