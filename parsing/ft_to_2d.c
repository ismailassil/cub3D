/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:37:35 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/21 17:31:16 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_is_num_utils(char **ar, int w, int i)
{
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
			return (ft_free_array(ar), 0);
		w++;
	}
	return (1);
}

int	ft_is_num_utils2(int w, t_data *data, char **ar, char *str)
{
	int	k;
	int	i;

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
		k = 0;
		while (str && (str[k] == ' '))
			k++;
		if (str && str[k] == 'C')
			k = 0;
		else
			k = 1;
		if (!ft_check_range(ar[w], data, k))
			return (printf("got here"), ft_free_array(ar), 0);
		w++;
	}
	return (1);
}

int	ft_is_num(char *str, t_data *data)
{
	int		i;
	int		k;
	char	**ar;
	int		w;

	1 && (i = 1, w = 0);
	while (str && (str[i] == ' '))
		i++;
	ar = ft_split(&str[i], ',');
	if (!ft_is_num_utils(ar, w, i))
		return (0);
	if (!ft_is_num_utils2(w, data, ar, str))
		return (0);
	return (ft_free_array(ar), 1);
}
