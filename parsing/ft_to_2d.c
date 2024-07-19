/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:37:35 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/19 12:14:55 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	ft_is_num(char *str, t_data *data)
{
	int		i;
	char	**ar;
	char	**ar1;
	int		w;

	1 && (i = 1, w = 0);
	while (str && (str[i] == ' '))
		i++;
	ar = ft_split(&str[i], ',');
	if (!ar)
		return (0);
	while (w <= 2)
	{
		if (w == 2)
		{
			i = 0;
			while (ar[w][i])
				i++;
			if (i != 0 && ar[w][i - 1] == '\n')
				ar[w][i - 1] = '\0';
		}
		if (!ft_num(ar[w]))
			return (ft_free_array(ar),0);
		w++;
	}
	w = 0;
	while (w <= 2)
	{
		if (w == 2)
		{
			i = 0;
			while (ar[w][i])
				i++;
			if (i != 0 && ar[w][i - 1] == '\n')
				ar[w][i - 1] = '\0';
		}
		int k = 0;
		while (str && (str[k] == ' '))
			k++;
		if (str && str[k] == 'C')
			k = 0;
		else
		 	k = 1;
		if (!ft_check_range(ar[w], data, k))
			return (printf("got here"),ft_free_array(ar), 0);
		w++;
	}
	return (ft_free_array(ar),1);
}


int	inside_map_validity(t_data *data, int line)
{
	int	k;
	int a;
	int	i;

	k = 0;
	i = 0;
	line++;
	a = 0;
	while (data->data[line])
	{
		if (line != 0 && ft_my_strl2(data->data[line]) > ft_my_strl2(data->data[line - 1]))
		{
			k = ft_my_strl2(data->data[line - 1]);
			i = ft_my_strl2(data->data[line]);
			a  = 0;
			int ss = i - k + 1;
			if (i == 0 && k == 0)
				return (printf("hhhh\n"), 0);
			while (k < i && a != ss)
			{
				if (data->data[line][i] == '0')
					return (printf("hhhh1\n"), 0);
				i--;
				a++;
			}
			return (1);
		}
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
		line++;
	}
	return (1);
}
