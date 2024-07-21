/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:25:59 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/21 16:39:58 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_count_semi(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	ft_check_num(char *str)
{
	int	i;

	i = 0;
	while (str && str[i + 1] && str[i + 1] != ',')
	{
		if (str[i] >= '0' && str[i] <= '9')
			;
		else
			return (0);
		i++; 
	}
	return (1);
}

int	ft_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0); 
	while (str && str[i])
	{
		if ((str[i] < '0' || str[i] > '9') 
			&& str[i] != ' ' && str[i] != '+' && str[i] != '-')
			return (printf("from here\n"), 0);
		i++;
	}
	return (1);
}

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void	ft_free_array(char **ar)
{
	int	i;

	i = 0;
	while (ar && ar[i])
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}
