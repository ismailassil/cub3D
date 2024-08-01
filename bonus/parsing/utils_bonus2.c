/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:40:59 by ybellakr          #+#    #+#             */
/*   Updated: 2024/08/01 10:41:07 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	my_strc1(char *str, char *str1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] == str1[j])
	{
		j++;
		i++;
	}
	if (str1[j] == '\0')
		return (1);
	return (0);
}
