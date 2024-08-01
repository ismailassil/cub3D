/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils6_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:41:50 by ybellakr          #+#    #+#             */
/*   Updated: 2024/08/01 10:04:22 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	ft_my_strl2(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str && str[i])
		i++;
	if (i > 0)
		i--;
	while (str && str[i] && i > 0)
	{
		if (str[i] == '1' || str[i] == '0')
			break ;
		i--;
	}
	return (i);
}

int	ft_chr(char *str)
{
	int	i;

	i = 0;
	while (str && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '\n')
		return (0);
	return (1);
}

int	ft_is_surounded(t_data *data, int count)
{
	int	i;

	i = 0;
	while (data->data[count])
	{
		i = 0;
		while (data->data[count][i])
		{
			if (data->data[count][i] == ' '
				&& ((i > 0 && data->data[count][i - 1] == '0')
				|| ((int)ft_strlen(data->data[count]) >= i
				&& data->data[count][i + 1] == '0')))
				return (0);
			i++;
		}
		count++;
	}
	return (1);
}

int	ft_borders(t_data *data, int i)
{
	t_map_utils	t;

	(1) && (t.l = 0, t.k = 0, t.j = 0, t.last = ft_get_last_line(data, i));
	while (data->data[i][t.j])
	{
		if (data->data[i][t.j] == '0')
			return (0);
		t.j++;
	}
	t.j = 0;
	while (data->data[t.last][t.j])
	{
		if (data->data[t.last][t.j] == '0')
			return (0);
		t.j++;
	}
	while (data->data[i])
	{
		t.k = ft_my_strl(data->data[i]);
		t.l = ft_my_strl2(data->data[i]);
		if (data->data[i][t.k] != '1' || data->data[i][t.l] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_path(char *str, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (str && (str[i] == ' '))
		i++;
	if ((int)ft_strlen(str) - 1 > i + 2)
		i += 2;
	while (str && str[i] == ' ')
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
