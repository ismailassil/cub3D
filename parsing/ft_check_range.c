/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_range.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:14:49 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/21 15:35:37 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_check_range_util(int *z, char c, int *i)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*z = -1;
		*i += 1;
	}
}

long long	ft_check_range_utils(char *str, int i, int z, long long t)
{
	while (str && (str[i] == ' '))
		i++;
	if (str[i] == '\0')
		return (printf("got here\n"), -1337);
	ft_check_range_util(&z, str[i], &i);
	while (str && str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			if (str[i] == '\0')
				break ;
			else if (str[i] != '\0')
				return (-1337);
		}
		(1) && (i++, t = t * 10 + str[i] - 48);
	}
	t = t * z;
	if (t < 0 || t > 255)
		return (-1337);
	return (t);
}

void	ft_assign_data(int flag, int *a, t_data *data, long long t)
{
	if (flag == 0)
	{
		if (*a == 0)
			data->ceiling.red = t;
		else if (*a == 1)
			data->ceiling.green = t;
		else if (*a == 2)
			data->ceiling.blue = t;
		*a += 1;
	}
	if (flag == 1)
	{
		if (*a == 0)
			data->floor.red = t;
		else if (*a == 1)
			data->floor.green = t;
		else if (*a == 2)
			data->floor.blue = t;
		*a += 1;
	}
}

int	ft_check_range(char *str, t_data *data, int flag)
{
	int			i;
	int			z;
	long long 	t;
	static	int	a;

	(1) && (t = 0, z = 1, i = 0);
	t = ft_check_range_utils(str, i, z, t);
	if (t == -1337)	
	 return (0);
	ft_assign_data(flag, &a, data, t);
	if (a == 3)
		a = 0;
	return (1);
}
